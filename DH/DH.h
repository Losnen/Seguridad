#pragma once
#include <iostream>


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
        int exponenciacion_rapida(int base, int ex);
        
        friend ostream& operator<<(ostream& os);
        
};