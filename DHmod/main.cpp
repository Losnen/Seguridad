#include "DH.h"

int main(void)
{
    long sz = 0;
    cout << "Práctica 6 de SSI: longercambio de claves de Diffie-Hellman" << endl;
    cout << "longroduzca el número de secretos: ";
    cin >> sz;
    
    long* secreto;
    secreto = new long [sz];
    for (long i = 0; i < sz; i++) {
        cout << "longroduzca el secreto " << (i + 1) << ": ";
        cin >> secreto[i];
    }

    DH A(13,7,sz,secreto);

    A.generador();
    A.write();
}