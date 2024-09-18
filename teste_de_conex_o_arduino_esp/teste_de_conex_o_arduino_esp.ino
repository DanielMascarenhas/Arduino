#include <ESP8266WiFi.h>

const char* ssid = "brisa-1761350";
const char* password = "xhwd107q";
const char* host = "192.168.0.18"; // Substitua pelo IP do seu servidor Node.js

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("WiFi conectado");
}

void loop() {
  if (Serial.available() > 0) {
    String mensagem = Serial.readStringUntil('\n');
    mensagem.trim();

    if (mensagem.length() > 0) {
      WiFiClient client;
      const int httpPort = 3000; // Porta do servidor Node.js
      if (!client.connect(host, httpPort)) {
        Serial.println("Falha ao conectar com o servidor");
        return;
      }

      String url = "/?mensagem=" + mensagem;
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: " + host + "\r\n" +
                   "Connection: close\r\n\r\n");

      while (client.available()) {
        String linha = client.readStringUntil('\r');
        Serial.print(linha);
      }
      Serial.println();
    }
  }
}
