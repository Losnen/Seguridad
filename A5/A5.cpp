#include "A5.h"

A5_t::A5_t(void)
{
    for (int i = 0; i < MAX1; i++)
    {
        R1.push_back(0); 
    }
    
    for (int i = 0; i < MAX2; i++)
    {
        R2.push_back(0);
    }
    
    for (int i = 0; i < MAX3; i++)
    {
        R3.push_back(0);  
    }
     
}

A5_t::~A5_t(void)
{}

void A5_t::leer_fichero(char fichero[])
{
    ifstream fich;
    fich.open(fichero);
    if (fich.is_open())
    {
        string r_1;
        string r_2;
        string r_3;
        
        while (!fich.eof())
        {
	        fich >> r_1;
	        fich >> r_2;
	        fich >> r_3;
        }
        iniciar_r1(r_1);
        iniciar_r2(r_2);
        iniciar_r3(r_3);
    }
    else
    {
        cerr << "Error al abrir el fichero" << endl;
    }
    fich.close();
}

int A5_t::polinomio_1(void)
{
    return (R1[18] ^ R1[21] ^ R1[22]);
}

int A5_t::polinomio_2(void)
{
    return (R2[21] ^ R2[20]);
}

int A5_t::polinomio_3(void)
{
    return (R3[22] ^ R3[21] ^ R3[20] ^ R3[7]);
}

int A5_t::z(void)
{
    return (R1[0] ^ R2[0] ^ R3[0]);
}

void A5_t::desplazar_1(void)
{
    int aux = polinomio_1();
    for (int i=0; i<MAX1; i++)
    {
        R1[i]=R1[i + 1];
    }
    R1[MAX1-1]= aux;
}

void A5_t::desplazar_2(void)
{
    int aux = polinomio_2();
    for (int i=0; i<MAX2; i++)
    {
        R2[i]=R2[i + 1];
    }
    R2[MAX2-1]= aux;
}

void A5_t::desplazar_3(void)
{
    int aux = polinomio_3();
    for (int i=0; i<MAX3; i++)
    {
        R3[i]=R3[i + 1];
    }
    R3[MAX3-1]= aux;
}

void A5_t::iniciar_r1 (string cad)
{
    for (int i = 0; i < MAX1; i++)
    {
        R1[i] = cad[i] -'0';
    }
}

void A5_t::iniciar_r2 (string cad)
{
    for (int i = 0; i < MAX2; i++)
    {
        R2[i] = cad[i] -'0';
    }
}

void A5_t::iniciar_r3 (string cad)
{
    for (int i = 0; i < MAX3; i++)
    {
        R3[i] = cad[i] -'0';
    }
}