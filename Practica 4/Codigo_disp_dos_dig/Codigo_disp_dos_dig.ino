const int segmentPins[7] = {2, 4, 5, 12, 13, 14, 15}; // Pines conectados a cada segmento del display (A a G)
const int transistor1 = 25; // Pin del transistor para el Display 1
const int transistor2 = 26; // Pin del transistor para el Display 2

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
  digitalWrite(transistor1, LOW); // Apagar displays al inicio
  digitalWrite(transistor2, LOW);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentTime;
    number++;
    if (number > 99) number = 0;
  }

  int tens = number / 10; // Decenas
  int units = number % 10; // Unidades

  // Mostrar decenas
  digitalWrite(transistor1, HIGH); // Activar Display 1
  digitalWrite(transistor2, LOW);
  setSegments(numbers[tens]);
  delay(5);

  // Mostrar unidades
  digitalWrite(transistor1, LOW);
  digitalWrite(transistor2, HIGH); // Activar Display 2
  setSegments(numbers[units]);
  delay(5);
}

// Función para actualizar los segmentos del display
void setSegments(const byte num[7]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], num[i]); // LOW enciende el segmento (ánodo común)
  }
}