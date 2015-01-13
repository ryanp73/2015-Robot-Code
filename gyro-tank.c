#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     slide,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     intake,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
|
|		 _____ _____  _   _   ___  _____ _   _  ______ _   ______
|		|____ /  __ \| | | | / _ \|_   _| \ | ||___  /| | |___  /
|		    / / /  \/| |_| |/ /_\ \ | | |  \| |   / // __)   / /
|		    \ \ |    |  _  ||  _  | | | | . ` |  / / \__ \  / /
|		.___/ / \__/\| | | || | | |_| |_| |\  |./ /__(   /./ /___
|		\____/ \____/\_| |_/\_| |_/\___/\_| \_/\_____/|_| \_____/
|
|		Team: Cobalt Colts 6547 © 2014-15
|		Head Tele-Op Programmer: Ryan Pope
|		Head Autonomous Programmer: Ethan Tucker
|
|			How to Drive the Robot
|			----------------------
|
|		Left Joystick Up/Down = Left Motor Speed on curve
|		Right Joystick Up/Down = Right Motor Speed on curve
|
|		Left Bumper lifts the linear slide
|		Right Bumper lowers the linear slide
|
|		Left Trigger rotates intake system into the robot
|		Right Trigger rotates intake system out of the robot
|
*/

//	Joystick code
#include "JoystickDriver.c"
//	Some stuff I need a little bit
#include "ryan.h"

/*
| ------------------------------------------------------------------------------
| Controller buttons
| ------------------------------------------------------------------------------
*/
int x = 1; int a = 2; int b = 3; int y = 4; /* Buttons */
int leftBumper = 5; int rightBumper = 6; /* bumpers */
int leftTrigger = 7; int rightTrigger = 8; /* triggers */

//	Idk what this variable is, but it works so cool
bool gyroed;

task main()
{
	//	Some kind of gyro sensor calibration
	calibrateGyro(gyro);

	while(true)
	{
		//	Update joystick values
		getJoystickSettings(joystick);

		//	Drive code
		motor[left] = speedCurve(joystick.joy1_y2);
		motor[right] = speedCurve(joystick.joy1_y1);

		//	Bumper controls for linear slides
		if(joy1Btn(leftBumper))
		{
			motor[slide] = 50;
		}
		else if(joy1Btn(rightBumper))
		{
			motor[slide] = -25;
		}
		else
		{
			motor[slide] = 0;
		}

		//	Trigger controls for intake systems
		if(joy1Btn(leftTrigger))
		{
			motor[intake] = 100;
		}
		else if(joy1Btn(rightTrigger))
		{
			motor[intake] = -100;
		}
		else
		{
			motor[intake] = 0;
		}

		//	Some gyro stuff I don't understand, ask Ethan
		while(joystick.joy1_TopHat == 4)
		{
			getJoystickSettings(joystick);
			if(SensorValue(gyro) > offset)//turning right
			{
				motor[right] = motor[right] - 1;
			}
			if(SensorValue(gyro) < offset)//turning left
			{
				motor[left] = motor[left] - 1;
			}
			gyroed = true;
		}

		//	Some other gyro stuff
		if(gyroed)
		{
			motor[left] = 1;
			motor[right] = 1;
			gyroed = false;
		}
	}
}
