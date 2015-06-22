const int TouchPin=11;
const int ledPin=13;
int status = 0;

void setup() {
pinMode(TouchPin, INPUT);
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);
Serial.begin(9600);
} 
 
void loop() {
  int sensorValue = digitalRead(TouchPin);
  if(sensorValue==1)
  {
    digitalWrite(ledPin,HIGH);
  } else {
    digitalWrite(ledPin,LOW);
  }
  Serial.println(sensorValue);
  delay(10);
}
