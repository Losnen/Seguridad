#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>

using namespace std;

class vigenere_t
{
    private:
        
        string      mensaje_;       //Contiene el mensaje
        string      clave_;         //Contiene la clave
        string      resultado_;     //Contiene el resultado
        string      r_descifrado_;  //Contiene el el descifrado
        
    public:
        
        vigenere_t(string mensaje, string clave);   //Constructor
        ~vigenere_t(void);                          //Destructor
        void mayusculas(void);                      //Pasa la cadena a mayusculas
        void quitar_espacios(void);                 //Quita los espacios de la cadena
        void cifrar(void);                          //Cifra el mensaje según la formula: C = (M + k) mod n
        void descifrar(void);                       // Descifra el mensaje según la formula: DC = (C-K) + n*x 
};