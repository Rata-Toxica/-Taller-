#include "BluetoothSerial.h"
//0 =======================
// CONFIGURACION BLUETOOTH
// =======================
BluetoothSerial SerialBT;

// =======================
// PINES
// =======================
const int sensorPin = 34;   // Sensor humedad: AOUT -> G34
const int relePin = 26;     // Relé: IN -> G26

// =======================
// CONFIGURACION
// =======================
int umbralSeco = 2500;          // Ajustar según prueba del sensor
int tiempoRiegoMs = 3000;       // Riega 3 segundos

// Relé activo en LOW
const int RELE_ON = LOW;
const int RELE_OFF = HIGH;

// =======================
// VARIABLES
// =======================
bool lloveraPronto = false;
bool esDeDia = true;

// =======================
// CONFIGURACION BLUETOOTH
// =======================
void setupBluetooth() {
  SerialBT.begin("ESP32_Device"); // Cambia el nombre según desees
  Serial.println("El dispositivo Bluetooth está listo para conectar");
}

// =======================
// REGAR
// =======================
//void regar() {
  //Serial.println(">>> REGANDO <<<");
 // digitalWrite(relePin, RELE_ON);
 // delay(tiempoRiegoMs);
//  digitalWrite(relePin, RELE_OFF);
 // Serial.println("Riego terminado");
//}

// =======================
// ENVIAR DATOS
// =======================
void enviarDatos(int humedad, bool suelo_seco, bool riego) {
  String json = "{";
  json += "\"humedad\":" + String(humedad) + ",";
  json += "\"probabilidad_lluvia\":" + String(lloveraPronto ? 50 : 0) + ",";
  json += "\"es_dia\":" + String(esDeDia ? 1 : 0) + ",";
  json += "\"suelo_seco\":" + String(suelo_seco ? 1 : 0) + ",";
  json += "\"riego\":" + String(riego ? 1 : 0) + ",";
  json += "\"duracion\":" + String(riego ? tiempoRiegoMs : 0);
  json += "}";

  SerialBT.println(json); // Enviar datos a través de Bluetooth
  Serial.println(json);      // USB → app2.py
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

  setupBluetooth(); // Inicializar Bluetooth
}

// =======================
// LOOP
// =======================
void loop() {
  int humedad = analogRead(sensorPin);
  bool sueloSeco = humedad > umbralSeco;
  bool seRiego = false;

  Serial.print("Humedad: ");
  Serial.println(humedad);

  if (sueloSeco) {
    Serial.println("Suelo seco");
//    regar(); // Riega si el suelo está seco
    seRiego = true;
  } else {
    Serial.println("Suelo húmedo: no se riega");
    digitalWrite(relePin, RELE_OFF);
  }

  enviarDatos(humedad, sueloSeco, seRiego); // Enviar datos por Bluetooth

  Serial.println("-------------------------");
  delay(5000); // Esperar 5 segundos antes de la siguiente lectura
}
