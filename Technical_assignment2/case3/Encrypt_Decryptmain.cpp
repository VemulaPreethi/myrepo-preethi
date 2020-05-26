/*filename      :   "Encrypt_Decryptmain.cpp"
  functionality :    main function for the program is written in this file 
  written by    :   preethi
  date          :   25/05/2020
  */
#include "Encrypt_Decrypt.h"
#include <iostream>
#include<string.h>

using namespace std;

int main(int argc,char *argv[])
{
    for(int iargcount=1;iargcount<=argc;iargcount++)
    {
        if(strcmp(argv[iargcount],"-h")==0)
       {
            cout<<"Enter -e to encrypt data or -d to decrypt data ";
            cout<<"followed by -f [filename] and -k [key] or viceversa ";
            return 0;
        }
        else if(strcmp(argv[iargcount],"-e")==0)
        {
            
            if((strcmp(argv[iargcount+1],"-f")==0 && strcmp(argv[iargcount+3],"-k")==0))
            {
                Encrypt_Decrypt encryptdecrypt;
                if(encryptdecrypt.Encryption(argv[iargcount+4],argv[iargcount+2])==1)
              cout<<"Your file has been encrypted"<<endl;
              else
              cout<<"Failed to encrypt!"<<endl;  
            }
           else if((strcmp(argv[iargcount+3],"-k")==0 && strcmp(argv[iargcount+1],"-f")==0)) 
           {
               
                Encrypt_Decrypt encryptdecrypt;
                if(encryptdecrypt.Encryption(argv[iargcount+2],argv[iargcount+4])==1)
              cout<<"Your file has been encrypted"<<endl;
              else
              cout<<"Failed to encrypt!"<<endl;  
           }
        }
        else if(strcmp(argv[iargcount],"-d")==0)
        {
         if((strcmp(argv[iargcount+1],"-f")==0 && strcmp(argv[iargcount+3],"-k")==0))
         {
             Encrypt_Decrypt encryptdecrypt;
             if(encryptdecrypt.Decryption(argv[iargcount+4],argv[iargcount+2])==1)
             cout<<"Your file has been decrypted"<<endl;
             else
             cout<<"Failed to decrypt!"<<endl; 
         }
        else if((strcmp(argv[iargcount+3],"-k")==0 && strcmp(argv[iargcount+1],"-f")==0)) 
        {
            Encrypt_Decrypt encryptdecrypt;
            if(encryptdecrypt.Encryption(argv[iargcount+2],argv[iargcount+4])==1)
            cout<<"Your file has been decrypted"<<endl;
            else
            cout<<"Failed to decrypt!"<<endl;  
         }
        }
        else
        {
            cout<<"you have entered wrong format!!"<<endl;
            cout<<"check -h for more help"<<endl;
            return 0;
        }
    }
}
