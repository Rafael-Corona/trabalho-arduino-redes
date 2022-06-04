
#define PINO_RX 13
#define PINO_TX 13
#define BAUD_RATE 1
#define HALF_BAUD 1000/(2*BAUD_RATE)

#include "Temporizador.h"

// Calcula bit de paridade - Par ou impar
bool bitParidade(char dado){

  int numeroBits1 = 0;

  /*Exemplo:
    dado = 01101010 = 106
    é par, então não aumenta numeroBits1
    dado >> 1 (left shift)
    dado = 00110101 = 53
    é ímpar, então numeroBits1++
  */
  while(dado != 0)
  {
    numeroBits1 += dado%2; 
    dado >>1;
  }

  //A paridade do dado eh impar, setar bit de paridade como 1
  if(numeroBits1 % 2 == 1) return true;
  
  //A paridade do dado eh par, setar bit de paridade como zero
  else return false;
}

// Rotina de interrupcao do timer1
// O que fazer toda vez que 1s passou?
ISR(TIMER1_COMPA_vect){
  //>>>> Codigo Aqui <<<<
}

// Executada uma vez quando o Arduino reseta
void setup(){
  //desabilita interrupcoes
  noInterrupts();
  // Configura porta serial (Serial Monitor - Ctrl + Shift + M)
  Serial.begin(9600);
  // Inicializa TX ou RX
  //>>>> Codigo Aqui <<<<
  // Configura timer
  //>>>> Codigo Aqui <<<<
  // habilita interrupcoes
  interrupts();
}

// O loop() eh executado continuamente (como um while(true))
void loop ( ) {
  //>>>> Codigo Aqui <<<<
}
