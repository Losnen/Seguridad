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
    
        bitset<MAX1>    R1;                     //Primer Registro
        bitset<MAX2>    R2;                     //Segundo Registro.
        bitset<MAX3>    R3;                     //Tercer Registro.
        bitset<MAX1>    R1m;                     //Primer Registro
        bitset<MAX2>    R2m;                     //Segundo Registro.
        bitset<MAX3>    R3m;                     //Tercer Registro.
        bitset<64>      k;               
        bitset<1>*      resultado_;             //Secuencia resultante
        int             sz_;                    //Número de bits a generar
        bitset<1>*      mensaje_;               //Mensaje a cifrar
        bitset<1>*      cifrado_;               //Mensaje cifrado 
        
    public:
    
        A5_t(char* input, int sz);              //Constructor donde se inicializan los Registros a 0 y posteriormente se lee del fichero
        ~A5_t(void);
    
        void generar(void);                     //Generador de secuencia.
        void write(void);                       //Imprime la secuencia
        
        void my_xor(void);                      //XOR entre el mensaje y la clave
        void resultado_xor(void);               //Imprime el resultado del XOR
        
        void modificacion(void);
        void mostrarmodificacion(void);
        
    private: 
    
        void leer_fichero(char* fichero);       //Lectura de fichero 
        
        bitset<1> polinomio_1(void);            //Retorna el XOR con los valores del polinomio 1.
        bitset<1> polinomio_2(void);            //Retorna el XOR con los valores del polinomio 2.
        bitset<1> polinomio_3(void);            //Retorna el XOR con los valores del polinomio 3.
        bitset<1> z(void);                      //Retorna el XOR de las posiciones 0 de los polinomios 1, 2 y 3.
        bitset<1> mayoria(void);                //Funcion que determina la mayoría
        
        void desplazar_1(void);                 //Desplaza el Registro 1.
        void desplazar_2(void);                 //Desplaza el Registro 2.
        void desplazar_3(void);                 //Desplaza el Registro 3.
        
        

};