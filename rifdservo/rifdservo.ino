#include <SPI.h>
#include <MFRC522.h>
#include<Servo.h>

int RST_PIN  = 9;
int SS_PIN = 10;
MFRC522 mfrc(SS_PIN, RST_PIN);
Servo myservo;
int servo_pin = 2;


void setup() {
  Serial.begin(9600);
  myservo.attach(servo_pin);
  SPI.begin();
  mfrc.PCD_Init();
}

void loop() {
  if (!mfrc.PICC_IsNewCardPresent()
      || !mfrc.PICC_ReadCardSerial()) {
    //Serial.println("Non");
    //myservo.write(0);
    delay(500);
    return;
  }

  Serial.print("Card UID:");
  for (byte i = 0; i < 4; i++) {
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();

  if (mfrc.uid.uidByte[0] == 250
      && mfrc.uid.uidByte[1] == 23
      && mfrc.uid.uidByte[2] == 127
      && mfrc.uid.uidByte[3] == 130) {
    myservo.write(90);
    delay(1000);
  }
  else {
    myservo.write(0);
    delay(1000);
  }
}
