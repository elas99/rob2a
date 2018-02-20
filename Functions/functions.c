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

int full_power = 127;


void resetEncoder()
{
	SensorValue[leftEncoder]=0;
	SensorValue[rightEncoder]=0;
}

void stopMotors()
{
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}
const float rotations = 180.0;
void Forward(float r)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */

  // While the encoders have not yet met their goal: (r * rotations) ie (3.0 * 360.0) or "three rotations"
  while(SensorValue[rightEncoder] < (r * rotations) && SensorValue[leftEncoder] < (r * rotations))
  {
    motor[rightMotor] = 63;         /* Run both motors        */
    motor[leftMotor]  = 63;         /* forward at half speed. */
  }
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
