#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

class A5_t
{
    private:
    
        bitset<8>*       R1_;               //Primer Registro
        bitset<8>*       R2_;               //Segundo Registro.
        bitset<8>*       R3_;               //Tercer Registro.
        
    public:
    
        A5_t(void);
        ~A5_t(void);

};