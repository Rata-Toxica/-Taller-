from flask import Flask, request
import pymysql
import bluetooth  # Añadir la biblioteca para Bluetooth
import json

app = Flask(__name__)

DB_CONFIG = {
    "host": "riego-inteligente-db-moira-e6a3.l.aivencloud.com",
    "port": 20656,
    "user": "avnadmin",
    "password": "AVNS_KKvHW7tTIBXOcONihOJ",
    "database": "defaultdb",
    "ssl": {"ssl": {}}
}

def conectar():
    return pymysql.connect(**DB_CONFIG)

@app.route("/")
def inicio():
    # ... (tu código actual para mostrar el dashboard)
    pass

@app.route("/guardar", methods=["POST"])
def guardar():
    # ... (tu código actual para guardar datos)
    pass

def recibir_datos_bluetooth():
    server_socket = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    server_socket.bind(("", bluetooth.PORT_ANY))
    server_socket.listen(1)

    port = server_socket.getsockname()[1]
    bluetooth.advertise_service(server_socket, "ESP32_Service", service_classes=[bluetooth.SERIAL_PORT_CLASS], profiles=[bluetooth.SERIAL_PORT_PROFILE])

    print(f"Esperando conexión en el puerto {port}...")
    client_socket, client_info = server_socket.accept()
    print(f"Conectado a {client_info}")

    try:
        while True:
            data = client_socket.recv(1024).decode("utf-8")
            if data:
                print(f"Datos recibidos: {data}")
                datos = json.loads(data)  # Convertir a diccionario
                guardar_en_base_datos(datos)  # Llama a la función para guardar en la base de datos
    except Exception as e:
        print(f"Error: {e}")
    finally:
        client_socket.close()
        server_socket.close()

def guardar_en_base_datos(datos):
    try:
        conexion = conectar()
        cursor = conexion.cursor()

        cursor.execute("""
        INSERT INTO datos_riego
        (
            humedad,
            probabilidad_lluvia,
            es_dia,
            suelo_seco,
            riego,
            duracion
        )
        VALUES (%s,%s,%s,%s,%s,%s)
        """,
        (
            datos["humedad"],
            datos["probabilidad_lluvia"],
            datos["es_dia"],
            datos["suelo_seco"],
            datos["riego"],
            datos["duracion"]
        ))

        conexion.commit()
        conexion.close()
        print("Datos guardados exitosamente.")

    except Exception as e:
        print(f"Error al guardar en la base de datos: {e}")

if __name__ == "__main__":
    # Iniciar el servidor Flask en un hilo separado si es necesario
    import threading
    threading.Thread(target=lambda: app.run(host="0.0.0.0", port=5000, debug=True)).start()
    recibir_datos_bluetooth()  # Iniciar la escucha de datos Bluetooth
