#define led_builtin 2
bool entra= true;
void setup() {
  pinMode(led_builtin, OUTPUT);

}

void loop() {
  for(int i=0; i<=500; i=i+10){
    digitalWrite(led_builtin, HIGH);
    delay(i);
    digitalWrite(led_builtin, LOW);
    delay(i);
  }
  for(int i=500; i>=0; i=i-10){
    digitalWrite(led_builtin, HIGH);
    delay(i);
    digitalWrite(led_builtin, LOW);
    delay(i);
  }
}
