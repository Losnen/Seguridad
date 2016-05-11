//
//  main.cpp
//  Fiat-Sharmi
//
//  Created by Samuel Ramos barroso on 10/5/16.
//  Copyright © 2016 Samuel Ramos barroso. All rights reserved.
//

#include <iostream>
#include "FiatShamir.hpp"

int main(void)
{
    cout <<"Práctica 9 de SSI: Fiat Shamir" << endl;

    FiatShamir A(7,5,3,2);
    FiatShamir B(683,811,43215,1);
    
    A.generar();
    A.verificar();
    A.imprimir();
    
    B.generar();
    B.verificar();
    B.imprimir();
}
