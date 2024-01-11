#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class lista{
    private:
        char nombre[25];
        int  elem;
        float tamanio;
    public:
        int operator == (lista);
        int operator != (lista);
        int operator > (lista);
        int operator < (lista);
        void operator = (lista);
        friend std::istream &operator>> (std::istream &, lista &);
        friend std::ostream &operator<< (std::ostream &, lista &);
};

int lista::operator==(lista pos){
    if(elem==pos.elem)
        return 1;
    return 0;
}

void lista::operator=(lista pos){
    elem=pos.elem;
    tamanio=pos.tamanio;
    //strcpy(nombre, pos.nombre);
}

int lista::operator!=(lista pos){
    if(elem!=pos.elem)// || tamanio!=pos.tamanio || strcmp(nombre,pos.nombre))
        return 1;
    return 0;
}

std::istream &operator>> (std::istream &Lee, lista &ObjProd){
    std::cout<<"\nIngrese elemento: ";
    Lee>> ObjProd.elem;
    return Lee;
}

std::ostream &operator<< (std::ostream &Escribe, lista &ObjProd){
    //Escribe<<"\nDatos de la lista: ";
    Escribe<<"\n Elementos: "<<ObjProd.elem;
    return Escribe;
}

class nodo{
    private:
        lista info;
        nodo *pnodo;
    public:
        nodo();
        friend class ListaSimpleCircular;
};

nodo::nodo(){
    pnodo=0;
}

class ListaSimpleCircular{
    private:
        nodo *pLista;
    public:
        ListaSimpleCircular();
        int vacia();
        void inserta(lista, nodo*);
        int elimina(nodo*);
        nodo* primero();
        nodo* ultimo();
        nodo* anterior(nodo*);
        nodo* siguiente(nodo*);
        nodo* localiza(lista);
        lista  recupera(nodo*);
        void imprime();
        void anula();
};

ListaSimpleCircular::ListaSimpleCircular(){
    pLista=0;
}

int ListaSimpleCircular::vacia(){
    if(pLista==0)
        return 1;
    return 0;
}

nodo* ListaSimpleCircular::primero(){
    return pLista;
}

nodo* ListaSimpleCircular::ultimo(){
    if(vacia())
        return NULL;
    nodo* aux=pLista;
    while(aux->pnodo!=pLista)
        aux=aux->pnodo;
    return aux;
}

nodo* ListaSimpleCircular::anterior(nodo* pos){
    if(vacia() || pos==NULL)
        return NULL;
    nodo* aux=pLista;
    while(aux->pnodo!=pos)
        aux=aux->pnodo;
    return aux;
}

nodo* ListaSimpleCircular::siguiente(nodo* pos){
    if(vacia() || pos==NULL)
        return NULL;
    return pos->pnodo;
}

nodo* ListaSimpleCircular::localiza(lista elem){
    if(vacia())
        return NULL;
    nodo* aux=pLista;
    do{
        if(aux->info!=elem)
            return aux;
        aux=aux->pnodo;
    }while(aux!=pLista);
    return NULL;
}

lista ListaSimpleCircular::recupera(nodo* pos){
    if(vacia() || pos==NULL)
        std::cout<<"Insuficiencia de datos";
    return pos->info;
}

void ListaSimpleCircular::imprime(){
    if(vacia())
    	cout<<"\nError, la lista esta vacia...\n";
        return;
    nodo* aux=pLista;
    cout<<"\nDatos de la lista: ";
    do{
        std::cout<<"\t"<<aux->info;
        aux=aux->pnodo;
    }while(aux!=pLista);
}

void ListaSimpleCircular::anula(){
    if(vacia())
        exit(EXIT_SUCCESS);
    nodo* aux, *marca=pLista;
    do{
        aux=pLista;
        pLista=pLista->pnodo;
        delete(aux);
    }while(pLista!=marca);
    pLista= NULL;
}

void ListaSimpleCircular::inserta(lista elem, nodo* pos){
    nodo* aux=new nodo;
    aux->info=elem;
    if(vacia()){
        aux->pnodo=aux;
        pLista=aux;
    }
    else{
        if(pos==NULL){
            aux->pnodo=pLista;
            ultimo()->pnodo=aux;
            pLista=aux;
        }
        else{
            aux->pnodo=pos->pnodo;
            pos->pnodo=aux;
        }
    }
}

int ListaSimpleCircular::elimina(nodo* pos){
    if(vacia() || pos==NULL )
        return 0;
    if(pos->pnodo==pos)
        pLista=NULL;
    else{
        if(pos==pLista){
            ultimo()->pnodo=pLista->pnodo;
            pLista=pLista->pnodo;
        }
        else
            anterior(pos)->pnodo=pos->pnodo;
    }
    delete(pos);
    return 1;
}

int main()
{
    ListaSimpleCircular Registro;
    lista lista;
    
    int opcion = 0;
    do {
    	system("cls");
    	std::cout<<"\n\t\t< Lista simplemente ligada sin encabezado >\n"<<endl;
    	std::cout<< "Que deseas hacer?\n"<<endl;
        std::cout<< "1.- Ingresar elemento"<<endl;
        std::cout<< "2.- Imprimir lista"<<endl;
		std::cout<< "3.- Eliminar elemento"<<endl;
		std::cout<< "4.- Modificar elemento"<<endl;
		std::cout<< "5.- Anular"<<endl;
		std::cout<< "6.- Vacia"<<endl;
		std::cout<<	"0.- Salir"<<endl;
		cout<< "Seleciona una opcion: ";
        std::cin>>opcion;
        
        switch (opcion) {
            case 1: {
				system("cls");
            	cout<<"\t\tIngresar elementos:"<<endl;
			    cin>>lista;
			    Registro.inserta(lista,Registro.ultimo());
			    //lista elem, nodo* pos
			    cout<<endl;
				system("pause");
				break;
			}
			
			case 2:{
				system("cls");
            	cout<<"\t\tImprimir lista:"<<endl;
				Registro.imprime();
				cout<<endl<<endl;
				system("pause");
				break;
			}
			
			case 3:{
				system("cls");
            	cout<<"\t\tEliminar elemento:"<<endl;
				Registro.elimina(nodo);
				cout<<endl<<endl;
				system("pause");
				break;
			}
			
			case 4:{
				system("cls");
            	cout<<"\t\tModificar elemento:"<<endl;
				
				break;
			}
			
	
			case 0:{
	            	system("cls");
	                break;
	            }
	            default:{
	                std::cout<<"Opcion invalida\n";
	                system("pause");
	                break;
	            }
	        }
	    } while (opcion != 0);
	
	/*
	for(int i=0; i<3;i++){
        std::cin>>list;
        Registro.inserta(list,Registro.ultimo());
    }
    Registro.imprime();*/

    return 0;
}
