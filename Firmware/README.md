# Firmware

## Descripción

Esta carpeta contiene el firmware desarrollado para el ESP32, encargado de controlar el funcionamiento del sistema de monitoreo de humedad y recomendación de riego.

## Funciones principales

- Lectura del sensor de humedad del suelo.
- Consulta de la probabilidad de lluvia mediante la API Open-Meteo.
- Análisis de las condiciones del suelo y del clima.
- Determinación de la recomendación de riego.
- Envío de los datos al servidor Flask.
- Envío de una notificación al dispositivo del usuario mediante Bluetooth.

## Archivo principal

- `riego_automatico.ino`

## Librerías utilizadas

- WiFi.h
- HTTPClient.h
- WiFiClientSecure.h
- ArduinoJson.h
- BluetoothSerial.h

## Plataforma

- ESP32
- Arduino IDE
