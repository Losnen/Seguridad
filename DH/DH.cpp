#include "DH.h"

DH::DH(void):
p(0),
alpha(0),
Ka(0),
Kb(0),
Xa(0),
Xb(0),
Ya(0),
Yb(0)
{}

DH::DH(int P, int ALPHA, int XA, int XB):
p(P),
alpha(ALPHA),
Ka(0),
Kb(0),
Xa(XA),
Xb(XB),
Ya(0),
Yb(0)
{}

DH::~DH(void)
{}

int DH::get_p(void)
{
    return p;
}
int DH::get_alpha(void)
{
    return alpha;
}

int DH::get_ka(void)
{
    return Ka;
}

int DH::get_kb(void)
{
    return Kb;
}

int DH::get_xa(void)
{
    return Xa;
}

int DH::get_xb(void)
{
    return Xb;
}

int DH::get_ya(void)
{
    return Ya;
}

int DH::get_yb(void)
{
    return Yb;
}

int DH::calcular_y (int alp, int x, int m)
{
    int y = 0;
    long aux = pow(alp,x);
    cout << " alp= "  << alp << "X= "  << x << endl;
    y = (aux % m);
    return y;
}

int DH::calcular_k(int y, int x, int m)
{
    int k = 0;
    long aux =  pow(y,x);
    k = (aux % m);
    return k;
}
/*
int DH::exponenciacion_rapida(int base, int ex, int m)
{
    int x = 1;
    int y = base % m;
    
    while((ex > 0) && (y > 1))
    {
        if((ex % 2) == 0)
        {
            x = ((x * y) % m);
            ex = (ex - 1); 
        }
        else
        {
            y = ((y * y) % m);
            ex = (ex / 2);
        }
    }
    return x;
}*/

void DH::generador(void)
{
    long double aux  = 0;
    aux = pow(alpha,Xa);
    cout << pow(alpha,Xa) << endl;
    Ya = (aux % p);  
    
    aux = 0;
    aux = pow(alpha,Xb);
    cout << aux << endl;
    Yb =  (aux % p);
 
    aux  = 0;
    aux = pow(Yb, Xa);
    cout << aux << endl;
    Ka =  (aux % p);
    
    aux  = 0;
    aux = pow(Ya, Xb);
    cout << aux << endl;
    Kb =  (aux % p);
}

ostream& operator<<(ostream& os, DH& a)
{
    os << "p: " << a.get_p() << " α: " << a.get_alpha() << " Xa: " << a.get_xa() << " Xb: " << a.get_xb() << " Ya: " << a.get_ya() << " Yb: " << a.get_yb() << " k: " << a.get_ka() << endl;
    return os;
}