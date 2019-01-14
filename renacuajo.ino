/*
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
#include <SoftwareSerial.h>


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

/* Definition of the values that can take continuous rotation servo,
  that is, the wheels */
#define wheelStopValue            90
#define leftWheelForwardValue     0
#define leftWheelBackwardsValue   180
#define rightWheelForwardValue    180
#define rightWheelBackwardsValue  0

/* Notas musicales */
#define SIB         247
#define DO          261
#define RE          294
#define RES         311
#define MI          330
#define FA          349
#define FAS         370
#define SOL         392
#define LAb         415
#define LA          440
#define SIb         466
#define SI          494
#define DOA         523
#define DOAS        554
#define REA         587

/* Duracion de las notas */
#define C           200    // corchea
#define CP  `       300    // corchea con puntillo
#define N           400    // negra
#define NP          600    // negra con puntillo
#define B           800    // blanca
#define BP          1200   // blanca con puntillo

/* Canciones */
int harryPotterNotas [ ] = {SIB, MI, SOL, FAS, MI, SI, LA, FAS, MI, SOL, FAS, RES, FAS, SIB,
                            SIB, MI, SOL, FAS, MI, SI, REA, DOAS, DOA, LAb, DOA, SI, SIb, SIB, SOL, MI,
                            SOL, SI, SOL, SI, SOL, DOA, SI, SIb, FAS, SOL, SI, SIb, SIB, RE, FAS, SI,
                            SOL, SI, SOL, SI, SOL, REA, DOAS, DOA, LAb, DOA, SI, SIb, SIB, SOL, MI
                           };
int harryPotterDuracion [ ] = {N, NP, C, N, B, N, BP, BP, NP, C, N, B, N, BP,
                               N, NP, C, N, B, N, B, N, B, N, NP, C, N, B, N, BP,
                               N, B, N, B, N, B, N, B, N, NP, C, N, NP, C, N, BP,
                               N, B, N, B, N, B, N, B, N, NP, C, N, B, N, BP
                              };
int happyBirthdayNotas [ ] = {DO, DO, RE, DO, FA, MI,
                              DO, DO, RE, DO, SOL, FA,
                              DO, DO, DOA, LA, FA, MI, RE,
                              SIb, SIb, LA, FA, SOL, FA
                             };
int happyBirthdayDuracion [ ] = {450, 150, 600, 600, 600, 1200,
                                 450, 150, 600, 600, 600, 1200,
                                 450, 150, 600, 600, 600, 600, 600,
                                 450, 150, 600, 600, 600, 1200
                                };


/* A object from Servo class is created for each servo */
Servo leftWheel;
Servo rightWheel;

/* A object from SoftwareSerial is created for the Bluetooth module */
SoftwareSerial BT(1, 0);    // Rx and Tx of the board

/* Variables */
bool buttonState = true;
int numTones = 7;
int tones[ ] = {261, 294, 330, 349, 392, 440, 494};
String B = ".";


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
  rightWheel.write(wheelStopValue);
  delay(10);
}

void moveForwards() {
  leftWheel.write(leftWheelForwardValue);
  rightWheel.write(rightWheelForwardValue);
  delay(10);
}

void moveBackwards() {
  leftWheel.write(leftWheelBackwardsValue);
  rightWheel.write(rightWheelBackwardsValue);
  delay(10);
}

void moveLeft() {
  leftWheel.write(wheelStopValue);
  rightWheel.write(rightWheelForwardValue);
  delay(10);
}

void moveRight() {
  leftWheel.write(leftWheelForwardValue);
  rightWheel.write(wheelStopValue);
  delay(10);
}

void happyBirthday() {

  int i = 0;
  int j = 0;
  for (i = 0; i < 25; i = i + 1) {
    tone(pinBuzzer, happyBirthdayNotas[i]);
    delay(happyBirthdayDuracion[j]);
    j = j + 1;
  }
  silencioNegra(pinBuzzer);
}

void harryPotter () {

  int i = 0;
  int j = 0;
  for (i = 0; i < 61; i = i + 1) {
    tone(pinBuzzer, harryPotterNotas[i]);
    delay(harryPotterDuracion[j]);
    j = j + 1;
    if (i == 13 || i == 29 || i == 45 || i == 60 ) {
      silencioBlanca(pinBuzzer);
    }
  }
}

void silencioNegra (int pin) {
  noTone(pin);
  delay(N);
}

void silencioBlanca (int pin) {
  silencioNegra(pin);
  silencioNegra(pin);
}

String GetLineBT() {
  String S = "" ;
  if (BT.available()){
    char c = BT.read();
    while ( c != '\r' ) {
      S = S + c;
      delay(25);
      c = BT.read();
    }
    return ( S );
  }
}

/******************************************************************
                               Setup
 ******************************************************************/

void setup() {
  
  pinMode(pinBuzzer, OUTPUT);
  leftWheel.attach(pinLeftWheel);
  rightWheel.attach(pinRightWheel);

  BT.begin(9600);
  
  stopWheels();

  delay(5000);

  harryPotter();
  happyBirthday();
  
}

/******************************************************************
                         Main program loop
 ******************************************************************/

void loop() {

  rightIR = digitalRead(pinRightIR);
  leftIR = digitalRead(pinLeftIR);
  
    if (BT.available()){
      B = GetLineBT();
    }

    if (B=="W"){
      moveForwards();
      delay(200);
    }

  if (buttonState) {
    buttonState = digitalRead(pinButton);
  }
  else {                                          // Main routine. Only executed
    if (rightIR == BLACK) {                        // after pressing the button.
      leftWheel.write(leftWheelForwardValue);
      delay(10);
      if (leftIR == WHITE) {
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
}

/*  Movement test subroutine
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


/* Buzzer test subroutine
  delay(5000);
  for (int i = 0; i < numTones; i++) {
  tone(pinBuzzer, tones[i]);
  delay(500);
  }
  noTone(pinBuzzer);
*/

