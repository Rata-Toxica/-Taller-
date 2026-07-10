# FUENTES

Este documento declara las librerías, plataformas, herramientas externas
y el uso de inteligencia artificial utilizados en el desarrollo del
prototipo de **Monitoreo de Humedad y Recomendación de Riego**.

------------------------------------------------------------------------

# Librerías utilizadas

  ----------------------------------------------------------------------------------------------
  Librería             Uso en el proyecto                    Fuente
  -------------------- ------------------------------------- -----------------------------------
  WiFi.h               Conexión WiFi del ESP32               Librería incluida en el core de
                                                             ESP32 para Arduino

  HTTPClient.h         Envío de datos HTTP desde el ESP32    Librería incluida en el core de
                       hacia el servidor Flask               ESP32 para Arduino

  WiFiClientSecure.h   Comunicación HTTPS cuando es          Librería incluida en el core de
                       requerida                             ESP32 para Arduino

  ArduinoJson.h        Construcción y lectura de mensajes    https://arduinojson.org
                       JSON                                  

  BluetoothSerial.h    Comunicación Bluetooth con el         Librería incluida en el core de
                       dispositivo del usuario para el envío ESP32 para Arduino
                       de recomendaciones                    

  Flask                Desarrollo del servidor backend y     https://flask.palletsprojects.com
                       dashboard web                         

  PyMySQL              Conexión entre Python y la base de    https://pymysql.readthedocs.io
                       datos MySQL                           
  ----------------------------------------------------------------------------------------------

------------------------------------------------------------------------

# Plataformas utilizadas

  -----------------------------------------------------------------------
  Plataforma                 Uso en el proyecto
  -------------------------- --------------------------------------------
  Arduino IDE                Desarrollo y carga del firmware del ESP32

  Visual Studio Code         Desarrollo del servidor en Python

  GitHub                     Repositorio y control de versiones del
                             proyecto

  Aiven MySQL                Base de datos para almacenar los registros
                             del sistema

  Open-Meteo API             Consulta de información climática para
                             apoyar la recomendación de riego

  Fusion 360                 Diseño 3D del encapsulado del dispositivo

  Canva                      Elaboración de la presentación del proyecto
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# Código externo adaptado

No se copió código externo completo desde repositorios de terceros.

Se utilizaron ejemplos generales y documentación oficial relacionados
con:

-   Conexión WiFi del ESP32.
-   Solicitudes HTTP mediante HTTPClient.
-   Desarrollo de aplicaciones utilizando Flask.
-   Conexión entre Python y MySQL mediante PyMySQL.
-   Consulta de información climática utilizando la API Open-Meteo.

Todo el código fue adaptado e integrado por el equipo para satisfacer
los requerimientos específicos del proyecto.

------------------------------------------------------------------------

# Uso de Inteligencia Artificial

## Desarrollo del firmware ESP32

**Herramienta:** ChatGPT

**Uso:** Apoyo para desarrollar, depurar y optimizar el firmware del
ESP32 encargado de leer el sensor de humedad, consultar las condiciones
climáticas mediante Open-Meteo y enviar la información al servidor.

**Adaptación:** El código fue ajustado al hardware utilizado por el
equipo, considerando el sensor de humedad, el módulo Bluetooth, la
conexión WiFi y la lógica implementada para generar recomendaciones de
riego.

**Comprensión:** El equipo comprende que el firmware realiza la lectura
del sensor, consulta la probabilidad de lluvia, analiza las condiciones
del entorno y genera una recomendación de riego que posteriormente es
enviada al servidor y al dispositivo del usuario.

------------------------------------------------------------------------

## Desarrollo del servidor y dashboard

**Herramienta:** ChatGPT

**Uso:** Apoyo en la construcción del servidor utilizando Flask, la
conexión con la base de datos MySQL y el desarrollo del dashboard web.

**Adaptación:** El backend fue configurado utilizando la base de datos
Aiven MySQL del proyecto. El dashboard fue adaptado para visualizar el
historial de registros, la humedad del suelo, la probabilidad de lluvia,
el estado del suelo y la recomendación de riego generada por el sistema.

**Comprensión:** El equipo comprende que el servidor recibe las
mediciones enviadas por el ESP32, almacena la información en la base de
datos y posteriormente presenta los registros mediante el dashboard web.

------------------------------------------------------------------------

## Documentación y organización de GitHub

**Herramienta:** ChatGPT

**Uso:** Apoyo en la elaboración del README.md, FUENTES.md, manual de
usuario y organización de la estructura de carpetas del repositorio.

**Adaptación:** Toda la documentación fue ajustada al proyecto de
monitoreo de humedad y recomendación de riego, sus componentes reales,
conexiones y funcionamiento.

**Comprensión:** El equipo comprende la función de cada carpeta, archivo
y plataforma utilizada durante el desarrollo del sistema.

------------------------------------------------------------------------

# Declaración final

El equipo declara que las herramientas externas y la inteligencia
artificial fueron utilizadas como apoyo para acelerar el desarrollo,
depuración, organización y documentación del proyecto.

Las decisiones técnicas, la integración del hardware, el desarrollo del
software, las pruebas de funcionamiento y la adaptación de la solución
al problema fueron realizadas por los integrantes del equipo.
