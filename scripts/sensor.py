import requests
import serial
import time

url = 'http://localhost:8000/api/data/temperature/'

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

while True:
    temperature = ser.readline().decode('utf-8').strip()
    payload = {'temp':temperature}
    response = requests.post(url, data=payload)
    print(response.text)

    time.sleep(5)