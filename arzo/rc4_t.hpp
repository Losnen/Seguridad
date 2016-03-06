//
// rc4_t.hpp
//
// Alejandro Arzola 5/03/2016.
//
// Práctica 3 - Seguridad en Sistemas Informáticos: Implementar generador RC4.
//

#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

class rc4_t
{
private:
    int*        s_;             //Vector de estado. s_[i]={0,1,2,...,255}
    int*        c_;             //Vector con los elementos de la clave.
    int         sz_;            //Numero de elementos de la clave.
    int*        k_;             //Vector con la semilla de la clave.
    int*        entrada_;       //Vector con los elementos a cifrar.
    int         entrada_sz_;    //Numero de elementos de la entrada.
    bitset<8>*  clave_;         //Secuencia cifrante en binario.
    bitset<8>*  entrada_bin_;   //Entrada en binario.
    bitset<8>*  salida_;        //Mensaje cifrado.

public:
    rc4_t(void);        //Constructor por defecto.
    rc4_t(int, int);    //Constructor con parametros.
    ~rc4_t(void);       //Destructor.
    
    void encryptSequenceGenerator(void);    //Método de generación de secuencia cifrante.
    void inputToBinary(void);               //Método que tranforma a binario la entrada.
    void encrypt(void);                     //Método que cifra mediante un XOR.
    
    void write(void);   //Método que muestra el valor de todos los atributos privados por pantalla.

private:
    void buildVector();     //Método que reserva la memoria para el vector de estado.
    void destroyVector(void);   //Método que libera la memoria del vector de estado.
    void initialization(void);  //Método que realiza la inicialización de los vectores.
};
    