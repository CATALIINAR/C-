#include <iostream>
using namespace std;
int op,i;
int codigo, cli = 0;

struct cliente {
	int codcli;
	char nomcli[20];
	char apecli[20];
	int cantidadfotos;
	float valorunit;
    
} clientes[]={
	{1025, "Carlos", "Fernandez", 20, 12.500},
    {1020, "Oscar", "Hidalgo", 12, 15.000},
    {1130, "Juan", "Peralta", 10, 17.500},
    {1015, "Diana", "Montoya", 15, 25.000}

};

void mostrarClientes() {
    cout << "Clientes:" << endl;
    for (int i = 0; i <=3; i++) {

        cout<<"Codigo: "<<clientes[i].codcli<<endl;
        cout<<"Nombre: "<<clientes[i].nomcli<<endl;
        cout<<"Apellido: "<<clientes[i].apecli<<endl;
        cout<<"Cantidad de Fotos: "<<clientes[i].cantidadfotos<<endl;
        cout<<"Valor por foto: $"<<clientes[i].valorunit<<endl;
        cout<<"---------------------------------------------------" << endl;
    }
}

void consultaCod() {
    
    cout << "Ingresa el codigo: ";
    cin >> codigo;
    
    for (int i = 0; i <=3; i++) {
        if (clientes[i].codcli == codigo) {
            cli = 1;
            
        cout<<"Codigo: "<<clientes[i].codcli<<endl;
        cout<<"Nombre: "<<clientes[i].nomcli<<endl;
        cout<<"Apellido: "<<clientes[i].apecli<<endl;
        cout<<"Cantidad de Fotos: "<<clientes[i].cantidadfotos<<endl;
        cout<<"Valor por foto: $"<<clientes[i].valorunit<<endl;
        cout<<"---------------------------------------------------" << endl;
            
        }
    }
    if (cli == 0) {
        cout << "No hay clientes con ese codigo" << endl;
    }
}

void consultaValorT() {
    
    cout << "Ingresa el codigo: ";
    cin >> codigo;
   
    for (int i = 0; i <=3; i++) {
    	double valorTotal = clientes[i].cantidadfotos * clientes[i].valorunit;
        if (clientes[i].codcli == codigo) {
            cli = 1;
            
        cout<<"Codigo: "<<clientes[i].codcli<<endl;
        cout<<"Nombre: "<<clientes[i].nomcli<<endl;
        cout<<"Apellido: "<<clientes[i].apecli<<endl;
        cout<<"Cantidad de Fotos: "<<clientes[i].cantidadfotos<<endl;
        cout<<"Valor por foto: $"<<clientes[i].valorunit<<endl;
        cout<<"Valor total : $ "<<valorTotal<<endl;
        cout<<"---------------------------------------------------" << endl;
        }
    }
    if (cli == 0) {
        cout << "No hay clientes con ese codigo" << endl;
    }
}


void eliminarcli() {
    cout << "Ingresa el codigo de cliente a eliminar: ";
    cin >> codigo;
   
    for (int i = 0; i <=3; i++) {
    	if (clientes[i].codcli == codigo) {
    	cli = 1;
    	clientes[i] =clientes[i+1];
    	cout << "Cliente Eliminado "<<endl;
		}
    }
    	if (cli == 0) {
        cout << "No hay clientes con ese codigo" << endl;
}
}

 int main(){
	
	bool seguir=true;
	
	do{
		cout << "Menu Clientes" << endl;
        cout << "1. Mostrar Clientes" << endl;
        cout << "2. Consultar Clientes por codigo" << endl;
        cout << "3. Consulta valor total" << endl;
        cout << "4. Eliminar Clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;
        switch (op) {
        	 case 1:
            	system("cls");
                mostrarClientes();
            break;
            case 2:
            	system("cls");
                consultaCod();
            break;
            case 3:
            	system("cls");
                consultaValorT();
            break;
            case 4:
            	system("cls");
                eliminarcli();
            break;
            case 5:
            	system("cls");
             cout << "bye :) "<<endl;
             break;
             
			default:
                cout <<"Opcion no valida, Intente de nuevo"<<endl;
	}	
	}while (op != 5);
	
}
