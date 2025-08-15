#include <DHT.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define DHTPIN 32
#define DHTTYPE DHT11
#define MQ2PIN 33
#define BUZZER_PIN 26
#define RELAY_PIN 5

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);               // Moniteur série (USB)
  SerialBT.begin("ESP32-SalleServeur");  // Nom Bluetooth

  dht.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.println("==== ESP32 démarré ====");
  Serial.println("En attente de commandes via Bluetooth...");
  SerialBT.println("Connexion Bluetooth OK. Vous pouvez envoyer des commandes.");
}

void loop() {
  // Lecture des capteurs
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  int mq2RawValue = analogRead(MQ2PIN);

  // Affichage sur le moniteur série
  Serial.println("----- Mesures -----");
  Serial.print("Température : "); Serial.print(temperatureC); Serial.println(" °C");
  Serial.print("Humidité    : "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Gaz (MQ2)   : "); Serial.println(mq2RawValue);
  Serial.println("-------------------");

  // Envoi vers l'app (Bluetooth)
  SerialBT.println("Température : " + String(temperatureC) + " °C");
  SerialBT.println("Humidité    : " + String(humidity) + " %");
  SerialBT.println("Gaz (MQ2)   : " + String(mq2RawValue));

  // Conditions automatiques
  if (temperatureC > 30 || mq2RawValue >= 100 || humidity >= 40) {
    tone(BUZZER_PIN, 1000); delay(500);
    tone(BUZZER_PIN, 2000); delay(500);
  } else {
    noTone(BUZZER_PIN);
  }

  if (temperatureC > 30 || mq2RawValue >= 100) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  // 🔹 Réception commandes Bluetooth
  if (SerialBT.available()) {
    String cmd = SerialBT.readStringUntil('\n');
    cmd.trim();

    Serial.println("Commande Bluetooth : [" + cmd + "]");

    if (cmd == "ON V") {
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("→ Ventilateur ON");
      SerialBT.println("Ventilateur activé.");
    }
    else if (cmd == "OFF V") {
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("→ Ventilateur OFF");
      SerialBT.println("Ventilateur désactivé.");
    }
    else if (cmd == "ON B") {
      tone(BUZZER_PIN, 1500);
      Serial.println("→ Buzzer ON");
      SerialBT.println("Buzzer activé.");
    }
    else if (cmd == "OFF B") {
      noTone(BUZZER_PIN);
      Serial.println("→ Buzzer OFF");
      SerialBT.println("Buzzer désactivé.");
    } else {
      Serial.println("Commande non reconnue.");
    }
  }

  delay(200); // Pause entre cycles
}
