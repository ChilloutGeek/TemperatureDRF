import paho.mqtt.client as mqtt
import requests
import serial
import time

ser = serial.Serial('/dev/ttyACM1', 115200, timeout=1)
mqtt_server = 'localhost'
mqtt_port = 1883
mqtt_topic = 'temperature'
rest_url = 'http://localhost:8000/api/data/temperature/'

def on_connect(client, userdata, flags,rc):
    print('Connected to MQTT broker with result code' + str(rc))

client = mqtt.Client()
client.on_connect = on_connect
client.connect(mqtt_server, mqtt_port, 60)

while True:
    if ser.in_waiting > 0:
        temperature = ser.readline().decode('utf-8').strip()
        temp_json = json.dumps{('temp':temperature, ensure_ascii=False, separators=(',':':'))}
        client.publish(mqtt_topic, temp_json)
        response = requests.post(rest_url, data={'temp':temp_json})
        time.sleep(8)