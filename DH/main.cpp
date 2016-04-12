#include "DH.h"

int main(void)
{
    DH A(2053,53,17,31);
    DH B(1973,125,21,33);
    
    A.generador();
    B.generador();
    C.generador();
    
    cout << "Práctica 6 de SSI: Intercambio de claves de Diffie-Hellman" << endl;
    cout << "Primer ejemplo: " << A;
    cout << "Segundo ejemplo: " << B;
    cout << "Tercer ejemplo: " << C;
}