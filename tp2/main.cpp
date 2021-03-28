#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include "funcoes.h"

int main (int argc, char* argv[]) {

//--------------------------- FLUXO DE ARQUIVO ----------------------------//

    if (argc < 2){
        std::cout << "Nome do arquivo de entrada deve ser passado como parâmetro.\n";
        return 0;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()){
        std::cout << "Não foi possível abrir o arquivo.\n";
        return 0;
    }

//-------------------------- DECLARAÇÃO E LEITURA ----------------------//

    unsigned int n, wmax, w, v;
    file >> n >> wmax;

    std::vector<Item*> itens;

    for (unsigned int i = 0; i < n; i++) {
        file >> v >> w;
        itens.push_back(new Item(w, v));
    }

    std::sort(itens.begin(), itens.end(), vw_comparator());
    
    for (unsigned int i = 0; i < n; i++){
        Item* item = itens.at(i);
        std::cout << i << " " << item->w << " " << item->v << " " << item->vw << std::endl;
    }

    file.close();
    return 0;
}