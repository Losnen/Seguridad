#include "vigenere_t.h"

using namespace std;

int main (void)
{
    vigenere_t A("ESTE MENSAJE SE AUTODESTRUIRA", "MISION");
    
    A.cifrar();
}