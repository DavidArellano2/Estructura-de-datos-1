#include <iostream>
#include "node.h"
#include "list.h"

int main() {
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
