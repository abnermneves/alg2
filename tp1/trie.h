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
    std::string buscarPorCodigo(int codigo);
    int codigo(std::string cadeia);
    void imprimir();
    void imprimirCadeias();
};

#endif