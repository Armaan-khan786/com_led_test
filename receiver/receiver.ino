// -------- Receiver ESP32 (COM7) --------

int ledPins[4] = {18, 19, 21, 22};
int ledIndex = 0;

void turnOffAll() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  turnOffAll();

  // First handshake
  Serial2.println("READY");
  Serial.println("Sent: READY");
}

void loop() {

  if (Serial2.available()) {

    int receivedPin = Serial2.parseInt();

    Serial.print("Received Pin: ");
    Serial.println(receivedPin);

    turnOffAll();

    digitalWrite(receivedPin, HIGH);
    delay(1000);

    digitalWrite(receivedPin, LOW);
    delay(500);

    // Tell sender ready for next
    Serial2.println("READY");
    Serial.println("Sent: READY");
  }
}