#include <ADXL345.h>
#include <Wire.h>
/*
  int pin1 = 6;
  int pin2 = 7;
  int pin3 = 8;
  int pin4 = 9;
  int pin5 = 10;
  int pin6 = 11;
  int pin7 = 12;
*/

int PIN = 12;
int pButtonState;
int buttonState = 0;

int val;
int pinval;
int ppinval;
int counter = 0;

ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

void setup() {
  Serial.begin(9600);
  adxl.powerOn();

  //set activity/ inactivity thresholds (0-255)
  adxl.setActivityThreshold(75); //62.5mg per increment
  adxl.setInactivityThreshold(75); //62.5mg per increment
  adxl.setTimeInactivity(10); // how many seconds of no activity is inactive?

  //look of activity movement on this axes - 1 == on; 0 == off
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);

  //look of inactivity movement on this axes - 1 == on; 0 == off
  adxl.setInactivityX(1);
  adxl.setInactivityY(1);
  adxl.setInactivityZ(1);

  //look of tap movement on this axes - 1 == on; 0 == off
  adxl.setTapDetectionOnX(0);
  adxl.setTapDetectionOnY(0);
  adxl.setTapDetectionOnZ(1);

  //set values for what is a tap, and what is a double tap (0-255)
  adxl.setTapThreshold(50); //62.5mg per increment
  adxl.setTapDuration(15); //625us per increment
  adxl.setDoubleTapLatency(80); //1.25ms per increment
  adxl.setDoubleTapWindow(200); //1.25ms per increment

  //set values for what is considered freefall (0-255)
  adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment

  //setting all interrupts to take place on int pin 1
  //I had issues with int pin 2, was unable to reset it
  adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,    ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,     ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,   ADXL345_INT1_PIN );

  //register interrupt actions - 1 == on; 0 == off
  adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT,  1);
  adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,   1);
  adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 1);

}

void loop() {
  //Boring accelerometer stuff
  int x, y, z;
  int Y;
  if (val > 870 && val < 890) {
    counter ++;
  }
  adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z

  double xyz[3];
  double ax, ay, az;
  adxl.getAcceleration(xyz);

  ay = xyz[1];

  pButtonState = buttonState;

  buttonState = digitalRead(PIN);

  val = analogRead(A0);

  // Serial.println(val);


  ppinval = pinval;

    if (counter % 2 == 1) {

      if (ay > 0) {

        if (val > 540 && val < 560) {
          Serial.println(11);
          pinval = 11;
        }
        if (val > 590 && val < 620) {
          Serial.println(21);
          pinval = 21;
        }
        if (val > 670 && val < 690) {
          Serial.println(31);
          pinval = 31;
        }
        if (val > 750 && val < 770) {
          Serial.println(41);
          pinval = 41;
        }
        else
        {
          //   Serial.println("out");
        }
      }

      if (ay < 0) {

        if (val > 540 && val < 560) {
          Serial.println(12);
          //  pinval = 12;
        }
        if (val > 590 && val < 620) {
          Serial.println(22);
          pinval = 22;
        }
        if (val > 670 && val < 690) {
          Serial.println(32);
          pinval = 32;
        }
        if (val > 750 && val < 770) {
          Serial.println(42);
          pinval = 42;
        }
        else {
          //   Serial.println("out");
        }
      }
    }
    if (counter % 2 == 0) {

      if (val > 540 && val < 560) {
        Serial.println(13);
        //  pinval = 13;
      }
      if (val > 590 && val < 620) {
        Serial.println(23);
        pinval = 23;
      }
      if (val > 670 && val < 690) {
        Serial.println(33);
        pinval = 33;
      }
      if (val > 750 && val < 770) {
        Serial.println(43);
        pinval = 43;
      }
    }
    delay(200);
  } 



