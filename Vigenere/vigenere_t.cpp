#include "vigenere_t.h"

vigenere_t::vigenere_t(string mensaje, string clave): //Constructor
mensaje_(mensaje),
clave_(clave),
resultado_(){}

vigenere_t::~vigenere_t(void)
{}  



void vigenere_t::mayusculas(void)
{
    for(int i = 0; i < mensaje_.size(); i++)    //for para pasar a mayúsculas el mensaje y la clave.
    {
        mensaje_[i] = toupper(mensaje_[i]);
    }
    for(int i = 0; i < clave_.size(); i++)      //for para pasar a mayúsculas el mensaje y la clave.
    {
        clave_[i] = toupper(clave_[i]);
    }
}

void vigenere_t::quitar_espacios(void)
{
    string aux;
    int spc = 0;
    for(int i = 0; i < mensaje_.size(); i++)    //Recorremos la cadena y contamos el número de espacios
    {
        int toint = mensaje_[i]; 
        if(toint == 32)
        {
            spc++;
        }
    }
    
    aux.resize(mensaje_.size() - spc);          //Le damos la longitud a la nueva cadena restándole el numero de espacios
    int j = 0;
    for(int i = 0; i < mensaje_.size(); i++)    //Recorremos la cadena copiando los caracteres que no sean espacio a la nueva
    {
        int toint = mensaje_[i]; 
        if(toint != 32)
        {
            aux[j] = toint;
            j++;
        }
    }
    mensaje_.clear();
    mensaje_ = aux;
}


void vigenere_t::cifrar(void)
{
    mayusculas();
    quitar_espacios();

    int j = 0;
    resultado_.resize(mensaje_.size());
    for(int i = 0; i< mensaje_.size(); i++)
    {
        
        if(j == (clave_.size()-1))
        {
            
            resultado_[i] = (((mensaje_[i] + clave_[j]) % 26) + 65);    //Realizamos la operación de j-1
            j = 0;                                                      //Se resetea el índice de la clave a 0.
        }
        else
        {
            resultado_[i] = (((mensaje_[i] + clave_[j]) % 26) + 65);    //Realizamos la operación desde 0 hasta j-2
            j++;
        }
    
    }

    cout << "Mensaje: " << mensaje_ << endl;
    cout << "Clave: " << clave_ << endl;
    cout << resultado_ << endl;
}

void vigenere_t::descifrar(void)
{
    int j = 0;
    int a = 0;
    r_descifrado_.resize(mensaje_.size());
    for(int i = 0; i< mensaje_.size(); i++)
    {
        
        if(j == (clave_.size()-1))
        {
            a = (resultado_[i] - clave_[j]);    //Realizamos la resta para revertir la suma.
            while(a < 0)                        //Mientras a sea negativa le sumamos el módulo hasta que sea positivo.
            {
	            a = a + 26;
            }
            r_descifrado_[i] = a + 65;          
            j = 0;
        }
        else
        {  
            a = (resultado_[i] - clave_[j]);    //Realizamos la resta para revertir la suma.
            while(a < 0)                        //Mientras a sea negativa le sumamos el módulo hasta que sea positivo.
            {
	            a = a + 26;                     
            }
            r_descifrado_[i] = a + 65;
            j++;
        }
    
    }
    
   cout << "Mensaje descifrado: " << r_descifrado_ << endl;
}

void vigenere_t::modificacion(void)
{
int j = 0;
	while(j<clave_.size())
	{
		for(int i = 0; i<resultado_.size(); i++)
		{
			if(i % clave_.size() == j)
			{
				cout << resultado_[i];
			}	
		}
	cout << endl;
	j++;
	}
}







