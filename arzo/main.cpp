//
// main.cpp
//
// Alejandro Arzola 5/03/2016.
//
// Práctica 3 - Seguridad en Sistemas Informáticos: Implementar generador RC4.
//
#include "rc4_t.hpp"

int main(void)
{
    int tex = 0;
    int clv = 0;
    
    cout << "-*-*- Práctica 3: Generador RC4 -*-*-" << endl;
    cout << "Número de elementos de la clave: ";
    cin >> clv;
    cout << "Número de elementos del texto a cifrar: ";
    cin >> tex;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << endl;
    
    rc4_t G(clv, tex);
    G.encryptSequenceGenerator();
    G.encrypt();
    G.write();
}