#include <iostream>
#include "funcoes.h"

int main (int argc, char* argv[]) {
    std::string s1, s2;
    std:: cin >> s1 >> s2;
    std::cout << qntdIguais(s1, s2) << std::endl;
    return 0;
}