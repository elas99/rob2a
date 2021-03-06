#pragma config(Sensor, in1,    Potato,         sensorPotentiometer)
#pragma config(Sensor, in2,    lightSensor,    sensorReflection)
#pragma config(Sensor, in3,    leftFollower,   sensorLineFollower)
#pragma config(Sensor, in4,    middleFollower, sensorLineFollower)
#pragma config(Sensor, in5,    rightFollower,  sensorLineFollower)
#pragma config(Sensor, in6,    gyroSensor,     sensorNone)
#pragma config(Sensor, in7,    gyroSensor,     sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  touch,          sensorTouch)
#pragma config(Sensor, dgtl6,  sonarInput,     sensorSONAR_cm)
#pragma config(Motor,  port2,  leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,  rightMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,  clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port7,  armMotor,      tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  Keyrir eftir svartri linu, ef middlefollowerinn ser svart tha keyrir hann beint                   *|
|*  ef left followerinn ser svart tha beygir robotinn til ad linan se i midjunni og sama med haegri   *|
|*  Thad er touch sensor framan a robotinum sem er haegt ad yta a til ad slokkva a honum              *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "../Functions/functions.c"
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{

// Declare Global Variables     /* 'rotations' will be a counter for every 360 encoder clicks */
	bool running = true;
  while(SensorValue(lightSensor) > 500)
	{
	}
  while(running && SensorValue(touch) == 0 || SensorValue(lightSensor) < 500)
  {




    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(leftFollower));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(middleFollower));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(rightFollower));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
		if(SensorValue(sonarInput) > 20 || SensorValue(sonarInput) == -1)
    	{
			    // RIGHT sensor sees dark:
			    if(SensorValue(rightFollower) > 2500)
			    {
			      // counter-steer right:
			      motor[leftMotor]  = 63;
			      motor[rightMotor] = 0;
			    }
			    // CENTER sensor sees dark:
			    if(SensorValue(middleFollower) > 2300)
			    {
			      // go straight
			      motor[leftMotor]  = 63;
			      motor[rightMotor] = 63;
			    }
			    // LEFT sensor sees dark:
			    if(SensorValue(leftFollower) > 2500)
			    {
			      // counter-steer left:
			      motor[leftMotor]  = 0;
			      motor[rightMotor] = 63;
			    }
			    }
    if(vexRT[Btn8R] == 1)
	   {
	     running = false;
	   }
    if(SensorValue(sonarInput) <  21 || SensorValue(sonarInput) == -1)
    	{

    		motor[leftMotor]  = 0;
      	motor[rightMotor] = 0;
     	  wait1Msec(500);
     	  motor[clawMotor] = 0;
				wait1Msec(500);
				motor[clawMotor] = -40;
				wait1Msec(500);
				motor[clawMotor] = 0;
				wait1Msec(500);
    		motor[clawMotor] = 40; 		//...close the gripper.\
  	 	 	wait10Msec(500);
  	 	 	motor[clawMotor] = 0;
  	 		TurnLeft(3);
  		}





  }
}
