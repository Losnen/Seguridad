#include <iostream>

using namespace std;

class vigenere_t
{
    private:
        
        string mensaje_;
        string clave_;
        
    public:
        
        vigenere_t(void);
        ~vigenere_t(void);
        void parse(void);
};