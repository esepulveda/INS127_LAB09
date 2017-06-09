

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int insertarBin(int conj, int var){
	printf ("Ingresamos el numero:  %d",var);
	printf ("\n");
	if (((conj>>var)%2)==0){
		conj+=1<<var;
		return conj;
	}
	else{
		printf ("Ya existe el numero %d en el conjunto",var);
		return conj;
	}
}
void imprimirBin(int conj){
	int cont;
	for (cont= pow(2,8);cont >0;cont >>=1){
		if (cont&conj){
			printf ("1");
		}else{
			printf ("0");
		}
	}
}
int eliminarBin(int conj,int num){
	printf ("\nEliminamos el numero:  %d",num);
	printf ("\n");
	if (((conj>>num)%2)==1){
		conj-=1<<num;
		printf ("\nEliminado");
		return conj;
	}
	else{
		printf ("\nNo existe");
		return conj;
	}
}
int llenarConjuntoA(){
	int newConj=(1<<4)+(1<<5)+(1<<2)+(1<<8)+(1<<7);
	return newConj;
}
int llenarConjuntoB(){
	int newConj=(1<<0)+(1<<1)+(1<<3)+(1<<4)+(1<<5);
	return newConj;
}
void arregloAnd(int arregloA[],int arregloB[]){
	int i,j;
	int *arregloAandB=(int*)malloc(10*sizeof(int));
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			if (arregloA[i]==arregloB[j]){
				arregloAandB[i]=arregloA[i];
			}
		}
	}
	printf("\nLa union de los arreglos A y B es: ");
	for (i=0;i<2;i++){
		printf("%d\t",arregloAandB[i]);
	}
}
int *insertarNum(int arreglo[],int num,int numB){
	int *newArreglo=(int*)malloc(8*sizeof(int));
	int i,swc=0,swcB=0;
	for (i=0;i<5;i++){
		newArreglo[i]=arreglo[i];
		if (num==arreglo[i]){
			swc=1;
		}
		if (numB==arreglo[i]){
			swcB=1;
		}
	}
	if (swc==0){
		printf("\nElemento %d agregado al arreglo",num);
		newArreglo[5]=num;
	}else{
		printf("\nEl elemento %d ya existe en el arreglo",num);
	}
	if (swcB==0){
		printf("\nElemento %d agregado al arreglo",numB);
		newArreglo[6]=numB;
	}else{
		printf("\nEl elemento %d ya existe en el arreglo",numB);
	}
	return newArreglo;
}
void imprimirArray(int *array,int largo){
	int i;
	for (i=0;i<largo;i++){
		printf("\t%d",array[i]);
	}
}
void interseccionArray(int *arrayA,int *arrayB){
	int i,j,x=0;
	int *arrayInter=(int*)malloc(10*sizeof(int));
	for (i=0;i<6;i++){
		for (j=0;j<5;j++){
			if (arrayA[i]==arrayB[j]){
				arrayInter[x]=arrayA[i];
				x++;
			}
		}
	}
	printf("\nLa interseccion de los arreglos A y B es: ");
	for (i=0;i<3;i++){
		printf("%d\t",arrayInter[i]);
	}
}