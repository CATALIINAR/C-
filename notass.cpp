#include <iostream>
using namespace std;

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
	int valor;
	int contador=1;
	for(int j=1;j<=5;j++)
	{
		cout<<"Ingrese la nota del estudiante "<<contador<<endl;
		cin>>valor;
		insertar_lista(valor);
		contador++;
	}
}



void mostrar()
{
	pauxiliar=pinicial;
	int contador=1;
	cout<<"Notas Estudiantes :"<<endl;
	while(pauxiliar!=NULL)
	{
	
		if(pauxiliar->numero>=3)
		{
			cout<<" Nota Estudiante #"<<contador<<" Paso con --> "<<pauxiliar->numero<<endl;
		}
		else if(pauxiliar->numero<=3)
		{
			cout<<" Nota Estudiante #"<<contador<<" Perdio con --> "<<pauxiliar->numero<<endl;
		}
		pauxiliar=pauxiliar->sgte;
		contador++;	
	}
}

void buscar(int valor)
{
	pauxiliar=pinicial;
	while(pauxiliar!=NULL)
	{
		if(pauxiliar->numero==valor)
		{
			cout<<"Elemento  "<<valor<<" Encontrado en la lista"<<endl;
			sw1=1;
		}
		pauxiliar=pauxiliar->sgte;
	}
}

void actualizar(int valor, int valora)
{
	pauxiliar=pinicial;
	while(pauxiliar!=NULL)
	{
		if(pauxiliar->numero==valor)
		{
			pauxiliar->numero=valora;
			cout<<"Valor "<<valor<<" encontrado en la lista y actualizado"<<endl;
			sw1=1;
		}
		pauxiliar=pauxiliar->sgte;
	}
}

void calculProme()
{
	int sum=0,contador=0,promedio;
	pauxiliar=pinicial;
	while(pauxiliar!=NULL)
	{
		sum+=pauxiliar->numero;
		pauxiliar=pauxiliar->sgte;
		contador++;
	}
	promedio=sum/contador;
	cout<<"El promedio de la clase es: "<<promedio<<endl;
}

void menu()
{
	int op;
	int valor;
	int valora;
	bool mseguir=true;
	do
	{
		cout<<"-----Menu Lista-----"<<endl;
		cout<<" 1. Ingresar Notas"<<endl;
		cout<<" 2. Mostrar Notas y clasificacion"<<endl;
		cout<<" 3. Buscar Estudiante"<<endl;
		cout<<" 4. Actualizar Notas"<<endl;
		cout<<" 5. Promedio Clase"<<endl;
		cout<<" 6. Salir"<<endl;
		cout<<" Seleccione la opcion"<<endl;
		cin>>op;
		switch(op){
			case 1:
				system("cls");
				ingresard();
				break;
			
			case 2:
				system("cls");
				mostrar();
				break;
				
			case 3:
				system("cls");
				cout<<"Ingrese el valor a buscar"<<endl;
				cin>>valor;
				buscar(valor);
				if(sw1==0)
				{
					cout<<"El elemento no fue encontardo en la lista"<<endl;
				}
				break;
			case 4:
				system("cls");
				cout<<"Ingrese el valor a actualizar"<<endl;
				cin>>valor;
				cout<<"Ingrese el nuevo elemento"<<endl;
				cin>>valora;
				actualizar(valor,valora);
				if(sw1==0)
				{
					cout<<"El elemento no fue encontardo en la lista"<<endl;
				}
				break;
			
			case 5:
				system("cls");
				calculProme();
				break;
				
			case 6:
				system("cls");
				mseguir=false;
				break;
		}
		
	}while(mseguir==true);

}

int main()
{
	menu();
}
