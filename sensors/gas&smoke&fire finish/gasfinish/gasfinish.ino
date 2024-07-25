#define ledpass 40
#define ledneg 41
const int gasPin = A0;
int gasread=0;

void setup()
{
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{

   gasread=analogRead(gasPin);
   if( gasread>500){
     digitalWrite(40 ,HIGH);
     digitalWrite(41 ,LOW);
     Serial.println(gasread);
     
   }
   else{
     digitalWrite(40 ,LOW);
     digitalWrite(41 ,LOW);
     Serial.println(gasread);
   }
}

