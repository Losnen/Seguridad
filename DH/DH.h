#pragma once
#include <iostream>
#include <cmath>


using namespace std;

class DH
{
    private:
        
        int     p;
        int     alpha;
        int     k;
        int     Xa;
        int     Xb;
        int     Ya;
        int     Yb;
        
    public:
        
        DH(void);
        DH(int P, int ALPHA, int K, int XA, int XB, int YA, int YB);
        ~DH(void);
        
        void generador(void);
        int calcular_y (int alp, int x, int m);
        int calcular_k(int y, int x, int m);
        int exponenciacion_rapida(int base, int ex);
        
        friend ostream& operator<<(ostream& os);
        
};