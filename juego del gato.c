#include <stdio.h>
#include <stdbool.h>


char numero = '1';
char gato[3][3];
char marca = 'X';



void llenarGato();
void imprimirGato();
void cambiarTurno();
int pedirCasillaAlJugador();
bool escribirEnLaCasilla(bool repetirTurnoElMismoJugador);




void cambiarTurno(){

	if (marca == 'X'){
		marca = 'O';
	}else{
		marca = 'X';
	}
}



void llenarGato(){


	for(int filas=0;filas<3;filas++)
		for(int columnas=0;columnas<3;columnas++)
			gato[filas][columnas] = numero++;

}

void imprimirGato(){
	for(int filas=0;filas<3;filas++){
		for(int columnas=0;columnas<3;columnas++)
			printf("%c ",gato[filas][columnas]);
				printf("\n");
	}
}


int pedirCasillaAlJugador(){
	int casillaDondeQuiereLaMarcaElJugador;
	printf("Dame el numero donde quieres poner la %c\n", marca);
	scanf("%d",&casillaDondeQuiereLaMarcaElJugador);

	return casillaDondeQuiereLaMarcaElJugador;
}


bool escribirEnLaCasilla(bool repetirTurnoElMismoJugador){
	switch(pedirCasillaAlJugador()){

					case 1:
							if(gato[0][0]=='1'){
								gato[0][0] = marca;

							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 2:
							if(gato[0][1]=='2'){
								gato[0][1] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 3:
							if(gato[0][2]=='3'){
								gato[0][2] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 4:
							if(gato[1][0]=='4'){
								gato[1][0] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 5:
							if(gato[1][1]=='5'){
								gato[1][1] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 6:
							if(gato[1][2]=='6'){
								gato[1][2] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 7:
							if(gato[2][0]=='7'){
								gato[2][0] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 8:
							if(gato[2][1]=='8'){
								gato[2][1] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					case 9:
							if(gato[2][2]=='9'){
								gato[2][2] = marca;
							}else{
								printf("Espacio ya ocupado\n");
								repetirTurnoElMismoJugador = true;
							}
							break;
					default: printf("No existe ese número dentro del gato\n");
							 repetirTurnoElMismoJugador = true;
				}

	return repetirTurnoElMismoJugador;
}


int main(){

		bool repetirTurnoElMismoJugador;
		bool seguirJugando;
		int vecesJugando = 1;

		llenarGato();

		do{

			do{
				imprimirGato();
				repetirTurnoElMismoJugador = false;
			}while(escribirEnLaCasilla(repetirTurnoElMismoJugador));

			if ((gato[0][0]==marca&&gato[0][1]==marca&&gato[0][2]==marca)||
				(gato[1][0]==marca&&gato[1][1]==marca&&gato[1][2]==marca)||
				(gato[2][0]==marca&&gato[2][1]==marca&&gato[2][2]==marca)||
				(gato[0][0]==marca&&gato[1][0]==marca&&gato[2][0]==marca)||
				(gato[0][1]==marca&&gato[1][1]==marca&&gato[2][1]==marca)||
				(gato[0][2]==marca&&gato[1][2]==marca&&gato[2][2]==marca)||
				(gato[0][0]==marca&&gato[1][1]==marca&&gato[2][2]==marca)||
				(gato[0][2]==marca&&gato[1][1]==marca&&gato[2][0]==marca)){

				printf("FELICIDADES GANO EL JUGADOR %c\n", marca);

				imprimirGato();

				seguirJugando = false;
			}else{

				if(vecesJugando<9){

					seguirJugando = true;
                    cambiarTurno();
					vecesJugando++;

				}else{

					printf("Empate!!!\n");
					seguirJugando = false;
				}

			}

		}while(seguirJugando);

	return 0;
}
