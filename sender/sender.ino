// -------- Sender ESP32 (COM6) --------

int ledPins[4] = {18, 19, 21, 22};
int ledIndex = 0;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {

  // Wait until receiver says READY
  if (Serial2.available()) {

    String response = Serial2.readStringUntil('\n');
    response.trim();

    if (response.equals("READY")) {

      int pinNumber = ledPins[ledIndex];

      Serial.print("Sending Pin: ");
      Serial.println(pinNumber);

      Serial2.println(pinNumber);

      ledIndex++;

      if (ledIndex >= 4) {
        ledIndex = 0;
      }
    }
  }
}