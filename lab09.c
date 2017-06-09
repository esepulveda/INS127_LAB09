//Estructura de datos <Esteban Sepulveda>
#include "lab09.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int conjA=llenarConjuntoA();
	int conjB=llenarConjuntoB();
	printf("\nEl conjunto A que contiene los elementos {4,5,2,8,7} se representa en binario: ");
	imprimirBin(conjA);
	printf("\nEl conjunto B que contiene los elementos {0,1,3,4,5} se representa en binario: ");
	imprimirBin(conjB);
	printf("\nConjunto A and B: ");
	int AandB=conjA & conjB;
	imprimirBin(AandB);
	int AorB=conjA | conjB;
	printf("\nConjunto A or B: ");
	imprimirBin(AorB);
	printf("\nConjunto (A - B)U(B + A): ");
	int conjC=((conjA&(~conjB))|(conjA&conjB));
	imprimirBin(conjC);
	printf("\n");
	conjA=insertarBin(conjA,1);
	conjA=insertarBin(conjA,2);
	printf("\nEl conjunto A con los numeros ingresados es: ");
	imprimirBin(conjA);
	printf("\n");
	conjB=insertarBin(conjB,4);
	printf("\n");
	conjB=insertarBin(conjB,5);
	printf("\nEl conjunto B con los numeros ingresados es: ");
	imprimirBin(conjB);
	int Cinterseccion=conjA&conjB;
	printf("\nLa interseccion de los conjuntos A y B es: ");
	imprimirBin(Cinterseccion);
	int Cunion=conjA|conjB;
	printf("\nLa union de los conjuntos A y B es: ");
	imprimirBin(Cunion);
	int arregloA[]={4,5,2,8,7};
	int arregloB[]={0,1,3,4,5};
	arregloAnd(arregloA,arregloB);
	int *arregloAN=(int*)malloc(8*sizeof(int));
	int *arregloBN=(int*)malloc(8*sizeof(int));
	arregloAN=insertarNum(arregloA,1,2);
	arregloBN=insertarNum(arregloB,5,4);
	printf("\nAhora el arreglo A contiene los siguientes elementos: ");
	imprimirArray(arregloAN,6);
	printf("\nAhora el arreglo B contiene los siguientes elementos: ");
	imprimirArray(arregloBN,5);
	interseccionArray(arregloAN,arregloBN);
	return 0;
}