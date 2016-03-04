
void setup() {
  setupMotors(5,6,9,10);
  Serial.begin(9600);
  
  setSpeeds(100,100);
  delay(500);
  setSpeeds(-100,-100);
  delay(500); 
  setSpeeds(0,0);
}

void loop() {
  char buffLeft[8];
  char buffRight[8];
  
//  Serial.readBytesUntil('x',buffLeft,5);
//  Serial.readBytesUntil('x',buffRight,5);
  if(Serial.available()){
    int leftSpeed = Serial.parseInt();
    int rightSpeed =  Serial.parseInt();
    
    Serial.print("LeftSpeed: ");
    Serial.print(leftSpeed);
    
    Serial.print(" RightSpeed: ");
    Serial.print(rightSpeed);
    
    Serial.println("");
    
    setSpeeds(leftSpeed,rightSpeed);
  }
  //This is done by stabja
}
