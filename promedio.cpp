#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int a=0,b=0;
int sw1=0;
//Definir struct del nodo
struct elemento{
	int numero;
	elemento *sgte;
};

struct elemento *pinicial, *pauxiliar, *pfinal;

void insertar_lista(int valor)
{
	if(pinicial==NULL)
	{
		pinicial= new elemento();
		pinicial->numero=valor;
		pfinal=pinicial;
	}
	else
	{
		pauxiliar=new elemento();
		pfinal->sgte=pauxiliar;
		pauxiliar->numero=valor;
		pfinal=pauxiliar;
	}
	pfinal->sgte=NULL;
}


void ingresard()
{
	{
	
	srand(time(NULL));
	cout<<"-----|5 Numeros aleatorios del 1 al 50|------"<<endl;
	for (b=1;b<=5;b++)
	{
		a=1+rand()%50;
		cout<<a<<"\t"<<endl;
		insertar_lista(a);	
	}
	
	
	}
}


void calculProme()
{
	int sum=1,promedio;
	pauxiliar=pinicial;
	while(pauxiliar!=NULL)
	{
		sum+=pauxiliar->numero;
		pauxiliar=pauxiliar->sgte;

	}
	promedio=sum/5;
	cout<<"El promedio es: "<<promedio<<endl;
}


int main()
{
	ingresard();
	calculProme();
	
}
