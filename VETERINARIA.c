//Ricardo David Lopez Arellano
#include <conio.h>
#include <stdio.h>

int main(){
    int opc,opc2,edadM[3],pesoM[5],numeroD[10],buscarM;
    char buscarT,nombreM[20],tipoM[20],nombreD[20],direccionD[30],buscarMnm[20],buscarMnd[20];

        printf( "\n\t\t\t < VETERINARIA TOY'S >\n" );
        printf("\nBienvenido a Veterinaria Toy's estamos para servirle, Qu%c desea ordenar?\n",130);
        printf("\nNuestas opciones son:");
        printf( "\n  1. Capturar o agregar mascotas." );
        printf( "\n  2. Mostrar mascotas:" );
        printf( "\n  3. Eliminar mascotas." );
        printf( "\n  4. Salir.\n" );
        do{
            printf("\nIntroduzca una opci%cn (1-4): ",162);
            scanf("%d",&opc);
            printf("\n");
            switch(opc)
            {
                case 1:
                    printf("\tSeleccionaste 'Capturar o agregar mascotas'\n");
                    printf("\nCu%cl es el nombre de tu mascota? ",160);
                    scanf("%s",&nombreM);
                    printf("Edad de tu mascota?(en a%cos) ",164);
                    scanf("%d",&edadM);
                    printf("Peso de tu mascota?(en kilos) ");
                    scanf("%d",&pesoM);
                    printf("Tipo de mascota?(Perro,gato,hamster,etc.) ");
                    scanf("%s",&tipoM);
                    printf("\nA continuaci%cn ingrese los datos del due%co",162,164);
                    printf("\nCu%cl es tu nombre? ",160);
                    scanf("%s",&nombreD);
                    printf("Cu%cl es tu direcci%cn? ",160,162);
                    scanf("%s",&direccionD);
                    printf("Cu%cl es tu n%cmero de telefono? ",160,163);
                    scanf("%d",&numeroD);
                    printf("\nEs todo lo que necesitas llenar, gracias! :) \n");

                case 2:
                    printf("\tSeleccionaste 'Mostrar Mascotas'\n");
                    printf("\nNuestras opciones para buscar son las siguientes: ");
                    printf( "\n  1. Todas las mascotas (se mostrar%cn alfab%cticamente)" ,160,130);
                    printf( "\n  2. Buscar una mascota en particular" );
                    printf( "\n  3. Por tipo (si s%clo se quieren ver los perros, o s%clo gatos, etc.)" ,162,162);
                    printf( "\n  4. Por due%co (Todas las mascotas de una persona solamente)" ,164);
                    printf( "\n  5. Salir.\n" );

                    printf("\nIntroduzca una opci%cn (1-5): ",162);
                    scanf("%d",&opc2);
                    printf("\n");

                    switch(opc2){
                        case 1:
                            printf("\tSeleccionaste 'Mostrar mascotas alfab%cticamente'\n",130);
                            printf("Las mascotas son: ");
                            printf(nombreM);
                        case 2:
                            printf("\tSeleccionaste 'Buscar una mascota en particular'\n");
                            printf("\nPuedes buscar las mascotas de la siguiente forma: \n");
                            printf("   1.  Nombre de la mascota\n");
                            printf("   2.  Nombre del due%co de la mascota\n",164);
                            printf("C%cmo quieres buscar la mascota? ",162);
                            scanf("%d",&buscarM);
                            if(buscarM == 1)
                                    printf("Cu%cl es el nombre de la mascota que quieres buscar? ",160);
                                    scanf("%s",&buscarMnm);
                            if(buscarM==2)
                                    printf("Cu%l es el nombre del due%co de la mascota? ",160,164);
                                    scanf("%s",&buscarMnd);
                        case 3:
                            printf("\tSeleccionaste 'Por tipo'\n");
                            printf("Que tipo quieres buscar? ");
                            scanf("%s",&buscarT);
                        case 4:
                            printf("\tSeleccionaste 'Por due%co'\n",164);
                            printf("C%cmo se llama el due%co? ",162,164);
                    }while ( opc2!=5 );

                case 3:
                    printf("\tSeleccionaste 'Eliminar mascotas'\n");


            }

        } while ( opc!=4 );
    return 0;
    }
