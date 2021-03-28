#include "node.h"

Node::Node(std::string label, int l, float v, float w,
        float b, std::vector<unsigned int> s) {
    this->label = label;
    this->l = l;
    this->v = v;
    this->w = w;
    this->b = b;
    this->s = s;
}

void Node::imprimir(){
    std::cout << this->label << std::endl
    << "Level: " << this->l << std::endl
    << "Value: " << this->v << std::endl
    << "Weight: " << this->w << std::endl
    << "Bound: " << this->b << std::endl
    << "Solution: " << std::endl;

    for (unsigned int i = 0; i < this->s.size(); i++){
        std::cout << this->s.at(i) << " " << std::endl;
    }
        std::cout << "\n======================================\n\n";
}

bool bound_comparator::operator()(const Node* n1, const Node* n2) const {
    return n1->b < n2->b;
}