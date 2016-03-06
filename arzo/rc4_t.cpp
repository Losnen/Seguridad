//
// rc4_t.cpp
//
// Alejandro Arzola 5/03/2016.
//
// Práctica 3 - Seguridad en Sistemas Informáticos: Implementar generador RC4.
//
#include "rc4_t.hpp"

/*
    --- Constructor por defecto. ---
*/
rc4_t::rc4_t(void):
s_(NULL),
c_(NULL),
sz_(0),
k_(NULL),
entrada_(NULL),
entrada_sz_(0),
clave_(),
entrada_bin_(),
salida_()
{
    buildVector();
    initialization();
    inputToBinary();
}

/*
    --- Constructor con parametros. ---
*/
rc4_t::rc4_t(int sz, int i_sz):
s_(NULL),
c_(NULL),
sz_(sz),
k_(NULL),
entrada_(NULL),
entrada_sz_(i_sz),
clave_(),
entrada_bin_(),
salida_()
{
    buildVector();
    initialization();
    inputToBinary();
}

/*
    --- Destructor. ---
*/
rc4_t::~rc4_t(void)
{
    destroyVector();
}

/*
    --- Método que reserva la memoria
        para el vector de estados. ---
*/
void rc4_t::buildVector()
{
    s_ = new int [256];
    c_ = new int [sz_];
    k_ = new int [256];
    entrada_ = new int [entrada_sz_];
    clave_ = new bitset<8>[entrada_sz_];
    entrada_bin_ = new bitset<8>[entrada_sz_];
    salida_ = new bitset<8>[entrada_sz_];
}

/*
    --- Método que libera la memoria
        del vector de estados. ---
*/
void rc4_t::destroyVector(void)
{
    if(s_ != NULL)
    {
        delete [] s_;
        s_ = NULL;
    }
    if(k_ != NULL)
    {
        delete [] k_;
        k_ = NULL;
    }
    if(c_ != NULL)
    {
        delete [] c_;
        c_ = NULL;
    }
    if(entrada_ != NULL)
    {
        delete [] entrada_;
        entrada_ = NULL;
    }
}

/*
    --- Método que muestra todos los
        atributos por pantalla. ---
*/
void rc4_t::write(void)
{
    int aux = 0;

    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << endl;
    cout << "S: " << endl;
    for (int i = 0; i <= 255; i++)
    {
        cout << setw(4) << fixed << s_[i] << " ";
        aux++;
        if (aux == 16)
        {
            cout << endl;
            aux = 0;
        }
    }
    cout << endl << endl;
    cout << "Elementos clave: ";
    for (int i = 0; i < sz_; i++)
    {
        cout << c_[i] << " ";
    }
    cout << endl <<  "Elementos a cifrar: ";
    for (int i = 0; i < entrada_sz_; i++)
    {
        cout << entrada_[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < entrada_sz_; i++)
    {
        cout << "Byte " << i+1 << " de secuencia cifrante: " << clave_[i] << endl;
        cout << "Byte " << i+1 << " de texto original: " << entrada_bin_[i] << endl;
        cout << "Byte " << i+1 << " de texto cifrado: " << salida_[i] << endl;
    }
    /*cout << "K: ";
    for (int i = 0; i < 256; i++)
    {
        cout << k_[i] << " ";
    }*/
    cout << endl;
}

/*
    --- Método que realiza la
        inicialización de los vectores. ---
*/
void rc4_t::initialization(void)
{
    for (int i = 0; i < 256; i++)
    {
        s_[i] = i;
    }

    for (int i = 0; i < sz_; i++)
    {
        cout << "Elemento clave[" << i << "]: ";
        cin >> c_[i];
    }
    cout << endl;

    for (int i = 0; i < entrada_sz_; i++)
    {
        cout << "Elemento a cifrar[" << i << "]: ";
        cin >> entrada_[i];
    }
    cout << endl;

    int cnt = 0;
    for (int i = 0; i < 256; i++)
    {
        k_[i] = c_[cnt];
        cnt++;
        if (cnt == sz_)
        {
            cnt = 0;
        }
    }

    int f = 0;

    for (int i = 0; i < 256; i++)
    {
        //cout << "S[" << i << "]=" << s_[i] << " K[" << i << "]=" << k_[i] << " -> ";
        f = (f + s_[i] + k_[i]) % 256;
        swap(s_[i],s_[f]);
        //cout << "f=" << f << " S[" << i << "]=" << s_[i] << " S[" << f << "]=" << s_[f] << endl;
    }
}

/*
    --- Método de generación
        de secuencia cifrante. ---
*/
void rc4_t::encryptSequenceGenerator(void)
{
    int i = 0;
    int f = 0;
    int t = 0;

    for (int a = 0; a < entrada_sz_; a++)
    {
        i = (i + 1) % 256;
        f = (f + s_[i]) % 256;
        swap(s_[i],s_[f]);
        t = (s_[i] + s_[f]) % 256;

        clave_[a] = s_[t];
    }
}

/*
    --- Método que tranforma a binario la entrada. ---
*/
void rc4_t::inputToBinary(void)
{
    for(int i = 0; i < entrada_sz_; i++)
    {
        entrada_bin_[i] = entrada_[i];
    }
}

/*
    --- Método que cifra mediante un XOR.
*/
void rc4_t::encrypt(void)
{
    for(int i = 0; i < entrada_sz_; i++)
    {
        salida_[i] = entrada_bin_[i] ^ clave_[i];
        //cout << salida_[i] << endl;
    }
}
