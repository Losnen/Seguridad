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
{
    if(!es_primo(p))
    {
        cout << "El número: " << p << " no es primo, por favor introduzcalo de nuevo: ";
        cin >> p;
    }
}

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

bool DH::es_primo(int primo)
{
    int a = 0;
    for(int i = 1; i <= primo; i++)
    {
        if(primo % i==0)
            a++;
    }

    if(a == 2)
    {
        return true;
    }
    else
    {
        return false; 
    }
}


int DH::exponenciacion_rapida(int alfa, int x, int m)
{
	int ex = 1;
	int der = alfa;
		
	while(x > 0)
	{
		if(x % 2 != 0)
		{
			ex = (ex * der) % m;
			x = x - 1;
		}
			
		else
		{
			der = (der * der) % m;
			x = x / 2;
		}
	}
	return ex;
}

void DH::generador(void)
{
    Ya = exponenciacion_rapida(alpha,Xa,p);
    Yb = exponenciacion_rapida(alpha,Xb,p);
    Ka = exponenciacion_rapida(Yb,Xa,p);
}

ostream& operator<<(ostream& os, DH& a)
{
    os << "p: " << a.get_p() << " α: " << a.get_alpha() << " Xa: " << a.get_xa() << " Xb: " << a.get_xb() << " Ya: " << a.get_ya() << " Yb: " << a.get_yb() << " k: " << a.get_ka() << endl;
    return os;
}