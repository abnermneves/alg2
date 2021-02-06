#ifndef NO_H
#define NO_H

#include <vector>
#include <string>

class No {
private:
    std::string texto;
    std::vector<No*> filhos;

public:
    No(std::string texto);
    ~No();
    bool ehFolha();
    No* busca(std::string padrao);

    std::vector<No*> getFilhos();
    std::string getTexto();
};

#endif