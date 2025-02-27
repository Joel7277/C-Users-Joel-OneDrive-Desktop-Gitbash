#define butPin 4

#define G7 18
#define B7 16
#define F7 17
#define A7 5
#define E7 21
#define D7 22
#define C7 19
int cont = -1;//el contador

bool butSt = 1, said = 0;

void setup() {
  pinMode(butPin, INPUT);
  pinMode(A7,OUTPUT);
  pinMode(B7,OUTPUT);
  pinMode(C7,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(E7,OUTPUT);
  pinMode(F7,OUTPUT);
  pinMode(G7,OUTPUT);
}

void loop() {
  butSt = digitalRead(butPin);
  if(butSt == 0 && said == 0){
    said=1;
    cont++;
    if(cont == 10){cont=0;}
    apagar();
    mostrar(cont);
  }
  if(butSt == 1)
  {
    said=0;
  }
}

void mostrar(int numero){
  switch(numero){
    case 0: 
      //FABCDE
      digitalWrite(F7,1);
      digitalWrite(A7,1);
      digitalWrite(B7,1);
      digitalWrite(C7,1);
      digitalWrite(D7,1);
      digitalWrite(E7,1);
    break;
    case 1:
      //BC
      digitalWrite(B7,1);
      digitalWrite(C7,1);
    break;
    case 2: 
      //ABGED
      digitalWrite(G7,1);
      digitalWrite(A7,1);
      digitalWrite(B7,1);
      digitalWrite(D7,1);
      digitalWrite(E7,1);
    break;
    case 3:
      //ABCDG
      digitalWrite(G7,1);
      digitalWrite(A7,1);
      digitalWrite(B7,1);
      digitalWrite(D7,1);
      digitalWrite(C7,1);
    break;
    case 4: 
      //FGBC
      digitalWrite(G7,1);
      digitalWrite(F7,1);
      digitalWrite(B7,1);
      digitalWrite(C7,1);
    break;
    case 5: 
      //AFGCD
      digitalWrite(G7,1);
      digitalWrite(A7,1);
      digitalWrite(F7,1);
      digitalWrite(D7,1);
      digitalWrite(C7,1);
    break;
    case 6: 
    //AFGCDE
      digitalWrite(G7,1);
      digitalWrite(A7,1);
      digitalWrite(F7,1);
      digitalWrite(D7,1);
      digitalWrite(C7,1);
      digitalWrite(E7,1);
    break;
    case 7: 
      //ABGC
      digitalWrite(G7,1);
      digitalWrite(A7,1);
      digitalWrite(B7,1);
      digitalWrite(C7,1);
    break;
    case 8: 
      //TODO SALVO DP
      digitalWrite(F7,1);
      digitalWrite(A7,1);
      digitalWrite(B7,1);
      digitalWrite(C7,1);
      digitalWrite(D7,1);
      digitalWrite(E7,1);
      digitalWrite(G7,1);
    break;
    case 9: 
      //FABGCD
      digitalWrite(F7,1);
      digitalWrite(A7,1);
      digitalWrite(B7,1);
      digitalWrite(C7,1);
      digitalWrite(D7,1);
      digitalWrite(G7,1);
    break;
  }
};
void apagar()
{
  digitalWrite(F7,0);
  digitalWrite(A7,0);
  digitalWrite(B7,0);
  digitalWrite(C7,0);
  digitalWrite(D7,0);
  digitalWrite(E7,0);
  digitalWrite(G7,0);
};
