#include <Servo.h>
#include "DYPlayerArduino.h"

DY::Player player;

#define motorRight1 2
#define motorRight2 3
#define motorRightSpeed 5
#define motorLeft1 4
#define motorLeft2 7
#define motorLeftSpeed 6
#define rightIR A2
#define leftIR  A5

Servo myservo;

const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;
int statusSensorL;
int statusSensorR;
float frontDistanceRight;
float frontDistanceCenter;
float frontDistanceLeft;
int stopDistance = 25;
int returnCheck;
long soundMillis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorRight1, OUTPUT);  
  pinMode(motorRight2, OUTPUT);
  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorRightSpeed, OUTPUT);
  pinMode(motorLeftSpeed, OUTPUT);
  pinMode (leftIR, INPUT);
  pinMode (rightIR, INPUT);
  myservo.attach(A0);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.print("Start"); 

  player.begin();
  player.setVolume(30); // 100% Volume
  delay(2000);
  player.playSpecified(1); // Play sound file 00001.mp3
  delay(2000);
  player.playSpecified(2); // Play sound file 00002.mp3
  soundMillis = millis();
  soundMillis  = soundMillis - 13000;
  delay(3000);
}

void loop() {
  drive();
  Serial.print(soundMillis);
  Serial.print(" ");
  Serial.println(millis());
  if (millis() > soundMillis + 23000){
    Serial.println("Play...");
    player.playSpecified(3); // Play sound file 00003.mp3
    soundMillis = millis();
  }
}
