class Item {
public:
    float w; // peso
    float v; // valor
    float vw; // valor/peso

    Item(float w, float v);
};

struct vw_comparator {
    bool operator()(const Item* a, const Item* b) const;
};