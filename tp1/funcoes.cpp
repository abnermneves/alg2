#include "funcoes.h"
#include <iostream>

// retorna quantos caracteres são iguais no início das strings
unsigned int qntdIguais(std::string s1, std::string s2){
    if (s1.length() == 0 || s2.length() == 0)
        return 0;
    
    unsigned int i = 0;

    for (; i < s1.length() && i < s2.length() && s1[i] == s2[i]; i++);

    return i;
}
