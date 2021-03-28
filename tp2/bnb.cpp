#include "bnb.h"

float bnbKnapsack(unsigned int n, float wmax, std::vector<Item*>* itens) {
    Item* item = itens->at(0);
    std::vector<unsigned int> solution;
    std::string solucao = "";
    Node root = Node("Nó 0", 0, 0, 0, wmax * item->vw, solution);
    std::priority_queue<Node*, std::vector<Node*>, bound_comparator> queue;
    queue.push(&root);
    float best = 0;

    unsigned int cont = 0;

    while (!queue.empty()) {
        Node* node = queue.top();
        queue.pop();
        int level = node->l;
        float value = node->v;
        float weight = node->w;
        float bound = node->b;

        //node->imprimir();

        if (level == n-1) {
            if (best < value) {
                best = value;
                solucao = node->label;
                std::copy(node->s.begin(), node->s.end()--, solution.begin());
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
                std::vector<unsigned int> sol;
                sol = node->s;
                sol.push_back(level);
                std::string label = "Nó " + std::to_string(cont) + ": " +  node->label + std::to_string(level) + " ";
                Node no = Node(label, level + 1, value + itens->at(level)->v,
                               weight + itens->at(level)->w, with, sol);
                queue.push(&no);
                cont++;

                no.imprimir();
            }
            if (wout > best) {
                std::string label2 = "Nó " + std::to_string(cont) + ": " +  node->label;
                std::vector<unsigned int> sol2(node->s.size());
                //sol2 = node->s;
                std::copy(node->s.begin(), node->s.end()--, sol2.begin());
                Node no2 = Node(label2, level + 1, value, weight, wout, sol2);
                queue.push(&no2);
                cont++;

                no2.imprimir();
            }

        }
        
        // std::cout << "Fila de prioridades: "
        // for ()
        // std::cout << node->label << std::endl
        //           << "Level: " << level << std::endl
        //           << "Value: " << value << std::endl
        //           << "Weight: " << weight << std::endl
        //           << "Bound: " << bound << std::endl
        //           << "Solution: " << std::endl;
        
        // for (unsigned int i = 0; i < node->s.size(); i++){
        //     std::cout << node->s.at(i) << " " << std::endl;
        // }
        // std::cout << "\n======================================\n\n";
    }
    
    std::cout << "Solução: " << best << "\n" << solucao <<  std::endl;
    for (unsigned int i = 0; i < solution.size(); i++){
        std::cout << solution.at(i) << " " << std::endl;
    }
    return best;
}