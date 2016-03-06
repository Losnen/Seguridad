#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

class RC4_t
{
    private:
    
        int*            S_;                     //Secuencia.
        int*            C_;                     //Clave.
        int             sz_c_;                  //Longitud de la clave.
        int*            K_;                     // Semilla.
        int*            M_;                     // Mensaje.    
        int             sz_m_;                  //Longitud del mensaje.
        bitset<8>*       mensaje_binario_;      //Mensaje binario.
        bitset<8>*       clave_binario_;        //Clave binario.
        bitset<8>*       resultado_binario_;    //Resultado binario.
    public:
        
        RC4_t(int szc, int szm);                // Constructor de la clase, se lleva a cabo la creación de vectores, inicialización(KSA) y pasar el mensaje a binario.
        ~RC4_t(void);                           //Destructor.
        void KSA(void);                         //Inicialización.
        void PRGA(void);                        //Generación de secuencia cifrante.
        void aBinario(void);                    //Pasa el mensaje a binario.
        void MyXOR(void);                       //Realiza un XOR entre el mensaje y la clave.
        void write(void);                       //Imprime el cifrado.
};