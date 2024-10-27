#include <iostream>
#include <string>

using namespace std;

struct datos {
    int codigo;
    char nombre[20];
    char apellido[20];
    int CantidadF;
    double ValorU;
    
} clientes[]={
	{1025, "Carlos", "Fernandez", 20, 12.500},
    {1020, "Oscar", "Hidalgo", 12, 15.000},
    {1130, "Juan", "Peralta", 10, 17.500},
    {1015, "Diana", "Montoya", 15, 25.000}

};


void mostrarClientes() {
    cout << "Los clientes ingresados son:" << endl;
    for (int i = 0; i <=3; i++) {

        cout << " Cliente " << i + 1 << endl;
        cout << " Codigo: " << clientes[i].codigo << endl;
        cout << " Nombre: " << clientes[i].nombre << endl;
        cout << " Apellido: " << clientes[i].apellido << endl;
        cout << " Cantidad de Fotos: " << clientes[i].CantidadF << endl;
        cout << " Valor por foto: $" << clientes[i].ValorU << endl;
        cout << "_______" << endl;
    }
}

void consultaCod() {
    int codigoIngresado, encontrado = 0;
    cout << "Ingresa el codigo: ";
    cin >> codigoIngresado;
    
    for (int i = 0; i <=3; i++) {
        if (clientes[i].codigo == codigoIngresado) {
            encontrado = 1;
            
            cout << " Cliente #" << i + 1 << endl;
            cout << " Nombre: " << clientes[i].nombre << endl;
            cout << " Apellido: " << clientes[i].apellido << endl;
            cout << " Cantidad Fotos: " << clientes[i].CantidadF << endl;
            cout << " Valor por foto : $ " << clientes[i].ValorU << endl;
            cout << "_______" << endl;
            
        }
    }
    if (encontrado == 0) {
        cout << "No hay clientes con ese codigo" << endl;
    }
}

void consultaValorT() {
    int i, codigoIngresado, encontrado = 0;
    cout << "Ingresa el codigo: ";
    cin >> codigoIngresado;
   
    for (int i = 0; i <=3; i++) {
    	double valorTotal = clientes[i].CantidadF * clientes[i].ValorU;
        if (clientes[i].codigo == codigoIngresado) {
            encontrado = 1;
            
            cout << " Cliente #" << i + 1 << endl;
            cout << " Nombre: " << clientes[i].nombre << endl;
            cout << " Apellido: " << clientes[i].apellido << endl;
            cout << " Cantidad Fotos: " << clientes[i].CantidadF << endl;
            cout << " Valor por foto: " << clientes[i].ValorU << endl;
            cout << "  Valor total : $ " <<valorTotal << endl;
            cout << "_________"<<endl;
        }
    }
    if (encontrado == 0) {
        cout << "No hay clientes con ese codigo" << endl;
    }
}

        
void eliminarCli() {
    int pos;
    cout << "Cual es la posicion a eliminar? : ";
    cin >> pos;

    if (pos >= 0 && pos < 4) {
        clientes[pos].codigo = +1; 
        cout << "Se ha eliminado el cliente de la posicion [" << pos << "]" << endl;
    } else {
        system("cls");
        cout << "Esa posicion no existe" << endl;
        eliminarCli();
    }
}


void salir() {
    cout << "Programa finalizado" << endl;
}

void menu() {
    int opcion;
    
    do {
        cout << "<<< Menu de opciones >>>" << endl;
        cout << "1. Mostrar Clientes" << endl;
        cout << "2. Consulta por codigo" << endl;
        cout << "3. Consulta valor total" << endl;
        cout << "4. Eliminar Clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
           
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
                eliminarCli();
            break;
            case 5:
            	system("cls");
                salir();
            break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    } while (opcion != 5);
}

int main() {
    menu();
    return 0;
}
