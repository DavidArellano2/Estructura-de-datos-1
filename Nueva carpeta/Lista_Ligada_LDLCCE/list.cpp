//
// Created by agust on 5/25/2021.
//

#include "list.h"

/**
 * inicializa los punteros en nulo y el tamaño en cero
 */
list::list() {
    first = 0;
    header = 0;
    last = 0;
    size = 0;
}

/**
 * Si la lista no tiene un primer elemento quiere decir que esta vacia
 *
 */
bool list::isEmpty() {
    return first == 0;
}

/**
 * Crea un nuevo nodo con el elemento y lo añade en el lugar del nodo o al principio ya sea si la lista esta vacia o no
 * se paso un nodo, cuando la lista no esta vacia se utilizan los punteros anterior y siguientes de los nodos auxiliares
 * para mantener el ordende la lista
 *
 * @param element numero a añadir en la lista
 * @param position nodo en el que se va añadir el elemento
 */
void list::add(int element, node *position) {
    node *aux = new node;
    aux->info = element;
    if (isEmpty()) {
        aux->next = aux;
        aux->prev = aux;
        first = aux;
    } else {
        if (position == 0) {
            aux->next = first;
            aux->prev = last;
            last->next = aux;
            first = aux;
        } else {
            aux->prev = position;
            aux->next = position->next;
            position->next->prev = aux;
            position->next = aux;
        }
    }
    if (aux->next == first)
        last = aux;
    size++;
}

/**
 * En caso de haber un nodo valido se inicializa la lista si se detecta que es el unico nodo, en cualquier otro caso se
 * reasignan los punteros correspondientes de los nodos contiguos y los auxiliares de la lista para despues liberar el
 * espacio de memoria
 *
 * @param position el nodo que se va a eliminar
 */
void list::remove(node *position) {
    if (isEmpty() || position == 0) {
        return;
    }
    if (position->next == position) {
        first = 0;
        header = 0;
        last = 0;
    } else {
        position->prev->next = position->next;
        position->next->prev = position->prev;
        if (position == first)
            first = first->next;
        if (position == last)
            last = position->prev;
    }
    size--;
    delete position;
}

/**
 *
 * @return El primer elemento de la lista
 */
node *list::getFirst() {
    return first;
}

/**
 *
 * @return El ultimo elemento de la lista
 */
node *list::getLast() {
    return last;
}

/**
 *
 * @param position nodo seleccionado por el usuario
 * @return El elemento anterior al nodo de la lista
 */
node *list::previous(node *postition) {
    if (isEmpty() || postition == 0) {
        return 0;
    }
    return postition->prev;
}

/**
 *
 * @param position nodo seleccionado por el usuario
 * @return El elemento siguiente al nodo de la lista
 */
node *list::next(node *postition) {

    if (isEmpty() || postition == 0) {
        return 0;
    }
    return postition->next;
}

/**
 *
 * @param position nodo seleccionado por el usuario
 * @return El elemento guardado en el nodo
 */
int list::get(node *position) {
    if (isEmpty() || position == 0) {
        throw "Datos Insuficientes";
    } else {
        return position->info;
    }
}

/**
 * Se recorre la lista desde el primer elemento hasta que regresamos a ese mismo, en caso de encontrar el numero en algun
 * nodo recorrido se regresa ese mismo nod. Si la lista esta vacia o no se encuentra un nodo con el mismo numero entonces
 * regresa nulo
 *
 * @param element numero seleccionado por el usuario
 * @return nodo perteneciente a la lista que contiene el numero
 */
node *list::find(int element) {
    if (isEmpty())
        return 0;
    node *aux = first;
    do {
        if (aux->info == element)
            return aux;
        aux = aux->next;
    } while (aux != first);
    return 0;
}

/**
 * Se recorre la lista desde el primer elemento hasta que regresamos a ese mismo, cada nodo se va eliminando y una vez
 * terminado se inicializan los punteros auxiliares a nulo y el tamaño en cero
 */
list::~list() {
    if (isEmpty()) {
        return;
    }
    node *end = first;
    do {
        header = first;
        first = first->next;
        delete header;
    } while (first != end);
    first = 0;
    header = 0;
    last = 0;
    size = 0;
}

/**
 * Sobre carga la operacion para imprimir, Se recore la lista y se envia al objeto encargado de imprimir en la consola
 *
 * @param out objeto encargado de imprimir en la consola
 * @param list lista a imprimir
 * @return El objeto encargado de imprimir
 */
std::ostream &operator<<(std::ostream &out, list &list) {
    if (list.isEmpty()) {
        out << "La lista esta vacia";
    } else {
        node *aux = list.getFirst();
        do {
            out << list.get(aux) << ((list.next(aux) != list.getFirst()) ? ", " : "");
            aux = list.next(aux);
        } while (aux != list.getFirst());
    }
    return out;
}

/**
 * Recorre la lista y decrementa el index, una vez llegue a cero se regresa el nodo en el que se encuentre el recorrido
 *
 * @param index posicion a obtener
 * @return nodo en el lugar indicado
 */
node *list::findByIndex(int index) {
    node *aux = first;
    do{
        if (index == 0)
            return aux;
        aux = aux->next;
        index--;
    }while (aux != first);
    return 0;
}

/**
 * Recorre la lista contando cada nodo, una vez se encuentra el nodo regresa el numero hasta el que se conto
 *
 * @param index nodo a buscar
 * @return numero que indica la posicion del nodo
 */
int list::getIndex(node *index) {
    int i = 0;
    node *aux = first;
    do {
        if (aux == index)
            return i;
        aux = aux->next;
        i++;
    }while (aux != first);
    return -1;
}
