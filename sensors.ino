void checkIR(){
  statusSensorL = !digitalRead(leftIR);  
  statusSensorR = !digitalRead(rightIR);  
}

void turnUltrasonic(int angle){
  myservo.write(angle);
}

float checkUltrasonic(){
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
  }

 int checkTurn(){
  turnUltrasonic(0);
  delay(500);
  float rightDis = checkUltrasonic();
  delay(500);
  turnUltrasonic(180);
  delay(500);
  float leftDis = checkUltrasonic();
  turnUltrasonic(90);
  
  if (rightDis > leftDis){ // Right bigger then left
    if (rightDis > stopDistance){ // Right bigger then stop distance
      return 2;
      }
      else{ // under stop distance
        return 3;
      }
    } else { // Left bigger then right
      if (leftDis > stopDistance){ // Left bigger then stop distance
      return 1;
      }
      else{ // under stop distance
        return 3;
      } 
   } 
  
}
