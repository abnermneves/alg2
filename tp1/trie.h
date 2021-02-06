#ifndef TRIE_H
#define TRIE_H

#include "no.h"

class Trie {
private:
    No* raiz;


public:
    Trie();
    ~Trie();
    void inserir(std::string texto);
    void buscar(std::string padrao);
    void remover(std::string padrao);

};

#endif