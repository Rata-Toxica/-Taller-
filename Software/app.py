from flask import Flask, request
import pymysql

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
    try:
        conexion = conectar()
        cursor = conexion.cursor()

        cursor.execute("""
        CREATE TABLE IF NOT EXISTS datos_riego (
            id INT AUTO_INCREMENT PRIMARY KEY,
            fecha DATETIME DEFAULT CURRENT_TIMESTAMP,
            humedad INT,
            probabilidad_lluvia INT,
            es_dia BOOLEAN,
            suelo_seco BOOLEAN,
            riego BOOLEAN,
            duracion INT
        )
        """)

        conexion.commit()

        cursor.execute("""
        SELECT *
        FROM datos_riego
        ORDER BY id DESC
        LIMIT 100
        """)

        registros = cursor.fetchall()

        html = """
        <html>
        <head>
            <title>Dashboard Riego Inteligente</title>
            <style>
                body{
                    font-family: Arial;
                    margin:30px;
                }

                table{
                    border-collapse: collapse;
                    width:100%;
                }

                th,td{
                    border:1px solid #ccc;
                    padding:8px;
                    text-align:center;
                }

                th{
                    background:#d4edda;
                }
            </style>
        </head>
        <body>

        <h1>🌱 Dashboard Riego Inteligente </h1>

        <table>
            <tr>
                <th>ID</th>
                <th>Fecha</th>
                <th>Humedad</th>
                <th>Lluvia (%)</th>
                <th>Es Día</th>
                <th>Suelo Seco</th>
                <th>Nes.Riego</th>
            </tr>
        """

        for fila in registros:
            html += f"""
            <tr>
                <td>{fila[0]}</td>
                <td>{fila[1]}</td>
                <td>{fila[2]}</td>
                <td>{fila[3]}</td>
                <td>{fila[4]}</td>
                <td>{fila[5]}</td>
                <td>{"SI" if fila[5] == 1 else "NO"}</td>
            </tr>
            """

        html += """
        </table>

        </body>
        </html>
        """

        conexion.close()

        return html

    except Exception as e:
        return str(e)

@app.route("/guardar", methods=["POST"])
def guardar():
    try:
        datos = request.get_json()

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

        return "OK"

    except Exception as e:
        return str(e)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)