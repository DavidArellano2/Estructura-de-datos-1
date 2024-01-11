//
// Created by agust on 5/25/2021.
//

#ifndef LISTA_CIRCULAR_DOBLEMENTE_LIGADA_CON_ENCABEZADO_LIST_H
#define LISTA_CIRCULAR_DOBLEMENTE_LIGADA_CON_ENCABEZADO_LIST_H

#include "node.h"

class list {
private:
    node *first;
    node *header;
    node *last;
    int size;
public:
    list();

    ~list();

    bool isEmpty();

    void add(int element, node *position);

    void remove(node *position);

    node *getFirst();

    node *getLast();

    node *previous(node *postition);

    node *next(node *postition);

    int get(node *position);

    node *find(int element);

    friend std::ostream &operator<<(std::ostream &, list &);

    node *findByIndex(int index);

    int getIndex(node *index);
};


#endif //LISTA_CIRCULAR_DOBLEMENTE_LIGADA_CON_ENCABEZADO_LIST_H
