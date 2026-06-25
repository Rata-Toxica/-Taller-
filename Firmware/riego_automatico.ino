#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// =======================
// WIFI
// =======================
const char* ssid = "iPhone de Moira";
const char* password = "66666666";

// =======================
// PINES
// =======================
const int sensorPin = 34;   // Sensor humedad: AOUT -> G34
const int relePin = 26;     // Relé: IN -> G26

// =======================
// UBICACION
// Santiago de Chile aprox.
// =======================
float latitude = -33.45;
float longitude = -70.66;

// =======================
// CONFIGURACION
// =======================
int umbralSeco = 2500;          // Ajustar según prueba del sensor
int probLluviaLimite = 50;      // Si probabilidad lluvia >= 50%, no riega
int tiempoRiegoMs = 3000;       // Riega 3 segundos

// Relé activo en LOW
const int RELE_ON = LOW;
const int RELE_OFF = HIGH;

// =======================
// VARIABLES
// =======================
bool lloveraPronto = false;
bool esDeDia = true;

unsigned long ultimoChequeoClima = 0;
unsigned long intervaloClima = 600000; // 10 minutos

// =======================
// CONECTAR WIFI
// =======================
void conectarWiFi() {
  Serial.print("Conectando a WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int intentos = 0;

  while (WiFi.status() != WL_CONNECTED && intentos < 40) {
    delay(500);
    Serial.print(".");
    intentos++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi conectado");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("No se pudo conectar al WiFi");
  }
}

// =======================
// CONSULTAR API CLIMA
// =======================
void consultarClima() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("No hay WiFi, no se consulta clima");
    return;
  }

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;

  String url = "https://api.open-meteo.com/v1/forecast?latitude=" + String(latitude, 6) +
               "&longitude=" + String(longitude, 6) +
               "&hourly=precipitation_probability,is_day" +
               "&forecast_hours=6" +
               "&timezone=auto";

  Serial.println("Consultando clima...");
  Serial.println(url);

  http.begin(client, url);
  int code = http.GET();

  if (code != 200) {
    Serial.print("Error al consultar clima. Codigo: ");
    Serial.println(code);
    http.end();
    return;
  }

  DynamicJsonDocument doc(12000);
  DeserializationError error = deserializeJson(doc, http.getStream());

  if (error) {
    Serial.print("Error leyendo JSON: ");
    Serial.println(error.c_str());
    http.end();
    return;
  }

  JsonArray lluvia = doc["hourly"]["precipitation_probability"];
  JsonArray dia = doc["hourly"]["is_day"];

  lloveraPronto = false;

  Serial.println("Probabilidad de lluvia proximas 6 horas:");

  for (int i = 0; i < 6; i++) {
    int prob = lluvia[i];

    Serial.print("Hora ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(prob);
    Serial.println("%");

    if (prob >= probLluviaLimite) {
      lloveraPronto = true;
    }
  }

  if (dia.size() > 0) {
    esDeDia = (dia[0] == 1);
  }

  Serial.print("Llovera pronto: ");
  Serial.println(lloveraPronto ? "SI" : "NO");

  Serial.print("Es de dia: ");
  Serial.println(esDeDia ? "SI" : "NO");

  http.end();
}

// =======================
// REGAR
// =======================
void regar() {
  Serial.println(">>> REGANDO <<<");

  digitalWrite(relePin, RELE_ON);
  delay(tiempoRiegoMs);
  digitalWrite(relePin, RELE_OFF);

  Serial.println("PRUEBA NUEVO CODIGO");

  Serial.println("Riego terminado");
}

void enviarDatos(
  int humedad,
  int probabilidad_lluvia,
  bool es_dia,
  bool suelo_seco,
  bool riego,
  int duracion
)
{
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Sin WiFi");
    return;
  }

  HTTPClient http;

  http.begin("http://172.20.10.14:5000/guardar");
  http.addHeader("Content-Type", "application/json");

  String json = "{";
  json += "\"humedad\":" + String(humedad) + ",";
  json += "\"probabilidad_lluvia\":" + String(probabilidad_lluvia) + ",";
  json += "\"es_dia\":" + String(es_dia ? 1 : 0) + ",";
  json += "\"suelo_seco\":" + String(suelo_seco ? 1 : 0) + ",";
  json += "\"riego\":" + String(riego ? 1 : 0) + ",";
  json += "\"duracion\":" + String(duracion);
  json += "}";

  Serial.println(json);

  int codigo = http.POST(json);

  Serial.print("HTTP: ");
  Serial.println(codigo);

  String respuesta = http.getString();

  Serial.print("Respuesta: ");
  Serial.println(respuesta);

  http.end();
}

// =======================
// SETUP
// =======================
void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, RELE_OFF);

  analogReadResolution(12); // lectura 0 a 4095

 conectarWiFi();
// consultarClima();

//enviarDatos(
  //  humedad,
  //  lloveraPronto ? 50 : 0,
   // esDeDia,
    //sueloSeco,
    //seRiego,
  //  seRiego ? tiempoRiegoMs : 0
//);
}

// =======================
// LOOP
// =======================
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi desconectado. Reintentando...");
    conectarWiFi();
  }

  if (millis() - ultimoChequeoClima > intervaloClima) {
    ultimoChequeoClima = millis();
    consultarClima();
  }

  int humedad = analogRead(sensorPin);

  bool sueloSeco = humedad > umbralSeco;
  bool seRiego = false;

  Serial.print("Humedad: ");
  Serial.println(humedad);

  if (humedad > umbralSeco) {
    Serial.println("Suelo seco");

    if (!esDeDia) {
      Serial.println("No riega: ya se puso el sol");
    } 
    else if (lloveraPronto) {
      Serial.println("No riega: llovera pronto");
    } 
    else {
      Serial.println("Condiciones correctas: se riega");
      regar();
      seRiego = true;
    }

  } else {
    Serial.println("Suelo humedo: no se riega");
    digitalWrite(relePin, RELE_OFF);
  }

  if (sueloSeco && esDeDia && !lloveraPronto) {
  seRiego = true;
}

  enviarDatos(
  humedad,
  lloveraPronto ? 50 : 0,
  esDeDia,
  sueloSeco,
  seRiego,
  seRiego ? tiempoRiegoMs : 0
);

  Serial.println("-------------------------");
  delay(5000);

}