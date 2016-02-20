#include <iostream>
#include <string>
#include <cstdlib>
#include <bitset>

using namespace std;

class vernam_t
{
    private:
        
        string      mensaje_;
        string      clave_;
        bitset<8>*       mensaje_binario_;
        bitset<8>*       clave_binaria_;
        int         mb_sz_;
    
    public:
        
        vernam_t(string mensaje);
        ~vernam_t(void);
        void StrToBin(string mensaje);
        void StrToBin_clave(string mensaje1);
        void StrRand(int sz);
        void cifrar(void);
        void descifrar(void);
        friend ostream& operator<<(ostream& os, const vernam_t& A);
};