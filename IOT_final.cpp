#include <Servo.h> 
Servo Myservo; 
#define trigPin 11     // Trig Pin Of HC-SR04
#define echoPin 12    // Echo Pin Of HC-SR04
#define MLa 4        //left motor 1st pin white
#define MLb 5        //left motor 2nd pin Yellow
#define MRa 6       //right motor 1st pin Brown
#define MRb 7       //right motor 2nd pin Orange
#define servoPin 9 //servo motor pin orange

long duration, distance;
int leftDistance, rightDistance;

void setup() 
{
	Serial.begin(9600);
	pinMode(MLa, OUTPUT); // Set Motor Pins As O/P
	pinMode(MLb, OUTPUT);
	pinMode(MRa, OUTPUT);
	pinMode(MRb, OUTPUT);
	pinMode(trigPin, OUTPUT); // Set Trig Pin As O/P To Transmit Waves
	pinMode(echoPin, INPUT); //Set Echo Pin As I/P To Receive Reflected Waves
	Myservo.attach(servoPin);
}

void loop()
{
	Serial.begin(9600);
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH); // Transmit Waves For 10us	
	delayMicroseconds(10);
	duration = pulseIn(echoPin, HIGH); // Receive Reflected Waves
	distance = duration * 0.0343 / 2;   // Convert duration to distance in centimeters
    Serial.println(distance);
    delay(10);
	if (distance> 15) // Condition For Absence Of Obstacle
	{	
		Myservo.write(90);
		digitalWrite(MRb, HIGH); // Move Forward
		digitalWrite(MRa, LOW);
		digitalWrite(MLb, HIGH);
		digitalWrite(MLa, LOW);	
	}
	else if ((distance < 10)&&(distance> 0)) // Condition For Presence Of Obstacle
	{
		stopMotors(); //Stop
		delay(100);

		Myservo.write(0);
		delay(500);
        leftDistance = getDistance();
        Serial.print("Left distance: ");
        Serial.println(leftDistance);

		Myservo.write(180);
		delay(500);
        rightDistance = getDistance();
        Serial.print("Right distance: ");
        Serial.println(rightDistance);
    
		Myservo.write(90);
		delay(500);

		digitalWrite(MRb, LOW); // Move Backward
		digitalWrite(MRa, HIGH);
		digitalWrite(MLb, LOW);
		digitalWrite(MLa, HIGH);
		delay(500);

		stopMotors(); //Stop
		delay(100);

		digitalWrite(MRb, HIGH); // Move Left
		digitalWrite(MRa, LOW);
		digitalWrite(MLa, LOW);
		digitalWrite(MLb, LOW);
		delay(500);

    if (leftDistance > rightDistance)
    {  // Turn left if more space on the left
      digitalWrite(MRb, HIGH); // Move Left
		  digitalWrite(MRa, LOW);
		  digitalWrite(MLa, LOW);
		  digitalWrite(MLb, LOW);
		  delay(500);
    }
    else
    {  // Turn right if more space on the right or equal space on both sides
      digitalWrite(MRb, LOW);  // Turn Right
      digitalWrite(MRa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MLa, LOW);
    }
	}
}

void stopMotors()
{
    digitalWrite(MRb, LOW);  // Stop
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);
}

int getDistance()
{
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.0343 / 2;
    return distance;
}