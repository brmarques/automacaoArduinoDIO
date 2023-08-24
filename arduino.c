#include <Arduino.h>

// Pinos para as lâmpadas
const int lampadaPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numLampadas = sizeof(lampadaPins) / sizeof(lampadaPins[0]);

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
  // Código para controlar os dispositivos
  // Exemplo: ligaLampada(2); // Ligar a lâmpada 2
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

void abrirCortinas() {
  digitalWrite(cortinaAbrirPin, HIGH);
  digitalWrite(cortinaFecharPin, LOW);
}

void fecharCortinas() {
  digitalWrite(cortinaAbrirPin, LOW);
  digitalWrite(cortinaFecharPin, HIGH);
}

void ligarArCondicionado() {
  digitalWrite(arCondicionadoPin, HIGH);
}

void desligarArCondicionado() {
  digitalWrite(arCondicionadoPin, LOW);
}

void ligarCafeteira() {
  digitalWrite(cafeteiraPin, HIGH);
}

void desligarCafeteira() {
  digitalWrite(cafeteiraPin, LOW);
}
