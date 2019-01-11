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

/******************************************************************
 *                     Definition of functions                    *
 ******************************************************************/

void stopWheels() {
  leftWheel.write(wheelStopValue);
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

  delay(2000);

  leftWheel.write(leftWheelForwardValue);       // Moverse adelante
  rightWheel.write(rightWheelForwardValue);
  delay(2000);

  stopWheels();

  delay(1000);

  leftWheel.write(leftWheelForwardValue);       // Girar a derechas
  delay(2000);
  
  stopWheels();

  delay(1000);
  
  leftWheel.write(leftWheelBackwardsValue);     // Moverse atrás
  rightWheel.write(rightWheelBackwardsValue);
  delay(2000);

  stopWheels();

  delay(1000);

  rightWheel.write(rightWheelForwardValue);     // Girar a izquierdas
  delay(2000);
  
  stopWheels();
  
}
