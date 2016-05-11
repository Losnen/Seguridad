//
//  FiatShamir.hpp
//  Fiat-Sharmi
//
//  Created by Samuel Ramos barroso on 10/5/16.
//  Copyright © 2016 Samuel Ramos barroso. All rights reserved.
//

#ifndef FiatShamir_hpp
#define FiatShamir_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

class FiatShamir
{
    private:
    
        int     p;
        int     q;
        int     s;
        int     it;
        int     n;
        int     v;
        int*    x;
        int*    y;
        int*    e;
        int*    a;
    
    
    public:
    
        FiatShamir(int P, int Q, int S, int IT);
        ~FiatShamir(void);
    
        bool lehman_peralta(long primo);
        long exponenciacion_rapida(long alp, long x, long m);
        bool euclides(long a, long b);
        void generar(void);
        bool verificar(void);
        void imprimir(void);
};
#endif /* FiatShamir_hpp */
