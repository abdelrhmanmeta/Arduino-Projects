#define led2pass 42
#define led2neg 43
const int smokePin = A1;
int smokeread=0;

void setup()
{
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{

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
}

