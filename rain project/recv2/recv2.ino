/* Joystick Receiver

   1 > GND
   2 > VCC 3.3V
   3 > CE to Arduino pin 9
   4 > CSN to Arduino pin 10
   5 > SCK to Arduino pin 13
   6 > MOSI to Arduino pin 11
   7 > MISO to Arduino pin 12
   8 > not connected
    */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define CEpin 7
#define CSNpin 8
  
const uint64_t pipe = 0xE1E1F0F0E1LL; // Define the transmit pipe
RF24 radio(CEpin, CSNpin); //  Radio
Servo myservo1;
Servo myservo2;

int joystick[6];  //Joystick readings
const int rainPin = A0;
const int sunPin = A1;
int rainread=0;
int sunread=0;
void setup()  
{
  pinMode(2, OUTPUT);       //for pwm1 pin .
  pinMode(3, OUTPUT);       //for pwm2 pin .
  pinMode(4, OUTPUT);       //for dir1 pin .
  pinMode(5, OUTPUT);       //for dir2 pin .
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  Serial.begin(9600);
  Serial.println("RF24L Startup Receiver");
  radio.begin();
  radio.openReadingPipe(1,pipe);
    radio.startListening();;
    myservo1.attach(9);
    myservo2.attach(10);
}

void loop()   
{
      rainread=analogRead(rainPin);
      sunread=analogRead(sunPin);
      radio.read( joystick, sizeof(joystick) );
      int joystickX = map(joystick[0],0,1023,0,180); // change the value of 0-1023 to 0-180 degrees
      int joystickY = map(joystick[1],0,1023,0,180);  // change the value of 0-1023 to 0-180 degrees
      
      // four button A B C D 
      int upbut = joystick[2];
      int rightbut = joystick[3];
      int downbut = joystick[4];
      int lefttbut = joystick[5];
     Serial.print("X = ");
      Serial.print(joystickX);
      Serial.print(" Y = ");  
      Serial.print(joystickY);
      Serial.print("\n");
   if(joystickX<=65  && joystickX>=59 && joystickY<=65  &&   joystickY>=55){ 
     digitalWrite(2 ,HIGH);
     analogWrite(3,0);            
     digitalWrite(4 ,HIGH);      
     analogWrite(5 ,0);
  }
  if(joystickX<=65  && joystickX>=59 && joystickY<=140  &&   joystickY>=110){
  digitalWrite(2 ,LOW);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,250);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,LOW);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5,250);
  }
  if(joystickX<=65  && joystickX>=59 && joystickY<=7  &&  joystickY>=0){ 
      digitalWrite(2 ,HIGH);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,255);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,HIGH);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,255);
  }
  if(joystickX<=140  && joystickX>=110 && joystickY<=65  &&  joystickY>=55){
      digitalWrite(2 ,LOW);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,200);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,LOW);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,50);
  }
  if( joystickX<=7  &&   joystickX>=0 && joystickY<=65  && joystickY>=55){
digitalWrite(2 ,LOW);     //for dir1 pin to dircation of motor 1 to make it turn left .
  analogWrite(3,50);      //for pwm1 pin to contorl speed of motor in speed 255 .
  digitalWrite(4 ,LOW);      //for dir2 pin to dircation of motor 2 to make it turn right .
  analogWrite(5 ,200); 
  }
  if( joystickX<=110  &&   joystickX>=90 && joystickY<=125  && joystickY>=100){
    myservo1.write(30);
  }
  if( joystickX<=7  &&   joystickX>=0 && joystickY<=125  && joystickY>=100){
    myservo1.write(100);
  }
  if( joystickX<=7  &&   joystickX>=0 && joystickY<=7  && joystickY>=0){
    myservo2.write(30);
  }
  if( joystickX<=125  &&   joystickX>=100 && joystickY<=7  && joystickY>=0){
    myservo2.write(1000);
  }
   //*********************************************************************************************
  if( rainread>600){
     digitalWrite(0 ,HIGH);
     Serial.println(rainread);
     Serial.println("Rain"); 
   }
   else{
     digitalWrite(0 ,LOW);
     
     Serial.println(rainread);
     Serial.println("Not Rain");
   }
   //********************************************************************************************
   if( sunread>400){
     digitalWrite(1 ,HIGH);
     Serial.println(sunread);
     Serial.println("sun");
   }
   else{
     digitalWrite(1 ,LOW);
     Serial.println(sunread);
     Serial.println("not sun");
   }
}

