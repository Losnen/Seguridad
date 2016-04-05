#include "AES.h"
#include "CBC.h"

int main (void)
{
    rijndael_t A;
    
    cout << "----------- PRÁCTICA 5 - IMPLEMENTACIÓN ALGORITMO RIJNDAEL -----------" << endl;
    cout << endl;
    
    A.encryptionProcess();
    CBC_t B;
    
    //B.generar();
    
    B.cipher_stealing();
}