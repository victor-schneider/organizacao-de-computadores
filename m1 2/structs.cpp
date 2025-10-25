#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <iostream>
using namespace std;

struct InstrucaoTipoR {
    // 0 - 6 -- Identificador
    string opcode = "0";
    // 7 - 11 -- RD
    string rd = "0";
    // 12 - 14 -- RM
    string funct3 = "0";
    // 15 - 19 -- RS1
    string rs1 = "0";
    // 20 - 24 -- RS2
    string rs2 = "0";
    // 25 - 31 -- Funct7
    string funct7 = "0";
  };

  struct InstrucaoTipoI {
    // 0 - 6 -- Identificador
    string opcode = "0";
    // 7 - 11 -- RD
    string rd = "0";
    // 12 - 14 -- Funct3
    string funct3 = "0";
    // 15 - 19 -- RS1
    string rs1 = "0";
    // 20 - 31 -- IMM[11]
    string imm = "0";
  };

  struct InstrucaoTipoS {
    // 0 - 6 -- Identificador
    string opcode = "0";
    // 7 - 11 -- RD
    string imm_4_0 = "0";
    // 12 - 14 -- RM
    string funct3 = "0";
    // 15 - 19 -- RS1
    string rs1 = "0";
    // 20 - 24 -- RS2
    string rs2 = "0";
    // 25 - 31 -- IMM[11:5]
    string imm_11_5 = "0";
  };

  struct InstrucaoTipoB {
    // 0 - 6 -- Identificador
    string opcode = "0";
    // 6 - 7 -- IMM[11]
    string imm_1_1 = "0";
    // 7 - 11 -- IMM[4:1]
    string imm_4_1 = "0";
    // 12 - 14 -- RM
    string funct3 = "0";
    // 15 - 19 -- RS1
    string rs1 = "0";
    // 20 - 24 -- RS2
    string rs2 = "0";
    // 25 - 30 -- IMM[10:5]
    string imm_10_5 = "0";
    // 30 - 31 -- IMM[12]
    string imm_12 = "0";
  };

  struct InstrucaoTipoU {
    // 0 - 6 -- Identificador
    string opcode = "0";
    // 7 - 11 -- RD
    string rd = "0";
    // 12 - 31 -- IMM[12:31]
    string imm_12_31 = "0";
  };

  struct InstrucaoTipoJ {
    // 0 - 6 -- Identificador
    string opcode = "0";
    // 7 - 11 -- RD
    string rd = "0";
    // 12 - 19 -- IMM[19:12]
    string imm_12_19 = "0";
    // 20 - 21 -- IMM[11]
    string imm_11 = "0";
    // 22 - 30 -- IMM[10:1]
    string imm_10_1 = "0";
    // 31 -- IMM[12]
    string imm_20 = "0";
  };

  #endif
