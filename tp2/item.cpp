#include "item.h"

Item::Item(unsigned int w, unsigned int v) {
    this->w = w;
    this->v = v;
    this->vw = static_cast<float>(v) / static_cast<float>(w);
}


bool vw_comparator::operator()(const Item* a, const Item* b) const {
    return a->vw > b->vw;
}