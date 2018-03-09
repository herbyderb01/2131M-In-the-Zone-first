#pragma config(Sensor, in1,    mobileP,        sensorPotentiometer)
#pragma config(Sensor, in2,    liftP,          sensorPotentiometer)
#pragma config(Sensor, in3,    selectP,        sensorPotentiometer)
#pragma config(Sensor, in4,    Gyro,           sensorGyro)
#pragma config(Sensor, in5,    ,               sensorPotentiometer)
#pragma config(Sensor, in6,    selecttwoP,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           DriveR,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           FourBar,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           INtake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           liftL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           liftR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           MobileR,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           MobileL,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RDrive,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          DriveL,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)
// Select Download method as "competition"
#pragma competitionControl(Competition)
//Main competition .background code...do not modify!
#include "Vex_Competition_Includes.c"
//include both Void programs, and PID
#include "BackOver Functions 2017-18.c"
#include "AutonTasks.c"
#include "Turn PID.c"
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void pre_auton()
{
	SensorValue[rightEncoder] = 0;  ///
  SensorValue[leftEncoder] = 0;   ///  Making sure to clear all values
	SensorValue[Gyro] = 0;					///
  bStopTasksBetweenModes = true;  ///
  /*
	for(int i = 0; i<2000; i++)
	{
		cumBias += SensorValue[Gyro];
		wait1Msec(1);
	}
	debug = cumBias / 2000;*/
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
task autonomous()
{/*
	SensorBias[Gyro] = 1743;

	SensorScale[Gyro] = debug;

	TurnPID(900,true);
	wait1Msec(1000);
	TurnPID(900,true);
	wait1Msec(1000);
	TurnPID(900,true);
	wait1Msec(1000);
	TurnPID(900,true);
	wait1Msec(1000);*/



	startTask(liftRController);    //Start Lift PID
	startTask(mobileRController);  //Start Mobile PID
	liftRSensorCurrentValue = SensorValue[ liftP ];
	//SensorBias[Gyro] = 249;

	//SensorScale[Gyro] = 144;
	SkillsTwo();
/*
	if (SensorValue[selecttwoP] > 300 && SensorValue[selecttwoP] < 1795) //=========== Score 5's ==========//
	{
			if (SensorValue[selectP] < 15)
			{
				RightFive();
			}
			if (SensorValue[selectP] > 15 && SensorValue[selectP] < 575)
			{
				LeftFive();
			}
			if (SensorValue[selectP] > 575 && SensorValue[selectP] < 1185)
			{

			}
			if (SensorValue[selectP] > 1185 && SensorValue[selectP] < 1780)
			{

			}
			if (SensorValue[selectP] > 1780 && SensorValue[selectP] < 2410)
			{

			}
			if (SensorValue[selectP] > 2410 && SensorValue[selectP] < 3110)
			{

			}
			if (SensorValue[selectP] > 3110 && SensorValue[selectP] < 4094)
			{

			}
			if (SensorValue[selectP] == 4095)
			{

			}

	}
	if (SensorValue[selecttwoP] > 1795 && SensorValue[selecttwoP] < 3530) //=========== Score 10's ==========//
	{
			if (SensorValue[selectP] < 15)
			{
				RightBTen();
			}
			if (SensorValue[selectP] > 15 && SensorValue[selectP] < 575)
			{
				LeftTen();
			}
			if (SensorValue[selectP] > 575 && SensorValue[selectP] < 1185)
			{

			}
			if (SensorValue[selectP] > 1185 && SensorValue[selectP] < 1780)
			{

			}
			if (SensorValue[selectP] > 1780 && SensorValue[selectP] < 2410)
			{

			}
			if (SensorValue[selectP] > 2410 && SensorValue[selectP] < 3110)
			{

			}
			if (SensorValue[selectP] > 3110 && SensorValue[selectP] < 4094)
			{

			}
			if (SensorValue[selectP] == 4095)
			{

			}

	}
	if (SensorValue[selecttwoP] > 3530) //=========== Score 20's ==========//
	{
			if (SensorValue[selectP] < 15)
			{
				RightTwenty();
			}
			if (SensorValue[selectP] > 15 && SensorValue[selectP] < 575)
			{
				LeftTwenty();
			}
			if (SensorValue[selectP] > 575 && SensorValue[selectP] < 1185)
			{

			}
			if (SensorValue[selectP] > 1185 && SensorValue[selectP] < 1780)
			{

			}
			if (SensorValue[selectP] > 1780 && SensorValue[selectP] < 2410)
			{

			}
			if (SensorValue[selectP] > 2410 && SensorValue[selectP] < 3110)
			{

			}
			if (SensorValue[selectP] > 3110 && SensorValue[selectP] < 4094)
			{

			}
			if (SensorValue[selectP] == 4095)
			{

			}

	}
	if (SensorValue[selecttwoP] < 300) //=========== Score Special's ==========//
	{
			if (SensorValue[selectP] < 15)
			{
				SkillsOne();
			}
			if (SensorValue[selectP] > 15 && SensorValue[selectP] < 575)
			{
				SkillsTwo();
			}
			if (SensorValue[selectP] > 575 && SensorValue[selectP] < 1185)
			{

			}
			if (SensorValue[selectP] > 1185 && SensorValue[selectP] < 1780)
			{

			}
			if (SensorValue[selectP] > 1780 && SensorValue[selectP] < 2410)
			{
				DoNothing();
			}
			if (SensorValue[selectP] > 2410 && SensorValue[selectP] < 3110)
			{
				SpecialAton();
			}
			if (SensorValue[selectP] > 3110 && SensorValue[selectP] < 4094)
			{
				DefensiveTwo();
			}
			if (SensorValue[selectP] == 4095)
			{
				Defensive();
			}
	}*/
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/
task usercontrol()
{
startTask(drive);
setFourBarPower(20);

	while (3.1415926535897932384626433832795028841971==3.1415926535897932384626433832795028841971)
  //starting while loop to always run during userconroll
	{
		if (vexRT[Btn7L]==0)																	//
		{																											//
		usertoggle=1;																					//
		}																											//
		if (vexRT[Btn7L]==1 && skillsVar==1 && usertoggle==1) //
		{																											//  USER CONTROL TOGGLE
			skillsVar=0;																				//		- To switch between
			usertoggle=0;																				//			our two different
		}																											//			modes
		if (vexRT[Btn7L]==1 && skillsVar==0 && usertoggle==1)	//
		{																											//
			skillsVar=1;																				//
			usertoggle=0;																				//
		}																											//

	//=========================Normal Match Control===========================//
	if (skillsVar == 0)
	{
    if (initalize==0)																			// To Initalize Normal
    {																											// match Code
      stopTask(liftRController);
      setFourBarPower(20);
    }
    initalize=1;

	//----------------------Lift Controll------------------------//

		if( vexRT[Btn5D] == 1)      // Setting Btn5D to lift Down
		{
			setLiftPower(-127);
			liftstillspeed=-15;
		}

		else if( vexRT[Btn5U] == 1)      // Setting Btn5U to lift Up
		{
			setLiftPower(127);
			liftstillspeed=15;
		}

		else if( vexRT[Btn5DXmtr2] == 1)      // Setting Btn5D on Secondary to lift Down
		{
			setLiftPower(-127);
			liftstillspeed=-15;
		}

		else if( vexRT[Btn5UXmtr2] == 1)      // Setting Btn5U on Secondary to lift Up
		{
			setLiftPower(127);
			liftstillspeed=15;
		}

		else
		{
			setLiftPower(liftstillspeed);	// Setting the Still Speed when no commands
		}

	//----------------------Intake Control------------------------//

		if( vexRT[Btn6U] == 1)      // Setting Btn 6U to Intake Cone
		{
			startTask(IntakeCone);
		}

		else if( vexRT[Btn6D] == 1)      // Setting Btn6D to Outtake Cone
		{
			startTask(OutakeCone);
		}

		else if( vexRT[Btn8LXmtr2] == 1)      // Setting Btn 6U to Intake Cone
		{
			startTask(IntakeCone);
		}
		else if( vexRT[Btn8DXmtr2] == 1)      // Setting Btn6D to Outtake Cone
		{
			startTask(OutakeCone);
		}

		//----------------------Moblie Goal Lift------------------------//
		if( vexRT[Btn7U] == 1)      // Setting Btn7U to Extend Goal
		{
				setMobilePower(127);
				mobilestillspeed=15;
		}

		else if( vexRT[Btn7D] == 1)      // Setting Btn7D to Intake Goal
		{
				setMobilePower(-127);
				mobilestillspeed=-15;
		}/*
		else if( vexRT[Btn6UXmtr2] == 1)      // Setting Btn 6U to Intake Cone
		{
			setMobilePower(-127);
		}
		else if( vexRT[Btn6DXmtr2] == 1)      // Setting Btn 6U to Intake Cone
		{
			setMobilePower(127);
		}
		else if( vexRT[Btn5UXmtr2] == 1)      // Setting Btn 6U to Intake Cone
		{
			setMobilePower(-64);
		}
		else if( vexRT[Btn5DXmtr2] == 1)      // Setting Btn 6U to Intake Cone
		{
			setMobilePower(64);
		}
		*/
		else
		{
			setMobilePower(mobilestillspeed);// Setting the Still Speed when no commands
		}

		//----------------------Four Bar Control ------------------------//
		if( vexRT[Btn8D] == 1)      // Setting Btn8D to Extend Four Bar
		{
			setFourBarPower(127);
			FourBarstillspeed=20;
		}

		else if( vexRT[Btn8R] == 1)      // Setting Btn8R to bring in Four Bar
		{
			setFourBarPower(-127);
			FourBarstillspeed=-20;
		}
		else if( vexRT[Btn6DXmtr2] == 1) // Setting Btn8D on 2nd to Extend Four Bar
		{
			setFourBarPower(127);
			FourBarstillspeed=20;
		}

		else if( vexRT[Btn6UXmtr2] == 1)// Setting Btn8D on 2nd to bring in Four Bar
		{
			setFourBarPower(-127);
			FourBarstillspeed=-20;
		}

		else
		{
			setFourBarPower(FourBarstillspeed);// Setting the Still Speed when no commands
		}

//-=-=-=-==-=-=-=--=-=-Auto Stacking-=-=-=-=-=-=-=-=-=-=-=//

	if (vexRT[Btn7DXmtr2] == 1)
	{
		if(curentteir == 1)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightOneTwo-300;
					wait1Msec(240);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightOneTwo+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightOneTwo;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 2)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightOneTwo-300;
					wait1Msec(240);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightOneTwo+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightOneTwo;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 3)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightThree-300;
					wait1Msec(240);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightThree+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightThree;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 4)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightFour-300;
					wait1Msec(240);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightFour+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightFour;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 5)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightFive-300;
					wait1Msec(240);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightFive+300;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightFive;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 6)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightSix-300;
					wait1Msec(240);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightSix+320;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightSix;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 7)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightSeven-300;
					wait1Msec(260);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightSeven+250;
					wait1Msec(550);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightSeven;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 8)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightEight-300;
					wait1Msec(260);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightEight+350;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightEight;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 9)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightNine-310;
					wait1Msec(270);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightNine+320;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightNine;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 10)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightTen-320;
					wait1Msec(300);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightTen+340;
					wait1Msec(530);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightTen;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 11)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightEleven-320;
					wait1Msec(310);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightEleven+400;
					wait1Msec(560);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightEleven;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 12)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightTwelve-300;
					wait1Msec(320);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightTwelve+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightTwelve;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 13)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightThirteen-300;
					wait1Msec(330);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightThirteen+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightThirteen;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 14)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightFourteen-300;
					wait1Msec(340);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightFourteen+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightFourteen;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}

		if(curentteir == 15)
		{
			startTask(liftRController);

					setIntakePower(127);
					wait1Msec(250);
					setIntakePower(10);
					wait1Msec(100);

					liftRRequestedValue = teirHeightFifteen-300;
					wait1Msec(350);
					setFourBarPower(127);
					liftRRequestedValue = teirHeightFifteen+200;
					wait1Msec(500);
					setFourBarPower(15);

					setIntakePower(-127);
					liftRRequestedValue = teirHeightFifteen;
					wait1Msec(300);
					setIntakePower(-10);

					setFourBarPower(-127);
					wait1Msec(500);
					setFourBarPower(-10);

			stopTask(liftRController);
		}
		curentteir++;
	}

	if (vexRT[Btn7LXmtr2] == 1 && stackReadyAdd == true)
	{
		curentteir++;
		stackReadyAdd = false;
	}
		else if (vexRT[Btn7LXmtr2] == 0)
	{
		stackReadyAdd = true;
	}
	if (vexRT[Btn7RXmtr2] == 1 && stackReadySubtract == true)
	{
		curentteir--;
		stackReadySubtract = false;
	}
		else if (vexRT[Btn7RXmtr2] == 0)
	{
		stackReadySubtract = true;
	}

	if (vexRT[Btn7UXmtr2] == 1)
	{
		curentteir = 1;
	}

}
//-=-=-=-==-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

