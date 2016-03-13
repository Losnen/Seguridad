#include "A5.h"

int main(int argc, char* argv[])
{
    char* input_file = argv[1];

    if (input_file!=NULL)
    {
        int sz;
        cout << "Introduzca el número de bits que desea generar: ";
        cin >> sz;
        
        A5_t A(input_file,sz);
        A.generar();
    }
    else
    {
        cout << "Error en la apertura del fichero" << endl;
        cout << "Este programa implementa la función de línea de comandos, por favor vuelva a ejecutar con el siguiente formato: " << endl;
        cout << "./a5 nombre_fichero.txt" << endl;
    }
}