#include "lz78.h"
#include "trie.h"
#include <iostream>
#include <string>
#include <cstdio>

void compressao(std::string fin, std::string fout){
    std::ifstream file(fin);
    std::ofstream out(fout);

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
            out << "(" << codigo << ", '" << c << "')";
            d.inserir(cadeia + c);
            cadeia = "";
        }
    }
    std::cout << std::endl;
    d.imprimirCadeias();
    file.close();
}

void decompressao(std::string fin, std::string fout){
    FILE* file;
    file = fopen (fin.c_str(), "r");
    if (file == nullptr)
        return;

    Trie d = Trie();
    std::string cadeia = "";
    int codigo;
    char c;
    d.inserir(cadeia);

    while (fscanf(file, "(%d, '%c')", &codigo, &c) == 2){
        std::cout << codigo << " " << c << std::endl;
    }

    fclose (file);
}