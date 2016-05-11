//
//  FiatShamir.cpp
//  Fiat-Sharmi
//
//  Created by Samuel Ramos barroso on 10/5/16.
//  Copyright © 2016 Samuel Ramos barroso. All rights reserved.
//

#include "FiatShamir.hpp"

FiatShamir::FiatShamir(int P, int Q, int S, int IT):
p(P),
q(Q),
s(S),
it(IT),
v(0),
n(0),
x(NULL),
y(NULL),
e(NULL),
a(NULL)
{
    x = new int[it];
    y = new int[it];
    e = new int[it];
    a = new int[it];
    n = p * q;
    
    for(int i = 0; i < it; i++)
    {
        cout << "Introduzca x[" << i <<"]: ";
        cin >> x[i];
        cout << "Introduzca e[" << i <<"]: ";
        cin >> e[i];
        cout << endl;
    }
    
    if(s < 0 && s > n)
    {
        cout << "S es mayor que N o menor que 0" << endl;
        exit(0);
    }
    
    if(!euclides(s, n))
    {
        cout << "S no es coprimo con N" << endl;
        exit(0);
    }
    
    v = ((s*s) % n);
    
    for(int i = 0; i < it; i++)
    {
        if(x[i] < 0 && x[i] > n)
        {
            cout << "X es mayor que N o menor que 0" << endl;
            exit(0);
        }
    }
}

FiatShamir::~FiatShamir(void)
{}

long FiatShamir::exponenciacion_rapida(long alfa, long x, long m)
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

void FiatShamir::generar(void)
{
    for(int i = 0; i < it; i++)
    {
        a[i] = ((x[i] * x[i]) % n);
        if(e[i] == 0)
        {
            y[i] = x[i] % n;
        }
        if(e[i] == 1)
        {
            y[i] = (x[i]*s) % n;
        }
        
    }
    
}

bool FiatShamir::verificar(void)
{
    for(int i = 0; i < it; i++)
    {
        a[i] = ((x[i] * x[i]) % n);
        if(e[i] == 0)
        {
            if((y[i] * y[i]) != a[i] % n)
            {
                return false;
            }
        }
        if(e[i] == 1)
        {
            if((y[i] * y[i]) != a[i] % n)
            {
                return false;
            }
        }
        
    }
    return true;
}


bool FiatShamir::euclides(long a, long b)
{
    long x[100];
    long z[100];
    
    if (a>b) {
        x[0]=a;
        x[1]=b;
    }else if (a<b) {
        x[0]=b;
        x[1]=a;
    }
    
    z[0]=1;
    z[-1]=0;
    
    int i=1;
    while ((x[i-1]%x[i])!=0) {
        x[i+1]=x[i-1]%x[i];
        z[i]=-(x[i-1]/x[i])*z[i-1]+z[i-2];
        i++;
    }
    
    if (x[i]==1)
    {
        return true;
    }
    
    return false;
}

void FiatShamir::imprimir(void)
{
    cout << "N: " << n << endl;
    cout << "V: " << v << endl;
    
    for(int i = 0; i < it; i++)
    {
        cout << "Iteración: " << i << endl;
        cout << "a: " << a[i] << endl;
        cout << "y: " << y[i] << endl;

    }
}
