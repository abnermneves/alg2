#include "lz78.h"
#include "trie.h"
#include <iostream>
#include <string>

void compressao(std::string fin, std::string fout){
    std::ifstream file(fin);

    if (!file.is_open())
        return;


    Trie d = Trie();
    std::string cadeia = "";
    char c;
    int codigo;
    d.inserir(cadeia);

    while (file.get(c)){
        codigo = d.codigo(cadeia + c);
        if (codigo >= 0){
            cadeia += c;
        }
        else {
            codigo = d.codigo(cadeia);
            std::cout << "(" << codigo << ", '" << c << "')";
            d.inserir(cadeia + c);
            cadeia = "";
        }
    }
    std::cout << std::endl;
    d.imprimirCadeias();
    file.close();
}

void decompressao(){

}