#define BLYNK_TEMPLATE_ID "TMPL6pepmvXmf"
#define BLYNK_TEMPLATE_NAME "PROYEK SMART GREENHOUSE"
#define BLYNK_AUTH_TOKEN "lA5W2zb3zkFdFj3wX0NXwGxppX0-vOCD"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

//=========================
// WIFI
//=========================
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

//=========================
// DHT22
//=========================
#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

//=========================
// LDR
//=========================
#define LDRPIN 34

//=========================
// RELAY KIPAS
//=========================
#define RELAYPIN 5

//=========================
// LED LAMPU GREENHOUSE
//=========================
#define LAMPPIN 26

//=========================
// SERVO VENTILASI
//=========================
#define SERVOPIN 13

Servo ventilationServo;

//=========================
// LCD
//=========================
LiquidCrystal_I2C lcd(0x27, 16, 2);

//=========================
// BLYNK PINS
//=========================
#define VPIN_TEMP   V1
#define VPIN_HUM    V2
#define VPIN_LIGHT  V3
#define VPIN_FAN    V4
#define VPIN_LAMP   V5
#define VPIN_VENT   V6
#define VPIN_ANGLE  V7

bool manualLamp = false;
bool manualVent = false;

//=========================
// MANUAL LAMP
//=========================
BLYNK_WRITE(VPIN_LAMP)
{
  manualLamp = param.asInt();

  if (manualLamp)
  {
    digitalWrite(LAMPPIN, HIGH);
  }
  else
  {
    digitalWrite(LAMPPIN, LOW);
  }
}

//=========================
// MANUAL VENT
//=========================
BLYNK_WRITE(VPIN_VENT)
{
  manualVent = param.asInt();

  if (manualVent)
  {
    ventilationServo.write(90);
    Blynk.virtualWrite(VPIN_ANGLE, 90);
  }
  else
  {
    ventilationServo.write(0);
    Blynk.virtualWrite(VPIN_ANGLE, 0);
  }
}

void setup()
{
  Serial.begin(115200);

  dht.begin();

  pinMode(RELAYPIN, OUTPUT);
  pinMode(LAMPPIN, OUTPUT);

  digitalWrite(RELAYPIN, LOW);
  digitalWrite(LAMPPIN, LOW);

  ventilationServo.attach(SERVOPIN);
  ventilationServo.write(0);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("SMART");
  lcd.setCursor(0, 1);
  lcd.print("GREENHOUSE");

  delay(2000);

  WiFi.begin(ssid, pass);

  lcd.clear();
  lcd.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");

  lcd.clear();
  lcd.print("WiFi OK");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
}

void loop()
{
  Blynk.run();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int lightValue = analogRead(LDRPIN);

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT Error");
    return;
  }

  //=================================
  // DETEKSI SIANG / MALAM
  //=================================
  bool malam = (lightValue > 2000);

  //=================================
  // KIRIM KE BLYNK
  //=================================
  Blynk.virtualWrite(VPIN_TEMP, temperature);
  Blynk.virtualWrite(VPIN_HUM, humidity);
  Blynk.virtualWrite(VPIN_LIGHT, lightValue);

  //=================================
  // KIPAS OTOMATIS
  //=================================
  if (temperature > 30)
  {
    digitalWrite(RELAYPIN, HIGH);
    Blynk.virtualWrite(VPIN_FAN, 1);
  }
  else
  {
    digitalWrite(RELAYPIN, LOW);
    Blynk.virtualWrite(VPIN_FAN, 0);
  }

  //=================================
  // LAMPU OTOMATIS
  //=================================
  if (!manualLamp)
  {
    if (malam)
    {
      digitalWrite(LAMPPIN, HIGH);
    }
    else
    {
      digitalWrite(LAMPPIN, LOW);
    }
  }

  //=================================
  // VENTILASI OTOMATIS
  //=================================
  if (!manualVent)
  {
    if (!malam && temperature > 32)
    {
      ventilationServo.write(90);
      Blynk.virtualWrite(VPIN_ANGLE, 90);
    }
    else
    {
      ventilationServo.write(0);
      Blynk.virtualWrite(VPIN_ANGLE, 0);
    }
  }

  //=================================
  // LCD
  //=================================
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C ");

  lcd.setCursor(9, 0);
  lcd.print("H:");
  lcd.print((int)humidity);

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lightValue);
  lcd.print("   ");

  //=================================
  // SERIAL MONITOR
  //=================================
  Serial.println("====================");
  Serial.print("Temperature : ");
  Serial.println(temperature);

  Serial.print("Humidity    : ");
  Serial.println(humidity);

  Serial.print("Light       : ");
  Serial.println(lightValue);

  Serial.print("Kondisi     : ");
  Serial.println(malam ? "MALAM" : "SIANG");

  Serial.print("Fan         : ");
  Serial.println(digitalRead(RELAYPIN));

  Serial.print("Lamp        : ");
  Serial.println(digitalRead(LAMPPIN));

  delay(1000);
}