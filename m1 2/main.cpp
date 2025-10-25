#include <iostream>
#include <fstream>
#include "tipos.cpp"
#include "structs.cpp"
using namespace std;

string hexParaBinario(string hex) {
    string binario = "";
    for (char& c : hex) {
        switch (toupper(c)) {
            case '0': binario += "0000"; break;
            case '1': binario += "0001"; break;
            case '2': binario += "0010"; break;
            case '3': binario += "0011"; break;
            case '4': binario += "0100"; break;
            case '5': binario += "0101"; break;
            case '6': binario += "0110"; break;
            case '7': binario += "0111"; break;
            case '8': binario += "1000"; break;
            case '9': binario += "1001"; break;
            case 'A': binario += "1010"; break;
            case 'B': binario += "1011"; break;
            case 'C': binario += "1100"; break;
            case 'D': binario += "1101"; break;
            case 'E': binario += "1110"; break;
            case 'F': binario += "1111"; break;
            case 'X': break;
        }
    }
    return binario;
}

int main (){

  fstream arquivo;
  string nomeArquivo;
  bool isHex = false;
  int tipoArquivo;

  cout << "Escolha o tipo de arquivo de entrada:" << endl;
  cout << "1 - Binário" << endl;
  cout << "2 - Hexadecimal" << endl;
  cin >> tipoArquivo;

  if (tipoArquivo == 1) {
      nomeArquivo = "./fib_rec_binario.txt";
  } else if (tipoArquivo == 2) {
      nomeArquivo = "./fib_rec_hexadecimal.txt";
      isHex = true;
  } else {
      cout << "Opção inválida." << endl;
      return 1;
  }

  arquivo.open(nomeArquivo);

  if (arquivo.is_open()) {
    cout << "Arquivo carregado com sucesso." << endl;
  } else {
    cout << "Erro ao carregar o arquivo " << nomeArquivo << endl;
    return 1;
  }

  string linhaLida;

  while (getline(arquivo, linhaLida)) {
    if (linhaLida.empty()) {
        continue;
    }

    string binarioString;
    if (isHex) {
        binarioString = hexParaBinario(linhaLida);
    } else {
        binarioString = linhaLida;
    }

    // primeiros 7 bits : tipo de instrução
    int bit32 = 25;
    string temp = "";
    int caracter;
    for (int j = 0; j < 7; j++) {
      bit32 = 25;
      bit32 += j;
      temp += binarioString[bit32];
      if (temp == "1100111" || // tipo I
        temp == "0000011" ||
        temp == "0010011" || 
        temp == "0001111" || 
        temp == "1110011") {
          InstrucaoTipoI instrucaoI;
          instrucaoI = tipoI(binarioString); // Chama a função para fazer a separação do restante do binário se baseando no template do tipo selecionado
          instrucaoI.opcode = temp;
          temp = "";
          cout << endl;
          cout << "opcode tipo I: " << instrucaoI.opcode << " : " << binarioParaImediato(instrucaoI.opcode) << endl;
          cout << instrucaoI.rd << " rd tipo I :" << binarioParaImediato(instrucaoI.rd) << endl;
          cout << instrucaoI.funct3 << " funct3 tipo I :" << binarioParaImediato(instrucaoI.funct3) << endl;
          cout << instrucaoI.rs1 << " rs1 tipo I:" << binarioParaImediato(instrucaoI.rs1) << endl;
          cout << instrucaoI.imm << " imm tipo I:"  << binarioParaImediato(instrucaoI.imm) << endl;
          cout << endl << endl;
          
          
        } else if (temp == "1101111") { // tipo J
          InstrucaoTipoJ instrucaoJ = tipoJ(binarioString);
          instrucaoJ.opcode = temp;

          cout << endl;
          cout << "opcode tipo J: " << instrucaoJ.opcode << endl;
          cout << instrucaoJ.rd << " rd tipo J: " << binarioParaImediato(instrucaoJ.rd) << endl;
          cout << instrucaoJ.imm_12_19 << " IMM_12_19 tipo J: " << binarioParaImediato(instrucaoJ.imm_12_19) << endl;
          cout << instrucaoJ.imm_11 << " IMM_11 tipo J: " << binarioParaImediato(instrucaoJ.imm_11) << endl;
          cout << instrucaoJ.imm_10_1 << " IMM_10_1 tipo J: " << binarioParaImediato(instrucaoJ.imm_10_1) << endl;
          cout << instrucaoJ.imm_20 << " IMM_20 tipo J: " << binarioParaImediato(instrucaoJ.imm_20) << endl;
          cout << endl << endl;

        } else if (temp == "0110011") { // tipo R
          InstrucaoTipoR instrucaoR = tipoR(binarioString);
          instrucaoR.opcode = temp;
          cout << instrucaoR.opcode << " opcode :" << binarioParaImediato(instrucaoR.opcode) << endl;
          cout << instrucaoR.rd << " rd tipo R :" << binarioParaImediato(instrucaoR.rd) << endl;
          cout << instrucaoR.funct3 << " funct3 tipo R :" << binarioParaImediato(instrucaoR.funct3) << endl;
          cout << instrucaoR.rs1 << " rs1 tipo R:" << binarioParaImediato(instrucaoR.rs1) << endl;
          cout << instrucaoR.rs2 << " rs2 tipo R:" << binarioParaImediato(instrucaoR.rs2) << endl;
          cout << instrucaoR.funct7 << " imm tipo R:"  << binarioParaImediato(instrucaoR.funct7) << endl;
          cout << endl << endl;

        } else if (temp == "0100011") { // Tipo S
          InstrucaoTipoS instrucaoS = tipoS(binarioString);
          instrucaoS.opcode = temp;
          cout << endl;
          cout << "opcode tipo S: " << instrucaoS.opcode << endl;
          cout << instrucaoS.imm_4_0 << " imm_4_0 tipo S: " << binarioParaImediato(instrucaoS.imm_4_0)<< endl;
          cout << instrucaoS.funct3 << " funct 3 tipo S: " << binarioParaImediato(instrucaoS.funct3)<< endl;
          cout << instrucaoS.rs1 << " rs1 tipo S: " << binarioParaImediato(instrucaoS.rs1)<< endl;
          cout << instrucaoS.rs2 << " rs2 tipo S: " << binarioParaImediato(instrucaoS.rs2)<< endl;
          cout << instrucaoS.imm_11_5 << " imm_11_5 tipo S: " << binarioParaImediato(instrucaoS.imm_11_5)<< endl;
          cout << endl << endl;

        } else if (temp == "1100011") { // tipo B
          InstrucaoTipoB instrucaoB = tipoB(binarioString);
          instrucaoB.opcode = temp;
          cout << endl;
          cout << "opcode tipo B: " << instrucaoB.opcode << endl;

          cout << instrucaoB.imm_1_1 << " imm11 tipo B: " << binarioParaImediato(instrucaoB.imm_1_1) << endl; 
          cout << instrucaoB.imm_4_1 << " imm4_1 tipo B: " << binarioParaImediato(instrucaoB.imm_4_1) << endl; 
          cout << instrucaoB.funct3 << " funct3 tipo B: " << binarioParaImediato(instrucaoB.funct3) << endl; 
          cout << instrucaoB.rs1 << " rs1 tipo B: " << binarioParaImediato(instrucaoB.rs1) << endl; 
          cout << instrucaoB.rs2 << " rs2 tipo B: " << binarioParaImediato(instrucaoB.rs2) << endl; 
          cout << instrucaoB.imm_10_5 << " imm_10_5 tipo B: " << binarioParaImediato(instrucaoB.imm_10_5) << endl;
          cout << instrucaoB.imm_12 << " imm_12 tipo B: " << binarioParaImediato(instrucaoB.imm_12) << endl; 
          cout << endl << endl;

          
        } else if (temp == "0010111" || temp == "0110111") { // tipo U
          InstrucaoTipoU instrucaoU = tipoU(binarioString);
          instrucaoU.opcode = temp;
          cout << endl;
          cout << "opcode tipo U: " << instrucaoU.opcode << endl;
          cout << instrucaoU.rd << " rd tipo U: " << binarioParaImediato(instrucaoU.rd) << endl;
          cout << instrucaoU.imm_12_31 << " IMM_12_31 tipo U: " << binarioParaImediato(instrucaoU.imm_12_31) << endl;
          cout << endl << endl;
        } 
    } 
  }

  arquivo.close();
}
