#include <iostream>
#include <fstream>
#include <vector>
#include "hazards.h"
using namespace std;

int conflitoDadosSemFw(vector<InstrucaoDecodificada>& programa) {
    int contagemConflitos = 0;
    string REG_ZERO = "00000";
    string REG_NULO = "-1";

    for (int i = 2; i < programa.size(); ++i) {

        string& atual_rs1 = programa[i].rs1;
        string& atual_rs2 = programa[i].rs2;
        string& prev1_rd = programa[i-1].rd;
        string& prev2_rd = programa[i-2].rd;

        if (prev1_rd != REG_NULO && prev1_rd != REG_ZERO) {
            if (prev1_rd == atual_rs1 || prev1_rd == atual_rs2) {
                contagemConflitos++;
            }
        }

        if (prev2_rd != REG_NULO && prev2_rd != REG_ZERO) {
            if (prev2_rd == atual_rs1 || prev2_rd == atual_rs2) {
                contagemConflitos++;
            }
        }
    }
    return contagemConflitos;
}
