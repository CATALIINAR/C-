//JHONATAN DAVID OROZC VIOLA
// CATALINA RICO SANCHES 
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
using namespace std;
int a = 0, b = 0, Edad = 0; 


struct elemento {
    int numero;
    elemento* sgte;
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


void ingresard() {
    srand(time(NULL));
    cout << "-----|5 Numeros aleatorios del 1 al 50|------" << endl;
    for (b=1;b<=5;b++) {
        a=1+rand() % 50;
        cout<<a<< "\t";
        insertar_lista(a);
    }
}



struct persona {
    int edad;
    persona* sgte;
};


persona *pInicial, *pAuxiliar, *pFinal ;

int validarEdad() {
    int edad;
    cout << "Ingrese la edad: ";
    cin >> edad;
    return edad;
}


void ingresarEdad() {
    if (pInicial == NULL) {
        system("cls");
        Edad = validarEdad();
        pInicial = new persona();
        pInicial->edad = Edad;
        pFinal = pInicial;
        system("pause");
    } else {
        system("cls");
        Edad = 100;
        pAuxiliar = new persona();
        pFinal->sgte = pAuxiliar;
        pAuxiliar->edad = Edad;
        pFinal = pAuxiliar;
        system("pause");
    }
    pFinal->sgte = NULL;
}

int rango1 = 0, rango2 = 0, rango3 = 0, rango4 = 0, rango5 = 0, rango6 = 0, rTotal = 0;

void recaudoEdades() {
    pAuxiliar = pInicial;
    while (pAuxiliar != NULL) {
        if (pAuxiliar->edad >= 5 && pAuxiliar->edad <= 9) {
            rango1 += 6000;
        } else if (pAuxiliar->edad >= 10 && pAuxiliar->edad <= 12) {
            rango2 += 7500;
        } else if (pAuxiliar->edad >= 13 && pAuxiliar->edad <= 16) {
            rango3 += 8500;
        } else if (pAuxiliar->edad >= 17 && pAuxiliar->edad <= 30) {
            rango4 += 9000;
        } else if (pAuxiliar->edad >= 31 && pAuxiliar->edad <= 55) {
            rango5 += 12500;
        } else if (pAuxiliar->edad > 55 && pAuxiliar->edad <= 100) {
            rango6 += 5000;
        }
        pAuxiliar = pAuxiliar->sgte;
    }
}


double total;

double calculo() {
    return rango1 + rango2 + rango3 + rango4 + rango5 + rango6;
}

void recaudos() {
    system("cls");
    cout << "---|TOTAL|---" << endl;
    cout << "TOTAL: " << calculo() << endl;
}


int validar() {
    bool flag = true;
    int opcion;
    while (flag) {
        cout << "ELEGIR";
        cin >> opcion;
        if (opcion >= 1 && opcion <= 4) {
            flag = false;
            break;
        } else {
            cout << "OPCION INVALIDA" << endl;
        }
    }
    return opcion;
}



void mostrarMenu() {
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Numeros Aleatorios " << endl;
    cout << "2.	Ingresar Edad" << endl;
    cout << "3. Mostrar Recaudos" << endl;
    cout << "4. Salir" << endl;
}


int main() 
{
    setlocale(LC_ALL, "");

    int opcion;

    do {
        system("cls");
        mostrarMenu();
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
        	case 1:
                ingresard();
                break;
            case 2:
                ingresarEdad();
                break;
            case 3:
                recaudoEdades();
                system("cls");
				cout<<"----|RECAUDO|----"<<endl;
				cout<<"ENTRE 6 A 9 AÑOS"<<rango1<<endl;	
				cout<<" ENTRE 10 A 12 AÑOS"<<rango2<<endl;
				cout<<" ENTRE 13 A 16 AÑOS"<<rango3<<endl;
				cout<<" ENTRE 17 A 30 AÑOS"<<rango4<<endl;	
				cout<<" ENTRE 31 A 55 AÑOS"<<rango5<<endl;
				cout<<" MAYORES DE 55 AÑOS"<<rango6<<endl;
				recaudos();
				system("pause");
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }

        system("pause");
    } while (opcion != 4);

    
}
