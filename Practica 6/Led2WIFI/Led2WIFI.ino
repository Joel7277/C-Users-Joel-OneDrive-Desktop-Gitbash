#include <WiFi.h>
#include <WebServer.h>

// Configuración del punto de acceso (AP)
const char *ssid = "ESP32_LED";  // Nombre de la red Wi-Fi del ESP32
const char *password = "123456789";  // Contraseña de la red Wi-Fi del ESP32

WebServer server(80);  // Servidor web en el puerto 80

// Pin del LED integrado en el ESP32
const int ledPin = 2;  // Pin GPIO2 (LED en la mayoría de las placas ESP32)

// Función para encender el LED
void handleLEDOn() {
  digitalWrite(ledPin, HIGH);  // Enciende el LED
  server.send(200, "text/html", "<html><body><h1>LED Encendido</h1><a href=\"/off\">Apagar LED</a></body></html>");
}

// Función para apagar el LED
void handleLEDOff() {
  digitalWrite(ledPin, LOW);  // Apaga el LED
  server.send(200, "text/html", "<html><body><h1>LED Apagado</h1><a href=\"/on\">Encender LED</a></body></html>");
}

// Función para manejar la página principal
void handleRoot() {
  server.send(200, "text/html", "<html><body><h1>Controlar LED ESP32</h1><a href=\"/on\">Encender LED</a><br><a href=\"/off\">Apagar LED</a></body></html>");
}

void setup() {
  // Inicia el puerto serial para depuración
  Serial.begin(115200);

  // Configura el pin del LED como salida
  pinMode(ledPin, OUTPUT);

  // Configura el ESP32 como punto de acceso (Access Point)
  WiFi.softAP(ssid, password);
  Serial.println("Punto de acceso iniciado");
  Serial.print("IP de acceso: ");
  Serial.println(WiFi.softAPIP());

  // Define las rutas para manejar las peticiones HTTP
  server.on("/", HTTP_GET, handleRoot);   // Página principal
  server.on("/on", HTTP_GET, handleLEDOn); // Encender LED
  server.on("/off", HTTP_GET, handleLEDOff); // Apagar LED

  // Inicia el servidor
  server.begin();
}

void loop() {
  server.handleClient();  // Maneja las peticiones HTTP
}
