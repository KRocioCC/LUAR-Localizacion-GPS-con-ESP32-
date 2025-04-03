#include <TinyGPS++.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

// Configuración Wi-Fi
const char* ssid = "Calderon031";          // Cambia por tu red Wi-Fi
const char* password = "Jcc&031f#nT";  // Cambia por tu contraseña

// Configuración de Firebase
FirebaseData firebase; // Objeto para manejar la comunicación con Firebase
FirebaseConfig config;
FirebaseAuth auth;

const char* firebase_host = "https://gps-perritos-default-rtdb.firebaseio.com/"; // URL de Firebase
const char* firebase_auth = "pssneYx00Wksn9qwwcduc23AXPDyLHveiW2A832x"; // Legacy Token

// GPS
TinyGPSPlus gps;
HardwareSerial gpsSerial(2); // UART2 para GPS

void setup() {
  // Iniciar Serial
  Serial.begin(115200);

  // Configurar comunicación UART2 para el GPS
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17); // RX2 (GPIO16) y TX2 (GPIO17)

  // Conexión Wi-Fi
  Serial.print("Conectando a Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectado a Wi-Fi");

  // Configuración de Firebase
  config.host = firebase_host;
  config.signer.tokens.legacy_token = firebase_auth;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  Serial.println("Conectado a Firebase");
}

void loop() {
  // Leer datos GPS
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    if (gps.location.isUpdated()) {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();

      // Enviar datos de latitud a Firebase
      if (Firebase.setFloat(firebase, "/gps/latitude", latitude)) {
        Serial.println("Latitud enviada a Firebase");
      } else {
        Serial.print("Error enviando latitud: ");
        Serial.println(firebase.errorReason());
      }

      // Enviar datos de longitud a Firebase
      if (Firebase.setFloat(firebase, "/gps/longitude", longitude)) {
        Serial.println("Longitud enviada a Firebase");
      } else {
        Serial.print("Error enviando longitud: ");
        Serial.println(firebase.errorReason());
      }

      // Mostrar datos en el Monitor Serie
      Serial.print("Latitud: ");
      Serial.println(latitude, 6); // 6 decimales para más precisión
      Serial.print("Longitud: ");
      Serial.println(longitude, 6);
    }
  }
}
