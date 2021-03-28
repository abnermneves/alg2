#include "item.h"

Item::Item(float w, float v) {
    this->w = w;
    this->v = v;
    this->vw = w == 0 ? 0 : v / w;
}


bool vw_comparator::operator()(const Item* a, const Item* b) const {
    return a->vw > b->vw;
}