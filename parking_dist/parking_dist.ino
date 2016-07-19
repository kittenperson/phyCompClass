#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define GreenLED 12
#define YellowLED 11
#define RedLED 10

int maximumRange = 500; // Maximum range needed
int minimumRange = 10; // Minimum range needed
long duration, distance; // Duration used to calculate distance
int rangeAverage[5];

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 pinMode(GreenLED, OUTPUT);
 pinMode(YellowLED, OUTPUT);
 pinMode(RedLED, OUTPUT);
 
 
 
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 rangeAverage[1] = distance; 
 
 rangeAverage[0] = (rangeAverage[1]+rangeAverage[2]+rangeAverage[3]+rangeAverage[4])/4; 
 
 rangeAverage[4] = rangeAverage[3];
 rangeAverage[3] = rangeAverage[2];
 rangeAverage[2] = rangeAverage[1];
 
 
 
 if (rangeAverage[0] >= 200){
 Serial.println("GO");
 digitalWrite(GreenLED, HIGH);
 digitalWrite(YellowLED, LOW);
 digitalWrite(RedLED, LOW);
 }
 if (rangeAverage[0] <= 150){
 Serial.println("SLOW"); 
 digitalWrite(GreenLED, LOW);
 digitalWrite(YellowLED, HIGH);
 digitalWrite(RedLED, LOW);
 }
 if (rangeAverage[0] <= 50){
 Serial.println("Stop");
 digitalWrite(YellowLED, LOW); 
 digitalWrite(GreenLED, LOW);
 digitalWrite(RedLED, HIGH);
 }
 
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);

 
 //Delay 50ms before next reading.
 delay(100);
}
