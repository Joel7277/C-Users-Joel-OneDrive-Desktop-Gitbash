const int segmentPins[7] = {15, 4, 18, 3, 1, 2, 21}; // Pines conectados a cada segmento del display (A a G)
const int transistor1 = 17; // Pin del transistor para el Display 1
const int transistor2 = 19; // Pin del transistor para el Display 2
const int transistor3 = 5; // Pin del transistor para el Display 3
const int transistor4 = 16; // Pin del transistor para el Display 4
// Matriz de segmentos para los números del 0 al 9 (ajustada para ánodo común)
const byte numbers[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

float i=0;
int un=0;
int de=0;
int ce=0;
int mi=0;

int t=2;
int number = 0; // Número a mostrar
unsigned long lastUpdateTime = 0;
const int updateInterval = 500; // Intervalo de actualización en ms

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH); // Apagar segmentos (ánodo común)
  }
  pinMode(transistor1, OUTPUT);
  pinMode(transistor2, OUTPUT);
  pinMode(transistor3, OUTPUT);
  pinMode(transistor4, OUTPUT);
  digitalWrite(transistor1, LOW); // Apagar displays al inicio
  digitalWrite(transistor2, LOW);
  digitalWrite(transistor3, LOW); 
  digitalWrite(transistor4, LOW);
}

void loop() {
  
  i=i+0.1;
  un=i;
  if(un==10){
    i=0;
    de=de+1;
  }

  if(de==6){
    de=0;
    ce=ce+1;
  }
  
  if(ce==10){
    ce=0;
    mi=mi+1;
  }

  if(mi==2 && ce==4){
    mi=0;
    ce=0;
  }

  /*unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentTime;
    number++;
    if (number > 9999) number = 0;
  }

  int tens = number / 1000; // Decenas
  int units = number % 1000; // Unidades
  int mil = number / 100; // Decenas
  int cent = number % 100; // Unidades*/

// Mostrar milesimas
  digitalWrite(transistor1, HIGH);
  digitalWrite(transistor2, LOW); // Activar Display 2
  digitalWrite(transistor3, LOW);
  digitalWrite(transistor4, LOW);
  setSegments(numbers[mi]);
  delay(t);

// Mostrar centenas
  digitalWrite(transistor1, LOW);
  digitalWrite(transistor2, HIGH); // Activar Display 2
  digitalWrite(transistor3, LOW);
  digitalWrite(transistor4, LOW);
  setSegments(numbers[ce]);
  delay(t);

  // Mostrar decenas
  digitalWrite(transistor1, LOW); // Activar Display 1
  digitalWrite(transistor2, LOW);
  digitalWrite(transistor3, HIGH);
  digitalWrite(transistor4, LOW);
  setSegments(numbers[de]);
  delay(t);

  // Mostrar unidades
  digitalWrite(transistor1, LOW);
  digitalWrite(transistor2, LOW); // Activar Display 2
  digitalWrite(transistor3, LOW);
  digitalWrite(transistor4, HIGH);
  setSegments(numbers[un]);
  delay(t);
}

// Función para actualizar los segmentos del display
void setSegments(const byte num[7]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], num[i]); // LOW enciende el segmento (ánodo común)
  }
}