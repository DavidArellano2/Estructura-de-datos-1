#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
    Nodo *aux;
    Nodo *aux1;
    Nodo *aux2;
    Nodo *aux3;
};

void MENU();

Nodo crearNodo(int, Nodo);

void insertarNodo(Nodo*&, int);

void MostrarA(Nodo *, int);

bool Buscar(Nodo *, int);

bool Modificar(Nodo *&, int);

void preOrden(Nodo *);

void enOrden(Nodo *);

void postOrden(Nodo *);

void Eliminar(Nodo *, int);

void EliminarNodo(Nodo *);

void Reemplazar(Nodo *, Nodo *);

void DestruirNodo(Nodo *);

void Rotacionsimpleizq(Nodo *);

void Rotacionsimpleder(Nodo *);

void RotacionDobleizq(Nodo *);

void RotacionDobleder(Nodo *);

Nodo *Minimo(Nodo *);

Nodo *arbol=NULL;

int main()
{
    MENU();

    return 0;
}

Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->padre=padre;

    return nuevo_nodo;
}

Nodo *Minimo(Nodo *arbol){
    if(arbol==NULL){
        return NULL;
    }
    if(arbol->izq){
        return Minimo(arbol->izq);
    }else{
        return arbol;
    }
}

void MENU(){
    int dato, op, contador=0, n, x;
    do{
        cout<<"-MENU-"<<endl;
        cout<<"(1)-Insertar nuevo Nodo"<<endl;
        cout<<"(2)-Imprimir arbol"<<endl;
        cout<<"(3)-Buscar elememto"<<endl;
        cout<<"(4)-Eliminar elemento"<<endl;
        cout<<"(5)-PreOrden"<<endl;
        cout<<"(6)-EnOrden"<<endl;
        cout<<"(7)-PosOrden"<<endl;
        cout<<"(8)-Rotacion simple a la izquierda"<<endl;
        cout<<"(9)-Rotacion simple a la derecha"<<endl;
        cout<<"(10)-Rotacion doble a la izquierda"<<endl;
        cout<<"(11)-Rotacion doble a la derecha"<<endl;
        cout<<"(12)-Salir"<<endl;
        cin>>op;
        switch(op){
            case 1: cout<<"Ingresa un numero: "<<endl;
            cin>>dato;
            insertarNodo(arbol,dato);
            system("pause");
            break;
            case 2:
                MostrarA(arbol, contador);
                cout<<"/n";
                system("pause");
                break;
            case 3:
               cout<<"Ingresa un elemento a buscar:"<<endl;
               cin>>dato;
               if(Buscar(arbol, dato)==true){
                cout<<"El elemento "<<dato<<" a sido encontrado en el arbol"<<endl;
               }else{
                   cout<<"El elemento no se encuentra dentro del arbol"<<endl;
               }
               system("pause");
               break;
            case 4:
                cout<<"Digita el numero a eliminar: "<<endl;
                cin>>dato;
                Eliminar(arbol, dato);
                cout<<endl;
                system("pause");
                break;
            case 5:
                cout<<"Pre Orden"<<endl;
                preOrden(arbol);
               break;
            case 6:
                cout<<"En Orden"<<endl;
                enOrden(arbol);
                break;
            case 7:
                cout<<"Post Orden"<<endl;
                postOrden(arbol);
                break;
            case 8:
                cout<<"Rotacion simple a la izquierda"<<endl;
                Rotacionsimpleizq(arbol);
                break;
            case 9:
                cout<<"Rotacion simple a la derecha"<<endl;
                Rotacionsimpleder(arbol);
                break;
            case 10:
                cout<<"Rotacion doble a la izquierda"<<endl;
                RotacionDobleizq(arbol);
                break;
            case 11:
                cout<<"Rotacion doble a la derecha"<<endl;
                RotacionDobleder(arbol);
                break;
        }
        system("cls");
    }while(op!=12);
}

void insertarNodo(Nodo *&arbol, int n){
    if(arbol==NULL){
        Nodo *padre = NULL;
        Nodo *nuevo_nodo=crearNodo(n,padre);
        arbol=nuevo_nodo;
    }else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->izq,n);
        }else{
            insertarNodo(arbol->der,n);
        }
    }
}

void MostrarA(Nodo *arbol, int contador){
    if(arbol==NULL){
        return;
    }else{
        MostrarA(arbol->der,contador+1);
        for(int i=0; i<contador; i++){
            cout<<"  ";
        }
        cout<<arbol->dato<<endl;
        MostrarA(arbol->izq,contador+1);
    }
}

