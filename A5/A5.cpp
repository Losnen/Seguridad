#include "A5.h"

A5_t::A5_t(char* input, int sz):
sz_(sz)
{
    resultado_ = new bitset<1> [sz_];
    mensaje_ = new bitset<1> [sz_];
    cifrado_ = new bitset<1> [sz_];
    int m = 0;
    for(int i = 0; i<sz_; i++)
    {
        cout << "introduzca el elemento " << i <<": ";
        cin >> m;
        mensaje_[i] = m;
    }
    
    leer_fichero(input);                     //Leo del fichero y lo meto en cada registro
}

A5_t::~A5_t(void)
{}

void A5_t::leer_fichero(char* fichero)
{
    ifstream fich;
    fich.open(fichero);
    if (fich.is_open())
    {
        
        while (!fich.eof())
        {
	        fich >> R1;
	        fich >> R2;
	        fich >> R3;
	        fich >> R1m;
	        fich >> R2m;
	        fich >> R3m;
	        fich >> k;
        }
    }
    else
    {
        cerr << "Error al abrir el fichero" << endl;
    }
    fich.close();
}

bitset<1> A5_t::polinomio_1(void)
{
    return (R1[18] ^ R1[17] ^ R1[16] ^ R1[13]);
}

bitset<1> A5_t::polinomio_2(void)
{
    return (R2[21] ^ R2[20]);
}

bitset<1> A5_t::polinomio_3(void)
{
    return (R3[22] ^ R3[21] ^ R3[20] ^ R3[7]);
}

bitset<1> A5_t::z(void)
{
    return (R1[MAX1-1] ^ R2[MAX2-1] ^ R3[MAX3-1]);
}

void A5_t::desplazar_1(void)
{
    bitset<1> aux = polinomio_1();
    R1<<=1;
    R1[0] = aux[0];
}

void A5_t::desplazar_2(void)
{
    bitset<1> aux = polinomio_2();
    R2<<=1;
    R2[0] = aux[0];
}

void A5_t::desplazar_3(void)
{
    bitset<1> aux = polinomio_3();
    R3<<=1;
    R3[0] = aux[0];
}

bitset<1> A5_t::mayoria(void)
{
    return ((R1[8] * R2[10]) ^ (R1[8] * R3[10]) ^ (R2[10] * R3[10]));
}

void A5_t::generar(void)
{
    bitset<1> m;
    bitset<1> rz;
    
    for(int i = 0; i< sz_; i++)
    {
       
        m = mayoria();
        rz = z();
        resultado_[i] = rz;
        cout << "Iteración: " << i << endl;
        write();
        if (m[0] == R1[8])
        {
	        desplazar_1();
        }
        if (m[0] == R2[10])
        {
	        desplazar_2();
        }
        if (m[0] == R3[10])
        {
            desplazar_3();
        }
    }
}

void A5_t::my_xor(void)
{
    for(int i = 0; i<sz_; i++)
    {
        cifrado_[i] = mensaje_[i] ^ resultado_[i]; 
    }
}

void A5_t::write(void)
{
    cout << "Registro 1: ";
    cout << R1 << endl;
    
    cout << "Registro 2: ";
    cout << R2 << endl;
    
    cout << "Registro 3: ";
    cout << R3 << endl;
    
    cout << "Resultado: ";
    for(int i = 0; i< sz_; i++)
    {
        cout << resultado_[i];
    }
    cout << endl;
}

void A5_t::resultado_xor(void)
{
    
    cout << "Mensaje: ";
    for(int i = 0; i< sz_; i++)
    {
        cout << mensaje_[i];
    }
    cout << endl;
    
    cout << "Clave: ";
    for(int i = 0; i< sz_; i++)
    {
        cout << resultado_[i];
    }
    cout << endl;
    
    cout << "Resultado del XOR: ";
    for(int i = 0; i< sz_; i++)
    {
        cout << cifrado_[i];
    }
    cout << endl;
}

void A5_t::modificacion(void)
{

    for(int i = 0; i<sz_; i++)
    {
        R1m[0] = (R1m[18] ^ R1m[17] ^ R1m[16] ^ R1m[13]) ^ k[i];
        //cout << "R1: " << R1m[0]  << endl;
        R1m<<=1;

        R2m[0] = (R2m[21] ^ R2m[20]) ^ k[i];
        //cout << "R2: " << R2m[0]  << endl;
        R2m<<=1;
      
        R3m[0] = (R3m[22] ^ R3m[21] ^ R3m[20] ^ R3m[7]) ^ k[i];
        //cout << "R3: " << R3m[0]  << endl;
        R3m<<=1;

    }
}

void A5_t::mostrarmodificacion(void)
{
    cout << "--------------- MODIFICACION -----------------" << endl;
    cout << "Registro 1: ";
    cout << R1m << endl;
    
    cout << "Registro 2: ";
    cout << R2m << endl;
    
    cout << "Registro 3: ";
    cout << R3m << endl;
    
}