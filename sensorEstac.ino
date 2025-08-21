// Pinos do sensor ultrassônico
const int trigPin = 9;
const int echoPin = 10;

// Pino do buzzer
const int buzzer = 8;

void setup() {
  // Inicializa os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  // Inicia a comunicação serial (opcional para debug)
  Serial.begin(9600);
}

void loop() {
  // Envia pulso ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo de resposta do eco
  long duracao = pulseIn(echoPin, HIGH);

  // Converte o tempo em distância (em cm)
  int distancia = duracao * 0.034 / 2;

  // Exibe a distância no monitor serial (opcional)
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Toca o buzzer com base na distância
  if (distancia < 10) {
    // Muito perto: bipes rápidos
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  } else if (distancia < 30) {
    // Médio: bipes moderados
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  } else if (distancia < 50) {
    // Longe: bipes lentos
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(600);
  } else {
    // Muito longe: silêncio
    digitalWrite(buzzer, LOW);
  }

  delay(100); // pequena pausa antes do próximo ciclo
}
