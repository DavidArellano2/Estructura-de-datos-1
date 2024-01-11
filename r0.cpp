/*NickName: NueveCero
Numero de ejercicio: Ejercicio0_EDA2
Titulo de ejercicio: Pruebas de Software
Tiempo 3:10*/

//Declaración y definición de constantes:
#include <iostream>
#include <locale.h>//acentos
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main(){
	setlocale(LC_CTYPE,"Spanish");//acentos
	srand(time(NULL));

	//Declaración de variables globales
	int i0 = 0, i1 = 1;
	int anio, mes, dia;
	srand(time(NULL));
	
	anio = (rand()%1000)+1500;	  
	mes = (rand()%15);
	dia = (rand()%50);
	//Título de la aplicación
	cout<<"\tVERIFICADOR DE FECHA v1.0"<<endl;
	cout<<"\nProbando fecha: "<<anio<<" / "<<mes<<" / "<<dia<<endl;
	
	//Desarrollo aplicacion
	if ((anio % 4 == 0)&& (anio %100 !=0)||(anio %400 == 0)){
		if (mes>=1 && mes<=12){
			if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia>=1 && dia<=31)){
			cout<<"Fecha válida";
			}
			else if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia>=1 && dia<=30)){
				cout<<"Fecha válida";
			}
			else if ((mes==2) && (dia>=1 && dia<=29)){
				cout<<"Fecha válida";
			}
			else{
				cout<<"Día inválido";
			}
		}
		else{
			cout<<"Mes inválido";
		}
	}		
	else{
		
		if (mes>=1 && mes<=12){
			if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia>=1 && dia<=31)){
			cout<<"Fecha válida";
			}
			else if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia>=1 && dia<=30)){
				cout<<"Fecha válida";
			}
			else if ((mes==2) && (dia>=1 && dia<=28)){
				cout<<"Fecha válida";
			}
			else{
				cout<<"Día inválido";
			}
		}
		else{
			cout<<"Mes inválido";
		}
	}
	cout<<"\n\nPresione entrar para continuar . . .";
	if(getchar()=='\n'){
		return 0;
	}		
}
