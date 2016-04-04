#include "DH.h"

DH(void):
p(0),
alpha(0),
k(0),
Xa(0),
Xb(0),
Ya(0),
Yb(0)
{}

DH(int P, int ALPHA, int K, int XA, int XB, int YA, int YB):
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
        
void generador(void)
{
    
}
void exponenciacion_rapida(int base, int ex)
{
    
}

ostream& operator<<(ostream& os)
{
    
}