#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ThingSpeak.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// char ssid[] = "WATERTANK";
// char pass[] = "60589254";
char ssid[] = "RAJAN";
char pass[] = "rajan123";

const int trigPin = 19;
const int echoPin = 18;
long duration;
long distance;
float waterHeight;
float tankHeight = 304; //tank height
float tankLength = 477; //tank lenght
float tankBreath = 353; //tank breath

float tankVolume = 51187824; //tank volume = tankHeight*tankLength*tankBreath
float waterQuantity;
float volume;
float waterHeight_ft;
int percentage;
float offset = 3030858;
const int redLedPin = 12;
const int greenLedPin = 13;

WiFiClient client;

const char *thingSpeakAddress = "api.thingspeak.com";
const char* apiKey = "V3FKYPWX1M8PCICU";
const unsigned long channelID = 2537708;

unsigned long lastLCDUpdate = 0; // Variable to store the time of the last LCD update
unsigned long lastThingSpeakUpdate = 0; // Variable to store the time of the last ThingSpeak update
const unsigned long LCDUpdateInterval = 2000; // Update LCD every 2 seconds
const unsigned long ThingSpeakUpdateInterval = 60000; // Update ThingSpeak every 5 minutes

void ultrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  volume = 168381 * distance;
  waterHeight = tankHeight - distance;
  waterHeight_ft = waterHeight * 0.0328084;
  waterQuantity = tankVolume - volume + offset;
  percentage = (waterQuantity / tankVolume) * 100;

  Serial.print("Empty height [cm]: ");
  Serial.println(distance);
  Serial.print("Water height [cm]: ");
  Serial.println(waterHeight);
  Serial.print("Water height [ft]: ");
  Serial.println(waterHeight_ft);
  Serial.print("Water Volume [l]: ");
  Serial.println(waterQuantity / 1000);
  Serial.print("Percentage filled: ");
  Serial.print(percentage);
  Serial.println("%");
  Serial.println();

  if (waterHeight <= 60) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else if (waterHeight >= 270) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Height: ");
  lcd.print(waterHeight_ft);
  lcd.print(" ft");

  lcd.setCursor(0, 1);
  lcd.print("Quant.: ");
  lcd.print(waterQuantity / 1000);
  lcd.print(" lit.");
}

void connectToWiFi() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting...");

  WiFi.begin(ssid, pass);
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Failed to ");
    lcd.setCursor(7, 1);
    lcd.print("connect! ");
    delay(5000);
    lcd.setCursor(0, 0);
    lcd.print("  JIET JODHPUR  ");
    lcd.setCursor(0, 1);
    lcd.print("  RAJAN Kr.(ECE) ");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    WATER TANK    ");
    lcd.setCursor(0, 1);
    lcd.print("      LEVEL      ");
    delay(3000);
    ultrasonic();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  JIET JODHPUR  ");
    lcd.setCursor(0, 1);
    lcd.print("  RAJAN Kr.(ECE) ");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    WATER TANK    ");
    lcd.setCursor(0, 1);
    lcd.print("      LEVEL      ");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Connected to");
    lcd.setCursor(5, 1);
    lcd.print("WiFi!");
    delay(2000);
  }
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  connectToWiFi();
  ThingSpeak.begin(client);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Update LCD every 2 seconds
  if (currentMillis - lastLCDUpdate >= LCDUpdateInterval) {
    ultrasonic(); // Call the ultrasonic function to update LCD
    lastLCDUpdate = currentMillis; // Update the last LCD update time
  }

  // Update ThingSpeak every 5 minutes
  if (currentMillis - lastThingSpeakUpdate >= ThingSpeakUpdateInterval) {
    // Call the ultrasonic function to update data
    ultrasonic();
    
    // Send data to ThingSpeak
    ThingSpeak.setField(1, waterHeight_ft);
    ThingSpeak.setField(2, waterQuantity / 1000);
    ThingSpeak.setField(3, percentage);
    int statusCode = ThingSpeak.writeFields(channelID, apiKey);
    if (statusCode == 200) {
      Serial.println("Data sent to ThingSpeak successfully!");
    } else {
      Serial.print("Failed to send data to ThingSpeak. Status code: ");
      Serial.println(statusCode);
    }

    lastThingSpeakUpdate = currentMillis; // Update the last ThingSpeak update time
  }
}
