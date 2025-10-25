#include <iostream>
#include "structs.cpp"
#include "instrucoes.cpp"
using namespace std;

int binarioParaImediato (string binario) {
  int c = binario.length() - 1; // para comecar no ultimo indice da string
  int aux = 1;
  int resultado = 0;
  
  do {
    if(binario[c] == '1' && c == binario.length() - 1) {  // Verificando somente o primeiro
      resultado = 1;
    } else if (binario[c] == '1') { // para percorrer o restante da string, pois a cada loop c vale 1 a menos
      resultado += aux;
    }
    aux = aux * 2; // potencia de 2
    c--;
  } while (c >= 0);

  return resultado;
}

InstrucaoTipoR tipoR (string binarioString) {
  InstrucaoTipoR tipoR;

  tipoR.rd = rd(binarioString);
  tipoR.funct3 = funct3(binarioString);
  tipoR.rs1 = rs1(binarioString);
  tipoR.rs2 = rs2(binarioString);
  tipoR.funct7 = funct7(binarioString);

  return tipoR;
}

InstrucaoTipoI tipoI (string binarioString) {
  InstrucaoTipoI tipoI;

  tipoI.rd = rd(binarioString);
  tipoI.funct3 = funct3(binarioString);
  tipoI.rs1 = rs1(binarioString);
  tipoI.imm = imediatoTipoI(binarioString);
  
  return tipoI;
}

InstrucaoTipoS tipoS (string binarioString) {
  InstrucaoTipoS tipoS;

  tipoS.funct3 = funct3(binarioString);
  tipoS.rs1 = rs1(binarioString);
  tipoS.rs2 = rs2(binarioString);
  imediatoTipoS(binarioString, tipoS);

  return tipoS;
} 

InstrucaoTipoB tipoB (string binarioString) {
  InstrucaoTipoB tipoB;

  tipoB.funct3 = funct3(binarioString);
  tipoB.rs1 = rs1(binarioString);
  tipoB.rs2 = rs2(binarioString);
  imediatoTipoB(binarioString, tipoB);

  return tipoB;
}

InstrucaoTipoU tipoU (string binarioString) {
  InstrucaoTipoU tipoU;

  tipoU.rd = rd(binarioString);
  imediatoTipoU(binarioString, tipoU);

  return tipoU;
}

InstrucaoTipoJ tipoJ (string binarioString) {
  InstrucaoTipoJ tipoJ;

  tipoJ.rd = rd(binarioString);
  imediatoTipoJ(binarioString, tipoJ);

  return tipoJ;
}
