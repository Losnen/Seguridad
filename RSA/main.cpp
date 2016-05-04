//
//  main.cpp
//  RSA
//
//  Created by Samuel Ramos barroso on 26/4/16.
//  Copyright © 2016 Samuel Ramos barroso. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include "RSA.hpp"

using namespace std;

int main(void)
{
    
    cout << "Práctica 8 SSI: RSA" << endl;
    RSA A(421,7,1619,"MANDA DINEROS");
    A.cifrar();
    cout << endl;
    RSA B(2347,347,5,"AMIGO MIO");
    B.cifrar();
}
