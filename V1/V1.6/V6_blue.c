#pragma config(Motor,  port4,           Door,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RClaw,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RDrive,        tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

void pre_auton()
{
  bStopTasksBetweenModes = true;
}

task autonomous()
{
	//Turn Right
	motor[LDrive] = 100;
	motor[RDrive] = 50;
	wait1Msec(3000);
	//Turn Left
	motor[LDrive] = 50;
	motor[RDrive] = 100;
	wait1Msec(3000);
	//Straight
	motor[LDrive] = 127;
	motor[RDrive] = 127;
	wait1Msec(3000);
}

task usercontrol()
{
	while(1==1)
	{
		motor[LDrive] = vexRT[Ch3];
		motor[RDrive] = vexRT[Ch2];
		if(vexRT[Btn6U] == 1)
		{
			motor[LClaw] = 127;
		}
		else
		{
			motor[LClaw] = 0;
		}
		if(vexRT[Btn5U] == 1)
		{
			motor[RClaw] = 127;
		}
		else
		{
			motor[RClaw] = 0;
		}
		if(vexRT[Btn8D] == 1)
		{
			motor[LClaw] = 127;
			motor[RClaw] = 127;
		}
		else(vexRT[Btn8D] == 0);
		{
			motor[LClaw] = 0;
			motor[RClaw] = 0;
		}
		if(vexRT[Btn7L] == 1)
		{
			motor[Door] = 127;
		}
		else(vexRT[Btn7L] == 0);
		{
			motor[Door] = 0;
		}
		if(vexRT[Btn7R] == 1)
		{
			motor[Door] = -127;
		}
		else(vexRT[Btn7R] == 0);
		{
			motor[Door] = 0;
		}
	}
}
