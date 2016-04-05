#include "AES.h"

rijndael_t::rijndael_t(void):
iBlock_(),
kBlock_(),
intermediateState_(),
oBlock_(),
sBox_(),
multMatrix_()
{
    initialization();
}

rijndael_t::rijndael_t(bitset<8> texto[TAM]):
iBlock_(),
kBlock_(),
intermediateState_(),
oBlock_(),
sBox_(),
multMatrix_()
{
    iBlock_ = new bitset<8> [TAM];
    kBlock_ = new bitset<8> [TAM];
    intermediateState_ = new bitset<8> [TAM];
    oBlock_ = new bitset<8> [TAM];
    string inputB, inputK;
    
    unsigned char s[256] =
    {
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
    };
    
    unsigned char r[10] =
    {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
    };
    
    for (int i = 0; i < 40; i++)
    {
        rCon_[i].reset();
        if (i<10)
        {
            rCon_[i] = r[i];
        }
    }

    for (int i = 0; i < 256; i++)
    {
        sBox_[i] = s[i];
    }
    
    multMatrix_[0] = 2; multMatrix_[1] = 3;
    multMatrix_[2] = 1; multMatrix_[3] = 1;
    multMatrix_[4] = 1; multMatrix_[5] = 2;
    multMatrix_[6] = 3; multMatrix_[7] = 1;
    multMatrix_[8] = 1; multMatrix_[9] = 1;
    multMatrix_[10] = 2; multMatrix_[11] = 3;
    multMatrix_[12] = 3; multMatrix_[13] = 1;
    multMatrix_[14] = 1; multMatrix_[15] = 2;

   /*unsigned char iB[TAM] =
    {
        0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
    };*/
    
    unsigned char iK[TAM] =
    {
        0xc7, 0x38, 0xe1, 0x83, 0x44, 0x56, 0xf9, 0x15, 0xf3, 0x7e, 0x20, 0x8d, 0x90, 0x34, 0x1b, 0x2b
    };
    
    for (int i = 0; i < TAM; i++)
    {
        iBlock_[i] = texto[i];
        kBlock_[i] = iK[i];
    }
}

rijndael_t::~rijndael_t(void)
{
    memoryRelease();
}

void rijndael_t::initialization(void)
{
    iBlock_ = new bitset<8> [TAM];
    kBlock_ = new bitset<8> [TAM];
    intermediateState_ = new bitset<8> [TAM];
    oBlock_ = new bitset<8> [TAM];
    string inputB, inputK;
    
    unsigned char s[256] =
    {
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
    };
    
    unsigned char r[10] =
    {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
    };
    
    for (int i = 0; i < 40; i++)
    {
        rCon_[i].reset();
        if (i<10)
        {
            rCon_[i] = r[i];
        }
    }

    for (int i = 0; i < 256; i++)
    {
        sBox_[i] = s[i];
    }
    
    multMatrix_[0] = 2; multMatrix_[1] = 3;
    multMatrix_[2] = 1; multMatrix_[3] = 1;
    multMatrix_[4] = 1; multMatrix_[5] = 2;
    multMatrix_[6] = 3; multMatrix_[7] = 1;
    multMatrix_[8] = 1; multMatrix_[9] = 1;
    multMatrix_[10] = 2; multMatrix_[11] = 3;
    multMatrix_[12] = 3; multMatrix_[13] = 1;
    multMatrix_[14] = 1; multMatrix_[15] = 2;

    unsigned char iB[TAM] =
    {
        0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
    };
    unsigned char iK[TAM] =
    {
        0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
    };
    
    for (int i = 0; i < TAM; i++)
    {
        iBlock_[i] = iB[i];
        kBlock_[i] = iK[i];
    }
}

void rijndael_t::memoryRelease(void)
{
    delete [] iBlock_;
    iBlock_ = NULL;
    delete [] kBlock_;
    kBlock_ = NULL;
    delete [] intermediateState_;
    intermediateState_ = NULL;
    delete [] oBlock_;
    oBlock_ = NULL;
}

