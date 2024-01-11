#include <iostream>

class nodo{
private:
    float info;
    nodo* izq;
    nodo* der;
public:
    nodo();
    friend class arbol;
};

nodo::nodo(){
    izq=NULL;
    der=NULL;
}

class arbol{
private:
    nodo* raiz;
public:
    arbol();
    int vacio();
    float recupera(nodo *);
    void inserta_iterativo(float);
    nodo* localiza(float, nodo*);
    nodo* menor(nodo*);
    nodo* mayor(nodo*);
    int es_hoja(nodo*);
    int recorrido_preorden(nodo* Arbol);
    nodo* get_raiz();
};

nodo* arbol::get_raiz(){
    return raiz;
}

arbol::arbol() {
    raiz=NULL;
}

arbol::vacio() {
    if(raiz==NULL)
        return  1;
    return  0;
}

float arbol::recupera(nodo* pos) {
    if(vacio() || pos==NULL){
        std::cout<<"¡Error de excepción! Insuficiencia de datos";
    }
    else
        return pos->info;
}

void arbol::inserta_iterativo(float elem){

    if(raiz==NULL){
        nodo* aux=new nodo;
        aux->info=elem;
        raiz=aux;
    }
    else{
        nodo* aux=raiz;
        nodo* aux2;
        while(aux!=NULL){
            aux2=aux;
            if(elem<aux->info){
                aux=aux->izq;
                if(aux==NULL){
                    nodo* p=new nodo;
                    p->info=elem;
                    aux2->izq=p;
                }
            }
            else{
                aux=aux->der;
                if(aux==NULL){
                    nodo* p=new nodo;
                    p->info=elem;
                    aux2->der=p;
                }
            }
        }
    }
}

nodo* arbol::localiza(float elem, nodo* Arbol){
    if(Arbol==NULL)
        return NULL;
    else
        if(elem==Arbol->info)
            return Arbol;
        else
            if(elem<Arbol->info)
                return localiza(elem, Arbol->izq);
            else
                return localiza(elem, Arbol->der);
}

nodo* arbol::menor(nodo *Arbol){
    if(Arbol==NULL)
        return NULL;
    else
        if(Arbol->izq==NULL)
            return Arbol;
        else
            return menor(Arbol->izq);
}

nodo* arbol::mayor(nodo *Arbol){
    if(Arbol==NULL)
        return NULL;
    else
        if(Arbol->der==NULL)
            return Arbol;
        else
            return mayor(Arbol->der);
}

int arbol::es_hoja(nodo* Arbol){
    if(Arbol==NULL)
        return 0;
    if(Arbol->der==NULL && Arbol->izq==NULL)
            return 1;
        else
            return 0;
}

int arbol::recorrido_preorden(nodo* Arbol){
    if(Arbol==NULL)
        return 0;
    std::cout<<"  "<<Arbol->info;
    recorrido_preorden(Arbol->izq);
    recorrido_preorden(Arbol->der);
}

int main()
{
    arbol Miarbol;
    int p;
    for(int i=1;i<=15;i++){
        std::cout<<"ingrese elemento \n";
        std::cin>>p;
        Miarbol.inserta_iterativo(p);
    }
    Miarbol.recorrido_preorden(Miarbol.get_raiz());
    return 0;
}
