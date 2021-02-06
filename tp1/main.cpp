#include <iostream>
#include "funcoes.h"
#include "trie.h"

int main (int argc, char* argv[]) {
    std::string s1 = "";
/*
    std::string s2 = "";
    //std::string s1, s2;
    //std:: cin >> s1 >> s2;
    bool b = s1 == s2;
    std::cout << qntdIguais(s1, s2) << " " << s1.length() << " " << b << std::endl;
    std::cout << s1.substr(0);

    */
   //if (s1)
     std::cout << s1.length() << std::endl;

    Trie t = Trie();
    /*
    t.inserir("cabeça");
    t.inserir("verde");
    t.inserir("marrom");
    t.inserir("maravilha");
    t.inserir("cacto");
    t.inserir("ovo");
    */
    t.inserir("minimize");
    t.inserir("inimize");
    t.inserir("nimize");
    t.inserir("imize");
    t.inserir("mize");
    t.inserir("ize");
    t.inserir("ze");
    t.inserir("e");
    /*
    */
    t.imprimir();
    return 0;
}