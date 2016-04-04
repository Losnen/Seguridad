#include "DH.h"

DH::DH(void):
p(0),
alpha(0),
k(0),
Xa(0),
Xb(0),
Ya(0),
Yb(0)
{}

DH::DH(int P, int ALPHA, int K, int XA, int XB, int YA, int YB):
p(P),
alpha(ALPHA),
k(K),
Xa(XA),
Xb(XB),
Ya(YA),
Yb(YB)
{}

~DH(void)
{}

int calcular_y (int alp, int x, int m)
{
    int y = 0;
    int aux = exponenciacion_rapida(alp,x,m);
    y = (aux % m);
    return y;
}

int calcular_k(int y, int x, int m)
{
    int auxk = 0;
    int aux = exponenciacion_rapida(y,x,m);
    auxk = (aux % m);
    return auxk;
}

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
            y = ((y * y) % m)
            ex = (ex / 2);
        }
    }
    return x;
}

void DH::generador(void)
{
    
}

ostream& operator<<(ostream& os)
{
    os << "p: " << p << " α: " << alpha << " Xa: " << Xa << " Xb: " << Xb << " Ya: " << Ya << " Yb: " << Yb << " k: " << K << endl;
    return os;
}