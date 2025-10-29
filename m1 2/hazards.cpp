#include <iostream>
#include <fstream>
#include <vector>
#include "hazards.h"
using namespace std;

int conflitoDadosSemFw(vector<InstrucaoDecodificada>& programa) {
    int contagemConflitos = 0;
    string REG_ZERO = "00000";
    string REG_NULO = "-1";

    for (int i = 1; i < programa.size(); ++i) {

        string& atual_rs1 = programa[i].rs1;
        // cout << "RS1 Atual"<< atual_rs1 << endl;
        string& atual_rs2 = programa[i].rs2;
        // cout << "RS2 Atual" << atual_rs2 << endl;

        if(atual_rs1 == REG_NULO && atual_rs2 == REG_NULO) {
          continue;
        }

        string& prev1_rd = programa[i-1].rd;
        // cout << "RD Anterior" << prev1_rd << endl;

        if (prev1_rd != REG_NULO && prev1_rd != REG_ZERO) {
            if (prev1_rd == atual_rs1 || prev1_rd == atual_rs2) {
                contagemConflitos++;
            }
        }

        if(i >= 2) {
          string& prev2_rd = programa[i-2].rd;
          if (prev2_rd != REG_NULO && prev2_rd != REG_ZERO) {
            if (prev2_rd == atual_rs1 || prev2_rd == atual_rs2) {
                contagemConflitos++;
            }
          }
        }
    }

    return contagemConflitos;
}

int conflitoDadosComFw(vector<InstrucaoDecodificada> &programa) {
      int contagemConflitos = 0;
      string REG_ZERO = "00000";
      string REG_NULO = "-1";

      for (int i = 1; i < programa.size(); i++) {
        if( programa[i-1].loadWord ) {
          string& lw_rd = programa[i-1].rd;
          // cout << "lw_rd: " << lw_rd << endl;

          if(lw_rd == REG_NULO || lw_rd == REG_ZERO) {
            continue;
          }

          string atual_rs1 = programa[i].rs1;
          // cout << "atual_rs1: " << atual_rs1 << endl;
          string atual_rs2 = programa[i].rs2;
          // cout << "atual_rs2: " << atual_rs2 << endl;

          if (lw_rd == atual_rs1 || lw_rd == atual_rs2) {
            contagemConflitos++;
          }
        }
      }

      return contagemConflitos;
    }

    int conflitoControle(vector<InstrucaoDecodificada>& programa) {
      int contagemConflitos = 0;

      for (int i = 0; i < programa.size(); i++) {
        if(programa[i].desvio) {
          contagemConflitos++;
          cout << programa[i].instrucaoOriginal << endl;
        }
      }

      return contagemConflitos;
    }
