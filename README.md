# 🌱 Sistema de Monitoreo de Humedad y Recomendación de Riego

Sistema basado en ESP32 que mide la humedad del suelo y determina si es recomendable regar. La información puede visualizarse mediante el monitor serial y transmitirse por Bluetooth, sin depender de una conexión WiFi permanente.

## Integrantes

- Tomás Varela
- Moira San Martín
- Cristian Noemi

## Descripción del proyecto

Este proyecto consiste en un sistema de monitoreo de humedad del suelo orientado a apoyar la decisión de riego.

Un sensor conectado al ESP32 mide el nivel de humedad de la tierra. El programa analiza la lectura obtenida y determina si el suelo se encuentra seco o húmedo. Posteriormente comunica el resultado al usuario mediante Bluetooth y comunicación serial por USB.

La versión final no activa automáticamente el flujo de agua. Su función es informar al usuario si corresponde regar, reduciendo la complejidad eléctrica y evitando depender de una conexión a internet.

## Problema que resuelve

En muchos contextos agrícolas y domésticos, el riego se realiza utilizando horarios fijos o estimaciones visuales, sin medir directamente la humedad del suelo.

Esto puede provocar:

- Riego innecesario.
- Uso excesivo de agua.
- Falta de riego cuando la tierra se encuentra seca.
- Decisiones basadas únicamente en la experiencia del usuario.

El sistema entrega una recomendación basada en una medición real de la humedad del suelo.

## Objetivos

- Medir la humedad del suelo mediante un sensor.
- Diferenciar entre suelo seco y suelo húmedo.
- Informar al usuario si es recomendable regar.
- Transmitir las mediciones mediante Bluetooth.
- Permitir la visualización de los datos mediante comunicación serial USB.
- Reducir la dependencia de redes WiFi en zonas agrícolas.
- Documentar las pruebas y cambios realizados durante el desarrollo.

## Arquitectura del sistema

```text
Sensor de humedad
        │
        ▼
      ESP32
        │
        ├── Bluetooth
        │
        └── Comunicación serial USB
                    │
                    ▼
          Computador o usuario
                    │
                    ▼
        Recomendación de riego
```

## Funcionamiento

1. El sensor de humedad realiza una lectura analógica de la tierra.
2. El ESP32 recibe la lectura mediante el pin GPIO 34.
3. El programa compara la medición con un umbral de referencia.
4. Si la lectura indica tierra seca, el sistema recomienda regar.
5. Si la lectura indica tierra húmeda, el sistema informa que no es necesario regar.
6. Los datos se muestran mediante el monitor serial.
7. La información también puede enviarse mediante Bluetooth.

Durante las pruebas se utilizó un umbral aproximado de `2500`.

- Valores superiores a `2500`: suelo seco.
- Valores iguales o inferiores a `2500`: suelo húmedo.

Este valor puede requerir una nueva calibración dependiendo del sensor, el tipo de tierra y las condiciones de uso.

## Versión final del proyecto

La versión final funciona como un sistema de monitoreo y recomendación de riego.

El dispositivo:

- Mide la humedad del suelo.
- Determina si el suelo está seco o húmedo.
- Comunica el resultado al usuario.
- No activa automáticamente una electroválvula.
- No necesita una conexión WiFi permanente.
- Puede utilizar Bluetooth o comunicación serial USB.

## Evolución del proyecto

La propuesta inicial consideraba:

- Comunicación mediante WiFi.
- Consulta de información climática.
- Uso de una electroválvula.
- Riego automático.
- Alimentación mediante una batería de 9 V.

Durante las primeras pruebas se comprobó que la batería de 9 V no entregaba la energía suficiente para accionar correctamente la electroválvula.

Posteriormente se probó una alimentación de 12 V, pero la electroválvula no funcionó de manera suficientemente confiable con la configuración utilizada.

También se identificó que depender de WiFi podía ser una limitación, ya que en zonas agrícolas o campos alejados no siempre existe una conexión estable.

Por estas razones se decidió:

- Cambiar la comunicación de WiFi a Bluetooth.
- Utilizar comunicación serial USB como alternativa.
- Eliminar la electroválvula de la versión final.
- Transformar el proyecto en un sistema de monitoreo y recomendación de riego.

La evolución completa está documentada en la carpeta [`iteraciones`](./iteraciones).

## Componentes principales

### Componentes de la versión final

- ESP32.
- Sensor de humedad del suelo.
- Protoboard.
- Cables Dupont.
- Fuente de alimentación.
- Computador para visualización y pruebas.
- Encapsulado impreso en 3D.

### Componentes utilizados durante las iteraciones

- Módulo relé de un canal.
- Electroválvula.
- Batería de 9 V.
- Alimentación de 12 V.

Estos componentes fueron utilizados durante las primeras versiones, pero no forman parte del funcionamiento final del sistema.

## Tecnologías utilizadas

- ESP32.
- Arduino IDE.
- C++ para Arduino.
- Biblioteca `BluetoothSerial`.
- Python.
- Comunicación Bluetooth.
- Comunicación serial USB.
- Autodesk Fusion 360.
- GitHub.

## Diseño 3D

Se diseñó un encapsulado simple y funcional para proteger y organizar los componentes electrónicos.

