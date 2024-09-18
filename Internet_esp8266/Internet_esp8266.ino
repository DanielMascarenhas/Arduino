#include <ESP8266WiFi.h>

// Substitua estas definições pelos dados da sua rede WiFi
const char* ssid = "brisa-1761350";
const char* password = "xhwd107q";

void setup() {
  // Inicializa a comunicação serial para monitorar a saída
  Serial.begin(115200);
  delay(10);

  // Conecta-se à rede WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  // Inicia a conexão WiFi
  WiFi.begin(ssid, password);

  // Aguarda até que a conexão esteja estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  // Imprime uma mensagem de sucesso na conexão e o endereço IP
  Serial.println("");
  Serial.println("WiFi conectado com sucesso");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
