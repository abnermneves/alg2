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

    if (operacao == 'c'){
        compressao(fin, fout);
    } else if (operacao == 'd'){
        decompressao();
    } else {

    }

/*
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::string s3 = s1 + s2;
    std::cout << s3 << std::endl;
    std::string s1 = "";
    std::string s2 = "";
    bool b = s1 == s2;
    std::cout << qntdIguais(s1, s2) << " " << s1.length() << " " << b << std::endl;
    std::cout << s1.substr(0);

    //if (s1)
    std::cout << s1.length() << std::endl;
    */  

    /*
    Trie t = Trie();
    t.inserir("cabeça");
    t.inserir("verde");
    t.inserir("marrom");
    t.inserir("maravilha");
    t.inserir("cacto");
    t.inserir("ovo");
    t.inserir("minimize");
    t.inserir("inimize");
    t.inserir("nimize");
    t.inserir("imize");
    t.inserir("mize");
    t.inserir("ize");
    t.inserir("ze");
    t.inserir("e");
    t.imprimir();
    */
    /*
    t.buscar("cabeça");
    t.buscar("verde");
    t.buscar("marrom");
    t.buscar("maravilha");
    t.buscar("cacto");
    t.buscar("ovo");
    t.buscar("minimize");
    t.buscar("inimize");
    t.buscar("nimize");
    t.buscar("imize");
    t.buscar("mize");
    t.buscar("ize");
    t.buscar("ze");
    t.buscar("e");
    */
/*
    t.codigo("cabeça");
    t.codigo("verde");
    t.codigo("marrom");
    t.codigo("maravilha");
    t.codigo("cacto");
    t.codigo("ovo");
    t.codigo("minimize");
    t.codigo("inimize");
    t.codigo("nimize");
    t.codigo("imize");
    t.codigo("mize");
    t.codigo("ize");
    t.codigo("ze");
    t.codigo("e");
    t.codigo("edd");
    t.codigo("edad");
    */

    return 0;
}