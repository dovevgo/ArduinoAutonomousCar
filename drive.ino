void driveTurn(){
  returnCheck = checkTurn(); // 1 = Turn Right, 2 Turn Left
    switch (returnCheck){
      case 1:
        turnRight(150);
        delay(950);
        motorStop();
        break;
      case 2:
        turnLeft(150);
        delay(950);
        motorStop();
        break;
      case 3:
        moveBackwards(255);
        delay(950);
        motorStop();
        driveTurn();
        break;
      }
  }

void drive(){
  frontDistanceCenter = checkUltrasonic();
  checkIR();
  Serial.println(frontDistanceCenter);
  if (frontDistanceCenter < stopDistance){
    motorStop();
    driveTurn(); 
  }    

  if (statusSensorL == 1){
    motorStop();
    turnRight(150);
    delay(150);
    motorStop();
    }

  if (statusSensorR == 1){
    motorStop();
    turnLeft(150);
    delay(250);
    motorStop();
    }
  moveForward(255);
}  
