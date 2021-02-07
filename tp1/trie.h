#ifndef TRIE_H
#define TRIE_H

#include "no.h"

class Trie {
private:
    No* raiz;
    int proximoCodigo;

public:
    Trie();
    ~Trie();
    void inserir(std::string cadeia);
    No* buscar(std::string cadeia);
    int codigo(std::string cadeia);
    void remover(std::string cadeia);
    void imprimir();
    void imprimirCadeias();
};

#endif