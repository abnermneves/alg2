#include "no.h"
#include "funcoes.h"
#include <iostream>

No::No(std::string label){
    this->label = label;
    this->fimDeCadeia = false;
    this->filhos = new std::vector<No*>;
}

No::No(std::string label, bool fimDeCadeia){
    this->label = label;
    this->fimDeCadeia = fimDeCadeia;
    this->filhos = new std::vector<No*>;
}

No::No(std::string label, bool fimDeCadeia, std::vector<No*>* filhos){
    this->label = label;
    this->fimDeCadeia = fimDeCadeia;
    this->filhos = filhos;
}

No::~No(){

}

/*
bool No::fimDeCadeia(){
    if (this->filhos->size() == 0)
        return true;
    else
        return false;
}
*/

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
    if (cadeia == this->label && this->fimDeCadeia){ //match
        return this;
    } else if (iguais > 0){ // prefixo bate, então consome e busca o resto
        // pega o resto dos caracteres que são diferentes
        std::string resto = cadeia.substr(iguais);

        // procura nos filhos se algum tem prefixo em comum
        auto it = this->filhos->begin();
        iguais = qntdIguais(resto, (*it)->getLabel());
        for (; it != this->filhos->end() && iguais == 0; it++){
            iguais = qntdIguais(resto, (*it)->getLabel());
        }

        if (it != this->filhos->end()) // casou com algum filho
            (*it)->buscar(resto);

    }

    return nullptr;
}

void No::inserir(std::string cadeia){
    unsigned int iguais = qntdIguais(cadeia, this->label);
    
    // cadeia já está inserida
    if (cadeia == this->label && this->fimDeCadeia){
        return;
    }
    // cadeia já estava inserida, mas só como prefixo
    else if (cadeia == this->label){
        this->fimDeCadeia = true;
    }
    // prefixo bate, então consome e insere o resto
    else if (iguais >= 0 && iguais >= this->label.length()){ 
        // pega o resto dos caracteres que são diferentes
        std::string resto = cadeia.substr(iguais);

        auto it = this->filhos->begin();

        // se tem algum filho, calcula qntdIguais com o primeiro
        if (it != this->filhos->end()){
            iguais = qntdIguais(resto, (*it)->getLabel());
            it++;
        }
        else{
            iguais = 0;
        }
        
        // procura nos filhos se algum tem prefixo em comum
        while (it != this->filhos->end() && iguais == 0){
            iguais = qntdIguais(resto, (*it)->getLabel());
            it++;
        }

        // se tem prefixo em comum, então insere o resto da cadeia no nó dele
        if (iguais > 0){
            it--;
            (*it)->inserir(resto);
        }
        // senão, cria novo nó e insere como filho
        else {
            No* no = new No(resto, true);
            this->filhos->push_back(no);
        }

    }
    // casa parcialmente com o prefixo, então cria novo nó e coloca os dois como filhos
    else if (iguais > 0 && iguais < this->label.length()){
        No* noCadeia = new No(cadeia.substr(iguais), true);
        No* noLabel = new No(this->label.substr(iguais), this->fimDeCadeia, this->filhos);

        this->label = this->label.substr(0, iguais);
        this->fimDeCadeia = false;
        this->filhos = new std::vector<No*>;
        this->filhos->push_back(noCadeia);
        this->filhos->push_back(noLabel);
    }
}

std::vector<No*>* No::getFilhos(){
    return this->filhos;
}

std::string No::getLabel(){
    return this->label;
}

void No::imprimir(){
    std::cout << "-----------------------" << std::endl
              << this->label << std::endl;
    
    for (auto it = this->filhos->begin(); it != this->filhos->end(); it++){
        std::cout << (*it)->getLabel() << "   |   ";
    }

    std::cout << std::endl
              << "-----------------------" << std::endl;

    for (auto it = this->filhos->begin(); it != this->filhos->end(); it++){
        (*it)->imprimir();
    }

}

void No::imprimirCadeias(std::string prefixo){
    prefixo += this->label;
    if (this->fimDeCadeia){
        std::cout << prefixo << std::endl;
    }
    for (auto it = this->filhos->begin(); it != this->filhos->end(); it++){
        (*it)->imprimirCadeias(prefixo);
    }

}