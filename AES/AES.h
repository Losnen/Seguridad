#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

class AES_t
{
    private:
    
        bitset<8>*      estado_;        //Estado
        bitset<8>*      clave_;         //Clave
        bitset<8>*      scaja_;         //scaja en binario
        int             n_;             //Número de columnas
        int             m_;             //Número de filas
        
        int pos(int i, int j);          //Función que realiza la correspondencia
        bitset<8> buscar(int a);        //Busca en la S-Caja
        long primero(bitset<8> aux);    //Bits 0-4 del estado
        long segundo(bitset<8> aux);    //Bits 4-8 del estado
    
    public:
        
        AES_t(void);                //Constructor
        ~AES_t(void);
        
        void AddRoundKey(void);     //Consiste en una OR-EXCLUSIVA entre el bloque de entrada y la clave original de cifrado.
        void SubBytes(void);        //Sustitución no lineal donde cada byte es reemplazado con otro de acuerdo a una tabla de búsqueda.
        void ShiftRows(void);       //Transposición donde cada fila del «state» es rotada de manera cíclica un número determinado de veces.
        void MixColumns(void);      //Operación de mezclado que opera en las columnas del «state», combinando los cuatro bytes en cada columna usando una transformación lineal.
        
        void Cifrar(void);          //Método para cifrar
        void write(void);           //Función para imprimir por pantalla el resultado
};