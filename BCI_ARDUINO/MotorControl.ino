


int motorPins[4];
int speeds[2];

void setupMotors(int pinA0,int pinA1,int pinB0,int pinB1){
  motorPins[0]=pinA0;
  motorPins[1]=pinA1;
  motorPins[2]=pinB0;
  motorPins[3]=pinB1;
  for(int i=0;i<4;i++)
    pinMode(motorPins[i],OUTPUT);
}

void setSpeeds(int leftSpeed,int rightSpeed){
  
  if(leftSpeed>0){
    analogWrite(motorPins[0],map(leftSpeed,0,100,0,255)); 
    analogWrite(motorPins[1],0);
  }
  else if(leftSpeed<0){
    analogWrite(motorPins[1],map(leftSpeed,0,-100,0,255)); 
    analogWrite(motorPins[0],0);
  }
  else {
    analogWrite(motorPins[0],0); 
    analogWrite(motorPins[1],0);
  }
  
  if(rightSpeed>0){
    analogWrite(motorPins[2],map(rightSpeed,0,100,0,255)); 
    analogWrite(motorPins[3],0);
  }
  else if(rightSpeed<0){
    analogWrite(motorPins[3],map(rightSpeed,0,-100,0,255)); 
    analogWrite(motorPins[2],0);
  }
  else {
    analogWrite(motorPins[2],0); 
    analogWrite(motorPins[3],0);
  }
  
}