bool Buscar(Nodo *arbol, int n){
    if(arbol==NULL){
        return false;
    }else
    if(arbol->dato==n){
        return true;
    }else
    if(n<arbol->dato){
        return Buscar(arbol->izq,n);
    }else{
        return Buscar(arbol->der,n);
    }
}

bool Modificar(Nodo *&arbol, int n){
    if(arbol==NULL){
        return false;
    }
    else if(arbol->dato==n){
        return true;
    }
    else if(n<arbol->dato){
        return Modificar(arbol->izq,n);
    }else{
        return Modificar(arbol->der, n);
    }
}

void preOrden(Nodo *arbol){
    if(arbol!=NULL){
            return;
    }else{
        cout<<arbol->dato<<"-"<<endl;
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(Nodo *arbol){
    if(arbol!=NULL){
            return;
    }else{
        enOrden(arbol->izq);
        cout<<arbol->dato<<"-"<<endl;
        enOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol){
    if(arbol!=NULL){
            return;
    }else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->dato<<"-"<<endl;
    }
}

void Eliminar(Nodo *arbol, int n){
    if(arbol==NULL){
        return;
    }else if(n<arbol->dato){
        Eliminar(arbol->izq,n);
    }else if(n>arbol->dato){
        Eliminar(arbol->der,n);
    }else{
        EliminarNodo(arbol);
    }
}

void Reemplazar(Nodo *arbol, Nodo *nuevoNodo){
    if(arbol->padre){
        if(arbol->dato==arbol->padre->izq->dato){
            arbol->padre->izq=nuevoNodo;
        }else if(arbol->dato==arbol->padre->der->dato){
            arbol->padre->der=nuevoNodo;
        }
    }
    if(nuevoNodo){
        nuevoNodo->padre=arbol->padre;
    }
}

void DestruirNodo(Nodo *Nodo){
    Nodo->izq=NULL;
    Nodo->der=NULL;
    delete Nodo;
}

void EliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->der){
        Nodo *menor=Minimo(nodoEliminar->der);
        nodoEliminar->dato=menor->dato;
        EliminarNodo(menor);
    }else if(nodoEliminar->izq){
        Reemplazar(nodoEliminar,nodoEliminar->izq);
        DestruirNodo(nodoEliminar);
    }else if(nodoEliminar->der){
        Reemplazar(nodoEliminar, nodoEliminar->der);
        DestruirNodo(nodoEliminar);
    }else{
        Reemplazar(nodoEliminar,NULL);
        DestruirNodo(nodoEliminar);
    }
}

void Rotacionsimpleizq(Nodo *arbol, Nodo *aux, Nodo *aux1){
    if(arbol==NULL){
        return;
    }else{
        aux=arbol->der;
        aux1=aux->izq;
        arbol->der=aux1;
        aux->izq=arbol;
        arbol=aux;
    }
}

void Rotacionsimpleder(Nodo *arbol, Nodo *aux, Nodo *aux1){
    if(arbol==NULL){
        return;
    }else{
        aux=arbol->izq;
        aux1=aux->der;
        arbol->izq=aux1;
        aux->der=arbol;
        arbol=aux;
    }
}

void RotacionDobleizq(Nodo *arbol, Nodo *aux, Nodo *aux1, Nodo *aux2, Nodo *aux3){
    if(arbol==NULL){
        return;
    }else{
     aux=arbol->der;
     aux1=aux->der->izq;
     aux2=aux1->izq;
     if(aux2==NULL){
        aux3=NULL;
     }else{
         aux3=aux1->der;
     }
     arbol->der=aux2;
     aux->izq=aux3;
     aux1->izq=arbol;
     aux1->der=aux;
     arbol=aux1;
    }
}

void RotacionDobleder(Nodo *, Nodo *aux, Nodo *aux1, Nodo *aux2, Nodo *aux3){
        if(arbol==NULL){
        return;
    }else{
     aux=arbol->izq;
     aux1=aux->der;
     aux2=aux1->der;
     if(aux2==NULL){
     aux3=NULL;
     }else{
     aux3=aux1->izq;
     arbol->izq=aux2;
     aux->der=aux3;
     aux1->der=arbol;
     aux1->izq=aux;
     arbol=aux1;
     }
    }
}
