#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string mp [6][6]={"v","v","f","v","v","v",
				  "f","v","v","v","v","v",
				  "v","v","v","v","v","f",
				  "v","v","v","v","v","v",
				  "v","v","f","v","f","v",
				  "v","v","f","v","f","v"};

				  
string me [6][6]={"X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X",
				  "X","X","X","X","X","X"};
				
int f,c,opcion,contrase= 000, score=50, fantasmas =3;

void mostrarMa(int opcion){
	if(opcion ==1){
		for(int f=0;f<=5;f++){
			for(int c=0;c<=5; c++){
				cout<<mp[f][c]<<"\t";
			
			}cout<<endl<<endl;
		}
	}else if(opcion==2){
		for(int f=0;f<=5;f++){
			for(int c=0;c<=5; c++){
				cout<<me[f][c]<<"\t";
			
			}cout<<endl<<endl;
		}
	}
}


bool validarIntentos(){
	if(fantasmas<=0){
		cout<<" Perdiste el juego. Hallaste 3 fantasmas "<<endl;
		return false;
	}
	return true;
}

bool posicionSeleccionada[6][6]={false};

void buscarFantasma(){
	cout<<" Encuentra el fantasma "<<endl;
	cout<<" Ingresa el numero de la fila:  "<<endl;
	cin>>f;
	cout<<" Ingresa el numero de la columna:  "<<endl;
	cin>>c;
	
	if(posicionSeleccionada[f][c]){
		cout<<" Esta posicion ya fue seleccionada. Has perdido 5 puntos"<<endl;
		score -=5;
	}
	
	posicionSeleccionada[f][c]=true;
	
	if(mp[f][c]=="f"){
		cout<<" Perdiste 5 puntos, hay un Fantasma en esa posicion"<<endl;
		me[f][c]="F";
		score -=5;
		fantasmas--;
		
	}else if(mp[f][c]=="v") {
		cout<<" Ganaste 3 puntos, no hay un Fantasma en esa posicion "<<endl;
		me[f][c]="V";
		score +=3;
	
	}
	
	mostrarMa(2);

	if(!validarIntentos()){
		cout<<" Puntaje final: "<<score<<endl;
		exit(0);
	}else if(score>=60){
		cout<<" Has ganado el juego !!!     score:"<<score<<endl;
		
		exit(0);
	}
	else{
		cout<<" Puntaje Actual: "<<score<<endl;
		cout<<"Cantidad de fantasmas : "<<fantasmas<<endl<<endl;
	}
}


void contrasena() {
    int ContrasenaIngresada;
    cout<< "Ingrese la contraseña: ";
    cin>>ContrasenaIngresada;

    if(ContrasenaIngresada == contrase){
    	cout << "La contraseña es correcta "<<endl;
        mostrarMa(1);
    }else{
        cout<< "La contraseña es incorrecta "<<endl;
    }
}

int inicio(){
	bool seguir=true;
	do{
	cout<<".........................."<<endl;
	cout<<" "<<endl;
	cout<<"1. Continuar jugando"<<endl;
	cout<<"2. Salir"<<endl;
	cout<<"ingresa la opcion que desee"<<endl;
	cin>>opcion;
	switch(opcion){
	    case 1:	
			system("cls");	
			mostrarMa(2);	
			buscarFantasma();
			break;
		
		case 2: 
			system("cls");	
			cout << "bye :) "<<endl;
            break;
             
			default:
            cout <<"Opcion no valida, Intente de nuevo"<<endl; 
		}
	}while (opcion != 2);
	
}	


int main(){
	int opcion;
	bool continuar =true;
    do {
    	cout << " Menu Juego Fantasma " << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Ver matriz parametrizada" << endl;
        cout << "3. salir "<< endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
            	system("cls");
                inicio();
                
            break;
            
            case 2:
            	system("cls");
            	contrasena();
            	
            break;
            
  			case 3:
            	system("cls");
            	continuar= false;
				cout<<" Programa Finalizado";
			break;
			;
            default:
                cout << "Opcion invalida.seleccione una opcion del 1 al 3 " << endl;
        }
    }while(continuar == true);
}
