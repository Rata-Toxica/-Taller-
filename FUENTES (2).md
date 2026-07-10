# FUENTES

Este documento declara las librerías, plataformas, herramientas externas
y el uso de inteligencia artificial utilizados durante el desarrollo del
proyecto de **Monitoreo de Humedad y Recomendación de Riego**.

## Librerías utilizadas

  ---------------------------------------------------------------------------------------------
  Librería             Uso en el proyecto                   Fuente
  -------------------- ------------------------------------ -----------------------------------
  WiFi.h               Conexión WiFi del ESP32              Core ESP32 para Arduino

  HTTPClient.h         Envío de datos HTTP desde el ESP32   Core ESP32 para Arduino

  WiFiClientSecure.h   Comunicación HTTPS                   Core ESP32 para Arduino

  ArduinoJson.h        Creación y lectura de mensajes JSON  https://arduinojson.org

  BluetoothSerial.h    Comunicación Bluetooth con el        Core ESP32 para Arduino
                       dispositivo del usuario              

  Flask                Desarrollo del servidor web y        https://flask.palletsprojects.com
                       dashboard                            

  PyMySQL              Conexión entre Python y MySQL        https://pymysql.readthedocs.io
  ---------------------------------------------------------------------------------------------

## Plataformas utilizadas

  Plataforma           Uso en el proyecto
  -------------------- -------------------------------------------
  Arduino IDE          Desarrollo y carga del firmware del ESP32
  Visual Studio Code   Desarrollo del servidor en Python
  GitHub               Repositorio del proyecto
  Aiven MySQL          Base de datos del sistema
  Open-Meteo API       Consulta de información climática
  Fusion 360           Diseño del encapsulado 3D
  Canva                Elaboración de la presentación

## Código externo adaptado

No se copió código completo desde repositorios externos.

Se utilizaron como referencia la documentación oficial y ejemplos
relacionados con:

-   Conexión WiFi del ESP32.
-   Solicitudes HTTP.
-   Desarrollo de aplicaciones con Flask.
-   Conexión entre Python y MySQL mediante PyMySQL.
-   Consulta de datos climáticos utilizando la API Open-Meteo.

Todo el código fue adaptado e integrado por el equipo para satisfacer
los requerimientos específicos del proyecto.

## Uso de Inteligencia Artificial

**Herramienta utilizada:** ChatGPT

Se utilizó como apoyo para:

-   Desarrollo y depuración del firmware del ESP32.
-   Desarrollo del servidor Flask.
-   Integración con la base de datos MySQL.
-   Integración de la API Open-Meteo.
-   Organización del repositorio en GitHub.
-   Elaboración del README, manual de usuario y documentación técnica.

El equipo comprende el funcionamiento del firmware, del servidor, de la
base de datos y del flujo completo del sistema.

## Declaración final

El equipo declara que las herramientas externas y la inteligencia
artificial fueron utilizadas únicamente como apoyo para acelerar el
desarrollo, resolver dudas, depurar código y elaborar la documentación.

Las decisiones de diseño, integración del hardware, programación,
pruebas y validación del sistema fueron realizadas por los integrantes
del equipo.
