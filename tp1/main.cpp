#include <iostream>
#include "funcoes.h"

int main (int argc, char* argv[]) {
    std::string s1 = "";
    std::string s2 = "";
    //std::string s1, s2;
    //std:: cin >> s1 >> s2;
    bool b = s1 == s2;
    std::cout << qntdIguais(s1, s2) << " " << s1.length() << " " << b << std::endl;
    std::cout << s1.substr(0);
    return 0;
}