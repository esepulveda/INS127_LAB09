//Estructura de datos <Esteban Sepulveda>

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