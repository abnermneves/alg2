#include "no.h"
#include "funcoes.h"
#include <iostream>

No::No(std::string label){
    this->label = label;
    this->fimDeCadeia = false;
    this->codigo = -1;
    this->filhos = new std::vector<No*>;
}

No::No(std::string label, bool fimDeCadeia, int codigo){
    this->label = label;
    this->fimDeCadeia = fimDeCadeia;
    this->codigo = codigo;
    this->filhos = new std::vector<No*>;
}

No::No(std::string label, bool fimDeCadeia, int codigo, std::vector<No*>* filhos){
    this->label = label;
    this->fimDeCadeia = fimDeCadeia;
    this->codigo = codigo;
    this->filhos = filhos;
}

No::~No(){
    for (auto it = this->filhos->begin(); it != this->filhos->end(); it++)
        delete (*it);
    delete filhos;
}

std::string No::buscarPorCodigo(int codigo, std::string prefixo){
    if (this->codigo == codigo)
        return prefixo + this->label;
    
    std::string cadeia;
    for (auto it = this->filhos->begin(); it != this->filhos->end(); it++){
        cadeia = (*it)->buscarPorCodigo(codigo, this->label);
        if (!cadeia.empty()){
            return prefixo + cadeia;
        }
    }

    return "";
}

No* No::buscar(std::string cadeia){
    /*

    três casos:

    1) se cadeia é igual ao label e o nó é um fim de cadeia, achou
    
    se não é igual:
    2) têm caracteres em comum, então consome e procura o resto da cadeia nos filhos do nó
    3) não têm caracteres em comum, então não achou

    */

    unsigned int iguais = qntdIguais(cadeia, this->label);
    if (cadeia == this->label && this->fimDeCadeia){ //match
        return this;
    }
    // prefixo bate, então consome e busca o resto
    else {
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

        // se tem prefixo em comum, então busca o resto da cadeia no nó dele
        if (iguais > 0){
            it--;
            return (*it)->buscar(resto);
        }

    }

    return nullptr;
}

void No::inserir(std::string cadeia, int codigo){
    unsigned int iguais = qntdIguais(cadeia, this->label);
    
    // cadeia já está inserida
    if (cadeia == this->label && this->fimDeCadeia){
        return;
    }
    // cadeia já estava inserida, mas só como prefixo
    else if (cadeia == this->label){
        this->fimDeCadeia = true;
        this->codigo = codigo;
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
            (*it)->inserir(resto, codigo);
        }
        // senão, cria novo nó e insere como filho
        else {
            No* no = new No(resto, true, codigo);
            this->filhos->push_back(no);
        }

    }
    // casa parcialmente com o prefixo, então cria novo nó e coloca os dois como filhos
    else if (iguais > 0 && iguais < this->label.length()){
        No* noCadeia = new No(cadeia.substr(iguais), true, codigo);
        No* noLabel = new No(this->label.substr(iguais), this->fimDeCadeia, this->codigo, this->filhos);

        this->label = this->label.substr(0, iguais);
        this->fimDeCadeia = false;
        this->codigo = -1;
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

int No::getCodigo(){
    return this->codigo;
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
        std::cout << this->codigo << ": " << prefixo << std::endl;
    }
    for (auto it = this->filhos->begin(); it != this->filhos->end(); it++){
        (*it)->imprimirCadeias(prefixo);
    }

}