#include <Servo.h>

float tempaverage1  = 0;
float tempaverage2  = 0;
float tempaverage3  = 0;
float tempaverage4  = 0;
float tempaverage5  = 0;
Servo myservo;  

int potpin = 0;  
int val;  
void setup()
{
  myservo.attach(9);  
  Serial.begin(9600);
}

void loop() 
{ 
  val = analogRead(potpin);
  
  float voltage = val * 5.0;
  voltage /= 1024.0; 
  float temperatureC = (voltage - 0.5) * 100 ;

  tempaverage1 = temperatureC;

  
  float tempaveragefinal = ( tempaverage1 + tempaverage2 +tempaverage3+ tempaverage4 +tempaverage5)/5;
  tempaverage2 = tempaverage1;
  tempaverage3 = tempaverage2;
  tempaverage4 = tempaverage3;
  tempaverage5 = tempaverage4;
  
  Serial.print(tempaveragefinal); 
  Serial.println(" degrees C");
  
  
  if (tempaveragefinal <= 26.0){
  myservo.write(0);
  delay(50); 
  }
  
  if (tempaveragefinal >= 28.0){
  myservo.write(180); 
  delay(50);
  }
  delay(200);                          
}
