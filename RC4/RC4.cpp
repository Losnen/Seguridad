#include "RC4.h"

RC4_t::RC4_t(int szc, int szm):
S_(NULL),
C_(NULL),
sz_c_(szc),
K_(NULL),
M_(NULL),
sz_m_(szm),
mensaje_binario_(),
clave_binario_(),
resultado_binario_()
{
    S_ = new int [256];
    C_ = new int [sz_c_];
    K_ = new int [256];
    M_ = new int [sz_m_];
    mensaje_binario_ = new bitset<8>[sz_m_];
    clave_binario_ = new bitset<8>[sz_m_];
    resultado_binario_ = new bitset<8>[sz_m_];
    KSA();
    aBinario();
}

RC4_t::~RC4_t(void)
{}

void RC4_t::KSA(void)
{
    for(int i = 0; i< 256; i++)
    {
        S_[i] = i;
    }
    
    for(int i = 0; i< sz_c_; i++)
    {
        cout << "Elemento "<< i << " de la clave: ";
        cin >> C_[i];
    }
    
    cout << endl;
    
    for(int i = 0; i< sz_m_; i++)
    {
        cout << "Elemento "<< i << " del mensaje: ";
        cin >> M_[i];
    }
    
    cout << endl;
    
    int aux = 0;
    for(int i = 0; i< 256; i++)
    {
        K_[i] = C_[aux];
        aux++;
        if(aux == sz_c_)
            aux = 0;
    }
    
    int j = 0;    
    for(int i = 0; i< 256; i++)
    {
        j = (j+ S_[i] + K_[i]) % 256;
        swap(S_[i],S_[j]);
    }
    
}

void RC4_t::PRGA(void)
{
   int i = 0;
   int j = 0;
   int t = 0;
   for(int x = 0; x< sz_m_; x++)
    {
        i = (i + 1) % 256;
        j = (j+S_[i]) % 256;
        swap(S_[i],S_[j]);
        t = (S_[i] + S_[j]) % 256;
        
        clave_binario_[x] = S_[t];
    }
}


void RC4_t::aBinario(void)
{
    for(int i = 0; i< sz_m_; i++)
    {
        mensaje_binario_[i] = M_[i];
    }
}

void RC4_t::MyXOR(void)
{
     for(int i = 0; i< sz_m_; i++)
    {
       resultado_binario_[i] = mensaje_binario_[i] ^ clave_binario_[i]; 
    }
}

void RC4_t::write(void)
{
    int aux = 0;

    
    cout << endl;
    cout << "S: " << endl;
    for (int i = 0; i <= 255; i++)
    {
        cout << setw(4) << fixed << S_[i] << " ";
        aux++;
        if (aux == 16)
        {
            cout << endl;
            aux = 0;
        }
    }
    cout << endl << endl;
    cout << "Elementos clave: ";
    for (int i = 0; i < sz_c_; i++)
    {
        cout << C_[i] << " ";
    }
    cout << endl <<  "Elementos a cifrar: ";
    for (int i = 0; i < sz_m_; i++)
    {
        cout << M_[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < sz_m_; i++)
    {
        cout << "Byte " << i+1 << " de secuencia cifrante: " << clave_binario_[i] << endl;
        cout << "Byte " << i+1 << " de texto original: " << mensaje_binario_[i] << endl;
        cout << "Byte " << i+1 << " de texto cifrado: " << resultado_binario_[i] << endl;
    }
  
    cout << endl;
}