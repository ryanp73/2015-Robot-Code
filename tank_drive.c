#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     leftMotor,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightMotor,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     intake,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     linearSlide,   tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

int speedCurve(int x)
{
	return 0.0000216166*pow(x,3)+1.19001*pow(10,-18)*pow(x,2)+0.427083*x;
}

task main()
{
	while(true)
	{
		getJoystickSettings(joystick);
		
		/*Drive code*/
		motor[leftMotor] = joystick.joy1_y1 * (100/128);
		motor[rightMotor] = joystick.joy1_y2 * (100/128);
	}
}
