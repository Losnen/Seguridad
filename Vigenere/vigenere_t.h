#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class vigenere_t
{
    private:
        
        string      mensaje_;       //Contiene el mensaje
        string      clave_;         //Contiene la clave
        string      resultado_;     //Contiene el resultado
        
    public:
        
        vigenere_t(string mensaje, string clave);
        ~vigenere_t(void);
        void cifrar(void);
        void descifrar(void);
};