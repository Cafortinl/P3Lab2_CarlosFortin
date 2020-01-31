#include <iostream>

using namespace std;

int MCD(int num1, int num2, int div){
	if(num2 == 0)
		return num1;
	else{
		return MCD(num2,(num1%num2)*10,1);
	}
}

void opciones(){
	cout << "     Menu     " << endl;
	cout << "**************" << endl;
	cout << "1. Ejercicio 1" << endl;
	cout << "2. Ejercicio 2" << endl;
	cout << "3. Ejercicio 3" << endl;
	cout << "0. Ejercicio 4" << endl;
}

void ejercicios(int opcion){
	switch(opcion){
		case 1:
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
				cout << "mcd(" << numero1 << ", " << numero2 << MCD(numero1,numero2, 1) << endl;
			else
				cout << "mcd(" << numero2 << ", " << numero1 << MCD(numero2,numero1, 1) << endl;

			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "La opcion ingresada no es valida" << endl;
			break;
	}
}

int main(){
	int opcion = 1;
	while(opcion != 0){
		opciones();
	}
	cout << "Fin del programa" << endl;

}
