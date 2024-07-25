const int xPin = A0; 
const int yPin=A1;
void setup()
{
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
	Serial.begin(9600);
}
void loop()
{
 Serial.println(xPin);
 Serial.println(yPin);
}

