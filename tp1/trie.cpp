#include "trie.h"
#include "funcoes.h"
#include <iostream>

Trie::Trie(){
    this->raiz = new No("", true, 0);
    this->proximoCodigo = 1;
}

Trie::~Trie(){
    delete this->raiz;
}

void Trie::inserir(std::string cadeia){
    if (!this->raiz->buscar(cadeia)){
        this->raiz->inserir(cadeia, this->proximoCodigo);
        this->proximoCodigo++;
    }
}

No* Trie::buscar(std::string cadeia){
    No* res = this->raiz->buscar(cadeia);

    return res;
}

std::string Trie::buscarPorCodigo(int codigo){
    std::string cadeia = this->raiz->buscarPorCodigo(codigo, this->raiz->getLabel());
    
    return cadeia;
}

int Trie::codigo(std::string cadeia){
    No* res = this->buscar(cadeia);
    int c;
    if (res)
        c = res->getCodigo();
    else
        c = -1;

    return c;
}

void Trie::imprimir(){
    this->raiz->imprimir();
}

void Trie::imprimirCadeias(){
    this->raiz->imprimirCadeias("");
}