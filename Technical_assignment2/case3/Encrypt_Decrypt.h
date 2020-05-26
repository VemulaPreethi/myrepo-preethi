/*filename      :   "Encrypt_Decrypt.h"
  functionality :    header file for the program which contains declaration
                    of class and variables,constructors used for encryption and 
                    decryption of file.
  written by    :   preethi
  date          :   25/05/2020
  */
#ifndef Encrypt_Decrypt_h

#define encryptDecrypt_h
//defining the header file


#include <iostream>
using namespace std;

//declaring variables used in methods
class Encrypt_Decrypt
{
    int icount;
    int len;
    char calph_neu;
    int iword;
    
public:
    //initializing variables through constructor
    Encrypt_Decrypt()
    {
        icount=0;
        len=0;
        
        iword=0;
        calph_neu='0';
    }
    //destructing memory
    ~Encrypt_Decrypt()
    {}
    bool Encryption(char*,char*);
    bool Decryption(char*,char*);
};

#endif
