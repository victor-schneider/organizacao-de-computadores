#include "instrucoes.h"
#include <iostream>
using namespace std;

string rd (string &binarioString) {
  int bit32 = 20; 
  string temp;

  for (int i = 0; i < 5; i++) { // bits do Registrador de Destino
    bit32 += i;
    temp += binarioString[bit32];
    bit32 = 20;
  }

  return temp;
}


string funct3 (string &binarioString) {
  int bit32;
  string temp;

  for (int i = 0; i < 3; i++) { // bits ula
    bit32 = 17;
    bit32 += i;
    temp += binarioString[bit32];
  }

  return temp;
}


string rs1 (string &binarioString) {
  int bit32;
  string temp;
  for (int i = 0; i < 5; i++) { // bits rs1
    bit32 = 12;
    bit32 += i;

    temp += binarioString[bit32];
  }
  

  return temp;
}


string rs2 (string &binarioString) {
  int bit32;
  string temp;

  for (int i = 0; i < 5; i++) {
    bit32 = 7;
    bit32 += i;

    temp += binarioString[bit32];
  }

  return temp;
}


string funct7 (string &binarioString) {
  int bit32;
  string temp;

  for (int i = 0; i < 7; i++) {
    bit32 = 0;
    bit32 += i;

    temp += binarioString[bit32];
  }
  
  return temp;
}


string imediatoTipoI (string &binarioString) {
  int bit32;
  string temp;

  for (int i = 0; i < 12; i++) {
    bit32 = 0;
    bit32 += i;
    temp += binarioString[bit32];
  }

  return temp;
}


void imediatoTipoS (string &binarioString, InstrucaoTipoS &tipoS) {
  int bit32;
  string temp;

  for (int i = 0; i < 5; i++) {
    bit32 = 20;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoS.imm_4_0 = temp;
  temp = "";

  for (int i = 0; i < 7; i++) {
    bit32 = 0;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoS.imm_11_5 = temp;
  temp = "";

}

void imediatoTipoB (string &binarioString, InstrucaoTipoB &tipoB) {
  int bit32;
  string temp;

  tipoB.imm_1_1 = binarioString[24];

  for (int i = 0; i < 4; i++){
    bit32 = 20;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoB.imm_4_1 = temp;
  temp = "";

  for (int i = 0; i < 6; i++) {
    bit32 = 1;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoB.imm_10_5 = temp;
  temp = "";

  tipoB.imm_12 = binarioString[0];
}

void imediatoTipoU (string &binarioString, InstrucaoTipoU &tipoU ) {
  int bit32;
  string temp;

  for (int i = 0; i < 20; i++) {
    bit32 = 0;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoU.imm_12_31 = temp;
  temp = "";
}

void imediatoTipoJ (string &binarioString, InstrucaoTipoJ &tipoJ) {
  int bit32;
  string temp;

  for ( int i = 0; i < 8; i++) {
    bit32 = 12;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoJ.imm_12_19 = temp;
  temp = "";

  tipoJ.imm_11 = binarioString[11];

  for (int i = 0; i < 10; i++) {
    bit32 = 1;
    bit32 += i;
    temp += binarioString[bit32];
  }

  tipoJ.imm_10_1 = temp;
  temp = "";

  tipoJ.imm_20 = binarioString[0];

}
