// Codificação do controle do braço seletor de cor //

#include <Servo.h>

// Conexões do sensor
const int s0 = 9; 
const int s1 = 10; 
const int s2 = 11; 
const int s3 = 12; 
const int out = 8; 
const int rele = 4;
  
// Variáveis 
int red = 0; 
int green = 0; 
int blue = 0; 

// Define os servos
Servo servoBase;
Servo servoAvanco;
Servo servoGarra;

// Pinos de conexão
const int pinBase = 3;
const int pinAvanco = 5;
const int pinGarra = 6;

// Posições iniciais
const int baseInicial = 30;
const int avancoInicial = 80;
const int garraInicial = 120;

int posBase = baseInicial;
int posAvanco = avancoInicial;
int posGarra = garraInicial;

// Limites de movimento
const int passo = 1;
const int delayMov = 10;

// Posição 1 (Esquerda menor)
const int baseEsquerda = 80;
const int avancoEsquerda = 140;
const int garraEsquerda = 45;

// Posição 2 (Esquerda média)
const int baseDireita = 125;
const int avancoDireita = 140;
const int garraDireita = 45;

// Posição 3 (Esquerda maior)
const int basedireita = 170;

void setup() {
  Serial.begin(9600);

  // Parâmetros do sensor
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  pinMode(out, INPUT);
  pinMode(rele, OUTPUT); 
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, LOW);
  digitalWrite(rele,HIGH);

  // Determinação das portas relacionadas ao braço
  servoBase.attach(pinBase);
  servoAvanco.attach(pinAvanco);
  servoGarra.attach(pinGarra);

  // Vai para posição inicial
  servoBase.write(posBase);
  servoAvanco.write(posAvanco);
  servoGarra.write(posGarra);
  delay(500);
}

void loop() {
  
  color(); // Função de leitura da cor
  Serial.print("R Intensity:"); 
  Serial.print(red, DEC); 
  Serial.print(" B Intensity : "); 
  Serial.print(blue, DEC);
  Serial.print(" G Intensity : "); 
  Serial.print(green, DEC);

  if (red <= 30 && blue > 50 && green > 50) 
  { 
   Serial.println(" Laranja"); 
   delay(300);
  } 

  else if (blue <= 40 && red <= 40 && green <= 40) 
  { 
   Serial.println(" Branco"); 
   delay(300);
  } 
  
  else if (blue <= 80 && red >= 100 && green >= 100){
  Serial.println(" Azul");
  delay(300); 
  } 
  
  else{
  Serial.println(); 
  }

    if (red <= 50 && blue >= 70 && green >= 70) { // Leitura da cor laranja
      
      // Desligar esteira
      digitalWrite(rele,LOW);
      
      // Pegar a peça
      moverServoPassoAPasso(servoAvanco, posAvanco, avancoEsquerda);
      posAvanco = avancoEsquerda;

      moverServoPassoAPasso(servoGarra, posGarra, garraEsquerda);
      posGarra = garraEsquerda;

      moverServoPassoAPasso(servoAvanco, posAvanco, avancoInicial);
      posAvanco = avancoInicial;

      // Move para esquerda
      moverServoPassoAPasso(servoBase, posBase, baseEsquerda);
      posBase = baseEsquerda;

      moverServoPassoAPasso(servoAvanco, posAvanco, avancoEsquerda);
      posAvanco = avancoEsquerda;

      moverServoPassoAPasso(servoGarra, posGarra, garraInicial);
      posGarra = garraInicial;

      delay(300); // Pequena pausa

      // Volta à posição inicial
      moverServoPassoAPasso(servoAvanco, posAvanco, avancoInicial);
      posAvanco = avancoInicial;

      moverServoPassoAPasso(servoBase, posBase, baseInicial);
      posBase = baseInicial;

      // Ligar esteira
      digitalWrite(rele,HIGH);

    } else if (blue <= 40 && red <= 40 && green <= 40) { // Leitura da cor branca

      // Desligar esteira
      digitalWrite(rele,LOW);
      
      // Pegar a peça
      moverServoPassoAPasso(servoAvanco, posAvanco, avancoEsquerda);
      posAvanco = avancoEsquerda;

      moverServoPassoAPasso(servoGarra, posGarra, garraEsquerda);
      posGarra = garraEsquerda;

      moverServoPassoAPasso(servoAvanco, posAvanco, avancoInicial);
      posAvanco = avancoInicial;
      
      // Move para direita
      moverServoPassoAPasso(servoBase, posBase, baseDireita);
      posBase = baseDireita;

      moverServoPassoAPasso(servoAvanco, posAvanco, avancoDireita);
      posAvanco = avancoDireita;

      moverServoPassoAPasso(servoGarra, posGarra, garraInicial);
      posGarra = garraInicial;

      delay(300); // Pequena pausa

      // Volta à posição inicial
      
      moverServoPassoAPasso(servoAvanco, posAvanco, avancoInicial);
      posAvanco = avancoInicial;

      moverServoPassoAPasso(servoBase, posBase, baseInicial);
      posBase = baseInicial;

      // Ligar esteira
      digitalWrite(rele,HIGH);

    } else if (blue <= 80 && red >= 100 && green >= 100) { // Leitura da cor azul

      // Desligar esteira
      digitalWrite(rele,LOW);
      
      // Pegar a peça
      moverServoPassoAPasso(servoAvanco, posAvanco, avancoEsquerda);
      posAvanco = avancoEsquerda;

      moverServoPassoAPasso(servoGarra, posGarra, garraEsquerda);
      posGarra = garraEsquerda;

      moverServoPassoAPasso(servoAvanco, posAvanco, avancoInicial);
      posAvanco = avancoInicial;
      
      // Move para direita
      moverServoPassoAPasso(servoBase, posBase, basedireita);
      posBase = basedireita;

      moverServoPassoAPasso(servoAvanco, posAvanco, avancoDireita);
      posAvanco = avancoDireita;

      moverServoPassoAPasso(servoGarra, posGarra, garraInicial);
      posGarra = garraInicial;

      delay(300); // Pequena pausa

      // Volta à posição inicial
      
      moverServoPassoAPasso(servoAvanco, posAvanco, avancoInicial);
      posAvanco = avancoInicial;

      moverServoPassoAPasso(servoBase, posBase, baseInicial);
      posBase = baseInicial;

      // Ligar esteira
      digitalWrite(rele,HIGH);
    }
}

// Função de movimento passo a passo
void moverServoPassoAPasso(Servo &servo, int posAtual, int posFinal) {
  if (posFinal > posAtual) {
    for (int i = posAtual; i <= posFinal; i += passo) {
      servo.write(i);
      delay(delayMov);
    }
  } else {
    for (int i = posAtual; i >= posFinal; i -= passo) {
      servo.write(i);
      delay(delayMov);
    }
  }
}

// Função da leitura e identificação das cores
void color() 
{   
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  //count OUT, pRed, RED 
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  digitalWrite(s3, HIGH); 
  //count OUT, pBLUE, BLUE 
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  digitalWrite(s2, HIGH); 
  //count OUT, pGreen, GREEN 
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  delay(200);
}
