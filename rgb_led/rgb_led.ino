int sensorValue = 0;
int sensorPin = A0;
bool curentswitchstate = HIGH;
bool lastswitchstate = HIGH;
int ledcontroll = 0 ;

void setup()
{ 
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
}

void loop() 
{
  sensorValue = (analogRead(sensorPin)/4);
  curentswitchstate = digitalRead(2);
  delay(50);
  if (curentswitchstate != lastswitchstate){
    ledcontroll++;
  }
  if (ledcontroll >= 3){
    ledcontroll = 0;
  }
  if (ledcontroll == 0 ){
  analogWrite(11, sensorValue); 
  }
  if (ledcontroll == 1 ){
  analogWrite(10, sensorValue); 
  }
  if (ledcontroll == 2 ){
  analogWrite(9, sensorValue); 
  }
  lastswitchstate = curentswitchstate;
}

