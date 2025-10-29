#ifndef HAZARDS_HPP
#define HAZARDS_HPP

#include <vector>
#include "structs.h"
using namespace std;

int conflitoDadosSemFw(vector<InstrucaoDecodificada>& programa);

int conflitoDadosComFw(vector<InstrucaoDecodificada>& programa);

int conflitoControle(vector<InstrucaoDecodificada>& programa);

#endif