int rijndael_t::pos(int i, int j, int n)
{
    return i*n+j;
}

void rijndael_t::addRoundKey(bitset<8> m1[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        intermediateState_[i] = m1[i] ^ kBlock_[i];
    }
    cout << endl;
    
    cout << "Estado intermedio 1 (AddRoundKey): " << endl;
    for (int i = 0; i < TAM/4; i++)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            cout << hex << intermediateState_[pos(j,i,N)].to_ulong() << " ";
        }
        
        cout << endl;
    }
}

void rijndael_t::byteSub(bitset<8> m1[TAM])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            bitset<8> aux1;
            bitset<4> left;
            bitset<4> right;
            
            aux1 = m1[pos(j,i,N)];
            istringstream bit_stream(aux1.to_string());
            bit_stream >> left;
            bit_stream >> right;
            
            m1[pos(j,i,N)] = sBox_[pos(left.to_ulong(),right.to_ulong(),S)];
        }
        
    }
    
    for (int i = 0; i < TAM; i++)
    {
        intermediateState_[i] = m1[i];
    }
    
    cout << "Estado intermedio 2 (ByteSub): " << endl;
    for (int i = 0; i < TAM/4; i++)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            cout << hex << intermediateState_[pos(j,i,N)].to_ulong() << " ";
        }
        
        cout << endl;
    }
    cout << endl;
}

void rijndael_t::shiftRow()
{
    int cnt = 0;
    while(cnt < 4)
    {
        bitset<8> aux1, aux2, aux3;
        if(cnt == 1)
        {
            aux1 = intermediateState_[pos(0,1,N)];
            for (int i = 0; i < 3; i++)
            {
                intermediateState_[pos(i,1,N)] = intermediateState_[pos(i+1,1,N)];
            }
            intermediateState_[pos(3,1,N)] = aux1;
        }
        else if (cnt == 2)
        {
            aux1 = intermediateState_[pos(0,2,N)];
            aux2 = intermediateState_[pos(1,2,N)];
            for (int i = 0; i < 3; i++)
            {
                intermediateState_[pos(i,2,N)] = intermediateState_[pos(i+2,2,N)];
            }
            intermediateState_[pos(2,2,N)] = aux1;
            intermediateState_[pos(3,2,N)] = aux2;
        }
        else if (cnt == 3)
        {
            aux1 = intermediateState_[pos(0,3,N)];
            aux2 = intermediateState_[pos(1,3,N)];
            aux3 = intermediateState_[pos(2,3,N)];
            for (int i = 0; i < 3; i++)
            {
                intermediateState_[pos(i,3,N)] = intermediateState_[pos(i+3,3,N)];
            }
            intermediateState_[pos(1,3,N)] = aux1;
            intermediateState_[pos(2,3,N)] = aux2;
            intermediateState_[pos(3,3,N)] = aux3;
        }
        cnt++;
    }
    
    cout << "Estado intermedio 3 (ShiftRow): " << endl;
    for (int i = 0; i < TAM/4; i++)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            cout << hex << intermediateState_[pos(j,i,N)].to_ulong() << " ";
        }
        
        cout << endl;
    }
    cout << endl;
}

