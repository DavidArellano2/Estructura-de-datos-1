//Ricardo David Lopez Arellano
#include <conio.h>
#include <stdio.h>

int main(){
    int opcion,nAleatorio[20],i=0,vector[15],matriz[4][5];
    int x=0,contador=0;
    char caracter,cadena[255];
    char nombres[5][20]={"Sonia", "Alex", "Ana", "Luis", "David"};
	int No_existe, z[10],codigo,op;
	int d, g, acumulador=0, promediar, promedio;
    int matriz2[4][5]={
            { 1,  5, 8, 2, 1 },
            { 5,  2, 4, 3, 0 },
            { 6,  4, 3, 5, 9 },
            { 5,  9, 7, 8, 4 },};

printf( "\n\t\t\t ARREGLOS Y FUNCIONES\n" );
        printf("\nLas opciones son:\n");
        printf( "\n  1. Llenar con valores aleatorios un vector de enteros de 20 elementos. ", 163 );
        printf( "\n  2. Llenar un vector de 15 elementos con valores enteros (tu decides cuales).", 163 );
        printf( "\n  3. Capturar un texto de máximo 255 caracteres de longitud.", 163 );
        printf( "\n  4. Calcular el promedio de una fila o de una columna de una matriz de 4x5.");
        printf( "\n  5. Buscar alumno por codigo." );
        printf( "\n  6. Salir.\n" );
        do{
            printf("\nIntroduzca una opcion (1-6): ");
            scanf("%d",&opcion);
            printf("\n");
            switch(opcion)
            {
                case 1:printf("\t Vector de 20 elementos con valores aleatorios entre 1 y 50.\n");
                    srand (time(0));
                    for (i=0; i<=20; i++) {
                        nAleatorio[i] =1 + rand()%50;}
                    printf("\nLos numeros aleatorios multiplos de 3 son: \n");
                    for (i=1;i<20;i++){
                        if(nAleatorio[i] % 3 == 0)
                        printf("- Posicion %d y el numero es: %d\n",i,nAleatorio[i]);}
                    printf("\nNumeros almacenados en los multiplos de 5 son: \n");
                    for (i=1;i<=20;i++){
                        if(i%5==0)
                        printf("- Posicion %d y el numero es: %d\n",i,nAleatorio[i]);}
                    printf("\nEl vector completo es el sigiente: \n");
                    for (i=1; i<=20; i++) {
                        printf("Aleatorio %d vale: %d\n", i, nAleatorio[i]);}
                    printf(" ");
                    break;

                case 2: printf("\tVector con 15 elementos los cuales tu decidiras\n\n");
                    for (i=0;i<15;i++){
                        printf("Ingresa un valor: ");
                        scanf("%d", &vector[i]);}
                    printf("\nValores Pares: \n");
                    for (i=0;i<15;i++){
                        if (vector[i]%2==0){
                            printf(" %d,",vector[i]);}}
                    printf("\n\nValores primos: \n");
                    for (i=0;i<15;i++){
                        if (vector[i]%2!=0){
                            printf(" %d,",vector[i]);}}
                        printf(" ");
                     break;
                case 3:printf("\t Ingresar un texto de maximo 255 caracteres de longitud\n\n");
                        printf("Ingrese una cadena (SIN ESPACIOS): ");
                        scanf("%s",cadena);
                        printf("Cual caracter quieres buscar? ");
                        scanf(" %c",&caracter);
                        while (cadena[x]!=0){
                            if (cadena[x]==caracter){
                                contador++;}
                            x++;}
                        if(contador>0){
                            printf("Tu caracter fue encontrado %d veces",contador);}
                        else{
                            printf("Ese caracter NO existe en la cadena");}
                        printf(" ");
                        break;

                case 4:printf("\tSACAR PROMEDIO DE COLUMNA O FILA DE LA MATRIZ\n");
                        printf("Opciones que hay: \n");
                        printf("1.  Fila \n");
                        printf("2.  Columna \n");
                        printf("Que deseas promediar? ");
                        scanf(" %d",&promediar);
                        switch(promediar)
                        {
                          case 1: printf("Ahora, escoge la fila que quieres del 1 al 4: ");
                                  scanf("%d",&d);
                                  for(i=0;i<5;i++){
                                        acumulador+=matriz2[d-1][i];}
                                   promedio=acumulador/5;
                                   printf("El promedio de la fila %d es: %d",d, promedio);
                                   break;
                          case 2: printf("Ahora escoge la columna que quieres de 1 al 5: ");
                                  scanf(" %d",&g);
                                  for(i=0;i<6;i++){
                                        acumulador+=matriz2[g-1][i];}
                                    promedio=acumulador/6;
                                    printf("El promedio de la columna %d es: %d",g, promedio);
                                    break;}
                                    printf("\nMatriz dada: \n");
                                    for (int i=0;i<4;i++){
                                        for (int j=0;j<5;j++){
                                            printf("%d ",matriz2[i][j]);}
                                        printf("\n");}
                case 5:printf("   NOMBRE Y CODIGO DE ALUMNOS\n\n");
                        printf("Codigo \nAlumno\t\tNombre");
                        printf("\n    \n");
                        for(i=0;i<5;i++){
                            z[i]=i+1;
                            printf("  %i             %s \n", z[i], nombres[i]);}
                        printf("\n Buscar alumno por codigo \n");
                        printf("\nIngrese el codigo: - ");
                                scanf("%i", &codigo);
                                No_existe=1;
                                for(i=0;i<5;i++){
                                    if(z[i]==codigo){
                                        printf("\n Se encontro una coincidencia en la posicion:%i \n Codigo de alumno:%i \n Nombre:%s\n", i, z[i], nombres[i]);
                                        No_existe=0;}}
                                if(No_existe==1){
                                    printf("\nEse alumno no existe en nuestra base de datos\n");}
                           break;
                           }
    } while ( opcion!=6 );
    return 0;
}
