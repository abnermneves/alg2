#include "trie.h"
#include "funcoes.h"
#include <iostream>

Trie::Trie(){
    this->raiz = new No("", true);
}

Trie::~Trie(){

}

void Trie::inserir(std::string cadeia){
    this->raiz->inserir(cadeia);
}

void Trie::buscar(std::string cadeia){
    No* res = this->raiz->buscar(cadeia);
    std::cout << res->getLabel() << std::endl;
    /*
    três casos:
    1) dar match inteiramente com algum filho do nó de mesmo tamanho
        1.1) se é uma folha, então a cadeia já está inserida
        1.2) se não é uma folha, então a cadeia não está inserida
    2) dar um match parcial
        2.1) se a cadeia é maior que o label do nó, consome os caracteres e busca com o resto
        2.2) se a cadeia é menor, então a cadeia não está inserida
    3) não dar match algum

    */



    /*


     unsigned int tamPadrao = padrao.length();
    unsigned int j = 0;
    No* v = this->raiz;
    bool f = true;

    while (f) {
        f = true;
        auto filhos = v->getFilhos();
        unsigned int i = 0;
        for (auto w = filhos.begin(); w != filhos.end(); w++){
            std::string texto = w->getTexto();

            //se o primeiro caractere do padrão é igual ao do texto, processa w
            if (padrao[j] = texto[i]){
                unsigned int tamTexto = texto.length();

                if (tamPadrao <= tamTexto){
                    if ()
                }
            }
        }

    }
*/
    
}

void Trie::remover(std::string s){

}

void Trie::imprimir(){
    this->raiz->imprimir();
}

void Trie::imprimirCadeias(){
    this->raiz->imprimirCadeias("");
}