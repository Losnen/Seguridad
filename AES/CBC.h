#pragma once
#include <iostream>
#include <cstdlib>
#include <bitset>
#include <string>
#include <sstream>
#include "AES.h"

#define TAM 16                                  //Para bloques de 128 bits utilizaremos matrices de tamaño 16
#define N 4
#define S 16
#define R 10

using namespace std;

class CBC_t
{
    private:
        
        bitset<8>*  vector_ini_;
        bitset<8>*  texto_plano_;
        bitset<8>*  texto_plano2_;
        bitset<8>*  texto_cifrado_;
        int pos(int, int, int);
        
    public:
        
        CBC_t(void);
        ~CBC_t(void);
        
        void generar(void);
        void cipher_stealing(void);
        void write(void);
};  