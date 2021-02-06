#ifndef TRIE_H
#define TRIE_H

#include "no.h"

class Trie {
private:
    No* raiz;


public:
    Trie();
    ~Trie();
    void inserir(std::string cadeia);
    void buscar(std::string cadeia);
    void remover(std::string cadeia);
    void imprimir();
};

#endif