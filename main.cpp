//Carlos Fortin 2020-01-31
//11911015
#include <iostream>
#include <cstdlib>

using namespace std;

int detMenor(int* a, int pos1, int size){
	int menor = 500, pos2 = 0;
	for(int i=pos1;i<size;i++){
		if(a[i]<menor){
			menor=a[i];
			pos2=i;
		}
	}
	return pos2;
}

int* llenarArreglo(int size){
	int* a=new int[size];
	for(int i=0;i<size;i++){
		int r=(rand()%100);
		a[i]=r;
	}
	return a;
}

void imprimirArreglo(int* a, int size){
	for(int i=0;i<size;i++){
		cout << "[" << a[i] << "] ";
	}
	cout << endl;
}

int* toArray(int num){
	int n1 , n2, n3, n4;
        n1 = num / 1000;
        n2 = (num / 100) - n1 * 10;
        n3 = (num/10) - ((n1*100)+(n2*10));
        n4 = num - ((n1 * 1000) + (n2 * 100) + (n3 * 10));
        int a[4]={n1,n2,n3,n4};
	return a;
}	

int toInt(int* a){
	return (a[0] * 1000) + (a[1] * 100) + (a[2] * 10) + a[3];
}

int ordenarArregloMenor(int* a, int pos, int size){
        if(pos == size){
                return toInt(a);
        }
        else{
                int pos1 = detMenor(a,pos,4);
                int temporal = a[pos1];
                a[pos1] = a[pos];
                a[pos] = temporal;
                return 1*ordenarArreglo(a,pos+1,size);
        }

}

int ordenarArregloMayor(int* a, int pos, int size){
        if(pos == size){
                return toInt(a);
        }
        else{
                int pos1 = detMayor(a,pos,4);
                int temporal = a[pos1];
                a[pos1] = a[pos];
                a[pos] = temporal;
                return 1*ordenarArreglo(a,pos+1,size);
        }

}

bool validarNum(int num){
        bool valido=true;
        int n1 , n2, n3, n4;
        n1 = num / 1000;
        n2 = (num / 100) - n1 * 10;
        n3 = (num/10) - ((n1*100)+(n2*10));
        n4 = num - ((n1 * 1000) + (n2 * 100) + (n3 * 10));
        int a[4]={n1,n2,n3,n4};
	imprimirArreglo(a,4);
	for(int i=0;i<5;i++){
		if(a[i] == a[i-1] && a[i])
			valido=false;
	}
	return valido;
}


int ordenarArreglo(int* a, int pos, int size){
        if(pos == size){
		cout << "Ronda " << pos+1 << ":" << endl;
		imprimirArreglo(a,size);
		return 0;
	}
	else{
		int pos1 = detMenor(a,pos,size);
		int temporal = a[pos1];
		a[pos1] = a[pos];
		a[pos] = temporal;
		cout << "Ronda " << pos+1 << ":" << endl;
		imprimirArreglo(a,size);
		return 1*ordenarArreglo(a,pos+1,size);
	}

}

int MCD(int num1, int num2){
	if(num2 == 0)
		return num1;
	else
		return MCD(num2,num1%num2);
}

void opciones(){
	cout << "     Menu     " << endl;
	cout << "**************" << endl;
	cout << "1. Ejercicio 1" << endl;
	cout << "2. Ejercicio 2" << endl;
	cout << "3. Ejercicio 3" << endl;
	cout << "0. Salir" << endl;
}

void ejercicios(int opcion){
	
	switch(opcion){
		case 1:{
			int numero1, numero2;
			cout << "Ingrese el primer numero: ";
			cin >> numero1;
			while(numero1 <= 0){
				cout << "El numero no puede ser negativo. ";
				cout << "Ingrese otro numero: ";
				cin >> numero1;
			}
			cout << "Ingrese el segundo numero: ";
			cin >> numero2;
			while(numero2 <= 0){
                                cout << "El numero no puede ser negativo. ";
                                cout << "Ingrese otro numero: ";
                                cin >> numero2;
                        }
			
			if(numero1 > numero2)
				cout << "mcd(" << numero1 << ", " << numero2 << ") = " << MCD(numero1,numero2) << endl;
			else
				cout << "mcd(" << numero1 << ", " << numero2 << ") = " <<  MCD(numero2,numero1) << endl;
			break;
		       }
		case 2:{
			int size;
			cout << "Ingrese la longitud deseada: ";
			cin >> size;
			while(size <=0){
				cout << "El numero no puede ser negativo ni 0. Ingrese un nuevo numero: ";
				cin >> size;
			}
			int* arreglo=llenarArreglo(size);
			imprimirArreglo(arreglo,size);
			ordenarArreglo(arreglo,0,size);
			break;
		       }
		 case 3:{
                        int numero, n1, n2, n3, n4;
                        cout << "Ingrese un numero de 4 cifras: ";
                        cin >> numero;
                       	while(validarNum(numero) == false || (numero < 1 || numero > 9999)){
                              	cout << "El numero ingresado no es valido, vuelva a ingresarlo: ";
                               	cin >> numero;
                        }
                       	break;
		}
                default:{
                        cout << "La opcion ingresada no es valida" << endl;
                        break;
		}
	}
}

int main(){
	int opcion = 1;
	while(opcion != 0){
		opciones();
		cin >> opcion;
		ejercicios(opcion);
	}
	cout << "Fin del programa" << endl;

}
