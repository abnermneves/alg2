#ifndef NO_H
#define NO_H

#include <vector>
#include <string>

class No {
private:
    std::string label;
    bool fimDeCadeia;
    int codigo;
    std::vector<No*>* filhos;

public:
    No(std::string label);
    No(std::string label, bool fimDeCadeia, int codigo);
    No(std::string label, bool fimDeCadeia, int codigo, std::vector<No*>* filhos);
    ~No();
    //bool fimDeCadeia();
    No* buscar(std::string cadeia);
    std::string buscarPorCodigo(int codigo, std::string prefixo);
    void inserir(std::string cadeia, int codigo);
    void imprimir();
    void imprimirCadeias(std::string prefixo);

    std::vector<No*>* getFilhos();
    std::string getLabel();
    int getCodigo();
};

#endif