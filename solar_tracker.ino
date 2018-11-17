#include <Servo.h>

Servo myservo;

int val = 83;             //position of the servo
int analog1 = A0;         //pins where sensors are connected
int analog2 = A1;
int tol = 8;              //tolerance, if smaller, tracker will be more sensitive
int time = 7;             //time between each step, if smaller, servo will be faster

void setup() 
{
  pinMode(analog1, INPUT);  //configuration of the pins
  pinMode(analog2, INPUT);
  myservo.attach(9);      //set the pin where servo is connected
  myservo.write(val);     //set servo in the initial position
  delay(1000);            //wait one second to avoid too fast movement
}

void loop() 
{
  int photo1 = analogRead(analog1);   //variables where data from sensors are stored
  int photo2 = analogRead(analog2);

  if(photo1 - photo2 > tol || photo2 - photo1 > tol)    //if difference between sensors is higher than tolerance - to avoid chaotic movement
  {
    if(photo1 > photo2 && val >= 0)   //if there is more light on the right side and servo isn't in its maximal position
    {
      val--;                          //current servo position - 1
      myservo.write(val);             //set servo in the new position             
    }

    if(photo1 < photo2 && val <= 165) //if there is more light on the left side and servo isn't in its maximal position
    {
      val++;                          //current servo position + 1
      myservo.write(val);             //set servo in the new position
    }
  }

  delay(time);                        //wait a few milliseconds to avoid too fast movement
}
