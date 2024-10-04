import paho.mqtt.client as mqtt
import json
import random
import time
import ssl

broker_address = "a3c7k5ajyxpwnh-ats.iot.ap-northeast-1.amazonaws.com"
port = 8883
topic = "India/Bihar/Patna"

ca_cert = r"C:\Users\nilagarw\Downloads\MyDoorLock2\AmazonRootCA1.pem"
client_cert = r"C:\Users\nilagarw\Downloads\MyDoorLock2\1ec0841b1eedab8b126ec35b08516b3618d20ce7d780defe7aa6f7247e544813-certificate.pem.crt"
client_key = r"C:\Users\nilagarw\Downloads\MyDoorLock2\1ec0841b1eedab8b126ec35b08516b3618d20ce7d780defe7aa6f7247e544813-private.pem.key"

def generate_message():
    values = [random.randint(0, 100) for _ in range(11)] 
    temperature_value = random.randint(20, 35) 
    humidity_value = random.randint(40, 100) 

    message = {
        "Command": "GetDeviceDetails",
        "Status": "Successful",
        "MAC": "D48AFCC4BC66",
        "CPU": "ESP32",
        "Memsize": "8388608",
        "Details": {
            "Firmware": "0.1.1",
            "Type": "4",
            "Name": "DiGi_Sensor_BC48",
            "enableBuzz": "-1",
            "ThingsCount": 3,
            "Things": [
                {
                    "Type": "SensorBox01",
                    "Name": "Sensors",
                    "Value": random.choice(values), 
                    "fcf": 4.95,
                    "acf": 0.059,
                    "Values": values
                },
                {
                    "Type": "ahuThing",
                    "Name": "Temperature Control",
                    "Value": temperature_value,  
                    "Min": 8,
                    "Max": 45,
                    "sd": 100,
                    "ofd": 12,
                    "Started": True,
                    "vfd": 100,
                    "On": True
                },
                {
                    "Type": "ahuThing",
                    "Name": "Humidity Control",
                    "Value": humidity_value, 
                    "Min": 35,
                    "Max": 90,
                    "sd": 100,
                    "ofd": 120,
                    "Started": True,
                    "vfd": 10,
                    "On": False
                }
            ]
        }
    }

    return message


def publish_message(client):
    while True:
        message = generate_message()
        client.publish(topic, json.dumps(message))
        print(f"Published message: {message}")
        time.sleep(10)  

client = mqtt.Client()
client.tls_set(ca_certs=ca_cert, certfile=client_cert, keyfile=client_key, tls_version=ssl.PROTOCOL_TLSv1_2)

def on_connect(client, userdata, flags, rc):
    print("Connected to MQTT Broker with result code:", rc)

client.on_connect = on_connect

try:
    client.connect(broker_address, port)
    client.loop_start()  
    publish_message(client)
except Exception as e:
    print("Error connecting to the broker:", str(e))
