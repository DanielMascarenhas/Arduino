#include <SoftwareSerial.h>

SoftwareSerial esp8266(0, 1); // RX, TX

void setup() {
  Serial.begin(9600); // Comunicação com o computador
  esp8266.begin(115200); // Comunicação com o ESP8266

  Serial.println("Setup completo. Iniciando comunicação com ESP8266...");
}

void loop() {
  // Enviar mensagem para o ESP8266 a cada 5 segundos
  static unsigned long lastSendTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastSendTime >= 5000) {
    lastSendTime = currentTime;

    int intValue = 42;
    float floatValue = 3.14;
    char charValue = 'A';
    String stringValue = "Hello";

    // Cria a mensagem concatenando diferentes tipos de variáveis
    String message = "Int: " + String(intValue) + ", Float: " + String(floatValue) + ", Char: " + String(charValue) + ", String: " + stringValue;

    esp8266.println(message); // Envia mensagem ao ESP8266
    Serial.println("Enviado para ESP8266: " + message); // Debug
  }

  // Verificar se há dados do ESP8266 para ler
  /* if (esp8266.available()) {
    String response = esp8266.readString();
    response.trim(); // Remove espaços em branco extras
    Serial.println("Recebido da ESP8266: " + response); // Debug
  } */
}
