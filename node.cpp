//
// Created by agust on 5/25/2021.
//

#include "node.h"
#include "list.h"

node::node() {
    next = nullptr;
    prev = nullptr;
}

std::ostream &operator<<(std::ostream &out, node &node) {
    out << node.info;
    return out;
}
