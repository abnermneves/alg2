#include <vector>

class Node {
public:
    unsigned int l; // level
    unsigned int v; // value
    unsigned int w; // weight
    unsigned int b; // bound
    std::vector<unsigned int> s; // solution

    Node(unsigned int l, unsigned int v, unsigned int w,
         unsigned int b, unsigned int s_include);

    Node(unsigned int l, unsigned int v, unsigned int w,
         unsigned int b);
};

struct bound_comparator {
    bool operator()(const Node* a, const Node* b) const;
};