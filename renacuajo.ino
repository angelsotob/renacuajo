/*  
 *
 *     ********************************************************
 *     ********************************************************
 *     ***                                                  ***
 *     ***                  Renacuajo                       ***
 *     ***                                                  ***
 *     ******************************************************** 
 *     ********************************************************
 *
 *    Arduino code for the renacuajo robot.
 *     
 *   ****************************************************
 *   * Fecha: 11/01/2019                                *
 *   * Autor: Angel Soto Boullosa                       *
 *   * Mail: angelsotob@outlook.es                      *
 *   * Licencia: MIT License                            *
 *   ****************************************************
 */

/******************************************************************/
/******************************************************************/




/******************************************************************
 *                           Libraries                            *
 ******************************************************************/ 

#include <Servo.h>


/******************************************************************
 *                    Definition of variables                     *
 ******************************************************************/

/* Pin definition of the board to be used */
#define pinLeftWheel    6
#define pinRightWheel   9
#define pinLeftIR       2
#define pinRightIR      3
#define pinButton       4     // The button is active down

/* Definition of the values ​​that can take continuous rotation servo,
 that is, the wheels */
#define wheelStopValue            90
#define leftWheelForwardValue     0
#define leftWheelBackwardsValue   180
#define rightWheelForwardValue    180
#define rightWheelBackwardsValue  0

/* A object from Servo class is created for each servo */
Servo leftWheel;
Servo rightWheel;

/* Variables */
int buttonState = 1;

/******************************************************************
 *                     Definition of functions                    *
 ******************************************************************/

void stopWheels() {
  leftWheel.write(wheelStopValue);
  delay(10);

  rightWheel.write(wheelStopValue);
  delay(10);
}

void moveForwards() {
  leftWheel.write(leftWheelForwardValue);
  delay(10);
  
  rightWheel.write(rightWheelForwardValue);
  delay(10);
}

void moveBackwards() {
  leftWheel.write(leftWheelBackwardsValue);
  delay(10);
  
  rightWheel.write(rightWheelBackwardsValue);
  delay(10);
}

void moveLeft() {
  leftWheel.write(wheelStopValue);
  delay(10);
  
  rightWheel.write(rightWheelForwardValue);
  delay(10);
}

void moveRight() {
  leftWheel.write(leftWheelForwardValue);
  delay(10);
  
  rightWheel.write(wheelStopValue);
  delay(10);
}


/******************************************************************
 *                             Setup                              *
 ******************************************************************/
 
void setup() {

  leftWheel.attach(pinLeftWheel);
  rightWheel.attach(pinRightWheel);

  stopWheels();
}


/******************************************************************
 *                       Main program loop                        *
 ******************************************************************/

void loop() {

  buttonState = digitalRead(pinButton);

  if (buttonState == 0) {
  
  delay(2000);

  moveForwards();
  delay(2000);

  stopWheels();

  delay(1000);

  moveRight();
  delay(2000);
  
  stopWheels();

  delay(1000);
  
  moveBackwards();
  delay(2000);

  stopWheels();

  delay(1000);

  moveLeft();
  delay(2000);
  
  stopWheels();
  }
  
}
