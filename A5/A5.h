#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;


const int MAX1 = 19;
const int MAX2 = 22;
const int MAX3 = 23;

class A5_t
{
    private:
    
        vector<int>     R1;                //Primer Registro
        vector<int>     R2;                //Segundo Registro.
        vector<int>     R3;                //Tercer Registro.
        
    public:
    
        A5_t(void);
        ~A5_t(void);
        void leer_fichero(char fichero[]);  //Lectura de fichero 
        
        int polinomio_1(void);              //Retorna el XOR con los valores del polinomio 1.
        int polinomio_2(void);              //Retorna el XOR con los valores del polinomio 2.
        int polinomio_3(void);              //Retorna el XOR con los valores del polinomio 3.
        int z(void);                        //Retorna el XOR de las posiciones 0 de los polinomios 1,2 y 3.
        
        void desplazar_1(void);              //Desplaza el Registro 1.
        void desplazar_2(void);              //Desplaza el Registro 2.
        void desplazar_3(void);              //Desplaza el Registro 3.
        
        void iniciar_r1 (string cad);       //Inicia el Registro 1 con la lectura del fichero
        void iniciar_r2 (string cad);       //Inicia el Registro 2 con la lectura del fichero
        void iniciar_r3 (string cad);       //Inicia el Registro 3 con la lectura del fichero
        
        
};