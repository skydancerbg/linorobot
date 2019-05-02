#ifndef LINO_BASE_CONFIG_H
#define LINO_BASE_CONFIG_H

//uncomment the base you're building
#define LINO_BASE DIFFERENTIAL_DRIVE // 2WD and Tracked robot w/ 2 motors
// #define LINO_BASE SKID_STEER      // 4WD robot
// #define LINO_BASE ACKERMANN       // Car-like steering robot w/ 2 motors
// #define LINO_BASE ACKERMANN1      // Car-like steering robot w/ 1 motor
// #define LINO_BASE MECANUM         // Mecanum drive robot

//uncomment the motor driver you're using
// #define USE_L298_DRIVER
#define USE_BTS7960_DRIVER
// #define USE_ESC

//uncomment the IMU you're using
// #define USE_GY85_IMU
// #define USE_GY91_IMU
// #define USE_MPU6050_IMU
// #define USE_MPU9150_IMU
#define USE_MPU9250_IMU

#define DEBUG 0

#define K_P 0.6 // P constant
#define K_I 0.3 // I constant
#define K_D 0.5 // D constant

//define your robot' specs here
#define MAX_RPM 95                // motor's maximum RPM - from Arlo motor mount document, should be the same
// Encoder resolution is 2.5 degrees per click, quadranture 36 position encoder on the drive shaft, 144 clicks per rev
#define COUNTS_PER_REV 144        // wheel encoder's no of ticks per rev 
#define WHEEL_DIAMETER 0.1524     // wheel's diameter in meters 6"*2.54=15.24cm from Eddie robot documentation
#define PWM_BITS 8                // PWM Resolution of the microcontroller -> doesent matter with BTS7960_DRIVER

// ??? check which distance is used in the calculations??? 
// measured on the robot outside to outside = 0.425
// between = 0.3615
// middle width to middle width = 0.3925
// for now we will be using the distance between the wheels --> 0.3615
#define LR_WHEELS_DISTANCE 0.3615  // distance between left and right wheels
#define FR_WHEELS_DISTANCE 0.30   // N/A-> distance between front and rear wheels. Ignore this if you're on 2WD/ACKERMANN
#define MAX_STEERING_ANGLE 0.415  // N/A-> max steering angle. This only applies to Ackermann steering

//=================BIGGER ROBOT SPEC (BTS7960)=============================
// #define K_P 0.05  // P constant
// #define K_I 0.9   // I constant
// #define K_D 0.1   // D constant

// define your robot' specs here
// #define MAX_RPM 45               // motor's maximum RPM
// #define COUNTS_PER_REV 4000      // wheel encoder's no of ticks per rev
// #define WHEEL_DIAMETER 0.15      // wheel's diameter in meters
// #define PWM_BITS 8               // PWM Resolution of the microcontroller
// #define LR_WHEELS_DISTANCE 0.32  // distance between left and right wheels
// #define FR_WHEELS_DISTANCE 0.38  // distance between front and back wheels. Ignore this if you're on 2WD/ACKERMANN
//================= END OF BIGGER ROBOT SPEC =============================


