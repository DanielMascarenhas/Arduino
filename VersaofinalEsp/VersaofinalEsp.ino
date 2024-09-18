#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "brisa-1761350";
const char* password = "xhwd107q";

const char* serverName = "https://script.google.com/macros/s/AKfycbzUxnpDp_jvjggB1rU2zm7-Pvo9sRHgR5CEHdh0Q_BAJfYI1Guqicnp0XTzczArUQ3G/exec";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("WiFi conectado!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (Serial.available() > 0) {
      String valor = Serial.readStringUntil('\n');  // Lê o valor da serial
      valor.trim();  // Remove espaços em branco extras

      WiFiClientSecure client;
      client.setInsecure();  // Ignora a verificação do certificado SSL

      HTTPClient http;

      String url = serverName;
      url += "?valor=" + valor;  // Adiciona o valor à URL
    
      http.begin(client, url);  // Inicia a conexão HTTPS

      int httpResponseCode = http.GET();  // Envia a requisição GET

      if (httpResponseCode > 0) {
        Serial.println("Dado enviado com sucesso!");  // Confirma que o dado foi enviado
      } else {
        Serial.println("Erro ao enviar o dado.");  // Indica que houve um erro no envio
      }

      http.end();  // Encerra a conexão
    }
  } else {
    Serial.println("WiFi desconectado");
  }
}
