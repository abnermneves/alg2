#ifndef NO_H
#define NO_H

#include <vector>
#include <string>

class No {
private:
    std::string label;
    std::vector<No*> filhos;

public:
    No(std::string label);
    ~No();
    bool fimDeCadeia();
    No* buscar(std::string cadeia);

    std::vector<No*>* getFilhos();
    std::string getLabel();
};

#endif