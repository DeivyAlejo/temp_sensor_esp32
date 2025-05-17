#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSansBoldOblique12pt7b.h>
#include <wifi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
#include <passwords.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SDA 8
#define SCL 9

#define DEEP_SLEEP_TIME 2

#define DHTPIN 0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = WIFI_NAME;
const char* password = WIFI_PASSWORD;

const char* mqtt_server = MQTT_SERVER_IP;

WiFiClient espClient;
PubSubClient client(espClient);

float Temperature;
float Humidity; 

void goToDeepSleep(){
  esp_sleep_enable_timer_wakeup(DEEP_SLEEP_TIME * 10 * 1000000);
  esp_deep_sleep_start();
}

void connect_to_wifi(){
  Serial.println("Conecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("IP: ");  
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("6ac6dfd2aecc42a18b88aed7adeb1228",MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Wire.begin(SDA,SCL);

  connect_to_wifi();

  pinMode(DHTPIN, INPUT);
  dht.begin();

  // initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  client.setServer(mqtt_server, 1883);



  // goToDeepSleep();
}

void loop() {
    if (!client.connected()) {
    reconnect();
  }

  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();

    // Display text with a different text format
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setCursor(0,35);
  display.print("Humidity: ");

  display.setCursor(0,12);
  display.setTextSize(2);
  display.print(Temperature,1);
  display.drawCircle(54,12,3,WHITE);
  display.print(" C");

  display.setCursor(0,47);
  display.print(Humidity,1);
  display.print("%");
  display.display();

  //Serial print
  Serial.print("Temperature: ");
  Serial.print(Temperature);
  // Serial.print((char)247);
  Serial.println("C");
  Serial.print("Humidity: ");
  Serial.print(Humidity);
  Serial.println("%");

  // Serial.println(WiFi.localIP());
  StaticJsonDocument<80> doc;
  char output[80];
  doc["t"] = Temperature;
  doc["h"] = Humidity;

  serializeJson(doc, output);
  Serial.println(output);
  client.publish("home/sensor", output);
  delay(5000);
}
