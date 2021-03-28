#include "bnb.h"

unsigned int bnbKnapsack(unsigned int n, unsigned int wmax, std::vector<Item*>* itens) {
    Item* item = itens->at(0);
    std::vector<unsigned int> solution;
    Node root = Node(0, 0, 0, wmax * item->vw);

    std::priority_queue<Node*, std::vector<Node*>, bound_comparator> queue;
    queue.push(&root);
    unsigned int best = 0;

    while (!queue.empty()) {
std::cout << "oi\n";
        Node* node = queue.top();
        queue.pop();

        if (node->l == n-1) {
std::cout << "oi2\n";
            if (best < node->v) {
std::cout << "oi3\n";
                best = node->v;
                solution = node->s; // ver o que ta acontecendo exatametnte nessa linha
            }
        }
        else if (node->b > best) {
std::cout << "oi4\n";
            unsigned int with, wout;

            with = node->v
            + itens->at(node->l)->v
            + (wmax - node->w - itens->at(node->l)->w) * itens->at(node->l + 1)->vw;

            wout = node->v + (wmax - node->w) * itens->at(node->l + 1)->vw;

            if ((node->w + itens->at(node->l + 1)->w < wmax) && with > best) {
std::cout << "oi5\n";
                std::vector<unsigned int> sol;
                sol = node->s;
                sol.push_back(node->l);
                Node no = Node(node->l + 1, node->v + itens->at(node->l)->v,
                                    node->w + itens->at(node->l)->w, with, sol);
                queue.push(&no);
            }

            if (wout > best) {
std::cout << "oi6\n";
                Node no = Node(node->l + 1, node->v, node->w, wout, node->s);
                queue.push(&no);
            }
        }
    }
    
    std::cout << "Solução: " << best << std::endl;
    for (unsigned int i = 0; i < solution.size(); i++){
        std::cout << solution.at(i) << std::endl;
    }
    return best;
}