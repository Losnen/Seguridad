#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double    p = 43; 
    double    alpha = 23;
    double    Ka;
    double    Kb;
    double    Xa = 25;
    double    Xb = 33;
    double    Ya;
    double    Yb;
    /*
    
    A 

    Escoge secreto Xa 

    Calcula Ya = α^Xa (mod p)

    Genera k = Yb^Xa (mod p)
     
    
    p = 43, α = 23 xA = 25, xB = 33, yA =40, yB =16, k = 4

    */
    
    Ya = fmod(pow(alpha,Xa),p); 
    Ka = fmod(pow(Ya,Xb),p); 
    cout << Ya << endl;
    cout << Ka << endl; 
     
    
}