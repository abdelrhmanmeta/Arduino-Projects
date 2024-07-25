//servo part
#include <Servo.h> 
Servo myservo1;
Servo myservo2;
int pos = 0;
int pos2 = 0;

//gas part 
const int gasPin = A0;
int gasread=0;

//smoke part
const int smokePin = A1;
int smokeread=0;

//fire part
const int firePin = A2;
int fireread=0;

//solar part
const int solarPin = A6;
int solarread=0;

//blutooth part
int xread=0;

void setup() 
{
  pinMode(2, OUTPUT);                           //room led
  pinMode(3, OUTPUT);                           //room led
  pinMode(4, OUTPUT);                           //sala led
  pinMode(5, OUTPUT);                           //sala led
  pinMode(6, OUTPUT);                           //marw7a 1
  pinMode(7, OUTPUT);                           //marw7a 1
  pinMode(8, OUTPUT);                           //marw7a 2
  pinMode(9, OUTPUT);                           //marw7a 2
  pinMode(40, OUTPUT);                          //gas led
  pinMode(41, OUTPUT);                          //gas led 
  pinMode(42, OUTPUT);                          //smoke led
  pinMode(43, OUTPUT);                          //smoke led
  pinMode(32, OUTPUT);                          //fire led
  pinMode(33, OUTPUT);                          //fire led
  pinMode(46, OUTPUT);                          //led solar
  pinMode(47, OUTPUT);                          //led solar
  pinMode(48, OUTPUT);                          //buzzer solar
  pinMode(49, OUTPUT);                          //buzzer solar
  Serial.begin(9600);
  //servo part
  myservo1.attach(11);
  myservo2.attach(10);
} 
 
void loop() 
{ 
  xread=Serial.read();
  switch(xread){
    //servo part
    case '1':{
  pos=120;
  myservo1.write(pos);
  Serial.println("garage door open");
  break; 
    }
    case '2': {
        pos=0;
  myservo1.write(pos);
  Serial.println("garage door close");
  break;
    }
    case '3': {
        pos2=120;
  myservo2.write(pos2);
  Serial.println("door open");
  break;
    }
    case '4': {
        pos2=0;
  myservo2.write(pos2);
  Serial.println("door close");
  break;
    }
    //rooms led
     case '5': {
     analogWrite(2 ,100); //ledpas
     analogWrite(3 ,0);  //lednag
        
  break;
    }
    //rooms led
     case '6': {
     analogWrite(2 ,200); //ledpas
     analogWrite(3 ,0);  //lednag
        
  break;
    }
    //rooms led
     case '7': {
     analogWrite(2 ,0); //ledpas
     analogWrite(3 ,0); //lednag
  break;
    }
    //sala led
     case '8': {
     analogWrite(4 ,200); //ledpas
     analogWrite(5 ,0);  //lednag
        
  break;
    }
    //sala led
     case '9': {
     analogWrite(4 ,0); //ledpas
     analogWrite(5 ,0); //lednag
  break;
    }
    case 'a': {
      //mrw7a speed 1
     analogWrite(6 ,150); //mrw7a pas
     analogWrite(7 ,0); //mrw7a nag
     analogWrite(8 ,150); //mrw7a pas
     analogWrite(9 ,0); //mrw7a nag
  break;
    }
    //marw7a speed 2
    case 'b': {
     analogWrite(6 ,255); //mrw7a pas
     analogWrite(7 ,0); //mrw7a nag
     analogWrite(8 ,255); //mrw7a pas
     analogWrite(9 ,0); //mrw7a nag
  break;
    }
    //marw7a speed 0
    case 'c': {
     analogWrite(6 ,0); //mrw7a pas
     analogWrite(7 ,0); //mrw7a nag
     analogWrite(8 ,0); //mrw7a pas
     analogWrite(9 ,0); //mrw7a nag
  break;
    }
  }
    //gas part
   gasread=analogRead(gasPin);
   if( gasread>400){
     digitalWrite(40 ,HIGH);
     digitalWrite(41 ,LOW);
     Serial.println(gasread);
     
   }
   else{
     digitalWrite(40 ,LOW);
     digitalWrite(41 ,LOW);
     Serial.println(gasread);
   }
   //smoke part
   smokeread=analogRead(smokePin);
   if( smokeread>400){
     digitalWrite(42 ,HIGH);
     digitalWrite(43 ,LOW);
     Serial.println(smokeread);
     
   }
   else{
     digitalWrite(42 ,LOW);
     digitalWrite(43 ,LOW);
     Serial.println(smokeread);
   }
   //fire part
   fireread=analogRead(firePin);
   if( fireread<300){
     digitalWrite(32 ,HIGH);
     digitalWrite(33 ,LOW);
     Serial.println(fireread);  
   }
   else{
     digitalWrite(32 ,LOW);
     digitalWrite(33,LOW);
     Serial.println(fireread);
   }
   //solar part  
solarread=analogRead(solarPin);
if(solarread<1024){
  digitalWrite(46 ,HIGH);
  digitalWrite(47 ,LOW);
  digitalWrite(48 ,HIGH);
  digitalWrite(49 ,LOW);
}
else{
  digitalWrite(46 ,LOW);
  digitalWrite(47 ,LOW);
  digitalWrite(48 ,LOW);
  digitalWrite(49 ,LOW);
  analogWrite(2 ,0); //ledpas
  analogWrite(3 ,0); //lednag
  analogWrite(4 ,0); //ledpas
  analogWrite(5 ,0); //lednag
}
}