/*
PCB connectors wiring:

---------------------------------------------------------------------------------------------------------------------------

000 <-Encoder_connector GND +5V	MOTOR1_ENCODER_A/Pin 10             MOTOR2_ENCODER_B/Pin24  +5V GND Encoder_connector-> 000
000 <-Encoder_connector GND +5V MOTOR1_ENCODER_B/Pin 11             MOTOR2_ENCODER_A/Pin25  +5V GND Encoder_connector-> 000


00000 <-GY91_IMU_connector +5v free GND SCL/Pin19 SDA/Pin18    


BTS7960_conector (2-8)    BTS7960_conector (1-7)                           (1-7) BTS7960_conector    (2-8) BTS7960_conector
|                         |                                                                     |                         |
0 MOTOR1_IN_B/Pin6        0 MOTOR1_IN_A/Pin5                                MOTOR2_IN_A/Pin3    0       MOTOR2_IN_B/Pin4  0
0 +5V                     0 +5V                                                          +5V    0                    +5V  0
0 free                    0 free                                                        free    0                   free  0
0 GND                     0  +5v                                                          +5V   0                     GND 0

----------------------------------------------------------------------------------------------------------------------------

TEENSY 3.5 PINS USED: 

         PIN:            		    Function:
         0	  Placeholder---	  MOTOR3_PWM
         1	  Placeholder---	  MOTOR1_PWM
         2	  Placeholder---	  MOTOR4_PWM
         3	  Right motor	      MOTOR2_IN_A //actually it's signal B - for now A and B are switched manually at the BTS7960
         4	  Right motor	      MOTOR2_IN_B //actually it's signal A - cable on the board connector, for now A and B are switched manually at the BTS7960
         5	  Left motor	      MOTOR1_IN_B 
         6	  Left motor	      MOTOR1_IN_A
         7	  Placeholder---	  STEERING_PIN
         8	  Placeholder---	  MOTOR2_PWM
         9	  Placeholder---	  MOTOR4_ENCODER_A
         10	  Left motor	      MOTOR1_ENCODER_A
         11	  Left motor	      MOTOR1_ENCODER_B
         12	  Placeholder---	  MOTOR4_ENCODER_B
         13	  free	  
         14	  free	  
         15	  free	  
         16	  Placeholder---	  MOTOR3_ENCODER_B
         17	  Placeholder---	  MOTOR3_ENCODER_A
         18	  IMU             	SDA 
         19	  IMU	              SCL 
         20	  free	  
         21	  free	  
         22	  Placeholder---    MOTOR3_IN_A	  
         23	  Placeholder---    MOTOR3_IN_B	  
         24	  Right motor	      MOTOR2_ENCODER_B
         25	  Right motor       MOTOR2_ENCODER_A
         26	  Placeholder---    MOTOR4_IN_A	  
         27	  Placeholder---    MOTOR4_IN_B	  

*/


/*
ROBOT ORIENTATION
         FRONT
    MOTOR1  MOTOR2  (2WD/ACKERMANN)
    MOTOR3  MOTOR4  (4WD/MECANUM)  
         BACK
*/

/// ENCODER PINS
#define MOTOR1_ENCODER_A 10 
#define MOTOR1_ENCODER_B 11  

#define MOTOR2_ENCODER_A 25 
#define MOTOR2_ENCODER_B 24  

#define MOTOR3_ENCODER_A 17
#define MOTOR3_ENCODER_B 16 

#define MOTOR4_ENCODER_A 9
#define MOTOR4_ENCODER_B 12

//MOTOR PINS
#ifdef USE_L298_DRIVER
  #define MOTOR_DRIVER L298

  #define MOTOR1_PWM 21
  #define MOTOR1_IN_A 20
  #define MOTOR1_IN_B 1

  #define MOTOR2_PWM 5
  #define MOTOR2_IN_A 8
  #define MOTOR2_IN_B 6

  #define MOTOR3_PWM 22
  #define MOTOR3_IN_A 23
  #define MOTOR3_IN_B 0

  #define MOTOR4_PWM 4
  #define MOTOR4_IN_A 2
  #define MOTOR4_IN_B 3

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif 

#ifdef USE_BTS7960_DRIVER
  #define MOTOR_DRIVER BTS7960  

  #define MOTOR1_PWM 1 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR1_IN_A 6 
  #define MOTOR1_IN_B 5 

  #define MOTOR2_PWM 8 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR2_IN_A 3 
  #define MOTOR2_IN_B 4 

  #define MOTOR3_PWM 0 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR3_IN_A 22
  #define MOTOR3_IN_B 23

  #define MOTOR4_PWM 2 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR4_IN_A 26 
  #define MOTOR4_IN_B 27 

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif

#ifdef USE_ESC
  #define MOTOR_DRIVER ESC  

  #define MOTOR1_PWM 1 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR1_IN_A 21
  #define MOTOR1_IN_B 20

  #define MOTOR2_PWM 8 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR2_IN_A 5
  #define MOTOR2_IN_B 6

  #define MOTOR3_PWM 0 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR3_IN_A 22
  #define MOTOR3_IN_B 23

  #define MOTOR4_PWM 2 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR4_IN_A 4
  #define MOTOR4_IN_B 3

  #define PWM_MAX 400
  #define PWM_MIN -PWM_MAX
