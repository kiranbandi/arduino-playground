
int sensorPin = A1;
int ledPin = 3;
int sensorValue = 0;
int ledValue = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(sensorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  pinMode(A0,OUTPUT);
  digitalWrite(A0,HIGH);
  pinMode(A2,OUTPUT);
  digitalWrite(A2,LOW);
   Serial.begin(9600);  

  

}

void loop() {
  // put your main code here, to run repeatedly:

   sensorValue = analogRead(sensorPin);
   ledValue = map(sensorValue,0,1023,0,255);
   Serial.println(sensorValue);
   analogWrite(ledPin,ledValue);
   delay(500);  
    
  
}
