# 🌱 Sistema Inteligente de Monitoreo de Humedad y Recomendación de Riego

## Integrantes

- Tomás Varela
- Moira San Martín
- Cristian Noemi


# Descripción

Este proyecto consiste en un sistema inteligente de monitoreo de humedad del suelo que ayuda a optimizar el uso del agua mediante recomendaciones de riego basadas en información obtenida en tiempo real.

Utilizando un ESP32 y un sensor de humedad, el sistema analiza el estado del suelo y complementa la información con datos climáticos obtenidos desde la API Open-Meteo. Posteriormente registra cada medición en una base de datos y genera una recomendación de riego que puede visualizarse mediante un dashboard web y notificarse al usuario.


# Problema que resuelve

La agricultura representa cerca del 70% de las extracciones de agua dulce a nivel mundial. Sin embargo, muchas decisiones de riego continúan realizándose utilizando horarios fijos o la experiencia del agricultor, sin considerar la humedad real del suelo ni las condiciones climáticas.

Este proyecto entrega una herramienta tecnológica que apoya la toma de decisiones mediante información objetiva y actualizada, favoreciendo un uso más eficiente del recurso hídrico.


# Objetivos

- Monitorear continuamente la humedad del suelo.
- Incorporar información climática en tiempo real.
- Analizar las condiciones del terreno.
- Generar recomendaciones inteligentes de riego.
- Registrar automáticamente todas las mediciones.
- Visualizar la información mediante un dashboard web.

# Arquitectura del sistema

Sensor de humedad
        │
        ▼
ESP32
        │
        ▼
API Open-Meteo
        │
        ▼
Servidor Flask
        │
        ▼
Base de datos MySQL (Aiven)
        │
        ▼
Dashboard Web
        │
        ▼
Notificación de recomendación de riego


# Funcionamiento

El sensor de humedad mide constantemente el estado del suelo.

El ESP32 obtiene las mediciones y consulta la API Open-Meteo para conocer las condiciones climáticas del lugar.

Con esta información el sistema analiza las variables disponibles y determina si es recomendable realizar un riego.

Finalmente, cada medición queda almacenada en la base de datos y puede visualizarse desde un dashboard web, donde también se presenta la recomendación generada.



# Componentes principales

## Hardware

- ESP32
- Sensor de humedad del suelo
- Módulo relé de un canal
- Electroválvula de agua 12V
- Adaptador de conexiones
- Batería
- Protoboard
- Cables Dupont

## Software

- Arduino IDE
- Python
- Flask
- MySQL
- Aiven
- API Open-Meteo
- GitHub

---

# Dashboard

El dashboard desarrollado permite visualizar:

- Historial de mediciones.
- Humedad del suelo.
- Probabilidad de lluvia.
- Estado del suelo.
- Recomendación de riego.
- Fecha y hora de cada registro.



# Modelo 3D

Se diseñó un encapsulado mediante impresión 3D que proporciona:

- Protección para los componentes electrónicos.
- Material impermeable.
- Ventilación adecuada.
- Tres aberturas para conexiones.
- Estructura resistente para uso en exteriores.


# Instalación

## Firmware ESP32

1. Abrir Arduino IDE.
2. Configurar la red WiFi.
3. Instalar las librerías necesarias.
4. Cargar el programa al ESP32.

## Servidor

Instalar dependencias:


pip install flask
pip install pymysql


Ejecutar:


python app.py

Abrir en el navegador:

http://localhost:5000


# Estructura del repositorio


firmware/
Código del ESP32.

software/
Servidor Flask y dashboard web.

hardware/
Esquemático, conexiones y lista de materiales.

modelo-3d/
Diseño del encapsulado.

testing/
Pruebas realizadas durante el desarrollo.

docs/
Documentación del proyecto.

README.md

# Tecnologías utilizadas

- ESP32
- Arduino IDE
- Python
- Flask
- MySQL
- Aiven Cloud
- API Open-Meteo
- GitHub

# Futuras mejoras

- Aplicación móvil dedicada.
- Historial estadístico con gráficos.
- Gestión de múltiples sensores.
- Integración con plataformas IoT.
- Configuración personalizada de umbrales de humedad.

# Licencia

Proyecto desarrollado para la asignatura Taller de Diseño e Innovación de la Universidad Adolfo Ibáñez.
