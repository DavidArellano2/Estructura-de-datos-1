//
// Created by agust on 5/25/2021.
//

#ifndef LISTA_CIRCULAR_DOBLEMENTE_LIGADA_CON_ENCABEZADO_NODE_H
#define LISTA_CIRCULAR_DOBLEMENTE_LIGADA_CON_ENCABEZADO_NODE_H

#include "ostream"

class node {
private:
    friend class list;

    int info;
    node *next;
    node *prev;
public:
    node();

    friend std::ostream &operator<<(std::ostream &, node &);
};


#endif //LISTA_CIRCULAR_DOBLEMENTE_LIGADA_CON_ENCABEZADO_NODE_H
