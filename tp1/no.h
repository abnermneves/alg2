#ifndef NO_H
#define NO_H

#include <vector>
#include <string>

class No {
private:
    std::string label;
    bool fimDeCadeia;
    std::vector<No*>* filhos;

public:
    No(std::string label);
    No(std::string label, bool fimDeCadeia, std::vector<No*>* filhos);
    ~No();
    //bool fimDeCadeia();
    No* buscar(std::string cadeia);
    void inserir(std::string cadeia);

    std::vector<No*>* getFilhos();
    std::string getLabel();
};

#endif