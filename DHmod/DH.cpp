#include "DH.h"

DH::DH(void):
p(0),
alpha(0),
K(0),
X(),
Y(),
n(0)
{}

DH::DH(long P, long ALPHA, long num, long* x):
p(P),
alpha(ALPHA),
K(0),
X(),
Y(),
n(num)
{
    if(!es_primo(p))
    {
        cout << "El número: " << p << " no es primo, por favor longroduzcalo de nuevo: ";
        cin >> p;
    }
    
    X = new long[n];
    Y = new long[n];
    X = x;
}

DH::~DH(void)
{}

bool DH::es_primo(long primo)
{
    long a = 0; 
    for(long i = 1; i <= primo; i++)
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


long DH::exponenciacion_rapida(long alfa, long x, long m)
{
	long ex = 1;
	long der = alfa;
		
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
    for (long i = 0; i < n; i++) 
    {
         Y[i] = exponenciacion_rapida(alpha,X[i],p);
    }
   
    K = exponenciacion_rapida(Y[1],X[0],p);
}

void DH::write(void)
{
    cout << "P: " << p << " alpha: " << alpha;
    for (long i = 0; i < n; i++) 
    {
         cout << " X" << (i + 1) << ": " << X[i] << " Y" << (i + 1) <<": " << Y[i] << " "; 
    }
    cout << "K: " << K << endl;
}