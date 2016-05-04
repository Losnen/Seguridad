//
//  RSA.cpp
//  RSA
//
//  Created by Samuel Ramos barroso on 26/4/16.
//  Copyright © 2016 Samuel Ramos barroso. All rights reserved.
//

#include "RSA.hpp"

RSA::RSA(long P, long Q, long D, string M):
d(D),
p(P),
q(Q),
n(0),
phi(0),
e(0),
mensaje(M)
{
    
    phi = (p-1) * (q-1);
    n = p * q;
    euclides(d, phi);
    if(lehman_peralta(p))
    {
        cout << "Ha longroducido numeros compuestos" << endl;
    }
    
    cout << "Mensaje: " << mensaje << endl << endl;
    cout << "Phi: " << phi << endl;
    cout << "q: " << q << endl;
    cout << "p: " << p << endl;
    cout << "n: " << n << endl;
    cout << "e: " << e << endl;
}

RSA::~RSA(void)
{}

bool RSA::lehman_peralta(long primo)
{
    long v[5] = {2,3,5,7,11};
    long a[100];
    long r[100];
    long cnt[3];
    
    for(long i = 0; i < 5; i++)
    {
        if(p == v[i])
        {
            return true;
        }
        if(primo % v[i] == 0)
        {
            return false;
        }
    }
    
    srand(time(NULL));
    
    for(long i = 0; i < 100; i++)
    {
        a[i] = rand() % (primo-2) + 2;
        r[i] = exponenciacion_rapida(a[i], ((primo-1)/2), primo);
        
    }
    
    for(long i = 0; i < 100; i++)
    {
        if(r[i] == 1)
        {
            cnt[0]++;
        }
        
        else if(r[i] == -1)
        {
            cnt[1]++;
        }
    }
    
    if(cnt[0] == 100)
    {
        return false;
    }
    
    else if(cnt[0] < 100 && cnt[1] >= 1)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

long RSA::exponenciacion_rapida(long alfa, long x, long m)
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

long RSA::euclides(long a, long b)
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
        if(z[i-1] < 0)
        {
            z[i-1] = phi + z[i-1];
        }
        
        e = z[i-1];
        return true;
    }
    
    return false;
}

void RSA::cifrar(void)
{
    long i = 0;
    while(n > pow(26,i))
    {
        i++;
    }
    
    bloque = i - 1;
    
    mensaje = quitar_espacios(mensaje);
    
    m_decimal = new long[mensaje.size()];
    resultado = new long[mensaje.size() / bloque];
    
    cout << "Tamaño de bloque: " << bloque << endl;
    
    long aux = 0;
    long j = bloque;
    long cnt = 0;
    
    for(long k = 0; k < mensaje.size(); k++)
    {
        m_decimal[k] = mensaje[k] - 65;
    }
    
    for(long k = 0; k < mensaje.size(); k++)
    {
        while(j-1 >= 0)
        {
            aux += m_decimal[k+cnt] * pow(26,j-1);
            j--;
            cnt++;
        }
        k+=(bloque-1);
        cnt = 0;
        resultado[k/bloque] = aux;
        aux = 0;
        j = bloque;
    }
    
    cout << endl << "Codificación numérica: ";
    for(long k = 0; k < mensaje.size() / bloque; k++)
    {
        cout << resultado[k] << " ";
    }
    cout << endl;
    
    
    for(long k = 0; k < mensaje.size() / bloque; k++)
    {
        resultado[k] = exponenciacion_rapida(resultado[k], e, n);
    }
    
    cout << endl <<"Cifrado final: ";
    for(long k = 0; k < mensaje.size() / bloque; k++)
    {
        cout << resultado[k] << " ";
    }
    cout << endl;
    
}

void RSA::descifrar(void)
{
    long descifrado[mensaje.size() / bloque];
    
    for(long k = 0; k < mensaje.size() / bloque; k++)
    {
        descifrado[k] = exponenciacion_rapida(resultado[k], e, n);
    }
    
    for(long k = 0; k < mensaje.size() / bloque; k++)
    {
        cout << descifrado[k] << " ";
    }
    cout << endl;
    
}

string RSA::quitar_espacios (string cad)
{
    string aux;
    aux.clear();
    for (long i = 0; i < cad.size(); i++)
    {
        
        if (cad[i]!=' ')
        {
            aux+= cad[i];
        }
    }
    
    return aux;
}



