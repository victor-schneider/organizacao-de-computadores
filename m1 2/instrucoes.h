#ifndef INSTRUCOES_HPP
#define INSTRUCOES_HPP

#include "structs.h"
using namespace std;

string rd (string &binarioString);
string funct3 (string &binarioString);
string rs1 (string &binarioString);
string rs2 (string &binarioString);
string funct7 (string &binarioString);
string imediatoTipoI (string &binarioString);
void imediatoTipoS (string &binarioString, InstrucaoTipoS &tipoS);
void imediatoTipoB (string &binarioString, InstrucaoTipoB &tipoB);
void imediatoTipoU (string &binarioString, InstrucaoTipoU &tipoU );
void imediatoTipoJ (string &binarioString, InstrucaoTipoJ &tipoJ);

#endif
