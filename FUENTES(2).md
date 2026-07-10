# FUENTES

Este documento declara las librerías, plataformas, herramientas externas y el uso de inteligencia artificial utilizados en el desarrollo del prototipo de **Monitoreo de Humedad y Recomendación de Riego**.

---

# Librerías utilizadas

| Librería | Uso en el proyecto | Fuente |
|-----------|--------------------|--------|
| WiFi.h | Conexión WiFi del ESP32 | Librería incluida en el core de ESP32 para Arduino |
| HTTPClient.h | Envío de datos HTTP desde el ESP32 hacia el servidor Flask | Librería incluida en el core de ESP32 para Arduino |
| WiFiClientSecure.h | Comunicación HTTPS cuando es requerida | Librería incluida en el core de ESP32 para Arduino |
| ArduinoJson.h | Construcción y lectura de mensajes JSON | https://arduinojson.org |
| BluetoothSerial.h | Comunicación Bluetooth con el dispositivo del usuario | Librería incluida en el core de ESP32 para Arduino |
| Flask | Desarrollo del servidor backend y dashboard web | https://flask.palletsprojects.com |
| PyMySQL | Conexión entre Python y MySQL | https://pymysql.readthedocs.io |

---

# Plataformas utilizadas

| Plataforma | Uso en el proyecto |
|------------|--------------------|
| Arduino IDE | Desarrollo y carga del firmware del ESP32 |
| Visual Studio Code | Desarrollo del servidor en Python |
| GitHub | Repositorio y control de versiones |
| Aiven MySQL | Base de datos del proyecto |
| Open-Meteo API | Consulta de información climática |
| Fusion 360 | Diseño del encapsulado 3D |
| Canva | Elaboración de la presentación |

---

# Código externo adaptado

No se copió código externo completo desde repositorios de terceros.

Se utilizaron ejemplos generales y documentación oficial sobre:

- Conexión WiFi del ESP32.
- Solicitudes HTTP mediante HTTPClient.
- Desarrollo de aplicaciones con Flask.
- Conexión entre Python y MySQL mediante PyMySQL.
- Consulta de datos mediante Open-Meteo.

Todo el código fue adaptado al proyecto.

---

# Uso de Inteligencia Artificial

## Desarrollo del firmware ESP32

- **Herramienta:** ChatGPT
- **Uso:** Apoyo para desarrollar y depurar el firmware del ESP32.
- **Adaptación:** El código fue ajustado al sensor de humedad, Bluetooth, WiFi y consulta de Open-Meteo.
- **Comprensión:** El equipo comprende el funcionamiento completo del firmware.

## Desarrollo del servidor y dashboard

- **Herramienta:** ChatGPT
- **Uso:** Apoyo en la creación del servidor Flask y dashboard.
- **Adaptación:** El backend fue configurado con Aiven MySQL y adaptado al proyecto.
- **Comprensión:** El equipo comprende el flujo entre ESP32, servidor y base de datos.

## Documentación y organización de GitHub

- **Herramienta:** ChatGPT
- **Uso:** Apoyo en README.md, FUENTES.md y organización del repositorio.
- **Adaptación:** La documentación fue adaptada al proyecto.
- **Comprensión:** El equipo comprende la función de cada archivo y carpeta.

---

# Declaración final

El equipo declara que las herramientas externas e inteligencia artificial fueron utilizadas únicamente como apoyo para acelerar el desarrollo, depuración y documentación del proyecto. Las decisiones técnicas, integración del hardware, desarrollo del software y pruebas fueron realizadas por los integrantes del equipo.
