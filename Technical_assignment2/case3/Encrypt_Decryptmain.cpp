
#include "Encrypt_Decrypt.h"
#include <iostream>
#include<string.h>

using namespace std;

int main(int argc, char *argv[])
{
     if(argc==2)
    {
         //created a help command
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"Enter -e to encrypt data or -d to decrypt data ";
            cout<<"followed by -f [filename] and -k [key] or viceversa ";
            return 0;
        }
    }
    else if(argc>2)
    {
        Encrypt_Decrypt encryptdecrypt;
        if(strcmp(argv[1],"-e")==0)
        {
           if(strcmp(argv[2],"-f")==0 && strcmp(argv[4],"-k")==0)
            {
              if(encryptdecrypt.Encryption(argv[5],argv[3])==1)
              cout<<"Your file has been encrypted"<<endl;
              else
              cout<<"Failed to encrypt!"<<endl;  
            }
            else if(strcmp(argv[2],"-k")==0 && strcmp(argv[4],"-f")==0)
            {
                if(encryptdecrypt.Encryption(argv[3],argv[5])==1)
              cout<<"Your file has been encrypted"<<endl;
              else
              cout<<"Failed to encrypt!"<<endl;  
            }
        }
       else if(strcmp(argv[1],"-d")==0)
        {
            
            if(strcmp(argv[2],"-f")==0 && strcmp(argv[4],"-k")==0)
            {
                if(encryptdecrypt.Decryption(argv[5],argv[3])==1)
              cout<<"Your file has been decrypted"<<endl;
              else
              cout<<"Failed to decrypt!"<<endl; 
            }
            else  if(strcmp(argv[2],"-k")==0 && strcmp(argv[4],"-f")==0)
            {
             if(encryptdecrypt.Encryption(argv[3],argv[5])==1)
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
