#include <iostream>
#include <cmath> // Incluimos cmath para usar abs
#include <ctime>
using namespace std;

int pasajerosDia = 0;
int segReinicioAsc = 30;

struct Elevator {
    int piso_actual;
    int capacidad;
    bool enuso;
};

Elevator elevator1 = {1, 0, false};
Elevator elevator2 = {30, 0, false};


void pisoacen(){
	cout<<"piso actial del ascensor 1:  "<<elevator1.piso_actual<<endl;
	cout<<"piso actual del ascensor 2:  "<<elevator2.piso_actual<<endl;
}


void verificarTiempo(time_t tiempoInicio, time_t tiempoActual){
	int segundosTranscurridos = static_cast<int>(tiempoActual - tiempoInicio); 
	if(segundosTranscurridos >= segReinicioAsc){
		elevator1.piso_actual = 1;
		elevator2.piso_actual = 30;

	}
}

int validarCapacidad (int capacidad){
	int capacidadTotal = 6 - capacidad;
	return capacidadTotal;
}

void salir(int caso){
	bool flag = true;
	int persal;
	
	if(caso == 1){
		while(flag){
			cout<<"Cuantas personas salen del ascensor: ";
			cin>>persal;
			if(persal > 0 && persal <= elevator1.capacidad){
				elevator1.capacidad = elevator1.capacidad - persal;
	
				flag=false;
				break;
			}else{
				cout<<"No hay tantos personas para salir."<<endl;
			}
	 	}	
	}
	else if(caso == 2){
		while(flag){
			cout<<"Cuantas personas salen del ascensor: ";
			cin>>persal;
			if(persal > 0 && persal <= elevator2.capacidad){
				elevator2.capacidad = elevator2.capacidad - persal;
			
				break;
			}else{
				cout<<"No hay tantos personas para salir."<<endl;
			}
		}	
	}
}

void ingreso(int caso){
	bool flag = true;
	int abordo;
	
	if(caso == 1){
		while(flag){
			cout<<"Cuantas personas ingresan al ascensor: ";
			cin>>abordo;
			if(abordo > 0 && abordo <= validarCapacidad(elevator1.capacidad)){
				elevator1.capacidad = elevator1.capacidad + abordo;
				pasajerosDia+=abordo;
				flag=false;
				break;
			}else{
				cout<<"No hay capacidad para tantas personas"<<endl;
			}
	 	}	
	}
	else if(caso == 2){
		while(flag){
			cout<<"Cuantas personas ingresan al ascensor: ";
			cin>>abordo;
			if(abordo > 0 && abordo <= validarCapacidad(elevator2.capacidad)){
				elevator2.capacidad = elevator2.capacidad + abordo;
				pasajerosDia+=abordo;
				break;
			}else{
				cout<<"No hay capacidad para tantas personas"<<endl;
			}
		}	
	}
}

void solicitarasc(int piso) {
    if (abs(elevator1.piso_actual - piso) <= abs(elevator2.piso_actual - piso)) {
        elevator1.enuso = true;
        elevator1.piso_actual=piso;
        cout << "El ascensor 1 se dirige al piso " << piso << endl;
        ingreso(1);
        cout<<"| Cantidad pasajeros en el ascensor 1: "<<elevator1.capacidad<<endl;
        salir(1);
        cout<<"| Cantidad pasajeros en el ascensor 1: "<<elevator1.capacidad<<endl;
    } else {
        elevator2.enuso = true;
        elevator2.piso_actual=piso;
        cout << "El ascensor 2 se dirige al piso " << piso << endl;
        ingreso(2);
        cout<<"| Cantidad pasajeros en el ascensor 2: "<<elevator2.capacidad<<endl;
        salir(2);
        cout<<"| Cantidad pasajeros en el ascensor 2: "<<elevator2.capacidad<<endl;
    }
}

int main() {
    int op, piso;
    time_t tiempoInicio = time(NULL);

    do {
    	time_t tiempoActual = time(NULL);
        cout<<"=== Menu ===" <<endl;
        cout<<"1. Solicitar ascensor" <<endl;
        cout<<"2. Total de pasajeros que usaron el ascensor"<<endl;
        cout<<"3. Piso actual de los acensores "<<endl;
        cout<<"4. Salir" <<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>op;

        switch(op){
            case 1:
            	system("cls");
            	verificarTiempo(tiempoInicio, tiempoActual);
                cout<< "Ingrese el piso al que desea ir: ";
                cin>>piso;
                if(piso >= 1 && piso <= 30) {
                    solicitarasc(piso);
                }else {
                    cout<<"Piso invalido. Ingrese un piso entre 1 y 30."<< endl;
                }
                tiempoInicio = time(NULL);
                break;
            case 2:
            	system("cls");
            	cout<<"| Cantidad pasajeros en total (Dia): "<<pasajerosDia<<endl;
                break;
            case 3:
				system("cls");
				verificarTiempo(tiempoInicio, tiempoActual);
				pisoacen();
				
				break;	    
            case 4:
				cout << "bye" << endl;
                break; 
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }

    } while (op != 4);
}


