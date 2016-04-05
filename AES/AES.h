#pragma once
#include <iostream>
#include <cstdlib>
#include <bitset>
#include <string>
#include <sstream>

#define TAM 16                                  //Para bloques de 128 bits utilizaremos matrices de tamaño 16
#define N 4
#define S 16
#define R 10

using namespace std;

class rijndael_t
{
    private:
    
        bitset<8>*  iBlock_;                    //Vector que simula una matriz y contiene el bloque de entrada.
        bitset<8>*  kBlock_;                    //Vector que simula una matriz y contiene la clave.
        bitset<8>*  intermediateState_;         //Matriz de estados intermedios.
        bitset<8>*  oBlock_;                    //Vector que simula una matriz y contiene el bloque de salida.
        bitset<8>   sBox_[256];                 //S-Caja.
        bitset<8>   multMatrix_[16];            //Matriz para multiplicación en MixColumn.
        bitset<8>   rCon_[40];                  //Rijndael key schedule.s
        
    public:
    
        rijndael_t(void);
        rijndael_t(bitset<8> texto[TAM]);
        ~rijndael_t(void);
        
        void addRoundKey(bitset<8> m1[TAM]);    //XOR entre el bloque de entrada y la clave original de cifrado.
        void byteSub(bitset<8> m1[TAM]);        //Sustitución no lineal de los bytes de la matriz de estado basada en una S-Caja que para cada byte genera un nuevo byte.
        void shiftRow(void);                    //Consiste en desplazar a la izquierda los bytes de las filas que conforman la matriz del estado actual.
        void mixColumn(void);                   //Intercambio de columnas.
        void keyExpansion(int);                 //Método que realiza la expansión de clave.
        
        void writeInput(void);                  //Método que muestra por pantalla los datos de entrada.
        void writeProcess(void);                //Método que muestra por pantalla los resultados de las operaciones intermedias.
        
        bitset<8>* get_cifrado(void);
        
        void encryptionProcess(void);           //Método que controla el ciclo completo del algoritmo de Rijndael.
    private:
        int pos(int, int, int);                 //Función que devuelve la posición k del vector del elemento (i,j) de la matriz.
        void initialization(void);              //Método que inicializa todos los atributos.
        void memoryRelease(void);               //Método que libera la memoria utilizada en la ejecución.
};