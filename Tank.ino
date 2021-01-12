// Motor library
#include<AFMotor.h>

// Motor connection for motor driver shield
AF_DCMotor motor_Right(1);
AF_DCMotor motor_Left(4);

// Value needed to move the robot remotely
char data = 0;

void setup()
{
Serial.begin(9600);

// Setting up the speed for each motor
motor_Right.setSpeed(200);
motor_Left.setSpeed(200);
}

void loop()
{
  // Remote control with IOS BLE Joystick
   if(Serial.available() > 0)  
   {
      data = Serial.read(); 
      Serial.println(data);
                
      if(data == 'a')
      {
        forward();
      }
      else if(data == 'c')
      {
        backward();
      }
      else if(data == 'b')
      {
        right();
      }
      else if(data == 'd')
      {
        left();
      }
      else if(data == 'g')
      {
        stopping();
      }
   }
 }

// Drive forward function
void forward()
{
  Serial.println("Driving forward");
  delay(500);
  motor_Right.run(FORWARD);
  motor_Left.run(FORWARD);
}

// Drive backward function
void backward()
{
  Serial.println("Driving backwards");
  delay(500);
  motor_Right.run(BACKWARD);
  motor_Left.run(BACKWARD);
}

// Drive left function
void left()
{
  Serial.println("Turning to the left");
  delay(500);
  motor_Right.run(FORWARD);
  motor_Left.run(RELEASE);
}

// Drive right function
void right()
{
  Serial.println("Turning to the right...");
  delay(500);
  motor_Right.run(RELEASE);
  motor_Left.run(FORWARD);
}

// Stop driving function
void stopping()
{
  Serial.println("Stopping");
  delay(500);
  motor_Right.run(RELEASE);
  motor_Left.run(RELEASE);
}

// Spin around to the right function
void spinRight()
{
  Serial.println("I am spinning to the right");
  delay(500);
  motor_Right.run(BACKWARD);
  motor_Left.run(FORWARD);
}

// Spin around to the left function
void spinLeft()
{
  Serial.println("Spining Left...");
  delay(500);
  motor_Right.run(FORWARD);
  motor_Left.run(BACKWARD);
}
