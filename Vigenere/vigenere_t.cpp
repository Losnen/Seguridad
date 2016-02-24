#include "vigenere_t.h"

vigenere_t::vigenere_t(string mensaje, string clave):
mensaje_(mensaje),
clave_(clave),
resultado_(){}

vigenere_t::~vigenere_t(void)
{}

void vigenere_t::cifrar(void)
{
    for(int i = 0; i < mensaje_.size(); i++) //for para pasar a mayúsculas el mensaje y la clave.
    {
        mensaje_[i] = toupper(mensaje_[i]);
    }
    for(int i = 0; i < clave_.size(); i++) //for para pasar a mayúsculas el mensaje y la clave.
    {
        clave_[i] = toupper(clave_[i]);
    }
    
    int j = 0;
    resultado_.resize(mensaje_.size());
    for(int i = 0; i< mensaje_.size(); i++)
    {
        
        if(j == (clave_.size()))
        {
            j = 0;
        }
        else
        {
            resultado_[i] = (((mensaje_[i] + clave_[j]) % 26) + 65);
            j++;
        }
    
    }
    
    cout << mensaje_ << endl;
    cout << clave_ << endl;
    cout << resultado_ << endl;
    
    
}

