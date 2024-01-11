#include <iostream>

using namespace std;

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

int main()
{
    list list;

    int opcion = 0;
    int info = 0;
    int pos = 0;
    bool result = false;
    node *aux = 0;

    do {
        std::cout
                << "1.- Insertar\n2.- Eliminar\n3.- Primer Elemento\n4.- Ultimo Elemento\n5.- Busqueda\n6.- Recupera \n7.- Imprime\n0.- Salir\n";
        std::cin >> opcion;
        switch (opcion) {
            case 1: {
                std::cout << "Ingrese el numero a insertar: ";
                std::cin >> info;

                std::cout << "Ingrese la posicion en la que desea insertar: ";
                std::cin >> pos;
                aux = list.findByIndex(pos);

                list.add(info, aux);
                std::cout << "Numero agregado exitosamente\n";
                break;
            }
            case 2: {
                std::cout << "Ingrese la posicion que desea eliminar: ";
                std::cin >> pos;
                aux = list.findByIndex(pos);

                list.remove(aux);
                std::cout << "Posicion eliminada exitosamente\n";
                break;
            }
            case 3: {
                try {
                    info = list.get(list.getFirst());
                    std::cout << "El numero en la primera posicion es " << info << "\n";
                } catch (std::exception &e) {
                    std::cout << "La lista esta vacia\n";
                }
                break;
            }
            case 4: {
                try {
                    info = list.get(list.getLast());
                    std::cout << "El numero en la ultima posicion es " << info << "\n";
                } catch (std::exception &e) {
                    std::cout << "La lista esta vacia\n";
                }
                break;
            }
            case 5: {
                std::cout << "Ingrese el numero a buscar: ";
                std::cin >> info;

                aux = list.find(info);
                if (aux != 0)
                    std::cout << "Se ha encontrado en la posicion " << list.getIndex(aux) << "\n";
                else
                    std::cout << "El numero no se encuentra en la lista\n";
                break;
            }
            case 6: {
                std::cout << "Ingrese la posicion a buscar: ";
                std::cin >> pos;

                aux = list.findByIndex(pos);
                try {
                    info = list.get(aux);
                    std::cout << "El numero en la posicion " << pos << " es " << info << "\n";
                } catch (std::exception &e) {
                    if (list.isEmpty())
                        std::cout << "La lista esta vacia\n";
                    else
                        std::cout << "La posicion no existe\n";
                }
                break;
            }
            case 7: {
                std::cout << list;
                std::cout << "\n";
                break;
            }
            case 0: {
                break;
            }
            default: {
                std::cout << "Opcion invalida";
                break;
            }

        }
    } while (opcion != 0);
}

node::node() {
    next = 0;
    prev = 0;
}

std::ostream &operator<<(std::ostream &out, node &node) {
    out << node.info;
    return out;
}

list::list() {
    first = 0;
    header = 0;
    last = 0;
    size = 0;
}

bool list::isEmpty() {
    return first == 0;
}

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

node *list::getFirst() {
    return first;
}

node *list::getLast() {
    return last;
}

node *list::previous(node *postition) {
    if (isEmpty() || postition == 0) {
        return 0;
    }
    return postition->prev;
}

node *list::next(node *postition) {

    if (isEmpty() || postition == 0) {
        return 0;
    }
    return postition->next;
}

int list::get(node *position) {
    if (isEmpty() || position == 0) {
        throw "Datos Insuficientes";
    } else {
        return position->info;
    }
}

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
