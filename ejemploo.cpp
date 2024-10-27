#include <iostream>
using namespace std;

//Búsqueda Binaria

int main(){
	int numeros[]= {1,2,3,4,5};
	int inf, sup, mitad, dato;
	char band = false;
	
	dato=4;
	
	inf=0;
	sup=5;
	
	while(inf<= sup){
		mitad= (inf+sup)/2;
		
		if(numeros[mitad]==dato){
			band = true;
			break;
		}
		if(numeros[mitad]> dato){
			sup= mitad;
			mitad= (inf+sup)/2;
		}
		if(numeros[mitad]< dato){
			inf= mitad;
			mitad= (inf+sup)/2;
		}
	}
	if(band == true){
		cout<<"el numero a sido encontrado en la posicion: "<<mitad<<endl;
	}
	else{
		cout<<"el numero No a sido encontrado"<<endl;
	}
}
