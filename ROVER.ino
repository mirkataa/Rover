#include <AFMotor.h>

// motors
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

int state = 0;
int flag = 0; 

void setup() 
{
	// Set initial speed of the motor & stop
  M1.setSpeed(255);
	M1.run(RELEASE);
  M2.setSpeed(255);
	M2.run(RELEASE);
  M3.setSpeed(255);
	M3.run(RELEASE);
	M4.setSpeed(255);
	M4.run(RELEASE);

  Serial.begin(9600);

}

void loop() 
{

    // if some date is sent, reads it and saves in state
    if(Serial.available() > 0)
    {     
      state = Serial.read();   
      flag = 1;
      if(flag == 1) Serial.println(state);
    }       
    // Forward
    if (state == 'F') 
    {
        M1.run(FORWARD);	
        M2.run(BACKWARD);	
        M3.run(BACKWARD);	
        M4.run(FORWARD);
        if(flag == 1) Serial.println("FORWARD");
    }
    // Backward
    else if (state == 'B') 
    {
        M1.run(BACKWARD);
        M2.run(FORWARD);
        M3.run(FORWARD);
        M4.run(BACKWARD);
        if(flag == 1) Serial.println("BACKWARD");
    }
    // Stop
    else if (state == 'S') 
    {
	      M1.run(RELEASE);
        M2.run(RELEASE);
        M3.run(RELEASE);
        M4.run(RELEASE);
        if(flag == 1) Serial.println("STOP");
    }
    // Right
    else if (state == 'R') 
    {
        M1.run(BACKWARD);
        M2.run(BACKWARD);
        M3.run(BACKWARD);
        M4.run(BACKWARD);
        if(flag == 1) Serial.println("RIGHT");
    }
    // Left
    else if (state == 'L') 
    {
        M1.run(FORWARD);
        M2.run(FORWARD);
        M3.run(FORWARD);
        M4.run(FORWARD);
        if(flag == 1) Serial.println("LEFT");
    }
    flag = 0;
}