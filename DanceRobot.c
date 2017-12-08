#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Motor,  motorA,          claw,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, driveRight, encoder)


task main()
{
//move forward for two seconds
	setMotorSpeed(left, 50);
	setMotorSpeed(right, 50);
	sleep(2000);

//move backward for two seconds
	setMotorSpeed(left, -50);
	setMotorSpeed(right, -50);
	sleep(2000);

//right turn for robot
	setMotorSpeed(left, -100);
	setMotorSpeed(right, 100);
	sleep(3000);

	//move backward for two seconds
	setMotorSpeed(left, -50);
	setMotorSpeed(right, -50);
	sleep(2000);

	//left turn for robot
	setMotorSpeed(left, 100);
	setMotorSpeed(right, -100);
	sleep(3000);

		setMotorSyncTime(left, right, 0, 1000, 50);
	sleep(1500);

	// This makes it go right (all power to left)
	setMotorSyncTime(left, right, 100, 1000, 50);
	sleep(1500);

	// This makes it go left (all power to right)
	setMotorSyncTime(left, right, -100, 1000, 50);
	sleep(1500);

	// This makes it go slow right (right motor turning at 50% of left one)
	setMotorSyncTime(left, right, 50, 1000, 50);
	sleep(1500);

	// This makes it go slow left (left motor turning at 50% of right one)
	setMotorSyncTime(left, right, -50, 1000, 50);
	sleep(1500);

		setMotorSpeed(left, 50);			//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(right, 50);  	//Set the rightMotor (motor6) to half power forward (50)
										//Wait for 1.5 seconds before continuing on in the program.

	// Move reverse at half power for 1.5 seconds
	setMotorSpeed(left, -100);			//Set the leftMotor (motor1) to half power reverse (100)
	setMotorSpeed(right, -100);  	//Set the rightMotor (motor6) to half power reverse (100)
											//Wait for 1.5 seconds before continuing on in the program.

	// Turn left at full power for 0.75 seconds
	setMotorSpeed(left, 100);		//Set the leftMotor (motor1) to full power forward (100)
	setMotorSpeed(right, -100);  //Set the rightMotor (motor6) to full power reverse (-100)
	sleep(750);

	setMotorSpeed(left, -100);
	setMotorSpeed(right, 100);
	sleep(3000);
}
