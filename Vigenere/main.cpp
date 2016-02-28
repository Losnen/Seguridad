#include "vigenere_t.h"
#include <stdlib.h>


using namespace std;

int main (void)
{
	string clave;
	cout << "Práctica 2 SSI: Cifrado de Vigenere" << endl;
	cout << "Introduzca la clave: " << endl;
	cin >> clave;
    vigenere_t A("ESTE MENSAJE SE AUTO DESTRUIRA",clave);
    
    int opcion = 9;
   	do
  	{
  	    cout << "Práctica 2 SSI: Cifrado de Vigenere" << endl;
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