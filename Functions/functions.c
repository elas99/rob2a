void Controller()
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