#endif

#define STEERING_PIN 7

#endif

/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////// This setup was used with Arduino Mega
//////////// in the previous build of Robco19:
/////////////////////////////////////////////////////////////////


// // // Arduino Mega pins used in the setup below:

// // // External Interrupts: 2 (interrupt 0), 3 (interrupt 1), 18 (interrupt 5), 
// // // 19 (interrupt 4), 20 (interrupt 3), and 21 (interrupt 2)

// // // I2C: 20 (SDA) and 21 (SCL)

// // // Interrupt pins used:
// // // Int0 Pin 2    --> MOTOR1_ENCODER_A 
// // // Int1 Pin 3    --> MOTOR1_ENCODER_B    
// // // Int5 Pin 18   --> MOTOR2_ENCODER_A 
// // // Int4 Pin 19   --> MOTOR2_ENCODER_B 
// // // Int3 Pin 20 SDA --> for IMU I2C 
// // // Int2 Pin 21 SCL --> for IMU I2C 

// // // SPI: 50 (MISO), 51 (MOSI), 52 (SCK), 53 (SS)

// // // The window lift motors used draw up to 8A based on the documentation

// // // IBT-2 H bridge is connected to the 12v SLA robot battery 
// // // (TODO: with a 15A (???10A???) fuse inline trough SPST switch MOTORS_ENABLE_SWITCH
// // // external switch, than trough the EMERGENCY_STOP_SWITCH)

// // // Connection to the IBT-2 board:
// // // LOOK AT: linorobot/teensy/firmware/lib/config/IBT-2-Input-Ports.jpg

// // // IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
// // // IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
// // // IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V pin
// // // IBT-2 pin 8 (GND) to Arduino GND
// // // IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected


// // // Arduino Mega PWM pins: 2 - 13 and 44 - 46

// // // PWM pins used:
// // // Pin  4 MOTOR1_IN_A   
// // // Pin  5 MOTOR1_IN_B   
// // // Pin  6 MOTOR2_IN_A 
// // // Pin  7 MOTOR2_IN_B  

// // // Pins 30 to 42 are used as placeholders!
// // // */


// // // /// ENCODER PINS
// // // #define MOTOR1_ENCODER_A 2  //Int0 Pin 2
// // // #define MOTOR1_ENCODER_B 3  //Int1 Pin 3 

// // // #define MOTOR2_ENCODER_A 18 //Int2 Pin 18
// // // #define MOTOR2_ENCODER_B 19 //Int3 Pin 19 

// // // #define MOTOR3_ENCODER_A 30  //Placeholder (set to unused mega pin)
// // // #define MOTOR3_ENCODER_B 31  //Placeholder (set to unused mega pin)

// // // #define MOTOR4_ENCODER_A 32  //Placeholder (set to unused mega pin)
// // // #define MOTOR4_ENCODER_B 33  //Placeholder (set to unused mega pin)

// // // //MOTOR PINS
// // // #ifdef USE_BTS7960_DRIVER
// // //   #define MOTOR_DRIVER BTS7960  

// // //   #define MOTOR1_PWM 34   //DON'T TOUCH THIS! This is just a placeholder
// // //   #define MOTOR1_IN_A 4  
// // //   #define MOTOR1_IN_B 5  

// // //   #define MOTOR2_PWM 35   //DON'T TOUCH THIS! This is just a placeholder
// // //   #define MOTOR2_IN_A 6  
// // //   #define MOTOR2_IN_B 7  

// // //   #define MOTOR3_PWM 36   //DON'T TOUCH THIS! This is just a placeholder
// // //   #define MOTOR3_IN_A 37  //Placeholder (set to unused mega pin)
// // //   #define MOTOR3_IN_B 38  //Placeholder (set to unused mega pin)

// // //   #define MOTOR4_PWM 39   //DON'T TOUCH THIS! This is just a placeholder
// // //   #define MOTOR4_IN_A 40  //Placeholder (set to unused mega pin)
// // //   #define MOTOR4_IN_B 41  //Placeholder (set to unused mega pin)

// // //   #define PWM_MAX pow(2, PWM_BITS) - 1
// // //   #define PWM_MIN -PWM_MAX
// // // #endif
