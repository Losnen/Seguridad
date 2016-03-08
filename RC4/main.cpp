#include "RC4.h"

int main(void)
{
    int tex = 0;
    int clv = 0;
    
    cout << "Práctica 3: Generador RC4" << endl;
    cout << "Número de elementos de la clave: ";
    cin >> clv;
    cout << "Número de elementos del texto a cifrar: ";
    cin >> tex;
    cout << endl;
    
    RC4_t A(clv, tex);
    A.PRGA();
    A.MyXOR();
    A.write();
    
    RC4_t B(clv, tex);
    B.modificacion();
    B.MyXOR();
    B.write();
}