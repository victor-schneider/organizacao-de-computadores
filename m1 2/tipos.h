#ifndef TIPOS_HPP
#define TIPOS_HPP

#include "structs.h"
#include <string>
using namespace std;

int binarioParaImediato (string binario);
InstrucaoTipoR tipoR (string binarioString);
InstrucaoTipoI tipoI (string binarioString);
InstrucaoTipoS tipoS (string binarioString);
InstrucaoTipoB tipoB (string binarioString);
InstrucaoTipoU tipoU (string binarioString);
InstrucaoTipoJ tipoJ (string binarioString);


#endif
