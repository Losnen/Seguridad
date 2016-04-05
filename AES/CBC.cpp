#include "CBC.h"

CBC_t::CBC_t(void)
{
    vector_ini_ = new bitset<8>[TAM];
    texto_plano_ = new bitset<8>[TAM];
    texto_plano2_ = new bitset<8>[TAM];
    texto_cifrado_ = new bitset<8>[TAM];
    
    unsigned char iB[TAM] =
    {
        0xe8, 0xb1, 0x1b, 0xea, 0x4a, 0x65, 0x9a, 0x7e, 0x22, 0x4f, 0x92, 0x4b, 0xda, 0x8d, 0x72, 0x39
    };
    
    unsigned char iA[TAM] =
    {
        0xda, 0x47, 0x51, 0x74, 0x9a, 0x1d, 0x45, 0xc9, 0x2b, 0x11, 0x43, 0x22, 0xe5, 0x10, 0x36, 0x65
    };
    
    for (int i = 0; i < TAM; i++)
    {
        texto_plano2_[i] = iA[i];
        texto_plano_[i] = iB[i];
        vector_ini_[i] = false;
    }
}

CBC_t::~CBC_t(void)
{}

int CBC_t::pos(int i, int j, int n)
{
    return i*n+j;
}

void CBC_t::generar(void)
{
    bitset<8> aux[TAM];
    
    for (int i = 0; i < TAM; i++)
    {
        aux[i] = vector_ini_[i] ^ texto_plano_[i];
    }
    
    
    rijndael_t A(aux);
    A.encryptionProcess();
    texto_cifrado_ = A.get_cifrado();
    
    int auxc = 0;
    cout << endl << "Primera Matriz" << endl;
    for (int i = 0; i < (TAM/4); i++)
    {
        for (int j = 0; j < (TAM/4); j++)
        {
            cout << hex << texto_cifrado_[pos(j,i,N)].to_ulong() << " ";
            
        
        }
        cout << endl;
    }
    
    for (int i = 0; i < TAM; i++)
    {
        aux[i] = 0; 
        aux[i] = texto_cifrado_[i] ^ texto_plano2_[i];
    }
    
    rijndael_t B(aux);
    B.encryptionProcess();
    texto_cifrado_ = B.get_cifrado();
    
    cout << endl << "Segunda matriz" << endl;
    for (int i = 0; i < (TAM/4); i++)
    {
        for (int j = 0; j < (TAM/4); j++)
        {
            cout << hex << texto_cifrado_[pos(j,i,N)].to_ulong() << " ";
            
        
        }
        cout << endl;
    }
    
}

void CBC_t::cipher_stealing(void)
{
    bitset<8> blq1[TAM];
    bitset<8> blq2[TAM];
    bitset<8>* cifr;
    cifr = new bitset<8> [TAM];
    bitset<8>* cifr_ult;
    cifr_ult = new bitset<8> [TAM];
    bitset<8>* aux;
    aux = new bitset<8> [TAM];
    bitset<8>* aux2;
    cifr_ult = new bitset<8> [TAM];
    
    unsigned char B1[TAM] =
    {
        0xe8, 0xb1, 0x1b, 0xea, 0x4a, 0x65, 0x9a, 0x7e, 0x22, 0x4f, 0x92, 0x4b, 0xda, 0x8d, 0x72, 0x39
    };
    
    unsigned char B2[TAM] =
    {
        0xda, 0x47, 0x51, 0x74, 0x9a, 0x1d, 0x45, 0xc9, 0x2b, 0x11, 0x43, 0x22, 0xe5, 0x10, 0 , 0
    };
    
    for (int i = 0; i < TAM; i++)
    {
        blq1[i] = B1[i];
        blq2[i] = B2[i];
    }
    
    rijndael_t A(blq1);
    A.encryptionProcess();
    cifr = A.get_cifrado();
    
    for (int i = 0; i < TAM; i++)
    {
        if(B2[i] == 0)
        {
            blq2[i] = cifr[i];
        }
        
    }
    
    cout << endl << "Padding:" << endl;
    for (int i = 0; i < (TAM/4); i++)
    {
        for (int j = 0; j < (TAM/4); j++)
        {
            cout << hex << blq2[pos(j,i,N)].to_ulong() << " ";
            
        
        }
        cout << endl;
    }
    
    
    rijndael_t B(blq2);
    B.encryptionProcess();
    cifr_ult = B.get_cifrado();
    
    cout << "Realizando intercambio..." << endl;
    
    aux = cifr;
    aux2 = cifr_ult;
    
    cifr = aux2;
    cifr_ult = aux;
    
    cout << "Intercambio realizado." << endl;
    
    cout << endl << "Último:" << endl;
    for (int i = 0; i < (TAM/4); i++)
    {
        for (int j = 0; j < (TAM/4); j++)
        {
            cout << hex << cifr[pos(j,i,N)].to_ulong() << " ";
            
        
        }
        cout << endl;
    }
    
    cout << endl << "Penúltimo: " << endl;
    for (int i = 0; i < (TAM/4); i++)
    {
        for (int j = 0; j < (TAM/4); j++)
        {
            cout << hex << cifr_ult[pos(j,i,N)].to_ulong() << " ";
            
        
        }
        cout << endl;
    }
    
    
    
    
    
}
