#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h> 
#define CE_PIN 7
#define CSN_PIN 8
//*******************************************************************************************
const int rainPin = A0;
const int sunPin = A1;
int rainread=0;
int sunread=0;
int pos = 0;
int pos2 = 0;
int i=0;
Servo myservo1;
Servo myservo2;
//*******************************************************************************************
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe  
RF24 radio(CE_PIN, CSN_PIN);
int joystick[6];
//*******************************************************************************************
void setup() {
  Serial.begin(9600);       //for opening port to work .
  pinMode(2, OUTPUT);       //for pwm1 pin .
  pinMode(3, OUTPUT);       //for pwm2 pin .
  pinMode(4, OUTPUT);       //for dir1 pin .
  pinMode(5, OUTPUT);       //for dir2 pin .
//  pinMode(12, OUTPUT);
//  pinMode(13, OUTPUT);
  //myservo1.attach(9);
  //myservo2.attach(10);
   radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() {
  
 // rainread=analogRead(rainPin);
 // sunread=analogRead(sunPin);
  //******************************************************************************************
 radio.read( joystick, sizeof(joystick) );
      int joystickX = map(joystick[0],0,1023,0,180); // turn value of 0-1023 to 0-180 degrees
      int joystickY = map(joystick[1],0,1023,0,180);  // turn value of 0-1023 to 0-180 degrees
      // the four button variables from joystick array
      int upbut = joystick[2];
      int rightbut = joystick[3];
      int downbut = joystick[4];
      int lefttbut = joystick[5];
    /*      myservo1.write(30);
    myservo2.write(90);
    delay(1000);
    myservo1.write(60);
    myservo2.write(90);
    delay(1000);
    myservo1.write(90);
    myservo2.write(90);
    delay(1000);
    myservo1.write(120);
    myservo2.write(90);
    delay(1000);
    myservo1.write(150);
    myservo2.write(90);
    delay(1000);*/
      
 //*******************************************************************************************     
       Serial.print("X = ");
      Serial.print(joystickX);
      Serial.print(" Y = ");  
      Serial.print(joystickY);
      Serial.print("\n");
  if(joystickX<=66  && joystickX>=50 && joystickY<=60  && joystickY>=50   ){
     digitalWrite(12 ,HIGH);     
     analogWrite(3,0);            
     digitalWrite(4 ,HIGH);      
     analogWrite(5 ,0);
     Serial.print("X = ");
      Serial.print(joystickX);
    
  }
  if(joystickX<66  && joystickX>50 && joystickY<122  &&   joystickY>114){
     digitalWrite(12 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,255);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,255); 
  Serial.print("X = ");
      Serial.print(joystickX);
    
  }
  if(joystickX<=60  && joystickX>=50 && joystickY<=7  &&  joystickY>=0){
     digitalWrite(12 ,LOW);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,200);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,LOW);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,200); 
  Serial.print("X = ");
      Serial.print(joystickX);
    
  }
  if(joystickX<=7  && joystickX>=0 && joystickY<66  &&  joystickY>50){
     digitalWrite(12 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,70);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,255); 
  Serial.print("X = ");
      Serial.print(joystickX);
      }
  if( joystickX<125  &&   joystickX>114 && joystickY<66    && joystickY>50){
     digitalWrite(12 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,255);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,70); 
  Serial.print("X = ");
      Serial.print(joystickX);
    
  }
  //*********************************************************************************************
  if( rainread<900){
     digitalWrite(12 ,LOW);
     digitalWrite(11 ,255);
     Serial.println(rainread);
     Serial.println("Rain"); 
   }
   else{
     digitalWrite(12 ,LOW);
     digitalWrite(11 ,0);
     Serial.println(rainread);
     Serial.println("Not Rain");
   }
   //********************************************************************************************
   if( sunread>500){
     digitalWrite(12 ,LOW);
     digitalWrite(11 ,HIGH);
     Serial.println(sunread);
     Serial.println("sun");
   }
   else{
     digitalWrite(12 ,LOW);
     digitalWrite(11 ,LOW);
     Serial.println(sunread);
     Serial.println("not sun");
   }
   //*******************************************************************************************
}
