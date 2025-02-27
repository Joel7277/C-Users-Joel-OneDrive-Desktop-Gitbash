#define led_Builtin 2
int PB=4;
int cont=0;
bool pb;
void setup() {

  Serial.begin(115200);
  pinMode(led_Builtin, OUTPUT);
  pinMode(PB, INPUT);

}

void loop() {
  if(digitalRead(PB)==LOW){
    if(cont==0){
      Serial.println("Hola");
      cont=1;
    }
  }
  else{
    cont=0;
  }

}
