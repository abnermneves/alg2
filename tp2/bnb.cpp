#include "bnb.h"
#include "node.h"

unsigned int bnbKnapsack(unsigned int n, unsigned int wmax, std::vector<Item*>* itens) {
    Item* item = itens->at(0);
    std::vector<unsigned int> solution;
    Node root = Node(0, 0, 0, wmax * item->vw);

    std::priority_queue<Node*, std::vector<Node*>, bound_comparator> queue;
    queue.push(&root);
    unsigned int best = 0;

    while (!queue.empty()) {
        Node* node = queue.top();
        queue.pop();

        if (node->l == n-1) {
            if (best < node->v) {
                best = node->v;
                solution = node->s; // ver o que ta acontecendo exatametnte nessa linha
            }
            else if (node->b > best) {
                unsigned int with = node->v;
            }
        }
    }
}