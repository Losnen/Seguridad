#pragma once
#include <iostream>
#include <cmath>


using namespace std;

class DH
{
    private:
        
        long      p;
        long      alpha;
        long      K;
        long*     X;
        long*     Y;
        long      n;
        
    public:
        
        DH(void);
        DH(long P, long ALPHA, long num, long* x);
        ~DH(void);
        

        
        bool es_primo(long primo);
        long exponenciacion_rapida(long alp, long x, long m);
        void generador(void);
        void write(void);
};