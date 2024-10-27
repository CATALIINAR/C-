#include<iostream>
using namespace std;
int vector1[10], vector2[5];
int suma =0, resta=0, multiplicacion=1, op, i, media,ops, a; 
float division = 1.0;



int menu1(){
	bool mseguir1= true;	
		do
	{
		
		cout<<"Menu Operaciones"<<endl;
		cout<<"1. Ingresar Numeros"<<endl;
		cout<<"2. Mostrar Numeros "<<endl;
		cout<<"3. Sumar "<<endl;
		cout<<"4. Restar "<<endl;
		cout<<"5. Multiplicar "<<endl;
		cout<<"6. dividir "<<endl;
		cout<<"7. Salir "<<endl;
		cout<<"Ingrese la opcion que desea"<<endl;
		cin>>op;
		switch(op)
			{
			 case 1:
			 	system("cls");
			 	for (i=0;i<=9;i++) {
					cout<<"Ingrese  (" << i + 1 << "/" << 10 <<"): " ;
				    cin>>vector1[i];
				}break;
				
			 case 2:
				 system("cls");
			 	for (i=0;i<=9;i++)	{
	     	    cout<<vector1[i]<<"\t"; //Tabular
	     	    }break;
	     	    
			 case 3: 
			     system("cls");
		    	 for (int i = 0; i < 10; i++){
       			 suma = suma + vector1[i];
    			 }cout << "La suma de los numeros es: " << suma << endl; break;
    			 
   			 case 4:
   			 	system("cls");
   			 	for (int i = 1; i < 10; i++){
       				 resta = resta - vector1[i];
    		    	}cout << "La resta de los numeros es: " << resta << endl; break;
    		    	
   			 case 5:
   			  	system("cls");
   			  	for (int i = 0; i < 10; i++){
       			multiplicacion = multiplicacion * vector1[i];
        	    }cout << "La multiplicacion de los numeros es: " << multiplicacion<< endl;break;
             	
             case 6:
   			  	system("cls");
   			  	for (int i = 0; i < 10; i++){
       			division = division / vector1[i];
        	    }cout << "La division de los numeros es: " << division<< endl;break;   
    			 
		   	case 7:
		   	 system("cls");	
             cout << "bye :) "<<endl;
             break;
             default:
                cout <<"Opcion no valida, Intente de nuevo"<<endl;
			}
	
	 }while (op != 7);
}

int menu2(){
	bool mseguir2= true;
	do
	{
	cout<<"Menu Media"<<endl;
		cout<<"1. Ingresar Numeros"<<endl;
		cout<<"2. Mostrar los numeros ingresados "<<endl;
		cout<<"3. Mostrar la media "<<endl;
		cout<<"4. Salir "<<endl;
		cout<<"Ingrese la opcion que desea"<<endl;
		cin>>op;
		switch(op)
			{
			 case 1:
			 	system("cls");
			 	for (i=0;i<=9;i++) {
					cout<<"Ingrese  (" << i + 1 << "/" << 10 <<"): " ;
				    cin>>vector1[i];
				    
				 }break;
			 case 2:
				 system("cls");
			   	for (i=0;i<=9;i++)	{
	     	    cout<<vector1[i]<<"\t"; //Tabular
	     	    }break;
	     	    
			 case 3: 
			     system("cls");
			     for (int i = 0; i < 10; i++){
       			 suma = suma + vector1[i];
       			 media = suma/10;
       			 
    			 } cout << "La media es : " << media << endl; break;
		 	case 4:
		 	 system("cls");	
             cout << "bye"<<endl;
             break;
             default:
                cout <<"Opcion no valida, Intente de nuevo"<<endl;
			}
	
	 }while (op != 4);
}

void notas(){
	for(a=0;a<4;a++){
		cout<<"ingrese la nota del estudiante "<<a+1<<endl;
		cin>>vector2[a];
	}
}
int estudiante(){
	cout<<"las notas ingresadas son: "<<endl;
	
	
	int deficientes=0, regulares=0, buenos=0, excelentes=0;
	for(a=0;a<=4;a++){
		if(vector2[a]<=6&&vector2[a]<=5){
			deficientes++;
		}
		else if(vector2[a]<=6&&vector2[a]<=10){
			regulares++;
		}
		else if(vector2[a]<=11&&vector2[a]<=15){
			buenos++;
		}
		else if(vector2[a]<=16&&vector2[a]<=20){
			excelentes++;
		}
		
	}
	cout<<"Deficientes: "<<deficientes<<endl;
	cout<<"Regulares: "<<regulares<<endl;
	cout<<"Buenos: "<<buenos<<endl;
	cout<<"Exelentes: "<<excelentes<<endl;
	
}

int main(){
	bool mseguir= true;
		do
	{
		cout<<" MENU PRINCIPAL"<<endl;
		cout<<"1. Operaciones"<<endl;
		cout<<"2. Media"<<endl;
		cout<<"3. Notas "<<endl;
		cout<<"4. Salir "<<endl;
		cout<<"Ingrese la opcion que desea"<<endl;
		cin>>ops;
		switch(ops){
			 case 1:
			 system("cls");
			 menu1();
			 break;
			 
			 case 2:
			 system("cls");
			 menu2();
			 break;
			 
			 case 3:
			 system("cls");
			 notas();
			 estudiante();
			 break;
			 case 4:
			 system("cls");
             cout << "bye :)"<<endl;
             break;
             default:
                cout <<"Opcion no valida, Intente de nuevo"<<endl;
			}
			
		
	}while (ops != 4);
	
}

