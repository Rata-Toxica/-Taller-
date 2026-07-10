# Pruebas y Evidencias del Sistema

Esta carpeta contiene las pruebas realizadas para verificar el correcto funcionamiento del sistema inteligente de monitoreo de humedad y recomendación de riego.

## Objetivos de las pruebas

- Comprobar la lectura del sensor de humedad.
- Verificar la detección de suelo seco y húmedo.
- Comprobar la comunicación entre el ESP32 y el computador.
- Verificar el envío de datos mediante Bluetooth o conexión USB.
- Comprobar el almacenamiento de las mediciones.
- Verificar el funcionamiento del dashboard.
- Registrar problemas encontrados y sus soluciones.

## Pruebas realizadas

### 1. Lectura en suelo seco

Se colocó el sensor en tierra seca y se registró el valor entregado por el ESP32.

**Resultado esperado:** el sistema debe identificar que el suelo necesita riego.



### 2. Lectura en suelo húmedo

Se colocó el sensor en tierra húmeda y se registró el valor entregado por el ESP32.

**Resultado esperado:** el sistema debe indicar que no es necesario regar.



### 3. Calibración del sensor

Se compararon las mediciones obtenidas en diferentes condiciones para establecer el umbral de humedad utilizado por el programa.

**Umbral utilizado:** 2500.

Los valores mayores al umbral se interpretan como suelo seco y los valores menores como suelo húmedo.

### 4. Comunicación del ESP32

Se comprobó que el ESP32 envía los datos del sensor en formato JSON mediante Bluetooth y conexión USB serial.



### 5. Recepción de datos en Python

Se verificó que la aplicación Python recibe los datos enviados por el ESP32.



### 6. Base de datos y dashboard

Se comprobó el almacenamiento y visualización de las mediciones cuando estas funciones estuvieron disponibles.



## Resultado general

Las pruebas permiten comprobar el funcionamiento de las distintas partes del sistema y detectar errores durante el desarrollo.
