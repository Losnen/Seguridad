//
//  RSA.hpp
//  RSA
//
//  Created by Samuel Ramos barroso on 26/4/16.
//  Copyright © 2016 Samuel Ramos barroso. All rights reserved.
//

#ifndef RSA_hpp
#define RSA_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

const char ABC[] = {'A','B','C','D','E','F','G','H','I','J',
			 'K','L','M','N','O','P','Q','R','S','T',
			 'U','V','W','Y','Z'};

class RSA
{
    private:
    
        long     d;
        long     p;
        long     q;
        long     n;
        long     phi;
        long     e;
        long     bloque;
        string  mensaje;
        long*    m_decimal;
        long*    resultado;
    
    public:
    
        RSA(long P, long Q, long D, string M);
        ~RSA(void);
    
        bool lehman_peralta(long primo);
        long exponenciacion_rapida(long alp, long x, long m);
        long euclides(long a, long b);
        void cifrar(void);
        void descifrar(void);
        string quitar_espacios(string a);

};


#endif /* RSA_hpp */