void rijndael_t::mixColumn(void)
{
    bitset<8> row[4];
    bitset<8> a[4];
    bitset<8> b[4];
    bitset<8> h;
    bitset<8> aux = 0x80;
    bitset<8> aux2 = 0x1b;
    
    int i = 0;
    
    while(i < TAM/4)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            row[j] = intermediateState_[pos(i,j,N)];
            a[j] = row[j];
            h = row[j] & aux;
            b[j] = row[j] <<1;
            if(h == aux)
            {
                b[j] ^= aux2;
            }
        }

        for (int j = 0; j < TAM/4; j++)
        {
            if(j == 0)
            {
                intermediateState_[pos(i,j,N)] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1];
            }
            if(j == 1)
            {
                intermediateState_[pos(i,j,N)] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2];
            }
            if(j == 2)
            {
                intermediateState_[pos(i,j,N)] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3];
            }
            if(j == 3)
            {
                intermediateState_[pos(i,j,N)] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0];
            }
        }
        i++;
    }

    cout << "Estado intermedio 4 (MixColumn): " << endl;
    for (int i = 0; i < TAM/4; i++)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            cout << hex << intermediateState_[pos(j,i,N)].to_ulong() << " ";
        }
        
        cout << endl;
    }
    cout << endl;
}

void rijndael_t::keyExpansion(int inx)
{
    bitset<8> aux;
    bitset<8> copykBlock[TAM];
    bitset<8> newkBlock[TAM];
    
    for (int i = 0; i < TAM; i++)
    {
        copykBlock[i] = kBlock_[i];
    }
    
    aux = copykBlock[pos(3,0,N)];
    for (int i = 0; i < 3; i++)
    {
        copykBlock[pos(3,i,N)] = copykBlock[pos(3,i+1,N)];
    }
    copykBlock[pos(3,3,N)] = aux;
    
    for (int i = 0; i < 4; i++)
    {
        bitset<4> left;
        bitset<4> right;
            
        aux = copykBlock[pos(3,i,N)];
        istringstream bit_stream(aux.to_string());
        bit_stream >> left;
        bit_stream >> right;
            
        copykBlock[pos(3,i,N)] = sBox_[pos(left.to_ulong(),right.to_ulong(),S)];
    }
    for (int j = 0; j < TAM/4; j++)
    {
        newkBlock[pos(0,j,N)] = copykBlock[pos(0, j, N)] ^ copykBlock[pos(3, j, N)] ^ rCon_[pos(j, inx, R)];
    }
    
    for (int i = 0; i < TAM/4; i++)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            newkBlock[pos(i+1, j, N)] = newkBlock[pos(i, j, N)] ^ kBlock_[pos(i+1, j, N)];
        }
    }
    
    for (int i = 0; i < TAM; i++)
    {
        kBlock_[i] = newkBlock[i];
    }
    
    cout << "Subclave 1: " << endl;
    for (int i = 0; i < TAM/4; i++)
    {
        for (int j = 0; j < TAM/4; j++)
        {
            cout << hex << newkBlock[pos(j,i,N)].to_ulong() << " ";
        }
        
        cout << endl;
    }
    cout << endl;
}

void rijndael_t::writeInput(void)
{
    cout << "----- INPUT ----------------------------------------------------------"<< endl;
    cout << "|                                                                    |"<< endl;
    cout << "| Bloque de entrada: ";
    for (int i = 0; i < TAM; i++)
    {
        cout << hex << iBlock_[i].to_ulong() << " ";
    }
    cout << " |"<< endl;
    cout << "| Clave:             ";
    for (int i = 0; i < TAM; i++)
    {
        cout << hex << kBlock_[i].to_ulong() << " ";
    }
    cout << " |"<< endl;
    cout << "|                                                                    |"<< endl;
    cout << "----------------------------------------------------------------------"<< endl;
    cout << endl;
}

void rijndael_t::encryptionProcess(void)
{
    writeInput();
    addRoundKey(iBlock_);
    
    int cnt = 0;
    
    while (cnt < 9)
    {
        cout << cnt << endl;
        
        byteSub(intermediateState_);
        shiftRow();
        mixColumn();
        keyExpansion(cnt);
        addRoundKey(intermediateState_);
        
        cnt++;
    }

    byteSub(intermediateState_);
    shiftRow();
    keyExpansion(9);
    addRoundKey(intermediateState_);
}

bitset<8>* rijndael_t::get_cifrado(void)
{
    return intermediateState_;
}
        