int trigPin1 = 6; // Trigger
int echoPin1 =7; // Echo
int trigPin2 =8; // Trigger
int echoPin2 =9; // Echo
long duration1, cm1,duration2,cm2;
void setup() {
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

}
void loop() {
// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
digitalWrite(trigPin1, LOW);
delayMicroseconds(5);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echoPin1, INPUT);
duration1 = pulseIn(echoPin1, HIGH);
// Convert the time into a distance
cm1 = (duration1/2) / 29.1; // Divide by 29.1 or multiply by 0.0343
digitalWrite(trigPin2, LOW);
delayMicroseconds(5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echoPin2, INPUT);
duration2 = pulseIn(echoPin2, HIGH);
// Convert the time into a distance
cm2= (duration2/2) / 29.1; // Divide by 29.1 or multiply by 0.0343
if (cm1<20 && cm2<20)
{
Serial.println("Vdn");
delay(300);
}
if(cm1>=20 && cm1<=30 && cm2>=20 && cm2<=30)
{ 
Serial.println("Vup");
delay(300);
}
if(cm1<=10 && cm2>=10)
{
Serial.println("back");
delay(300);
}
if(cm1>=30 && cm2<=10)
{Serial.println("next");
delay(300);
}
}