La carpeta [`Modelo 3D`](./Modelo%203D) contiene:

- Archivos editables de Fusion 360 en formato `.f3d`.
- Archivos CAD en formato `.step`.
- Archivos para impresión 3D en formato `.stl`.
- Imágenes con vistas y dimensiones del encapsulado.
- Documentación del diseño.

El modelo no tuvo cambios importantes durante el desarrollo, ya que el diseño inicial cumplía con las funciones necesarias.

## Pruebas realizadas

Las pruebas del sistema incluyeron:

- Lectura del sensor en suelo húmedo.
- Lectura del sensor en suelo seco.
- Evaluación de condiciones antes de recomendar el riego.
- Pruebas de activación realizadas durante las versiones iniciales.
- Comunicación mediante monitor serial.
- Pruebas del montaje físico.
- Pruebas de alimentación.
- Pruebas de comunicación WiFi y Bluetooth.

Las evidencias y resultados están disponibles en la carpeta [`testing`](./testing).

## Instalación y uso

### Requisitos

- Arduino IDE.
- Soporte para placas ESP32 instalado.
- Cable USB compatible con el ESP32.
- Sensor de humedad conectado.
- Computador con Bluetooth, en caso de utilizar esa comunicación.

### Cargar el firmware

1. Descargar o clonar este repositorio.
2. Abrir Arduino IDE.
3. Instalar el soporte para placas ESP32.
4. Abrir el archivo:

```text
Firmware/monitoreo_automatico.ino
```

5. Conectar el ESP32 al computador mediante USB.
6. Seleccionar la placa ESP32 correspondiente.
7. Seleccionar el puerto COM correcto.
8. Cargar el programa al ESP32.
9. Abrir el monitor serial.
10. Configurar la velocidad en `115200` baudios.

### Conexiones principales

- Salida analógica del sensor de humedad: GPIO 34.
- Alimentación del sensor: según las especificaciones del módulo.
- Tierra del sensor: GND del ESP32.

El diagrama completo de conexiones está disponible en la carpeta [`hardware`](./hardware).

### Comunicación Bluetooth

1. Activar Bluetooth en el computador.
2. Encender el ESP32.
3. Buscar el dispositivo:

```text
ESP32_Device
```

4. Vincular el computador con el ESP32.
5. Utilizar una aplicación compatible con comunicación serial Bluetooth.

La comunicación mediante USB serial puede utilizarse como alternativa durante las pruebas.

## Software

La carpeta [`Software`](./Software) contiene archivos desarrollados en Python para experimentar con la recepción, interpretación y almacenamiento de los datos enviados por el ESP32.

Esta parte del proyecto requiere configuración adicional dependiendo del sistema operativo, la conexión Bluetooth y la base de datos utilizada.

## Hardware

La carpeta [`hardware`](./hardware) contiene:

- Diagrama de conexiones.
- Descripción del hardware.
- Lista de materiales.
- Fotografías o representaciones del montaje.
- Información de los componentes utilizados.

## Documentación

La carpeta [`docs`](./docs) contiene:

- Informe del proyecto.
- Manual de usuario.
- Documentación complementaria.

## Estructura del repositorio

```text
-Taller-/
├── Firmware/
│   └── Código del ESP32
│
├── Modelo 3D/
│   ├── Archivos F3D
│   ├── Archivos STEP
│   ├── Archivos STL
│   └── Vistas del encapsulado
│
├── Software/
│   └── Aplicación desarrollada en Python
│
├── docs/
│   └── Informes y manuales del proyecto
│
├── hardware/
│   ├── Diagrama de conexiones
│   ├── Lista de materiales
│   └── Documentación del hardware
│
├── iteraciones/
│   └── Evolución y decisiones de diseño
│
├── testing/
│   └── Protocolos, resultados y evidencias
│
├── .gitignore
├── FUENTES.md
├── LICENSE
└── README.md
```

## Limitaciones

- El sistema final no activa el riego automáticamente.
- El umbral de humedad puede requerir una nueva calibración.
- La comunicación Bluetooth depende de la compatibilidad del computador.
- La versión final no utiliza información climática mediante internet.
- No se implementó una aplicación móvil dedicada.
- La electroválvula fue eliminada debido a problemas de alimentación y funcionamiento.

## Futuras mejoras

- Crear una aplicación móvil.
- Mejorar la estabilidad de la comunicación Bluetooth.
- Agregar una pantalla local.
- Incorporar una batería recargable.
- Implementar gráficos con el historial de mediciones.
- Permitir la configuración del umbral de humedad.
- Reincorporar un sistema de riego automático utilizando una fuente de alimentación adecuada.
- Integrar información climática como una función opcional.
- Permitir la conexión con varios sensores.

## Fuentes

Las librerías, referencias externas, código adaptado y herramientas de inteligencia artificial utilizadas se encuentran declaradas en [`FUENTES.md`](./FUENTES.md).

## Licencia

Este proyecto utiliza la licencia MIT. Consultar el archivo [`LICENSE`](./LICENSE).

## Contexto académico

Proyecto desarrollado para la asignatura Taller de Diseño en Ingeniería de la Universidad Adolfo Ibáñez.
