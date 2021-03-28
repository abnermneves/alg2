#include "bnb.h"

float bnbKnapsack(unsigned int n, float wmax, std::vector<Item*>* itens) {
    Item* item = itens->at(0);
    std::string solucao = "";
    Node root = Node("Nó 0", 0, 0, 0, wmax * item->vw, "");
    std::priority_queue<Node*, std::vector<Node*>, bound_comparator> queue;
    queue.push(&root);
    float best = 0;

    unsigned int cont = 1;

    while (!queue.empty()) {
        Node* node = queue.top();
        queue.pop();
        std::string label = node->label;
        int level = node->l;
        float value = node->v;
        float weight = node->w;
        float bound = node->b;
        std::string solution = node->s;

        //node->imprimir();

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
                Node no = Node("Nó " + std::to_string(cont),
                               level + 1,
                               value + itens->at(level)->v,
                               weight + itens->at(level)->w,
                               with,
                               solution + " " + std::to_string(level));
                queue.push(&no);
                cont++;

                no.imprimir();
            }
            if (wout > best) {
                Node no2 = Node("Nó " + std::to_string(cont),
                                level + 1,
                                value,
                                weight,
                                wout,
                                solution);
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

    return best;
}