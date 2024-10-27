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
				
int f,c,opcion,contrase= 12345, score=50, fantasmas =3;

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

void actualizarScore(string letra){
	if(letra=="f"){
		score-=5;
	}else if (letra=="v"){
		score +=3;
	}
	if(score>=60){
		cout<<" Ganaste el juego "<<endl;
		cout<<" Puntaje final: "<<score<<endl;
		exit(0);
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
		actualizarScore("F");
		return;
	}
	
	posicionSeleccionada[f][c]=true;
	
	if(mp[f][c]=="f"){
		cout<<" Perdiste 5 puntos, hay un Fantasma en esa posicion"<<endl;
		me[f][c]="F";
		actualizarScore("f");
		fantasmas--;
		
	}else if(mp[f][c]=="v") {
		cout<<" Ganaste 3 puntos, no hay un Fantasma en esa posicion "<<endl;
		me[f][c]="V";
		actualizarScore("v");
	}
	
	mostrarMa(2);
	
	if(!validarIntentos()){
		cout<<" Puntaje final: "<<score<<endl;
		exit(0);
	}else {
		cout<<"Puntaje Actual: "<<score<<endl<<endl;
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
                buscarFantasma();
                
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
