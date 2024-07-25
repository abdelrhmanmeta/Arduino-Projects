//gas part 
const int gasPin = A0;
int gasread=0;

//smoke part
const int smokePin = A1;
int smokeread=0;

//fire part
const int firePin = A2;
int fireread=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(40, OUTPUT);                          //gas led
  pinMode(41, OUTPUT);                          //gas led 
  pinMode(42, OUTPUT);                          //smoke led
  pinMode(43, OUTPUT);                          //smoke led
  pinMode(44, OUTPUT);                          //fire led
  pinMode(45, OUTPUT);                          //fire led
  Serial.begin(9600);
}

void loop() {
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
     //Serial.println(smokeread);
     
   }
   else{
     digitalWrite(42 ,LOW);
     digitalWrite(43 ,LOW);
     //Serial.println(smokeread);
   }
   //fire part
   fireread=analogRead(firePin);
   if( fireread<200){
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
