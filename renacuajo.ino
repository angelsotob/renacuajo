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
#define pinBuzzer       13

/* Definition of the values ​​that can take continuous rotation servo,
 that is, the wheels */
#define wheelStopValue            90
#define leftWheelForwardValue     0
#define leftWheelBackwardsValue   180
#define rightWheelForwardValue    180
#define rightWheelBackwardsValue  0

/* Notas musicales */
#define DO    261
#define RE    294
#define MI    330
#define FA    349
#define SOL   392
#define LA    440
#define SI    494
#define DOalto   523
#define SIb   466

/* A object from Servo class is created for each servo */
Servo leftWheel;
Servo rightWheel;

/* Variables */
bool buttonState = true;
int numTones = 7;
int tones[ ] = {261, 294, 330, 349, 392, 440, 494};

/* Variables of the line follower */
int rightIR;
int leftIR;
int BLACK = 0;
int WHITE = 1;

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

void happyBirthday(){

  tone(pinBuzzer, DO);
  delay(450);
  noTone(pinBuzzer);
  tone(pinBuzzer, DO);
  delay(150);
  tone(pinBuzzer, RE);
  delay(600);
  tone(pinBuzzer, DO);
  delay(600);
  tone(pinBuzzer, FA);
  delay(600);
  tone(pinBuzzer, MI);
  delay(1200);

  tone(pinBuzzer, DO);
  delay(450);
  noTone(pinBuzzer);
  tone(pinBuzzer, DO);
  delay(150);
  tone(pinBuzzer, RE);
  delay(600);
  tone(pinBuzzer, DO);
  delay(600);
  tone(pinBuzzer, SOL);
  delay(600);
  tone(pinBuzzer, FA);
  delay(1200);

  tone(pinBuzzer, DO);
  delay(450);
  noTone(pinBuzzer);
  tone(pinBuzzer, DO);
  delay(150);
  tone(pinBuzzer, DOalto);
  delay(600);
  tone(pinBuzzer, LA);
  delay(600);
  tone(pinBuzzer, FA);
  delay(600);
  tone(pinBuzzer, MI);
  delay(600);
  tone(pinBuzzer, RE);
  delay(600);

  tone(pinBuzzer, SIb);
  delay(450);
  noTone(pinBuzzer);
  tone(pinBuzzer, SIb);
  delay(150);
  tone(pinBuzzer, LA);
  delay(600);
  tone(pinBuzzer, FA);
  delay(600);
  tone(pinBuzzer, SOL);
  delay(600);
  tone(pinBuzzer, FA);
  delay(1200);

  noTone(pinBuzzer);
}


/******************************************************************
 *                             Setup                              *
 ******************************************************************/
 
void setup() {

  pinMode(pinBuzzer, OUTPUT);
  leftWheel.attach(pinLeftWheel);
  rightWheel.attach(pinRightWheel);

  stopWheels();

  /* Buzzer test subroutine
  delay(5000);
  for (int i = 0; i < numTones; i++) {
    tone(pinBuzzer, tones[i]);
    delay(500);
    }
  noTone(pinBuzzer);
  */

  delay(5000);

  

  happyBirthday();
}


/******************************************************************
 *                       Main program loop                        *
 ******************************************************************/

void loop() {
  
    rightIR = digitalRead(pinRightIR);
    leftIR = digitalRead(pinLeftIR);

    if (buttonState) {
      buttonState = digitalRead(pinButton);
    }
    else{                                           // Main routine. Only executed
     if (rightIR == BLACK){                         // after pressing the button.
        leftWheel.write(leftWheelForwardValue);
        delay(10);
        if (leftIR == WHITE){
          rightWheel.write(wheelStopValue);
          delay(10);
        }
        else {
          rightWheel.write(rightWheelForwardValue);
          delay(10);
        }
        delay(50);
      }
      else {
        moveLeft();
        delay(50);
      }
    }
    
    

/* Movement test subroutine
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
*/

}
