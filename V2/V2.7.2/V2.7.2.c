#pragma config(Motor,  port2,           LClaw,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           LArm,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RArm,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RUDriving,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RDDriving,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LUDriving,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LDDriving,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
void endDrive()
{
	motor[LUDriving] = 0;
	motor[LDDriving] = 0;
	motor[RUDriving] = 0;
	motor[RDDriving] = 0;
}
void moveForward(float time)
{
	motor[LUDriving] = 127;
	motor[LDDriving] = 127;
	motor[RUDriving] = 127;
	motor[RDDriving] = 127;
	delay(time);
	endDrive();
}
void moveBackward(float time)
{
	motor[LUDriving] = -127;
	motor[LDDriving] = -127;
	motor[RUDriving] = -127;
	motor[RDDriving] = -127;
	delay(time);
	endDrive();
}
void turnLeft(float time)
{
	motor[LUDriving] = -80;
	motor[LDDriving] = -80;
	motor[RUDriving] = 80;
	motor[RDDriving] = 80;
	delay(time);
	endDrive();
}
void turnRight(float time)
{
	motor[LUDriving] = 80;
	motor[LDDriving] = 80;
	motor[RUDriving] = -80;
	motor[RDDriving] = -80;
	delay(time);
	endDrive();
}

void pre_auton()
{
  bStopTasksBetweenModes = true;
}
task autonomous()
{
	moveForward(1200);
	moveBackward(1200);
}
task usercontrol()
{
  while (true)
  {
    //Driving
		motor[LUDriving] = vexRT[Ch3];
		motor[LDDriving] = vexRT[Ch3];
		motor[RUDriving] = vexRT[Ch2];
		motor[RDDriving] = vexRT[Ch2];
		//Arm
		if (vexRT[Btn5U] == 1)
			{
				motor[LArm] = 80;
				motor[RArm] = 80;
			}
		else if (vexRT[Btn5D] == 1)
			{
				motor[LArm] = -10;
				motor[RArm] = -10;
			}
		else
			{
				motor[LArm] = 19;
				motor[RArm] = 19;
			}
			//Claw
		if (vexRT[Btn6D] == 1)
			{
				motor[LClaw] = -127;
				motor[RClaw] = -127;
			}
		else if (vexRT[Btn6U] == 1)
			{
				motor[LClaw] = 127;
				motor[RClaw] = 127;
			}
		else
			{
				motor[LClaw] = 0;
				motor[RClaw] = 0;
			}
	}
}
