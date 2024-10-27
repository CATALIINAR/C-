#include <iostream>
using namespace std;
int costo1=0, costo2=0, costo3=0, costo4=0, costo5=0, costo6=0, costo7=0, i;
	int c[10];
// Definir una estructura para representar a una persona en la fila
struct elemento {
    int edad;
    elemento *sgte;
};

struct elemento *pinicial,*pauxiliar, *pfinal;


void insertar_lista(int valor)
{
	if(pinicial==NULL)
	{
		pinicial = new elemento();
		pinicial->edad=valor;
		pfinal=pinicial;  
	}
	else
	{
		pauxiliar=new elemento();
		pfinal->sgte=pauxiliar;
		pauxiliar->edad=valor;
		pfinal=pauxiliar;
	}
	pfinal->sgte=NULL;
}

void ingresard()
{
	int valor;
	for(int j=1;j<=3;j++)
	{
		cout<<"Ingrese la edad "<<endl;
		cin>>valor;
		insertar_lista(valor);
		
	}
}

void recaudo(){

	int edad;
	
	pauxiliar=pinicial;
	
	while(pauxiliar!=NULL)
	{
		if (pauxiliar->edad >= 0 && pauxiliar->edad <= 3) {
	        costo1=0;
	        c[0]+costo1;
	        
	    }else if (pauxiliar->edad <= 4 && pauxiliar->edad <= 8) {
	        costo2=6000;
	        c[1]+costo2;
	        
	    }else if (pauxiliar->edad <= 9 && pauxiliar->edad <= 11) {
	        costo2=7500;
	        c[2];
			    
	    }else if (pauxiliar->edad <= 12 && pauxiliar->edad <= 15) {
	        costo3 = 8500;
	        c[3];
	        
	    }else if (pauxiliar->edad <= 16 && pauxiliar->edad <= 29) {
	        costo4 = 9000;
	        c[4];
	        
	    }else if (pauxiliar->edad <= 30 && pauxiliar->edad <= 54) {
	        costo5 = 12500;
	        c[5];
	            
	    }else {
	        costo7 = 5000;
	        c[6];
	    }
	    pauxiliar = pauxiliar->sgte;
	}
}

void valorrecaud(){
	recaudo();
	cout << "Recaudo por edades:" << endl;
    cout << "0-4   $" <<c[i]<< endl;
    cout << "5-9   $" <<c[i]<< endl;
    cout << "10-12 $" <<costo3<< endl;
    cout << "13-16 $" <<costo4<< endl;
    cout << "17-30 $" <<costo5<< endl;
    cout << "31-55 $" <<costo6<< endl;
    cout << "55+   $" <<costo7<< endl;
}


int main(){
	ingresard();
	valorrecaud();

}
