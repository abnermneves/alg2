#include "node.h"

Node::Node(unsigned int l, unsigned int v, unsigned int w,
        unsigned int b, std::vector<unsigned int> s) {
    this->l = l;
    this->v = v;
    this->w = w;
    this->b = b;
    this->s = s;
}


Node::Node(unsigned int l, unsigned int v, unsigned int w,
     unsigned int b) {
    this->l = l;
    this->v = v;
    this->w = w;
    this->b = b;
}

bool bound_comparator::operator()(const Node* a, const Node* b) const {
    return a->b < b->b;
}