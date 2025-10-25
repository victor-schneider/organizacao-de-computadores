#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tipos.h"
#include "hazards.h"

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
  int enderecoAtual = 0;
  vector <InstrucaoDecodificada> programa;

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
          
          InstrucaoDecodificada inst;
          inst.rd = inst.rd;
          inst.rs1 = inst.rs1;
          inst.instrucaoOriginal = linhaLida;
          inst.endereco = enderecoAtual;
          inst.desvio = false;

          programa.push_back(inst);
          
        } else if (temp == "1101111") { // tipo J
          InstrucaoTipoJ instrucaoJ = tipoJ(binarioString);
          instrucaoJ.opcode = temp;

          InstrucaoDecodificada inst;
          inst.rd = instrucaoJ.rd;
          inst.desvio = true;
          
          programa.push_back(inst);

        } else if (temp == "0110011") { // tipo R
          InstrucaoTipoR instrucaoR = tipoR(binarioString);
          instrucaoR.opcode = temp;
          
          InstrucaoDecodificada inst;
          inst.rs1 = instrucaoR.rs1;
          inst.rs2 = instrucaoR.rs2;
          inst.rd = instrucaoR.rd;
          inst.desvio = false;
          inst.instrucaoOriginal = linhaLida;
          inst.endereco = enderecoAtual;

          programa.push_back(inst);

        } else if (temp == "0100011") { // Tipo S
          InstrucaoTipoS instrucaoS = tipoS(binarioString);
          instrucaoS.opcode = temp;
   
          InstrucaoDecodificada inst;
          inst.rs1 = instrucaoS.rs1;
          inst.rs2 = instrucaoS.rs2;
          inst.instrucaoOriginal = linhaLida;
          inst.desvio = false;
          inst.endereco = enderecoAtual;

          programa.push_back(inst);

        } else if (temp == "1100011") { // tipo B
          InstrucaoTipoB instrucaoB = tipoB(binarioString);
          instrucaoB.opcode = temp;

          InstrucaoDecodificada inst;
          inst.rs1 = instrucaoB.rs1;
          inst.rs2 = instrucaoB.rs2;
          inst.desvio = true;
          inst.instrucaoOriginal = linhaLida;
          inst.endereco = enderecoAtual;

          programa.push_back(inst);

        } else if (temp == "0010111" || temp == "0110111") { // tipo U        
          InstrucaoTipoU instrucaoU = tipoU(binarioString);
          instrucaoU.opcode = temp;

          InstrucaoDecodificada inst;
          inst.rd = instrucaoU.rd;
          inst.instrucaoOriginal = linhaLida;
          inst.endereco = enderecoAtual;

          programa.push_back(inst);
        } 
    } 
    enderecoAtual += 4;
  }
  arquivo.close();

  int conflitos_dados_sfwd = conflitoDadosSemFw(programa);
  cout << conflitos_dados_sfwd;
}
