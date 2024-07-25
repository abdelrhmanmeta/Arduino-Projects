#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT11.h>
#include <Servo.h> 
#define CE_PIN 6
#define CSN_PIN 7
//*******************************************************************************************
const int gasPin = A0;
const int hydroginPin = A1;
const int soilPin = A2;
const int airPin = A3;
int tempPin=8;
DHT11 dht11(tempPin);
int gasread=0;
int hydroginread=0;
int soilread=0;
int airread=0;
int pos = 0;
Servo myservo1;
//*******************************************************************************************
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe  
RF24 radio(CE_PIN, CSN_PIN);
int joystick[6];
//*******************************************************************************************
void setup() {
  Serial.begin(9600);       //for opening port to work .
  pinMode(3, OUTPUT);       //for pwm1 pin .
  pinMode(5, OUTPUT);       //for pwm2 pin .
  pinMode(2, OUTPUT);       //for dir1 pin .
  pinMode(4, OUTPUT);       //for dir2 pin .
  pinMode(13, OUTPUT);
  myservo1.attach(9);
   radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}



void loop() {
  
  gasread=analogRead(gasPin);
  hydroginread=analogRead(hydroginPin);
  soilread=analogRead(soilPin);
  airread=analogRead(airPin);
  int err;
  float temp, humi;
  //******************************************************************************************
 radio.read( joystick, sizeof(joystick) );
      int joystickX = map(joystick[0],0,1023,0,180); // turn value of 0-1023 to 0-180 degrees
      int joystickY = map(joystick[1],0,1023,0,180);  // turn value of 0-1023 to 0-180 degrees
      
      // the four button variables from joystick array
      int upbut = joystick[2];
      int rightbut = joystick[3];
      int downbut = joystick[4];
      int lefttbut = joystick[5];
 //*******************************************************************************************     
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
     digitalWrite(2 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,70);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,200); 
  }
  if( joystickX<125  &&   joystickX>114 && joystickY<66    && joystickY>50){
     digitalWrite(2 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,200);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,70); 
  }
  //*********************************************************************************************
  if( gasread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(gasread); 
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(gasread);
   }
   //********************************************************************************************
   if( hydroginread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(hydroginread);
     
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(hydroginread);
   }
   //********************************************************************************************
   if(downbut==1){
  pos=120;
  myservo1.write(pos);
   if( soilread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(soilread);
     
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(soilread);
   }
   }
   else{
  pos=0;
  myservo1.write(pos);
   }
  
  //*******************************************************************************************
   if( airread>400){
     digitalWrite(13 ,HIGH);
     Serial.println(airread);
     
   }
   else{
     digitalWrite(13 ,LOW);
     Serial.println(airread);
   }
   //*******************************************************************************************
   dht11.read(humi, temp);
   Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    if(temp > 32 && humi > 32){
      digitalWrite(13 ,LOW);
    }
    else{
      digitalWrite(13 ,LOW);
    }
    //*******************************************************************************************
    
}
