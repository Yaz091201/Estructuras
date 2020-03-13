//Crea una lista que almacene n numeros reales y calcular:
//A)Suma. B)Promedio. C)Multuplicacion entre mayor y menor numero. D)Diferencia entre suma y promedio.

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Goto.h"

using namespace std;

struct nodo{
	int dato;
	float suma,multiplicacion;
	nodo*siguiente;
	nodo*Tlista;
};

void insertar_lista(nodo*&, int);
float multi_mayor_menor(nodo *);
float suma_lista(nodo *);

int main(){
nodo*lista=NULL;
int dato;
int opc;
char res;
float multiplicacion, mayor, menor;
do{
	system("cls");
	gotoxy(45,1);cout<<"*-*Lista*-*\n\n";
	gotoxy(30,3);cout<<"1)Insertar datos.\n";
	gotoxy(30,5);cout<<"2)Suma y promedio.\n";
    gotoxy(30,7);cout<<"3)Multuplicacion entre mayor y menor numero.\n";
    gotoxy(30,9);cout<<"4)Diferencia entre suma y promedio.\n";
    gotoxy(30,11);cout<<"5)Salir.\n";
    
	gotoxy(70,14);cout<<"*Seleccione una opcion: ";
	gotoxy(80,15);cin>>opc;

	switch(opc){
		case 1:
			system("cls");
			do{
			gotoxy(10,2);cout<<"*-*Insertar datos.*-*";
	         gotoxy(30,4);cout<<"Teclee un numero:";
	         gotoxy(35,5);cin>>dato;
	         gotoxy(30,6);insertar_lista(lista,dato);
	         gotoxy(45,8);cout<<endl<<"Desea insertar otro elemento? s/n: ";
	         gotoxy(50,9);cin>>res;
            }while(res!='n');
	break;
		case 2:
			system("cls");
			gotoxy(45,2);
			cout<<"***********************************";
			gotoxy(56,3);
			cout<<"Sumar datos";
			gotoxy(45,5);
			cout<<"El resultado de la suma es-> "<<suma_lista(lista);
			gotoxy(45,7);
			cout<<"***********************************";
			getch();
		break;
		case 3:
			system("cls");
			gotoxy(45,2);
			cout<<"***********************************";
			gotoxy(47,3);
			cout<<"Multiplicar Dato mayor y menor";
			gotoxy(45,5);
			cout<<"La multiplicacion es-> "<<multi_mayor_menor(lista);
			gotoxy(45,7);
			cout<<"***********************************";
			getch();
		break;	
	}
	gotoxy(50,10);cout<<endl<<"Desea regresar al menu? s/n: "<<endl;
	        gotoxy(55,9);cin>>res;
	        }while(res!='n');

 getch();
}

void insertar_lista(nodo*&lista, int n) {
	nodo*nvo_nodo=new nodo();
	nvo_nodo->dato=n;
	nodo*aux1=lista;
	nodo*aux2;
while ((aux1 !=NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
		if (lista==aux1){
			lista=nvo_nodo;
		}
		else{
			aux2->siguiente=nvo_nodo;
		}
		nvo_nodo->siguiente=aux1;
		cout<<"\tElemento "<<n<<" insertado en la lista correctamente."<<endl;
}
float multi_mayor_menor(nodo *lista ){
	float multiplicacion;
	float mayor=0;
	float menor=999999;
	while(lista != NULL){
		if((lista->dato) > mayor){
			
			mayor = lista->dato;	
		}
		if((lista->dato) < menor){
			menor = lista->dato;
		}
		lista = lista->siguiente;
	}
	multiplicacion=mayor*menor;
	return multiplicacion;
}

float suma_lista(nodo *lista){
	float suma;
	while(lista != NULL){
		suma =suma+lista->dato;
		lista = lista->siguiente;
	}
	return suma;
}