//===========================================================================//

  if (skillsVar == 1)
  //--------------------------Specialties-Contol----------------------------//
  {
    if (initalize==1)															//
    {																							//
      startTask(liftRController);									//   SPECIALTIES CONTOLL
      liftRRequestedValue=SkillsLift;										//		TOGGLE
     	setFourBarPower(127);													//
			wait1Msec(200);															//
			setFourBarPower(15);													//


    }

    initalize=0;																	// initalize for toggle

    //---------------------PreLoad Task-----------------------------//
    if (vexRT[Btn5U] == 1)
    {
    	startTask(OutakePreload);
    }
    //--------------------Simple Auto Stack-------------------------//
    if (vexRT[Btn5D] == 1)
    {
    	startTask(AutoStackUpSimple);
    }

			//----------------------Moblie Goal Lift------------------------//
			if( vexRT[Btn6U] == 1)      // Setting Btn6U to Extend Goal
			{
				setMobilePower(127);
				mobilestillspeed=15;
			}

			else if( vexRT[Btn6D] == 1)      // Setting Btn6D to Intake Goal
			{
				setMobilePower(-127);
				mobilestillspeed=-15;
			}
			else
			{
				setMobilePower(mobilestillspeed);      // Else, stop mobile motors
			}
    }
	}
}
