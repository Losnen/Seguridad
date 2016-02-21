#include "vernam_t.h"

#include <iostream>
#include <cstdlib>

using namespace std;
int main(void)
{
    vernam_t A("SOL");
    
    int opcion = 9;
   	do
  	{
  		cout << "Práctica 1 SSI: Cifrado de Vernam" << endl;
	    cout << "MENU:" << endl;
	    cout << "1. Cifrar" << endl;
	    cout << "2. Descifrar" << endl;
	    cout << "0. Salir"<< endl;
	    cout << "Introduzca una opción: ";
	    cin >> opcion;
	
	    switch(opcion)
	    {
	      case 0:
	    	exit(0);
	      break;
	      case 1:
	        system("clear");
	        A.cifrar();
	      break;
	      case 2:
	      	system("clear");
	    	A.descifrar();
	      break;
	      default:
	      	system("clear");
	        cout << "Opción incorrecta." <<endl;
	      break;
	    }
	  }while(opcion!=-1);
}