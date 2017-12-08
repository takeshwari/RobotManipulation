#pragma config(StandardModel, "EV3_REMBOT")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
This program assumes you are using the standard LEGO Education robot
Sensor Ports:
S1 = Touch
S2 = Gyro
S3 = Color
S4 = Sonar (Ultrasonic)

Motor Ports:
A = Arm Motor
B = Right Motor
C = Left Motor
*/

 int encoderLine1;
 int encoderLine2;
 int height;
 float distanceLine1;
 float distanceLine2;



 //method move forward until no color is detected or if already in no color zone, till color is detected
void moveForward(){
resetMotorEncoder(leftMotor);
resetMotorEncoder(rightMotor);

setMotorSpeed(leftMotor, 30);
setMotorSpeed(rightMotor, 30);

//waitUntil(getColorName(colorSensor)!= colorNone );
waitUntil(SensorValue[S4]<15 );
setMotorSpeed(leftMotor, 0);
setMotorSpeed(rightMotor, 0);
 sleep(1000);

resetMotorEncoder(leftMotor);
resetMotorEncoder(rightMotor);
setMotorSpeed(leftMotor, 30);
setMotorSpeed(rightMotor, 30);

//waitUntil( getColorName(colorSensor)== colorNone);
waitUntil(SensorValue[S4]>15 );
setMotorSpeed(leftMotor, 0);
setMotorSpeed(rightMotor, 0);
}


//function to recieve height
int getHeight(int height){
displayBigTextLine(4, "height: %d", height);
//while enter is not pressed, obtain height from user
while(getButtonPress(buttonEnter) == 0)
	{
			if(getButtonPress(buttonUp) == 1 & getButtonPress(buttonDown) ==0 )
			{
			height= height +1;
	  	displayBigTextLine(4, "height: %d", height);
	  	}

		  else if(getButtonPress(buttonDown) ==1 & getButtonPress(buttonUp) == 0)
		  {
		  	height= height -1;
				displayBigTextLine(4, "height: %d", height); }

			wait1Msec(450);
	}return height; }


//function to convert encoderCounts to CM
float encoderToCM(int encoderCounts){
	return ((encoderCounts/360.0)* (5.6 *PI)-1);
}


//function to turn robot left
void turnLeft(){
// make a turn using gyroSensor
	resetGyro(gyroSensor);
	setMotorSpeed(motorC, 20);
	setMotorSpeed(motorB, -20);
	waitUntil(getGyroDegrees(gyroSensor)< -85 );
	setMotorSpeed(motorC, 0);
	setMotorSpeed(motorB, 0);

	}


	//Last display function to display volume, two distances found
void DisplayFinal( float distance1, float distance2, int height){
float volume = distance1*distance2* height;
 while(getButtonPress(buttonEnter) == 0){
   			setLEDColor(ledRed);
 displayBigTextLine(3, "1: %.2f", distance1);
 displayBigTextLine(5, "2: %.2f", distance2);
 displayBigTextLine(7, "V: %.2f", volume );
} }


//sound to signal end
void endSound(){
	playTone(600, 20);
	while(bSoundActive)
		sleep(1);
}



	task main()
{

//input height using buttons and begin program
height=10;
height = getHeight(height);
 eraseDisplay();

//move forward to measure side 1
 moveForward();
  // use encoder to calculate distance traveled
 encoderLine1= getMotorEncoder(leftMotor);

// get distance traveled in CM
 distanceLine1= encoderToCM(encoderLine1)-5;

 //edge ahead for turn
 setMotorSpeed(leftMotor, 30);
 setMotorSpeed(rightMotor, 30);
 wait1Msec(100);

 //turn robot
	turnLeft();

	//move forward to measure side 2
	moveForward();
	encoderLine2= getMotorEncoder(leftMotor);
	distanceLine2= encoderToCM(encoderLine2)-5;

	//finale sound & display values
 	endSound();
	DisplayFinal(distanceLine1, distanceLine2, height);

}
