#include <iostream>
#include <string.h>

using namespace std;

int main (void)
{
    string a = "ABC";
    string b = "DEF";
    string c;
    
    for(int i = 0; i<a.size(); i++)
    {
        c[i] = (((a[i] + b[i]) % 26) + 65);
        cout << c[i];
    }
}