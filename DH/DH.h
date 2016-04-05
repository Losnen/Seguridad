#pragma once
#include <iostream>
#include <cmath>


using namespace std;

class DH
{
    private:
        
        int     p;
        int     alpha;
        int     Ka;
        int     Kb;
        int     Xa;
        int     Xb;
        int     Ya;
        int     Yb;
        
    public:
        
        DH(void);
        DH(int P, int ALPHA, int XA, int XB);
        ~DH(void);
        
        int get_p(void);
        int get_alpha(void);
        int get_ka(void);
        int get_kb(void);
        int get_xa(void);
        int get_xb(void);
        int get_ya(void);
        int get_yb(void);
        
        int calcular_y (int alp, int x, int m);
        int calcular_k(int y, int x, int m);
        int exponenciacion_rapida(int base, int ex);
        void generador(void);
        
        friend ostream& operator<<(ostream& os, DH&);
        
};