#define PINO_RX 13
#define CTS 11
#define RTS 12
#define PINO_TX 13
#define BAUD_RATE 1
#define HALF_BAUD 1000/(2*BAUD_RATE)

#include "Temporizador.h"

//Variavel auxiliar que verifica se o temporizador ja foi iniciado alguma vez, e variavel auxiliar que serve para finalizar a transmissao.
int aux, finaliza;
//Variavel auxiliar que verifica se ja pode ler um novo caractere do serial monitor.
int pode_ler;
//Variavel auxiliar para lermos os bits de um caractere(composto de 8 bits).
int index;
//Variavel que usaremos para lermos os caracteres do Serial monitor.
char value;

// Calcula bit de paridade - Par ou impar
bool bitParidade(char dado){

  int numeroBits1 = 0;
  int i = 0;
  
  //Loop que soma todos os digitos do caractere em forma binaria.
  while(i < 8){
    numeroBits1 += bitRead(dado, i);
    i++;
  }

  //A paridade do dado eh impar, setar bit de paridade como 1
  if(numeroBits1 % 2 == 1) return true;
  
  //A paridade do dado eh par, setar bit de paridade como zero
  else return false;
}

//printa no serial monitor o dado que está sendo enviado
void MostraChar(char dado){

    Serial.print("Enviando o caracter \'");
    if(value != '\n'){
      Serial.print(dado);
    }
    else{
      Serial.print("\\n");
    }
    Serial.print("\' e o bit de paridade:");
}

// Rotina de interrupcao do timer1
// O que fazer toda vez que 1s passou?
ISR(TIMER1_COMPA_vect){
  //Se o Serial monitor tem caracteres disponiveis para serem lidos e podemos ler:
  if(Serial.available() && pode_ler == 1){
    //Seta a variavel auxiliar para 0 até que o caractere tenha sido enviado por completo.
    pode_ler = 0;
    //Lê o caractere.
    value = Serial.read();

    MostraChar(value); //visualizacao
  }

 
  
  //Se pode_ler é igual a 0 quer dizer que já temos um caractere para ser enviado.
  if(pode_ler == 0){


    //Se a posição do bit do caractere a ser enviado estiver entre 0 e 7:
    if(index >= 0 && index <= 7){
      
      //Se o bit for 1, setamos o pino 13 para o nivel alto.
      if(bitRead(value, index) == 1){
        digitalWrite(PINO_TX, HIGH);
        Serial.print(digitalRead(PINO_TX));
      }//Se o bit for 0, setamos o pino 13 para o nivel baixo.
      else{
        digitalWrite(PINO_TX, LOW);
        Serial.print(digitalRead(PINO_TX));
      }
      //Decrementamos o index para que na proxima interrupção o próximo bit seja transmitido.
      index--;
    }//Se o index não estiver entre 0 e 7 quer dizer que transmitimos todos os bits do caractere, e agora iremos transmitir o bit de paridade.
    else{
      
      //Enviamos o bit de paridade correto:
      if(bitParidade(value) == true){
      	digitalWrite(PINO_TX, HIGH);
        Serial.println(digitalRead(13));
      }else{
      	digitalWrite(PINO_TX, LOW);
        Serial.println(digitalRead(13));
      }
      
      //Setamos o index para 7, para enviarmos o bit correto do próximo caractere.
      index = 7;
      //Setamos pode_ler para 1 para que o próximo caractere possa ser lido do serial monitor.
      pode_ler = 1;
      
      //Caso não haja mais caracteres para serem lidos setamos finaliza para 1 para encerrarmos a transmissao.
      if(!Serial.available()){
        finaliza = 1;
      }
    }
  }
  
}

// Executada uma vez quando o Arduino reseta
void setup(){
  //desabilita interrupcoes
  noInterrupts();
  // Configura porta serial (Serial Monitor - Ctrl + Shift + M)
  Serial.begin(9600);
  // Inicializa TX
  pinMode(PINO_TX,OUTPUT);
  // Configura timer
  configuraTemporizador(BAUD_RATE);
  // habilita interrupcoes
  interrupts();
  
  //Inicializa o RTS.
  pinMode(RTS, OUTPUT);
  
  //Inicializa o CTS.
  pinMode(CTS, INPUT);
  
  //Seta o RTS para 0.
  digitalWrite(RTS, LOW);
  
  //Inicializa as variaveis auxiliares.
  aux = 0;
  finaliza = 0;
  pode_ler = 1;
  index = 7;
  value = '\0';
}



// O loop() eh executado continuamente (como um while(true))
void loop ( ) {
  
  //Se o temporizador nunca foi inicializado e há input do usuário, setamos o RTS para 1
  if(aux == 0 && Serial.available() > 0){
    aux++;
    digitalWrite(RTS, HIGH);
  }else if(digitalRead(CTS) == HIGH && aux == 1){
    aux++;
    iniciaTemporizador();
  }//Se finaliza é igual a 1, paramos o temporizador e setamos o RTS para 0.
  else if(finaliza == 1){
    paraTemporizador();
    delay(HALF_BAUD);
    digitalWrite(RTS, LOW);
    finaliza = 0;
    aux = 0;
  }
  
}
