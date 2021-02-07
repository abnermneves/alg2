#include <iostream>
#include <fstream>
#include "funcoes.h"
#include "trie.h"
#include "lz78.h"

int main (int argc, char* argv[]) {
  
//--------------------------- FLUXO DE ARQUIVO ----------------------------//

    if (argc < 3)
        return 0;

    char operacao = argv[1][1];

    std::string fin, fout;
    fin = argv[2];
    

//---------------------- PROCESSAMENTO NO NOME DO ARQUIVO ------------------------//

    if (argc == 5 && argv[3][1] == 'o'){
        fout = argv[4];
    }
    else if (operacao == 'c'){
        fout = fin;
        if (fin.substr(fin.size()-4) == ".txt")
            fout = fin.substr(0, fin.size()-4);
        fout = fout + ".z78";
    }
    else if (operacao == 'd'){
        fout = fin.substr(0, fin.size()-4) + ".txt";
    }

    
//--------------------------- CHAMADAS DAS FUNÇÕES ----------------------------//

    if (operacao == 'c'){
        compressao(fin, fout);
    } else if (operacao == 'd'){
        decompressao(fin, fout);
    } else {
        std::cout << "Escolha uma operação válida." << std::endl;
    }

    return 0;
}