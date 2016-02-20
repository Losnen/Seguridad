#include "vernam_t.h"

vernam_t::vernam_t(string mensaje):
    mensaje_(mensaje),
    clave_(),
    clave_binaria_(),
    mensaje_binario_(),
    mb_sz_(0)
{}

vernam_t::~vernam_t(void)
{}

void vernam_t::StrToBin(string mensaje)
{
    int sz = mensaje.size();
    bitset<8> aux[sz];
    mensaje_binario_ = new bitset<8>[sz];
    for (std::size_t i = 0; i < sz; ++i)
    {
        aux[i] = bitset<8>(mensaje.c_str()[i]);
        mensaje_binario_[i] = aux[i].to_ulong();
        
    }

    mb_sz_ = sz;
    
}

void vernam_t::StrToBin_clave(string mensaje1)
{   
    int sz = mensaje1.size();

    bitset<8> aux1[sz];

    clave_binaria_ = new bitset<8>[sz];
    for (std::size_t i = 0; i < sz; ++i)
    {
        aux1[i] = bitset<8>(mensaje1.c_str()[i]);
        clave_binaria_[i] = aux1[i];
        
    }
}

void vernam_t::StrRand(int sz)
{
    clave_.resize(sz);
    string aux;
    aux.resize(sz);
    srand(time(NULL));
    for(int i=0; i < sz; i++)
    {
        aux[i] = 33 + rand() % (126 - 33);
        clave_[i] = aux[i];
        aux.clear();
    }
   
   
}

void vernam_t::cifrar(void)
{
    StrToBin(mensaje_);
    cout << "Mensaje: " << mensaje_ << endl;
    cout << "Mensaje Binario: " << endl;
    
    for(int i = 0; i < mb_sz_; i++)
    {
        cout << mensaje_binario_[i] << " ";
    }
    
    
    StrRand(mb_sz_);
    cout << endl << "Clave: "<< clave_ << endl;
    StrToBin_clave(clave_);
    
    cout << "Clave Binaria: " << endl;
    for(int i = 0; i < mb_sz_; i++)
    {
        cout << clave_binaria_[i] << " ";
    }
    
    cout << endl << "Resultado XOR: " << endl;
    for(int i = 0; i < mb_sz_; i++)
    {
        bitset<8> aux = mensaje_binario_[i] ^ clave_binaria_[i];
        cout << aux << " ";
    }
    
    cout << endl;
}