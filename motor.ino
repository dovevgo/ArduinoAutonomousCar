int currentSpeed = 0;

void moveForward(int speed){
  currentSpeed = speed;
// 1=HIGH backwards
// 2=HIGH forwards
  analogWrite(motorRightSpeed, speed);
  analogWrite(motorLeftSpeed, speed);
  digitalWrite(motorRight2,HIGH);
  digitalWrite(motorRight1,LOW);
  digitalWrite(motorLeft2,HIGH);
  digitalWrite(motorLeft1,LOW);
}
  
void moveBackwards(int speed){
  currentSpeed = speed;
  // 1=HIGH backwards
  // 2=HIGH forwards
  analogWrite(motorRightSpeed, speed);
  analogWrite(motorLeftSpeed, speed);
  digitalWrite(motorRight1,HIGH);
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorLeft1,HIGH);
  digitalWrite(motorLeft2,LOW);
} 

void turnRight(int speed){
  currentSpeed = speed;
  analogWrite(motorRightSpeed, speed);
  analogWrite(motorLeftSpeed, speed);
  digitalWrite(motorLeft2,HIGH);
  digitalWrite(motorLeft1,LOW);
  digitalWrite(motorRight1,HIGH);
  digitalWrite(motorRight2,LOW);
  }

void turnLeft(int speed){
  currentSpeed = speed;
  analogWrite(motorRightSpeed, speed);
  analogWrite(motorLeftSpeed, speed);
  digitalWrite(motorLeft1,HIGH);
  digitalWrite(motorLeft2,LOW);
  digitalWrite(motorRight2,HIGH);
  digitalWrite(motorRight1,LOW);
  }

void motorStop(){
  for(int i = currentSpeed; i > 80; i=i-75){
      analogWrite(motorRightSpeed, i);
      analogWrite(motorLeftSpeed, i);
      delay(25);
  }
  analogWrite(motorRightSpeed, 0);
  analogWrite(motorLeftSpeed, 0);
  digitalWrite(motorLeft1,LOW);
  digitalWrite(motorLeft2,LOW);
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorRight1,LOW);
  delay(1000);
}
