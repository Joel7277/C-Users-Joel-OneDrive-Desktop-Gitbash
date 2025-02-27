#define LED_PIN 2  // Define el pin donde está conectado el LED (puedes cambiarlo si usas otro pin)

int delayTime = 1000;  // Tiempo inicial de espera (1 segundo)
bool decreasing = true; // Controla si el tiempo de delay debe decrecer o aumentar

void setup() {
  // Configura el pin como salida
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Enciende el LED
  digitalWrite(LED_PIN, HIGH);
  delay(delayTime);  // Espera según el tiempo actual

  // Apaga el LED
  digitalWrite(LED_PIN, LOW);
  delay(delayTime);  // Espera según el tiempo actual

  // Cambia el ritmo de parpadeo
  if (decreasing) {
    delayTime -= 100;  // Reduce el tiempo de delay (parpadeo más rápido)
    if (delayTime <= 100) {
      decreasing = false; // Cuando llega a 100ms, empieza a aumentar el tiempo
    }
  } else {
    delayTime += 100;  // Aumenta el tiempo de delay (parpadeo más lento)
    if (delayTime >= 1000) {
      decreasing = true; // Cuando llega a 1000ms, empieza a disminuir el tiempo
    }
  }
}