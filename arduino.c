#include <Arduino.h>

// Pinos para as lâmpadas
const int lampadaPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numLampadas = sizeof(lampadaPins) / sizeof(lampadaPins[0]);

// Pinos para os botões das lâmpadas
const int botaoPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};

// Pinos para as cortinas
const int cortinaAbrirPin = 10;
const int cortinaFecharPin = 11;

// Pinos para o ar condicionado e a cafeteira
const int arCondicionadoPin = 12;
const int cafeteiraPin = 13;

void setup() {
  for (int i = 0; i < numLampadas; i++) {
    pinMode(lampadaPins[i], OUTPUT);
    digitalWrite(lampadaPins[i], LOW); // Desligar as lâmpadas inicialmente
    pinMode(botaoPins[i], INPUT_PULLUP); // Configurar os botões como entrada com resistor pull-up
  }

  pinMode(cortinaAbrirPin, OUTPUT);
  pinMode(cortinaFecharPin, OUTPUT);
  pinMode(arCondicionadoPin, OUTPUT);
  pinMode(cafeteiraPin, OUTPUT);

  digitalWrite(cortinaAbrirPin, LOW); // Cortinas fechadas inicialmente
  digitalWrite(cortinaFecharPin, LOW);
  digitalWrite(arCondicionadoPin, LOW); // Ar condicionado desligado inicialmente
  digitalWrite(cafeteiraPin, LOW); // Cafeteira desligada inicialmente
}

void loop() {
  for (int i = 0; i < numLampadas; i++) {
    // Verificar se o botão da lâmpada i foi pressionado
    if (digitalRead(botaoPins[i]) == LOW) {
      // Inverter o estado da lâmpada i
      if (digitalRead(lampadaPins[i]) == HIGH) {
        desligaLampada(i + 1); // Desligar lâmpada
      } else {
        ligaLampada(i + 1); // Ligar lâmpada
      }
      
      // Aguardar um curto intervalo para evitar detecção falsa
      delay(50);
    }
  }
  
  // Verificar outras funcionalidades (cortinas, ar condicionado, cafeteira)
}

void ligaLampada(int lampadaNumero) {
  if (lampadaNumero >= 1 && lampadaNumero <= numLampadas) {
    digitalWrite(lampadaPins[lampadaNumero - 1], HIGH); // Ligar a lâmpada
  }
}

void desligaLampada(int lampadaNumero) {
  if (lampadaNumero >= 1 && lampadaNumero <= numLampadas) {
    digitalWrite(lampadaPins[lampadaNumero - 1], LOW); // Desligar a lâmpada
  }
}

void abreCortinas() {
  digitalWrite(cortinaAbrirPin, HIGH);
  digitalWrite(cortinaFecharPin, LOW);
}

void fechaCortinas() {
  digitalWrite(cortinaAbrirPin, LOW);
  digitalWrite(cortinaFecharPin, HIGH);
}

void ligaArCondicionado() {
  digitalWrite(arCondicionadoPin, HIGH);
}

void desligaArCondicionado() {
  digitalWrite(arCondicionadoPin, LOW);
}

void ligaCafeteira() {
  digitalWrite(cafeteiraPin, HIGH);
}

void desligaCafeteira() {
  digitalWrite(cafeteiraPin, LOW);
}
