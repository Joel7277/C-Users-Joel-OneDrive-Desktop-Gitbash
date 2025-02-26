int pinpot = 34;
int value=0;
float volt=0;
float degre=0;
int percentage=0;
int pinled=2;
int value2=0;
void setup() {
  Serial.begin(115200);
  pinMode(pinled, OUTPUT);
  pinMode(pinpot, INPUT);

}

void loop() {
  value=analogRead(pinpot);
  volt=(value*3.3)/4095;
  degre=(volt*257)/PI;
  percentage=(value*100)/4095;
  value2=value/16;
  //Serial.println(value);
  analogWrite(pinled,value2);
  Serial.println(volt);
  Serial.println(degre);
  Serial.print(percentage);
  Serial.print('%');
  Serial.println( );
  Serial.println(value2);
  delay(5);
}
