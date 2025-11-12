#define BLYNK_TEMPLATE_ID   "TMPL3XvNjxP5O"
#define BLYNK_TEMPLATE_NAME "Home"
#define BLYNK_AUTH_TOKEN    "XyTXQLOly_l6bDvdOfjRkuQTRk8h-JyTh"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>


// Wi-Fi Credentials
char ssid[] = "internet";
char pass[] = "12345678";
char auth[] = "XyTXQLoy_I6bDvdfQifkuQTRkBh-JyTh";

// Pin definitions
#define DHTPIN D2
#define DHTTYPE DHT11
#define FLAME_PIN D5
#define RELAY_PIN D6
//#define LED_PIN D7

// Set to true if your flame sensor outputs LOW when flame is detected
#define FLAME_ACTIVE_LOW true

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

bool flameDetected = false;

// Function to send sensor data to Blynk
void sendSensorData() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int flameVal = digitalRead(FLAME_PIN);

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Determine flame state
  bool fire = FLAME_ACTIVE_LOW ? (flameVal == LOW) : (flameVal == HIGH);
  flameDetected = fire;

  // Send data to Blynk
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, fire ? 1 : 0);

  // Local action for flame
  if (fire) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("🔥 Flame Detected! LED + Relay ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW);
  }

  Serial.print("Temp: "); Serial.print(t);
  Serial.print(" °C | Hum: "); Serial.print(h);
  Serial.print(" % | Flame: "); Serial.println(fire ? "YES" : "NO");
}

// Manual control from Blynk
BLYNK_WRITE(V4) {
  int state = param.asInt();
  digitalWrite(LED_PIN, state);
  digitalWrite(RELAY_PIN, state);
  Serial.print("Manual control: ");
  Serial.println(state ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);

  pinMode(FLAME_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  Serial.println("Connecting to Wi-Fi...");
  Blynk.begin(auth, ssid, pass);

  // Send data every 3 seconds
  timer.setInterval(3000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}