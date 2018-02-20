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


/*----------------------------------------------------------------------------------------------------*\                                    *|
|*                                                                                                    *|
|*    � �essu verkefni byrjar robotinn ekki a� keyra fyrr en �a� er kveikt � lj�sinu (lightsensor)		*|
|*     og ef hann er a� fara klessa � �� stoppar hann 50cm ��ur en �a� ver�ur �rekstur   							*|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "../Functions/functions.c"
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{

	while(SensorValue(lightSensor) > 500)
	{
	}
	while(SensorValue(lightSensor) < 500 && (SensorValue(sonarInput) > 50  || SensorValue(sonarInput) == -1))
	{
		Forward(1);
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
