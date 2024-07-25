#include <Servo.h> 
Servo myservo1;
Servo myservo2;
int pos = 0;
int pos2 = 0; 
int xread=0;
void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(10);
} 
 
void loop() 
{ 
  xread=Serial.read();
  switch(xread){
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
     case '5': {
     analogWrite(2 ,100); //ledpas
     analogWrite(3 ,0);  //lednag
        
  break;
    }
     case '6': {
     analogWrite(2 ,200); //ledpas
     analogWrite(3 ,0);  //lednag
        
  break;
    }
     case '7': {
     analogWrite(4 ,200); //ledpas
     analogWrite(5 ,0); //lednag
  break;
    }
    
     case '8': {
     analogWrite(2 ,0); //ledpas
     analogWrite(3 ,0);  //lednag
        
  break;
    }
     case '9': {
     analogWrite(4 ,0); //ledpas
     analogWrite(5 ,0); //lednag
  break;
    }
    case 'a': {
     analogWrite(4 ,100); //mrw7a pas
     analogWrite(5 ,0); //mrw7a nag
  break;
    }
    case 'b': {
     analogWrite(4 ,255); //mrw7a pas
     analogWrite(5 ,0); //mrw7a nag
  break;
    }
    case 'c': {
     analogWrite(4 ,0); //mrw7a pas
     analogWrite(5 ,0); //mrw7a nag
  break;
    }
}
}

