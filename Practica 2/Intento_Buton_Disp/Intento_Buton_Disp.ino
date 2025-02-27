int A=5;
int B=16;
int C=19;
int D=22;
int E=21;
int F=17;
int G=18;
int PB=4;
int cont=0;
bool pb;
void setup() {

  Serial.begin(115200);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(PB, INPUT);

}

void loop() {
  if(digitalRead(PB)==LOW){
    switch(cont){
      case 0:
        Serial.println("Presionado");
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
      break;
      case 1:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
      break;
      case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(G, HIGH);
      break;
      case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(G, HIGH);
      break;
      case 4:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
      case 5:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
      case 6:
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
      case 7:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
      break;
      case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
      case 9:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        cont=0;
      break;
    }
  }
  else{
    cont++;
  }

}
