#include "trie.h"
#include "funcoes.h"
#include <iostream>

Trie::Trie(){
    this->raiz = new No("", true, 0);
    this->proximoCodigo = 1;
}

Trie::~Trie(){

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

int Trie::codigo(std::string cadeia){
    No* res = this->buscar(cadeia);
    int c;
    if (res)
        c = res->getCodigo();
    else
        c = -1;

    return c;
}

void Trie::remover(std::string s){

}

void Trie::imprimir(){
    this->raiz->imprimir();
}

void Trie::imprimirCadeias(){
    this->raiz->imprimirCadeias("");
}