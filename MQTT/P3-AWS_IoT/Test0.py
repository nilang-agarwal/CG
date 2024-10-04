import paho.mqtt.client as mqtt
import ssl
import time

# AWS IoT parameters
broker_address = "a3c7k5ajyxpwnh-ats.iot.ap-northeast-1.amazonaws.com"  # e.g., "xxxxxxxxxx.iot.us-east-1.amazonaws.com"
port = 8883

client = mqtt.Client()

# Set up TLS
client.tls_set(r"C:\Users\nilagarw\Downloads\MyDoorLock2\AmazonRootCA1.pem", 
                certfile=r"C:\Users\nilagarw\Downloads\MyDoorLock2\1ec0841b1eedab8b126ec35b08516b3618d20ce7d780defe7aa6f7247e544813-certificate.pem.crt", 
                keyfile=r"C:\Users\nilagarw\Downloads\MyDoorLock2\1ec0841b1eedab8b126ec35b08516b3618d20ce7d780defe7aa6f7247e544813-private.pem.key", 
                tls_version=ssl.PROTOCOL_TLSv1_2)

# Connect to the broker
try:
    client.connect(broker_address, port)
    client.loop_start()  # Start the loop to process network traffic
except Exception as e:
    print("Connection error:", str(e))

# Publish a message
topic = "India/Bihar/Patna"

message = """{
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
        "Value": 5,
        "fcf": 4.95,
        "acf": 0.059,
        "Values": [
          8,
          21,
          47,
          14,
          56,
          0,
          52,
          1,
          42,
          59,
          24
        ]
      },
      {
        "Type": "ahuThing",
        "Name": "Temperature Control",
        "Value": 30,
        "Min": 8,
        "Max": 45,
        "sd": 100,
        "ofd": 12,
        "Started": true,
        "vfd": 100,
        "On": true
      },
      {
        "Type": "ahuThing",
        "Name": "Humidity Control",
        "Value": 90,
        "Min": 35,
        "Max": 90,
        "sd": 100,
        "ofd": 120,
        "Started": true,
        "vfd": 10,
        "On": false
      }
    ]
  }
}"""


client.publish(topic, message)

# Optional: Wait a bit to ensure the message is sent before disconnecting
time.sleep(2)

# Stop the loop and disconnect
client.loop_stop()
client.disconnect()
