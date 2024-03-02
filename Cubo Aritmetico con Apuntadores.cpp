#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

#define TAM 5 

void rellenar_cubo();
void imprimir_cubo();
void menu_sumas();
void sumar_cubo();
void sumar_fila();
void sumar_columna();
void sumar_cara();
void graficos();

	int cubo[TAM][TAM][TAM];
	int *apCubo=cubo[0][0];

int main(){
	srand(time(NULL));
	rellenar_cubo();
		printf("*********************************************************************************************\n");
		printf("TAMANO DE CUBO EN BYTES: %d \n",sizeof(cubo));
		printf("*********************************************************************************************\n");
	menu_sumas();

	return 0;
}


void rellenar_cubo(){
	for(int i=0;i<sizeof(cubo)/sizeof(int);i++){
	
		*apCubo=1+rand()%9;
		apCubo++;
	}
}


void menu_sumas(){
	int eleccion_suma;
	do{
	imprimir_cubo();
	printf("*********************************************************************************************\n");
	printf("BIENVENIDO AL MENU DE OPCIONES, SELECCIONES UNA OPCION.\n");
	printf("\n1. Sumar todo el cubo. \n");
	printf("2. Sumar los elementos de una fila. \n");
	printf("3. Sumar los elementos de una cara. \n");
	printf("4. Sumar los elementos de una columna. \n");
	printf("5. Mostrar graficos. \n");
	printf("0. Salir. \n");
	printf("*********************************************************************************************\n");
	
	scanf("%d",&eleccion_suma);
	
	switch(eleccion_suma){
	
		case 1: sumar_cubo();	break;
		case 2:	sumar_fila();break;
		case 3: sumar_cara();	break;
		case 4: sumar_columna();   break;
		case 5: graficos();break;
		case 0: break; 
		default: printf("NO EXISTE:c \n"); 
	}
	
	}while(eleccion_suma != 0);
}


void sumar_cubo(){

	apCubo=cubo[0][0];
	
	int sumatotal=0;
	
	for(int i=0;i<sizeof(cubo)/sizeof(int);i++){
	
		sumatotal+=*apCubo;

		apCubo++;
	}
	printf("*********************************************************************************************\n");
	printf("\nLa suma de todos los elementos del cubo es = %d \n\n",sumatotal);

	system("pause");
	system("cls");
}

void sumar_fila(){
	fflush(stdin);
	int cara,fila;
	printf("*********************************************************************************************\n");
	printf("Dime una cara del cubo de la 1 al %d: ",TAM);
	scanf("%d",&cara);
	printf("\n");	
	if(cara>TAM || cara<1){
		printf("valor invalido, volviendo al menu \n"); 
		system("pause");
		system("cls");
		return;
	}
	printf("*********************************************************************************************\n");
	printf("seleccionaste cara %d, ahora escoge una fila de la 1 al %d: ",cara,TAM);
	scanf("%d",&fila);	
	printf("\n");
	if(fila>TAM || fila<1){
		printf("valor invalido, volviendo al menu\n"); 
		system("pause");
		system("cls");
		return;
	}
		
	apCubo=cubo[cara-1][fila-1];
	
	int sumafila=0;

		for(int i=0;i<TAM;i++){
	
			sumafila+=*apCubo;	
		
			apCubo++;
	}
	printf("*********************************************************************************************\n");
	printf("La suma de los elementos de  la fila %d cara %d = %d \n\n",fila,cara,sumafila);
	
	system("pause");
	system("cls");
}


void sumar_cara(){
	fflush(stdin);
	int cara=99;
	printf("*********************************************************************************************\n");
	printf("Dime una cara del cubo de la 1 al %d: ",TAM);
	scanf("%d",&cara);
	if(cara>TAM || cara<1){
		printf("\n valor invalido, volviendo al menu \n"); 
		system("pause");
		system("cls");
		return;
	}
	printf("\n");
	apCubo=cubo[cara-1][0];
	int sumacara=0;
		for(int i=0;i<(TAM*TAM);i++){
			sumacara+=*apCubo;	
			apCubo++;
	}
	printf("*********************************************************************************************\n");
	printf("La suma de los elementos de  la cara %d es = %d \n\n",cara,sumacara);
	system("pause");
	system("cls");
}


void sumar_columna(){
	fflush(stdin);
	int cara,columna;
	printf("*********************************************************************************************\n");
	printf("Dime una cara del cubo de la 1 al %d: ",TAM);
	scanf("%d",&cara);
		if(cara>TAM || cara<1){
			printf("valor invalido, volviendo al menu \n"); 
			system("pause");
			system("cls");
			return;
	}
	printf("\n");
	printf("*********************************************************************************************\n");
	printf("seleccionaste cara %d, ahora escoge una columna de la 1 al %d: ",cara,TAM);
	scanf("%d",&columna);
		if(columna>TAM || columna<1){
			printf("valor invalido, volviendo al menu \n"); 
			system("pause");
			system("cls");
			return;
	}
	printf("\n");	
	apCubo=cubo[cara-1][0];
	apCubo+=(columna-1);
	int sumacolumna=0;
		for(int i=0;i<TAM;i++){
			sumacolumna+=*apCubo;	
			apCubo+=TAM;
	}
		printf("*********************************************************************************************\n");
		printf("La suma de los elementos de  la columna 1 cara %d = %d \n\n",cara,sumacolumna);
		system("pause");
		system("cls");
	}

void imprimir_cubo(){
		printf("\n----------------------------------------------------------------------------------------------------\n");
		printf(" \n\tELEMENTOS QUE CONTIENE EL CUBO: \n\n");
		int cont=0;	
		apCubo=cubo[0][0];
		
		for(int i=0;i<sizeof(cubo)/sizeof(int);i++){
			
			cont++;
			printf("| %d |-",*apCubo);
			apCubo++;
	}
	printf("\n----------------------------------------------------------------------------------------------------\n");
	printf("\n El total de elementos es: %d \n\n",cont);
}


void graficos(){

	int term,Term,term1, Term1,cont1=1;
	int pantalla=DETECT,modo;
	initgraph(&pantalla,&modo,"\\TC\\BGI");

	
    setbkcolor(CYAN);
	settextstyle(0,0,2);
	setcolor(BLACK);
	outtextxy(100,29,"REPRESENTACION GRAFICA DEL CUBO");
	
		
for(int i=0;i<TAM;i++){
	int x1=120+(i*30),x2=220+(i*30);

	setlinestyle(2, 2, 2);
	setcolor(1+i);
	line(x1,80,x2,180);
	line(x2,180,x2,380);
	line(x2,380,x1,280);
	line(x1,280,x1,80);
}
	while(!kbhit());
	closegraph();
	
		system("cls");
}
