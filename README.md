# ESP32 Temperature & Humidity Logger with OLED Display and MQTT

This project logs temperature and humidity readings using a **DHT11 sensor**, displays the values on an **SSD1306 OLED screen**, and publishes the data to an **MQTT broker** over Wi-Fi using an **ESP32**. After sending the data, the ESP32 enters **deep sleep** to save power, making it ideal for low-energy IoT applications.

---

## 🛠 Features

- Reads temperature and humidity from a DHT11 sensor.
- Displays real-time values on a 128x64 I2C OLED display.
- Sends sensor data in JSON format to an MQTT broker.
- Enters deep sleep after publishing to save power.

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

 ---
 
## 🧠 Skills Practiced

This project helps reinforce and practice the following embedded systems and IoT skills:

- **Embedded C++** programming using the Arduino framework.
- **Interfacing with digital sensors** (DHT11 for temperature and humidity).
- **Using I2C communication** to control peripherals (SSD1306 OLED display).
- **Displaying dynamic data** using the `Adafruit_GFX` graphics library.
- **Establishing Wi-Fi connections** using the ESP32 WiFi module.
- **Publishing data via MQTT** using the `PubSubClient` library.
- **JSON serialization** with `ArduinoJson` for structured data transfer.
- **Modular coding** with external credential files (`passwords.h`).
- **Implementing deep sleep** for power-efficient IoT cycles.
- **Serial debugging** and monitoring with `Serial.println()` for development and troubleshooting.

---
