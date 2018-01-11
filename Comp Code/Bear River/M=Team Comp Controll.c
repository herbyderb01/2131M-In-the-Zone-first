#pragma config(Sensor, in1,    liftP,          sensorPotentiometer)
#pragma config(Sensor, in2,    chainP,         sensorPotentiometer)
#pragma config(Sensor, in3,    selectP,        sensorPotentiometer)
#pragma config(Sensor, in4,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           INtake,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           liftR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           liftL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           MobileL,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           MobileR,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           chainR,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           chainL,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RDrive,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LDrive,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

//include both Void defining, and PID

#include "BackOver Functions 2017-18.c"
#include "AutonTasks.c"

int liftstillspeed; //define the liftstillspeed
int manual;



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  bStopTasksBetweenModes = true;

}

///////////////////////////Tasks/////////////////////////////////
/////////////////--------/////////------/////////////////////////

task drive() //Redirecting Drive into a task
{
	while (true)
	{
		setDrivePower(vexRT[Ch3], vexRT[Ch2]);
	}
wait1Msec(25);
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */

/*                                                                           */
/*---------------------------------------------------------------------------*/

task autonomous()
{

	startTask(chainRController);
	startTask(liftRController);
	liftRSensorCurrentValue = SensorValue[ liftP ];

	/*
	SensorType[Gyro] = sensorNone;
	wait1Msec(500);
	SensorType[Gyro] = sensorGyro;
	SensorScale[Gyro] = 125;
	SensorFullCount[Gyro] = 3600;
	wait1Msec(2000);
*/
	if (SensorValue[selectP] == 0) // Defensive
	{
		startTask(Defensive);
	}
	if (SensorValue[selectP] > 1 && SensorValue[selectP] < 575) // Right Blue
	{
		startTask(RightBlue);
	}

	if (SensorValue[selectP] > 575 && SensorValue[selectP] < 1185) //Left Blue
	{
		startTask(LeftBlue);
	}

	if (SensorValue[selectP] > 1185 && SensorValue[selectP] < 1780)//Skils 1
	{
		startTask(SkillsOne);
	}

	if (SensorValue[selectP] > 1780 && SensorValue[selectP] < 2410)//Skills 2
	{
		startTask(SkillsTwo);
	}

	if (SensorValue[selectP] > 2410 && SensorValue[selectP] < 3110)//Left Red
	{
		startTask(LeftRed);
	}

	if (SensorValue[selectP] > 3110 && SensorValue[selectP] < 4094)//Right Red
	{
		startTask(RightRed);
	}

	if (SensorValue[selectP] == 4095)//Do Nothing
	{
		startTask(DoNothing);
	}

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task usercontrol()
{

startTask(chainRController); //Start Chain PID
startTask(drive);
startTask(liftRController);  //Start Lift PID
//manual = 1;
  while (true) //starting while loop to always run during userconroll
	{
/*
		if ( manual== 1 && Btn7R==1)
		{
		manual = 0;
		while(Btn7R==1);
		}
		if ( manual== 0 && Btn7R==1)
		{
		manual = 1;
		while(Btn7R==1);
		}
*/

	//----------------------Lift Controll------------------------//

		if( vexRT[Btn5D] == 1   )      // Setting Btn5D to lift Down
		{
			setLiftPower(-127);
			liftstillspeed=-15;
		}

		else if( vexRT[Btn5U] == 1)      // Setting Btn5U to lift Up
		{
			setLiftPower(127);
			liftstillspeed=-10;
		}
		//still speeds
		else if (SensorValue[liftP] < 2500 ) // Setting still speeds to keep lift at constant value
		{
			setLiftPower(10);
		}
		else
		{
			setLiftPower(liftstillspeed);
		}

	//----------------------Intake Control------------------------//

		if( vexRT[Btn6U] == 1)      // Setting Btn 6U to Intake Cone
		{
			setIntakePower(127);
		}

		else if( vexRT[Btn6D] == 1)      // Setting Btn6D to Outtake Cone
		{
			setIntakePower(-127);
		}

		else
		{
			setIntakePower(40);   // Else, set a intake still speed to hold cone in
		}

		//----------------------Moblie Goal Lift------------------------//
		if( vexRT[Btn7U] == 1)      // Setting Btn7U to Extend Goal
		{
			setMobilePower(127);
		}

		else if( vexRT[Btn7D] == 1)      // Setting Btn7D to Intake Goal
		{
			setMobilePower(-127);
		}

		else
		{
			setMobilePower(0);      // Else, stop mobile motors
		}

		//----------------------PIV Control with PID------------------------//
		if( vexRT[Btn8D] == 1)      // Setting Btn8D PID, to Strait Up
		{
			chainRRequestedValue = 1290;
		}

		else if( vexRT[Btn8R] == 1)      // Setting Btn8R PID, to Out Position
		{

			chainRRequestedValue = 2955;
		}

		else if( vexRT[Btn8L] == 1)      // Setting Btn8L PID, to Stationary Position
		{
			chainRRequestedValue = 1790;
		}
		else if( vexRT[Btn8U] == 1)      // Setting Btn8U PID, to In Position
		{
			chainRRequestedValue = 220;
		}
	}
}