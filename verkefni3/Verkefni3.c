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
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex269, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*       Notar baedi joysticks til ad hreyfa robotinn                                                 *|
|*       vinstri joystickinn stjornar vinstri motornum og haegri joystickinn stjornar haegri motorinum*|
|*       Takki 6U faerir arminn upp og 6D faerir hann nidur, Takki 8R stoppar robotinn                *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 6          armMotor             VEX Motor           Arm motor                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{
  int running = 1;
	while(running == 1)
  {

    motor[leftMotor] = vexRT[Ch3];
    motor[rightMotor] = vexRT[Ch2];
    if(vexRT[Btn6U] == 1)
	    {
	      motor[armMotor] = 40;
	    }
	    else if(vexRT[Btn6D] == 1)
	    {
	      motor[armMotor] = -10;
	    }
	    else
	    {
	      motor[armMotor] = 0;
	    }
	   if(vexRT[Btn8R] == 1)
	   {
	     running = 0;
	   }
  }

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
