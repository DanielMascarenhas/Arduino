#define CHAVE A0 //Define CHAVE como 2
void setup()
{
  
  pinMode(CHAVE, OUTPUT); //Configura o pino 2 como entrada
  Serial.begin(9600); //Habilita a porta Serial com um Baud Rate de 9600
}

void loop()
{
    Serial.println("1\n");
    digitalWrite(CHAVE, HIGH);
    delay(200); //Delay de 250 milissegundos 
    digitalWrite(CHAVE, LOW);
    Serial.println("0\n");
    delay(100);
    Serial.println("1\n");
    digitalWrite(CHAVE, HIGH);
    delay(200); //Delay de 250 milissegundos 
    digitalWrite(CHAVE, LOW);
    Serial.println("0\n");
    delay(1000); //Delay de 250 milissegundos 
}
