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
      //creating help command
        if(strcmp(argv[iargcount],"-h")==0)
       {
            cout<<"Enter -e to encrypt data or -d to decrypt data ";
            cout<<"followed by -f [filename] and -k [key] or viceversa ";
            return 0;
        }
      //checking if the user option is encryption
        else if(strcmp(argv[iargcount],"-e")==0)
        {
          //checking filename and key
            if((strcmp(argv[iargcount+1],"-f")==0 && strcmp(argv[iargcount+3],"-k")==0))
            {
              //creating object for the class to proceed encryption
                Encrypt_Decrypt encryptdecrypt;
                if(encryptdecrypt.Encryption(argv[iargcount+4],argv[iargcount+2])==1)
              cout<<"Your file has been encrypted"<<endl;
              else
                //if the file fails to encrypt
              cout<<"Failed to encrypt!"<<endl;  
            }
          //filename and key can be given viceversa followed by -e
           else if((strcmp(argv[iargcount+3],"-k")==0 && strcmp(argv[iargcount+1],"-f")==0)) 
           {
               
                Encrypt_Decrypt encryptdecrypt;
                if(encryptdecrypt.Encryption(argv[iargcount+2],argv[iargcount+4])==1)
              cout<<"Your file has been encrypted"<<endl;
              else
              cout<<"Failed to encrypt!"<<endl;  
           }
        }
      //checking if the user wants to decrypt the file
        else if(strcmp(argv[iargcount],"-d")==0)
        {
          //checking for filename and key
         if((strcmp(argv[iargcount+1],"-f")==0 && strcmp(argv[iargcount+3],"-k")==0))
         {
           //creating object for the class
             Encrypt_Decrypt encryptdecrypt;
             if(encryptdecrypt.Decryption(argv[iargcount+4],argv[iargcount+2])==1)
             cout<<"Your file has been decrypted"<<endl;
             else
               //if it fails to decrypt
             cout<<"Failed to decrypt!"<<endl; 
         }
          //user can give filename and key viceversa followed by -d
        else if((strcmp(argv[iargcount+3],"-k")==0 && strcmp(argv[iargcount+1],"-f")==0)) 
        {
            Encrypt_Decrypt encryptdecrypt;
            if(encryptdecrypt.Encryption(argv[iargcount+2],argv[iargcount+4])==1)
            cout<<"Your file has been decrypted"<<endl;
            else
            cout<<"Failed to decrypt!"<<endl;  
         }
        }
      //if the user option does not match any of the format
        else
        {
            cout<<"you have entered wrong format!!"<<endl;
            cout<<"check -h for more help"<<endl;
            return 0;
        }
    }
}
