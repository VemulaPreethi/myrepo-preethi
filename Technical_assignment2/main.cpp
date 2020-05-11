#include<bits/stdc++.h>
#include"decryption.h"
#include"encryption.h"
#include<iostream>
#include<string.h>
#include<fstream>
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
        Encryption eobj;
        Decryption dobj;
        if(strcmp(argv[1],"-e")==0)
        {
            if(strcmp(argv[2],"-f")==0)
            {
                eobj.encrypt(argv[5]);
                return 0;
            }
            else if(strcmp(argv[2],"-k")==0)
            {
                eobj.encrypt(argv[3]);
            }
        }
       else if(strcmp(argv[1],"-d")==0)
        {
            
            if(strcmp(argv[2],"-f")==0)
            {
                dobj.decrypt(argv[5]);
                return 0;
            }
            else if(strcmp(argv[2],"-k")==0)
            {
                dobj.decrypt(argv[3]);
                return 0;
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
