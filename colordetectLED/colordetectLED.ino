#include <Wire.h>
#include <Adafruit_TCS34725.h>

float r, g, b;
Adafruit_TCS34725 tcs
  = Adafruit_TCS34725
    (TCS34725_INTEGRATIONTIME_50MS,
     TCS34725_GAIN_4X);



void setup() {
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  }
  else {
    Serial.println("No found");
    while (1);
  }
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  tcs.setInterrupt(false);
  delay(60);
  tcs.getRGB(&r, &g, &b);
  tcs.setInterrupt(true);
  Serial.print("R:  "); Serial.print(int(r));
  Serial.print("  G:  "); Serial.print(int(g));
  Serial.print("  B:  "); Serial.println(int(b));

  analogWrite(9,int(r));
  analogWrite(10,int(g));
  analogWrite(11,int(b));
  delay(10);
}
