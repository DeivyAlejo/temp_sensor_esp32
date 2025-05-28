# ESP32 Temperature & Humidity Logger with OLED Display and MQTT

This project logs temperature and humidity readings using a **DHT11 sensor**, displays the values on an **SSD1306 OLED screen**, and publishes the data to an **MQTT broker** over Wi-Fi using an **ESP32**. After sending the data, the ESP32 enters **deep sleep** to save power, making it ideal for low-energy IoT applications.

---

## 🛠 Features

- 📡 Reads temperature and humidity from a DHT11 sensor.
- 🖥 Displays real-time values on a 128x64 I2C OLED display.
- ☁ Sends sensor data in JSON format to an MQTT broker.
- 🔋 Enters deep sleep after publishing to save power.

---

## 🔧 Hardware Requirements

- ESP32 board
- DHT11 sensor
- SSD1306 OLED display (128x64, I2C)
- Jumper wires & breadboard

---

## 🧩 Software Requirements

- Arduino IDE with ESP32 board support
- Required libraries:
  - `Adafruit_Sensor`
  - `DHT`
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`
  - `PubSubClient`
  - `ArduinoJson`
