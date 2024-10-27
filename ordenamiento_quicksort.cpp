#include <iostream>
using namespace std;

//Ordenamiento QuickSort

void QuickSort(int* arr, int izq, int der){
	int i= izq, j= der, tmp;
	int p= arr[(izq + der)/2];
	while(i <= j){
		while(arr[i]<p) i++;
		while(arr[j]>p) j--;
		if(i<=j){
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++; j--;
		}
	}
if(izq<j)
	QuickSort(arr, izq, j);
	if(i<der)
		QuickSort(arr, i, der);	
}

int main(){
	cout<<"Ordenamiento QuickSort"<<endl;
	cout<<"lista que utilizaremos: "<<endl;
	cout<<"88, 6, 69, -33, 98, 7, 23, 5, 0, 100"<<endl;
	cout<<"lista oredenada: "<<endl;
	int arreglo[10]= {88, 6, 69, -33, 98, 7, 23, 5, 0, 100};
	QuickSort(arreglo, 0, 9);
	
	for(int i=0; i<10;i++)
		cout<<arreglo[i]<<" ";
		
	
}
