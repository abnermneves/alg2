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

    // insere uma cadeia e define um código para ela
    void inserir(std::string cadeia);

    // retorna o nó com o final da cadeia procurada
    No* buscar(std::string cadeia);

    // retorna a string correspondente a um código ou string vazia
    std::string buscarPorCodigo(int codigo);
    
    // retorna o código correspondente a uma cadeia ou -1 se ela não existir
    int codigo(std::string cadeia);
    
    // imprime cada nó e seus respectivos filhos
    void imprimir();

    // imprime todas as cadeias inseridas e seus respectivos códigos
    void imprimirCadeias();
};

#endif