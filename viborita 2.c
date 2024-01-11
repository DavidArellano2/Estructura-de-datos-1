#include <stdio.h>
#define v 20
#define h 60    //longitud del campo
#define n 100   //largo de la serpiente

typedef struct{
    int x,y;
    int modX,modY;
    char imagen;
}snk;

typedef struct{
    int x,y;
}frt;

snk snake[n];
frt fruta;

void inicio (int*tam,char campo[v][h]);
void intro_campo(char campo[v][h]);
void intro_datos(char campo[v][h],int tam);
void draw (char campo[v][h]);

int main (){
    int tam;
    char campo[v][h];

    inicio(&tam,campo); //iniciar todos nuestros elementos
    draw(campo);

    system("pause");
    return 0;
}

void inicio (int*tam,char campo[v][h]){
    //cabeza de la serpiente
    snake[0].x=32;
    snake[0].y=10;
    int i;

    //tamaño serpiente
    *tam=5;

    //coordenadas frutas
    srand(time(NULL));
    fruta.x=rand()%(h-1);//H para que no sea mayor a H y se salga la fruta
    fruta.y=rand()%(v-1);

    while(fruta.x==0){
        fruta.x=rand()%(h-1);
    }
    while (fruta.y==0){
        fruta.y=rand()%(v-1);
    }

    for (i = 0;i < *tam; i++){
        snake[i].modX==1;// para que no avance en diagonal
        snake[i].modY==0;
    }
    intro_campo(campo);
    intro_datos(campo,*tam);
}
//creacion del campo de juego
void intro_campo(char campo[v][h]){
    int i,j;

    for (i=0;i<v;i++){
        for (j=0;j<h;j++){
            if (i==0||i==v-1){
                campo[i][j]='|';
            }
            else if (j==0||j==h-1){
                campo[i][j]='|';
            }
            else{
                campo[i][j]=' ';
            }
        }
    }
}
// meter los datos en la matriz "campo"
void intro_datos(char campo[v][h],int tam){
    int i;

    for (i=1;i<tam;i++){//para rear las cordenadas x,y del resto de la serpiente
        snake[i].x=snake[i-1].x-1;
        snake[i].y=snake[i-1].y-1;

        snake[i].imagen='o';
}
    snake[0].imagen='0';

    for (i=0;i<tam;i++){
        campo[snake[i].y][snake[i].x]=snake[i].imagen;//coordenada vertical y horizontal
    }
    campo[fruta.y][fruta.x]='%';
}
void draw (char campo[v][h]){
    int i,j;

    for (i=0;i<v;i++){
        for (j=0;j<h;j++){
            printf("%.c",campo[i][j]);
        }
        printf("/n");
    }
}
