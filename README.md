# Trabalho Arduino - SSC0142 - Redes de Computadores
Trabalho de Redes de Computadores - ICMC - 1 semestre - 2022


## Sumário
* [Grupo](#grupo)
* [Descrição do Projeto](#descrição-do-projeto)
* [Requisitos](#requisitos)
* [Tutorial da Utilização da Aplicação](#tutorial-da-utilização-da-aplicação)
* [Demonstração do funcionamento](#demonstracao-do-funcionamento)
* [Problemas encontrados](#problemas-encontrados)
* [Comentários adicionais](#comentários-adicionais)  

## Grupo
 - Rafael Corona | Número USP: 4769989
 - Leonardo Gabriel Fusineli Silva |  Número USP: 11218841
 - Luccas Stroppa Saliba Barizon | Número USP: 11275022

## Descrição do Projeto
Neste projeto, vamos implementar uma comunicação síncrona entre duas plataformas Arduino. A comunicação conta com detecção de erros feita por bit de paridade e um handshake simples entre emissor e receptor. Nosso grupo ficou responsável por programar o transmissor.

## Requisitos
Lista de componentes necessários para testar o projeto:
- Placa arduíno uno: 2
- Cabo usb AM/BM: 2
- computador: 2
- Jumpers macho/macho: 3  
Para poder testar o sistema, é necessário instalar nos 2 computadores a [interface de desenvolvimento Arduino](https://www.arduino.cc/en/software)  


## Tutorial da Utilização da Aplicação

### Montagem do circuito:  
Cada Arduino deve ser conectado a um computador com um cabo USB AM/BM. A comunicação entre os microcontroladores será feita com os 3 jumpers, que devem ser conectados nas portas 11, 12 e 13 de cada Arduino, como mostram as imagens:

![Circuito montado](/images/photo4974681665305684750.jpg)
![Arduinos em foco](/images/photo4974681665305684751.jpg)
![Portas utilizadas em foco](/images/photo4974681665305684752.jpg)
![Portas utilizadas em foco](/images/photo4974681665305684753.jpg)


### Configurando o Emissor
Para configurar o emissor, basta abrir e carregar o arquivo [Serial.ino](/src/Serial) pela Arduino IDE no microcontrolador escolhido como transmissor. Para enviar as mensagens, utilize o Monitor Serial.

### Configurando o Receptor
Para configurar o receptor, pegue o código do emissor disponível no [Git do grupo que programou o receptor](https://www.google.com) e o carregue no microcontrolador escolhido como receptor. Para ler as mensagens recebidas, utilize o Monitor Serial.

## Demonstração do funcionamento

- [Link para o video](https://drive.google.com/file/d/1oB4xWgB4pqJyI3-xkTnc5sU9GDMeOZTq/view?usp=sharing)  
- Visão do emissor, após enviar a mensagem "USP":  
![Portas utilizadas em foco](/images/captura-tela.png)  
- Visão do receptor, após receber a mensagem "USP":  
![Tela do receptor](/images/captura-tela-recep.jpg)

## Problemas encontrados  
## Comentários adicionais  
