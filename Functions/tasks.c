#include "../Functions/functions.c"
task verkefni2_1(){
	int x = 200;
	for(i=0; i<5; i++){
	motor[rightMotor] = 127;
	motor[leftMotor]  = 127;
	wait1Msec(x);
	while( motor[leftMotor] > 0 || motor[rightMotor] > 0){
	motor[rightMotor] = motor[rightMotor] - 1;
	motor[leftMotor]  = motor[leftMotor] - 1;
	wait1Msec(10);
	}
	motor[rightMotor] = -127;
	motor[leftMotor] = -127;
	wait1Msec(x);
	while( motor[leftMotor] < 0 || motor[rightMotor] < 0){
	motor[rightMotor] = motor[rightMotor] + 1;
	motor[leftMotor]  = motor[leftMotor] + 1;
	wait1Msec(10);
	}
	x = x + 1000;
	}
}

task verkefni2_2(){
	wait1Msec(10000);
  int i;
  for(i=0; i<16; i++)
  {
  	if(i % 3 == 0){
    Forward(i);
    Backward(i);
    }
  }
}

task verkefni2_3(){
 		Forward(4.5);
    TurnLeft(1.3);
    Forward(4.5);
    TurnRight(1.78);
    Forward(4.5);
    TurnRight(1.78);
    Forward(4.5);

}

task verkefni3()
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

task verkefni4()
{

	while(SensorValue(lightSensor) > 500)
	{
	}
	while(SensorValue(lightSensor) < 500)
	{

		if(SensorValue(sonarInput) > 50  || SensorValue(sonarInput) == -1)
		{
			Forward(1);
		}
		else
		{
			TurnLeft(1.3);
		}
	}

}

task verkefni5()
{


  int threshold = 2200;
  bool running = true;
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


    if(SensorValue(rightFollower) > threshold)
    {

      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }

    if(SensorValue(middleFollower) > threshold)
    {

      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }

    if(SensorValue(leftFollower) > threshold)
    {

      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }
    if(vexRT[Btn8R] == 1)
	   {
	     running = false;
	   }
  }
}

task verkefni6()
{


		motor[clawMotor] = 0;
		motor[clawMotor] = -40;
		wait1Msec(500);
		motor[clawMotor] = 0;
		wait1Msec(500);
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

			    if(SensorValue(rightFollower) > 2500)
			    {

			      motor[leftMotor]  = 63;
			      motor[rightMotor] = 0;
			    }

			    if(SensorValue(middleFollower) > 2300)
			    {

			      motor[leftMotor]  = 63;
			      motor[rightMotor] = 63;
			    }

			    if(SensorValue(leftFollower) > 2500)
			    {

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
    		motor[clawMotor] = 40;
  	 	 	wait10Msec(500);
  	 	 	motor[clawMotor] = 0;
  	 		TurnLeft(3);
  		}





  }
}
