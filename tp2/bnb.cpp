#include "bnb.h"

float bnbKnapsack(unsigned int n, float wmax, std::vector<Item*>* itens) {
    Item* item = itens->at(0);
    std::string solucao = "";
    Node root = Node("Nó 0", 0, 0, 0, wmax * item->vw, "");
    std::vector<Node*> queue;
    queue.push_back(&root);
    float best = 0;

    unsigned int cont = 1;

    while (!queue.empty()) {
        std::sort(queue.begin(), queue.end(), bound_comparator());
        
        std::cout << "\n\nApós inserir o nó " + std::to_string(cont) + "\n\n";

        for (auto it = queue.begin(); it != queue.end(); it++){
            (*it)->imprimir();
        }

        Node* node = queue.at(0);
        queue.erase(queue.begin());

        std::string label = node->label;
        int level = node->l;
        float value = node->v;
        float weight = node->w;
        float bound = node->b;
        std::string solution = node->s;

        if (level == n-1) {
            if (best < value) {
                best = value;
                solucao = solution;
            }
        }
        else if (bound > best) {
            float with, wout;

            with = value
            + itens->at(level)->v
            + (wmax - weight - itens->at(level)->w) * itens->at(level + 1)->vw;

            wout = value + (wmax - weight) * itens->at(level + 1)->vw;

            //if feasible and has a better bound than current solution
            if (((weight + itens->at(level)->w) < wmax) && with > best) { // acho que é at level só
                Node* no = new Node("Nó " + std::to_string(cont),
                               level + 1,
                               value + itens->at(level)->v,
                               weight + itens->at(level)->w,
                               with,
                               solution + " " + std::to_string(level));
                queue.push_back(no);
                cont++;

                //no.imprimir();
            }
            if (wout > best) {
                Node* no2 = new Node("Nó " + std::to_string(cont),
                                level + 1,
                                value,
                                weight,
                                wout,
                                solution);
                queue.push_back(no2);
                cont++;

                //no2.imprimir();
            }

        }
    }
    
    std::cout << "Solução: " << best << "\nItens:" << solucao <<  std::endl;

    return best;
}