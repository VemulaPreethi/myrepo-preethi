#ifndef Encrypt_Decrypt_h
//checking the file is defined or not
#define encryptDecrypt_h
//defining the header file

#include <iostream>

using namespace std;

/*Declaring and initializing variables that are to be used in Encryption and Decryption methods
  destructing memory after the completion of processing*/

class Encrypt_Decrypt
{
    int icount;
    int len;
    char calph_neu;
    int iword;
    
public:
    Encrypt_Decrypt()
    {
        icount=0;
        len=0;
        
        iword=0;
        calph_neu='0';
    }
    ~Encrypt_Decrypt()
    {
       
    }
    bool Encryption(char*,char*);
    bool Decryption(char*,char*);
};

#endif
