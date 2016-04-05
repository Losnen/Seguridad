#include "DH.h"

int main(void)
{
    DH A(13,4,5,2);
    DH B(43,23,25,33);
    DH C(113,43,54,71);
    
    A.generador();
    B.generador();
    C.generador();
    
    cout << "Práctica 6 de SSI: Intercambio de claves de Diffie-Hellman" << endl << endl;
    cout << "Primer ejemplo: " << A << endl << endl;
    cout << "Pr ejemplo: " << B << endl << endl;
    cout << "Tercer ejemplo: " << C;
}