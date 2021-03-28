class Item {
public:
    unsigned int w; // peso
    unsigned int v; // valor
    float vw; // valor/peso

    Item(unsigned int w, unsigned int v);
};

struct vw_comparator {
    bool operator()(const Item* a, const Item* b) const;
};