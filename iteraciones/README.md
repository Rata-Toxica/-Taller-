# Iteraciones del proyecto

Esta carpeta documenta la evolución del sistema de monitoreo de humedad y recomendación de riego.

Durante el desarrollo se realizaron cambios en la alimentación eléctrica, el método de comunicación y el alcance de la solución. Estas modificaciones surgieron a partir de las pruebas realizadas y de la retroalimentación recibida durante el curso.

## Iteración 1: riego automático con WiFi y batería de 9 V

### Propuesta inicial

La primera versión fue planteada como un sistema de riego automático.

El prototipo incluía:

- ESP32.
- Sensor de humedad del suelo.
- Módulo relé.
- Electroválvula.
- Batería de 9 V.
- Comunicación mediante WiFi.

### Funcionamiento esperado

1. El sensor mediría la humedad del suelo.
2. El ESP32 determinaría si la tierra estaba seca.
3. El sistema consultaría información climática mediante internet.
4. Si las condiciones eran adecuadas, el relé activaría la electroválvula.
5. La electroválvula permitiría el paso del agua.

### Problemas encontrados

Durante las pruebas se comprobó que la batería de 9 V no entregaba la energía suficiente para accionar correctamente la electroválvula.

También se identificó una limitación en el uso de WiFi. Nos dimos cuenta que, en zonas agrícolas o campos alejados, los usuarios no siempre disponen de una conexión WiFi estable.

### Aprendizajes

Esta primera versión permitió comprender que debían considerarse:

- El voltaje requerido por cada componente.
- La corriente necesaria para accionar la electroválvula.
- La disponibilidad real de conectividad en el lugar de uso.
- La dependencia del sistema respecto de internet.

## Iteración 2: alimentación de 12 V

### Objetivo

Resolver el problema energético detectado en la primera versión mediante una fuente de alimentación de 12 V.

### Cambio realizado

Se reemplazó la alimentación de 9 V por una alternativa de 12 V, manteniendo:

- ESP32.
- Sensor de humedad.
- Relé.
- Electroválvula.
- Lógica de riego automático.

### Resultado

A pesar del cambio de alimentación, la electroválvula no funcionó con la configuración utilizada.

El sistema electrónico podía detectar el estado del suelo, pero no se consiguió una activación del mecanismo de agua.

### Decisión

Se determinó que mantener la electroválvula aumentaba la complejidad eléctrica y reducía la confiabilidad del prototipo.

Por esta razón, se decidió eliminar la función de riego automático de la versión final.

## Iteración 3: cambio de WiFi a Bluetooth

### Problema identificado

La propuesta inicial dependía de una red WiFi para transmitir información.

Sin embargo, el sistema estaba pensado para utilizarse en contextos agrícolas, donde muchas veces no existe acceso a WiFi o la conexión puede ser inestable.

### Cambio realizado

Se modificó el método de comunicación:

- Se dejó de depender exclusivamente de WiFi.
- Se incorporó comunicación Bluetooth entre el ESP32 y un computador.
- También se utilizó la conexión USB serial como alternativa durante las pruebas.

### Objetivo del cambio

Permitir que el sistema pudiera transmitir las mediciones a corta distancia sin necesitar una conexión permanente a internet.

### Resultado

El ESP32 fue configurado para enviar los datos de humedad y la recomendación de riego mediante Bluetooth y comunicación serial.

Durante el desarrollo se realizaron ajustes para mejorar la recepción de los datos.

## Iteración 4: sistema de monitoreo y recomendación de riego

### Versión final

La versión final dejó de realizar el riego de forma automática.

El sistema se concentró en:

1. Medir la humedad del suelo.
2. Determinar si el suelo está seco o húmedo.
3. Evaluar las condiciones programadas.
4. Comunicar si es recomendable regar.
5. Mostrar la información mediante el monitor serial y los medios de comunicación implementados.

### Ventajas de la versión final

- Menor consumo energético.
- Menor complejidad eléctrica.
- Mayor seguridad.
- Eliminación del riesgo de activar agua accidentalmente.
- Menor dependencia de internet.
- Mayor facilidad para probar el sistema.
- Mantención del objetivo principal de apoyar la decisión de riego.

## Diseño 3D

El encapsulado 3D no tuvo iteraciones importantes durante el desarrollo.

Desde el inicio se eligió un diseño simple y funcional, orientado a:

- Proteger los componentes.
- Mantener el sistema ordenado.
- Facilitar el acceso a las conexiones.
- Utilizar una tapa desmontable.
- Permitir la fabricación mediante impresión 3D.

Debido a que el diseño cumplía correctamente estas funciones, no fue necesario realizar modificaciones relevantes.

Los archivos editables e imprimibles se encuentran en la carpeta `Modelo 3D`.

## Resumen de las iteraciones

| Iteración | Modificación principal | Resultado |
|---|---|---|
| 1 | Riego automático, WiFi y batería de 9 V | Energía insuficiente y dependencia de WiFi |
| 2 | Alimentación de 12 V | Electroválvula sin funcionamiento confiable |
| 3 | Cambio de WiFi a Bluetooth | Menor dependencia de internet |
| 4 | Eliminación de la electroválvula | Sistema final de monitoreo y recomendación |

## Conclusión

El proyecto evolucionó desde una propuesta de riego automático conectada mediante WiFi hacia un sistema de monitoreo y recomendación de riego con comunicación Bluetooth y serial.

Los cambios realizados respondieron a problemas reales detectados durante las pruebas:

- falta de energía para la electroválvula;
- funcionamiento poco confiable del mecanismo de agua;
- falta de disponibilidad de WiFi en entornos agrícolas.

La versión final mantiene el objetivo de ayudar al usuario a decidir cuándo regar, pero utiliza una solución más simple, segura y coherente con las condiciones del lugar de uso.
