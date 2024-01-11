#include <iostream>
#include <locale.h>//acentos
#include <fstream>//doc.txt

using namespace std;

void lectura();

int main(){
	lectura();
	
	system ("pause");
	return 0;
}

void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("Cabecera Ethernet.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo...";
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}

