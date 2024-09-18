#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h> // Biblioteca para envio de e-mail

const char* ssid = "brisa-1761350";
const char* password = "xhwd107q";

// Configuração do SMTP
const char* emailSender = "dan.mmascar@gmail.com";
const char* emailSenderPassword = "sdvdlnpmriavesrk";
const char* emailRecipient = "dan.mmascar@gmail.com"; // Mesma conta para enviar e receber
const char* smtpServer = "smtp.gmail.com";
const int smtpPort = 465;

SMTPSession smtp;
ESP_Mail_Session mailSession;
SMTP_Message message;

void setup() {
  Serial.begin(115200);

  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);

  Serial.println("Conectando ao WiFi...");
  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - startAttemptTime >= 30000) { // Timeout após 30 segundos
      Serial.println("Falha ao conectar ao WiFi.");
      return;
    }
    delay(1000);
    Serial.println("Conectando...");
  }
  Serial.println("WiFi conectado!");

  // Configurar a sessão SMTP
  mailSession.server.host_name = smtpServer;
  mailSession.server.port = smtpPort;
  mailSession.login.email = emailSender;
  mailSession.login.password = emailSenderPassword;
  mailSession.login.user_domain = "";

  smtp.debug(1);

  // Enviar e-mail de teste
  sendTestEmail();
}

void loop() {
  // O loop fica vazio, pois estamos apenas enviando o e-mail no setup
}

void sendTestEmail() {
  // Configurar a mensagem de e-mail
  message.sender.name = "Nome";
  message.sender.email = emailSender;
  message.subject = "E-mail de Teste";
  message.addRecipient("Destinatário", emailRecipient);
  message.text.content = "Este é um e-mail de teste enviado pelo ESP8266.";

  // Conectar ao servidor SMTP e enviar o e-mail
  if (!smtp.connect(&mailSession)) {
    Serial.println("Erro ao conectar ao servidor SMTP.");
    return;
  }

  if (!MailClient.sendMail(&smtp, &message)) {
    Serial.println("Erro ao enviar e-mail.");
  } else {
    Serial.println("E-mail de teste enviado com sucesso.");
  }

  smtp.closeSession();
}
