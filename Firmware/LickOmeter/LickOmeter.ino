#include <Servo.h>
#include <CapacitiveSensor.h>

Servo myservo;  // create servo object to control a servo

CapacitiveSensor cs_10_11 = CapacitiveSensor(10, 11);  //10M Resistor between pins 2 and 3, you may also connect an antenna on pin 8
unsigned long csSum;

//Variables for Code
int RewardThresh = 1; // 
int LickCounter = 0; //
int ServPosOut = 4; // starting position of servo (from where its strating to drive out)
int ServPosIn = 68; // Servo Position when out, how far to drive out
int ServSignalIn = 0;
int ServStatus = 0;
int ServoPos = 0;   // <------ variable to store the rotation in degrees of the servo motor.
volatile bool ChangeDetected = false;

void setup() {
  // Servo Control is attached to pin 8
  myservo.attach(8);
  myservo.write(ServPosOut);
  delay(50);
  //LED is on pin 12 // with 220 Ohm resistor at longer side/ Pin 12 (red) side
  pinMode(12, OUTPUT);
  //Lick OUT is on pin 9
  pinMode(9, OUTPUT);
  //Servo IN os on pin 3
  //digitalWrite(10, LOW);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), ServoInDetectChange, CHANGE); // important function, needs to be special pin (e.g., 3) where its possible to excecute functions and interrupt. If lick detected then stop and move to last code and say true than new loop started
  myservo.write(ServPosOut);
  ServStatus = myservo.read();
}

void loop() { 
  noInterrupts();
  LickDetect();
  ServControl();
  interrupts();
}

void LickDetect() {
  long cs = cs_10_11.capacitiveSensor(80);  //a: Sensor resolution is set to 80
  if (cs > 100) {                         //b: Arbitrary number
    csSum += cs;
    if (csSum >= 2300)  //c: This value is the threshold, a High value means it takes longer to trigger #original value = 3800
    {
      LickCounter = LickCounter + 1;
      LickOut();      
      if (csSum > 0) { csSum = 0; }  //Reset
      cs_10_11.reset_CS_AutoCal();     //Stops readings
    }
  } else {
    csSum = 0;  //Timeout caused by bad readings
  }
}

void LickOut() {
  if (LickCounter == RewardThresh) {
    digitalWrite(12, HIGH);  //  if a lick is detected, turn LED ON.
    digitalWrite(9, HIGH);   // TTL out start
    delay(1);
    digitalWrite(9, LOW);   // TTL out stop
    digitalWrite(12, LOW);  //  turn the LED OFF.
    LickCounter = 0;
  }
}
  
void ServControl() {
  if (ChangeDetected==true) {
    ServSignalIn = digitalRead(3);
    if (ServSignalIn == HIGH) {
      for (ServoPos = ServStatus; ServoPos <= ServPosIn; ServoPos += 1) {myservo.write(ServoPos); delay(10);}
      ServStatus = myservo.read();
    } else {
      for (ServoPos = ServStatus; ServoPos >= ServPosOut; ServoPos -= 1) {myservo.write(ServoPos); delay(10);}
      ServStatus = myservo.read();
    }
    ChangeDetected == false; //Reset Change Detection
  }
}

void ServoInDetectChange() {
  ChangeDetected = true; // if true than lick-spout drives out
}

// Stecker für Lick-spout:
// 1. Lick-spout, 2. PIN (orangenes Kabel Servo ), 3. Strom (rotes Kabel Servo), 4. GND (braunes Kabel Servo)