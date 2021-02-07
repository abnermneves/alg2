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

    // retorna o nó com o final da cadeia procurada
    No* buscar(std::string cadeia);
    
    // retorna a string correspondente a um código ou string vazia
    std::string buscarPorCodigo(int codigo, std::string prefixo);
    
    // insere uma cadeia com seu respectivo código
    void inserir(std::string cadeia, int codigo);

    // imprime cada nó e seus respectivos filhos
    void imprimir();

    // imprime todas as cadeias inseridas e seus respectivos códigos
    void imprimirCadeias(std::string prefixo);

    // getters
    std::vector<No*>* getFilhos();
    std::string getLabel();
    int getCodigo();
};

#endif