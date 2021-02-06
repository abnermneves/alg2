#include "no.h"

No::No(std::string texto){
    this->texto = texto;
}

No::~No(){

}

bool No::ehFolha(){
    if (this->filhos.size() == 0)
        return true;
    else
        return false;
}

No* No::busca(std::string padrao){
    return nullptr;
}

std::vector<No*> No::getFilhos(){
    return this->filhos;
}

std::string No::getTexto(){
    return this->texto;
}
