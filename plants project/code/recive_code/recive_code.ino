/* JoyStick module receiver code
By Nazmus
http://www.Easyprogramming.net
http://nazm.us
 - CONNECTIONS: nRF24L01 Modules See:
 http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 6
   4 - CSN to Arduino pin 7
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
   
   Above connections created by shield
   On Motor Shield connect Servos to servo connections 1 & 2
 */

/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT11.h>
#include <Servo.h>
#define CE_PIN 6
#define CSN_PIN 7
//*******************************************************************************************
const int airPin = A0;
const int hydrogenPin = A1;
const int gasPin = A2;
const int soilPin = A3;
int tempPin=8;
DHT11 dht11(tempPin);
int airread=0;
int hydrogenread=0;
int gasread=0;
int pos = 0;
int i=0;
Servo myservo1;
//********************************************************************************************
  
// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[6];  // 6 element array holding Joystick readings

//********************************************************************************************
void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);       //for opening port to work .
  pinMode(3, OUTPUT);       //for pwm1 pin .
  pinMode(5, OUTPUT);       //for pwm2 pin .
  pinMode(2, OUTPUT);       //for dir1 pin .
  pinMode(4, OUTPUT);       //for dir2 pin .
  pinMode(8, OUTPUT);

  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  
      airread=analogRead(airPin);
      hydrogenread=analogRead(hydrogenPin);
      gasread=analogRead(gasPin);
      soilread=analogRead(soilPin);
      int err;
      float temp, humi;
      
//********************************************************************************************

      radio.read( joystick, sizeof(joystick) );
      int joystickX = map(joystick[0],0,1023,0,180); // turn value of 0-1023 to 0-180 degrees
      int joystickY = map(joystick[1],0,1023,0,180);  // turn value of 0-1023 to 0-180 degrees
      Serial.println(joystickX);
      // the four button variables from joystick array
      int upbut = joystick[2];
      int rightbut = joystick[3];
      int downbut = joystick[4];
      int lefttbut = joystick[5];
      
          
  if(joystickX<=66  && joystickX>=50 && joystickY<=60  && joystickY>=50   ){
    
     digitalWrite(2 ,HIGH);     
     analogWrite(3,0);            
     digitalWrite(4 ,HIGH);      
     analogWrite(5 ,0);
  }
  if(joystickX<66  && joystickX>50 && joystickY<122  &&   joystickY>114){
     digitalWrite(2 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,255);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,255);
  }
  if(joystickX<=60  && joystickX>=50 && joystickY<=7  &&  joystickY>=0){
     digitalWrite(2 ,LOW);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,200);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,LOW);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,200);
  }
  if(joystickX<=7  && joystickX>=0 && joystickY<66  &&  joystickY>50){
     digitalWrite(2 ,LOW);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,200);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,200);
  digitalWrite(8 ,HIGH); 
  }
  if( joystickX<125  &&   joystickX>114 && joystickY<66    && joystickY>50){
     digitalWrite(2 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,200);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,LOW);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,200);
  digitalWrite(8 ,HIGH); 
  }
    //*********************************************************************************************
  if( airread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(airread); 
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(airread);
   }
   //********************************************************************************************
   if( gasread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(gasread);
     
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(gasread);
   }
   //*******************************************************************************************
   if( soilread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(soilread);
     
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(soilread);
   }
   //*******************************************************************************************
      if( hydrogenread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(hydrogenread);
     
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(hydrogenread);
   }
   //*******************************************************************************************
      dht11.read(humi, temp);
   Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    if(temp > 32 && humi > 32){
      digitalWrite(13 ,HIGH);
    }
    else{
      digitalWrite(13 ,LOW);
    }
    //*******************************************************************************************
    if(upbut==1){
      for(i=0;i<100;i+2){
        pos=i;
        myservo1.write(pos);
      }
    }
    else if(upbut==0){
      myservo1.write(pos);
    }
    //*****************************************************************
   if(downbut==1){
      for(i=pos;i>0;i-2){
        pos=i;
        myservo1.write(pos);
      }
    }
    else if(downbut==0){
      myservo1.write(pos);
    }
    //**********************************************************************

}//--(end main loop )---
