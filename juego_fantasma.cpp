#include <iostream>
using namespace std;
string m1 [6][6]={"v","v","f","v","v","v",
				  "f","v","v","v","v","v",
				  "v","v","v","v","v","f",
				  "v","v","v","v","v","v",
				  "v","v","f","v","f","v"};

				  
string m2 [6][6]={"X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X"};
int f,c,op,x=50, con, puntos;
int contr=000;

void mostrarm2(){
	for (int f=0; f<=5;f++){
		for (int c=0;c<=5;c++){
		cout<<m2[f][c]<<"\t";
		}
		cout<<endl<<endl;
	}
		
}

void mostrarm(){
	for (int f=0; f<=5;f++){
		for (int c=0;c<=5;c++){
		cout<<m1[f][c]<<"\t";
		}
		cout<<endl<<endl;
	}
		
}
void iniciojuego(){
	cout<<" Encuentra el fantasma"<<endl;
	cout<<"Puntos del juego: "<<x<<endl;
	cout<<"ingrese el numero de la fila"<<endl;
	cin>>f;
	cout<<"ingrese el numero de la columna"<<endl;
	cin>>c;
	
	if(m1[f][c]=="f"){
		cout<<"perdiste 5 puntos, hay un fantasma en esa posicion "<<endl;
		m2[f][c]="f";
		puntos=x-5;
		
	}else {
		cout<<"Ganaste 3 puntos, no hay fantasma en esa posicion "<<endl;
		m2[f][c]="v";
		puntos=x+3;
	}
	mostrarm2();
	cout<<"Puntos del juego: "<<puntos<<endl;
}

int contrasena(){
	
	if (con==contr){
	mostrarm();
	}
	else if(con!=contr){
	cout<<"contrasena incorrecta"<<endl;
	}
	
}


int main(){
	
	bool seguir=true;
	
	do{
	cout<<"------| MENU fantasmal |------"<<endl;
	cout<<"1. Iniciar juego "<<endl;
	cout<<"2. Mostrar  Matriz"<<endl;
	cout<<"3. Salir "<<endl;	
	cout<<"ingresa la opcion que desee"<<endl;
	cin>>op;
		
		switch(op)
		{
			
			case 1:
				system("cls");	
				cout<<"iniciando el juego"<<endl;
				mostrarm2();
				iniciojuego();
				
				break;
			case 2:
				system("cls");
				cout<<"Ingrese la contraseña para visualizar la mariz"<<endl;
				cin>>con;
				contrasena();
				break;
			case 3:
			cout << "bye :) "<<endl;
            break;
             
			default:
                cout <<"Opcion no valida, Intente de nuevo"<<endl; 	
			}	
	}while (op != 3);
	
}
