#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class vernam_t
{
    private:
        
        string mensaje_;
        string clave_;
        string clave_binaria_;
        string mensaje_binario_;
    
    public:
        
        vernam_t(string mensaje);
        ~vernam_t(void);
        void cifrar(void);
        void descifrar(void);
};