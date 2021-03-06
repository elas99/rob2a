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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  Keyrir eftir svartri linu, ef middlefollowerinn ser svart tha keyrir hann beint                   *|
|*  ef left followerinn ser svart tha beygir robotinn til ad linan se i midjunni og sama med haegri   *|
|*  Thad er touch sensor framan a robotinum sem er haegt ad yta a til ad slokkva a honum              *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{


  int threshold = 2200;      /* found by taking a reading on both DARK and LIGHT    */
  bool running = true;                          /* surfaces, adding them together, then dividing by 2. */
  while(running && SensorValue(touch) == 0)
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

    // RIGHT sensor sees dark:
    if(SensorValue(rightFollower) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(middleFollower) > threshold)
    {
      // go straight
      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }
    // LEFT sensor sees dark:
    if(SensorValue(leftFollower) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }
    if(vexRT[Btn8R] == 1)
	   {
	     running = false;
	   }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
