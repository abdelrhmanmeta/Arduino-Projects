#define led3pass 44
#define led3neg 45
const int firePin = A2;
int fireread=0;

void setup()
{
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{

   fireread=analogRead(firePin);
   if( fireread<500){
     digitalWrite(44 ,HIGH);
     digitalWrite(45 ,LOW);
     Serial.println(fireread);
     
   }
   else{
     digitalWrite(44 ,LOW);
     digitalWrite(45 ,LOW);
     Serial.println(fireread);
   }
}

