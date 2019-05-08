int s1, s2, s3;

//sensor A
#define Sesquerda A0

//sensor B
#define Smeio A1

//sensor C
#define Sdireita A2

//motor A
int A1N1 = 5;
int A1N2 = 4;
int velocidadeA = 3;

//motor B
int B1N1 = 7;
int B1N2 = 9;
int velocidadeB = 6;

//valores dos sensores
#define preto 700
#define branco 100
//variavel auxiliar
int velocidade = 0;
/*
#include <Ultrasonic.h>
#define pino_trigger 12
#define pino_echo 13
Ultrasonic ultrasonic(pino_trigger, pino_echo);
*/ 

void setup() {

  pinMode(Sesquerda, INPUT);
  pinMode(Smeio, INPUT);
  pinMode(Sdireita, INPUT);
  pinMode(A1N1, OUTPUT);
  pinMode(A1N2, OUTPUT);
  pinMode(B1N1, OUTPUT);
  pinMode(B1N2, OUTPUT);
  pinMode(velocidadeA, OUTPUT);
  pinMode(velocidadeB, OUTPUT);
}

void loop() {

  s1 = analogRead(Sesquerda);
  s2 = analogRead(Smeio);
  s3 = analogRead(Sdireita);

  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, HIGH);
  digitalWrite(A1N2, HIGH);
  digitalWrite(B1N1, HIGH);
  digitalWrite(B1N2, HIGH);

  if (s1 >= preto && s2 >= preto && s3 >= preto) //encruzilhada
  {
    analogWrite(velocidadeA, 51);
    analogWrite(velocidadeB, 51);
    delay(1000);

  }

  else

  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }

  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, LOW);
  digitalWrite(A1N2, LOW);
  digitalWrite(B1N1, HIGH);
  digitalWrite(B1N2, HIGH);

  //verde
  if ((s1 >= branco && s1 <= preto ) && s2 >= preto && s3 <= branco) //curva esquerda
  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 51);
    delay(1000);
  }
  else
  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);
    Serial.println("Motor A=1 Motor B=1");
    delay(1000);
  }
  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, HIGH);
  digitalWrite(A1N2, HIGH);
  digitalWrite(B1N1, HIGH);
  digitalWrite(B1N2, HIGH);
  if (s1 <= branco && s2 >= preto && s3 <= branco) //linha reta
  {
    analogWrite(velocidadeA, 51);
    analogWrite(velocidadeB, 51);
  
    delay(1000);
  }
  else
  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);

    delay(1000);
  }

  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, HIGH);
  digitalWrite(A1N2, HIGH);
  digitalWrite(B1N1, LOW);
  digitalWrite(B1N2, LOW);

  //verde
  if (s1 <= branco && s2 >= preto && (s3 >= branco && s3 <= preto ))//curva direita
  {
    analogWrite(velocidadeA, 51);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }
  else {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }
  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, HIGH);
  digitalWrite(A1N2, HIGH);
  digitalWrite(B1N1, HIGH);
  digitalWrite(B1N2, HIGH);
  if (s1 <= branco && s2 <= branco && s3 <= branco)//gap
  {
    analogWrite(velocidadeA, 51);
    analogWrite(velocidadeB, 51);
    delay(1000);
  }
  else
  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }
  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, HIGH);
  digitalWrite(A1N2, LOW);
  digitalWrite(B1N1, HIGH);
  digitalWrite(B1N2, LOW); // problema

  //verde                                     //verde
  if ((s1 <= branco && s1 <= preto && s2 >= preto && (s3 >= branco && s3 <= preto))) //giro de 180
  {
    analogWrite(velocidadeA, 51);
    analogWrite(velocidadeB, 51);
    delay(1000);
  }

  else
  {
   analogWrite(velocidadeA, 0);
   analogWrite(velocidadeB, 0);
    delay(1000);
  }
  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, HIGH);
  digitalWrite(A1N2, HIGH);
  digitalWrite(B1N1, LOW);
  digitalWrite(B1N2, LOW);

  if (s1 <= branco && s2 >= preto && s3 >= preto) // direita
  {
    analogWrite(velocidadeA, 51);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }
  else
  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }

  //estabelecendo o sentido de giro dos motores

  digitalWrite(A1N1, LOW);
  digitalWrite(A1N2, LOW);
  digitalWrite(B1N1, HIGH);
  digitalWrite(B1N2, HIGH);
  if (s1 >= preto && s2 <= branco && s3 <= branco) // esquerda
  {
    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 51);
    delay(1000);
  }
  else
  {

    analogWrite(velocidadeA, 0);
    analogWrite(velocidadeB, 0);
    delay(1000);
  }
   /* float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
if(cmMsec <= 16)
{
  //COLOCAR OBSTACULO _ GIRO A DIREITA > ESQUERDA > ESQUERDA > DIREITA
}*/
}

