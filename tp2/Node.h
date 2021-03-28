#include <vector>
#include <string>
#include <iostream>

class Node {
public:
    std::string label;
    int l; // level
    float v; // value
    float w; // weight
    float b; // bound
    std::string s; // solution

    Node(std::string label, int l, float v, float w,
         float b, std::string s);
    
    void imprimir();
};

struct bound_comparator {
    bool operator()(const Node* n1, const Node* n2) const;
};