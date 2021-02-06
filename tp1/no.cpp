#include "no.h"
#include "funcoes.h"
No::No(std::string label){
    this->label = label;
}

No::~No(){

}

bool No::fimDeCadeia(){
    if (this->filhos.size() == 0)
        return true;
    else
        return false;
}

No* No::buscar(std::string cadeia){
    /*
    três casos:
    1) dar match inteiramente com algum filho do nó de mesmo tamanho
        1.1) se é uma folha, então a cadeia já está inserida
        1.2) se não é uma folha, então a cadeia não está inserida
    2) dar um match parcial
        2.1) se a cadeia é maior que o label do nó, consome os caracteres e busca com o resto
        2.2) se a cadeia é menor, então a cadeia não está inserida
    3) não dar match algum

    se não é igual:
    1) cadeia e label têm o mesmo tamanho. então iguais é sempre < cadeia.length e < label.length
        1.1) iguais == 0
             
        1.2) iguais > 0

    2) cadeia e label têm tamanhos diferentes

    */
    unsigned int iguais = qntdIguais(cadeia, this->label);
    if (cadeia == this->label && this->fimDeCadeia()){ //match
        return this;
    } else if (iguais > 0){ // prefixo bate, então consome e busca o resto
        // pega o resto dos caracteres que são diferentes
        std::string resto = cadeia.substr(iguais);

        // procura nos filhos se algum tem prefixo em comum
        auto it = this->filhos.begin();
        iguais = qntdIguais(resto, (*it)->getLabel());
        for (; it != this->filhos.end() && iguais == 0; it++){
            iguais = qntdIguais(resto, (*it)->getLabel());
        }

        if (it != this->filhos.end()) // casou com algum filho
            (*it)->buscar(resto);

    }

    return nullptr;
}

std::vector<No*>* No::getFilhos(){
    return &this->filhos;
}

std::string No::getLabel(){
    return this->label;
}
