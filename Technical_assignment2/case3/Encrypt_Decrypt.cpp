/*filename      :   "Encrypt_Decrypt.cpp"
  functionality :    methods declared in the header file are defiined in this 
                     file.
  written by    :   preethi
  date          :   25/05/2020
  */
#include "Encrypt_Decrypt.h"
#include <iostream>
#include<string.h>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstring>
//#include<cmath>
//#include<math.h>
using namespace std;
//method used for key encryption and decryption
//using XOR operation
string encryptdecrypt_key(string toEncrypt) {
    char key = 'K'; //Any char will work
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key;
    //returns the encrypt or decrypted key
    return output;
}
//encryption of file function
bool Encrypt_Decrypt::Encryption(char* ckey,char* filename)
{
    if(strcmp(filename,"inputfile.txt")==0)
    {
        //taking alphaneumeric value from the user to fill in space
        cout<<"enter an alphaneumeric character:";
        cin>>calph_neu;
        ifstream myfile ("inputfile.txt");
        //opening output file
        ofstream outfile ("encrypt.txt");
        
    if (myfile.is_open())
     {
     string encryptedkey = encryptdecrypt_key(ckey);
      outfile<<encryptedkey<<endl;
      outfile<<calph_neu<<endl;
      string line;
      while (! myfile.eof())	
        {
            //takes line by line
            getline (myfile,line);
            int len=line.length();
            for(icount=0;icount<len;icount++)
            {
	         if(line[icount]==' ')
	         {
			  reverse(line.begin()+iword,line.begin()+icount);
			  //replaces space with alphaneumeric character
		      line[icount]=calph_neu;
		      iword=icount+1;
	         }
		     else if(icount==len-1)
	         {
		       reverse(line.begin()+iword,line.end());
		     }
	        }
	        outfile<<line<<endl;
        }//endofwhile
      myfile.close();
    outfile.close();
    return 1;
     } //endof if
     else
     {
     cout<<"cannot open file"<<endl;
     return 0;
     }
    }//endof if checkfilename
    else
    {
        cout<<"you have entered wrong filename!"<<endl;
        return 0;
    }
}//endofmethod

//method used for decryption of encrypted file after checking the key and file name
bool Encrypt_Decrypt::Decryption(char* key,char* filename)
{
    if(strcmp(filename,"encrypt.txt")==0)
    {
       string line,skey,dummyline,salpha_neumeric,sword;
       string sinput_key=key;
       ifstream myfile("encrypt.txt");
       getline(myfile,skey);
       string decryptedkey = encryptdecrypt_key(skey);
       getline(myfile,salpha_neumeric);
        //checking the user entered key with the key set for encryption 
       if(strcmp(sinput_key.c_str(),decryptedkey.c_str())==0)
       {
        ifstream myfile ("encrypt.txt");
        //opening output file
        ofstream outfile ("decrypt.txt");
        if (myfile.is_open())
        {
            getline (myfile,dummyline);
            getline(myfile,dummyline);
             while (! myfile.eof())	
          {
            getline (myfile,line);
            //int len=line.length();
            int len=line.length();
            for(icount=0;icount<len;icount++)
            {
	         if((line[icount])==salpha_neumeric[0])
	         {
			  reverse(line.begin()+iword,line.begin()+icount);
			  //replaces alphaneumeric character with space
		      line[icount]=' ';
		      iword=icount+1;
	         }
		     else if(icount==len-1)
	         {
		       reverse(line.begin()+iword,line.end());
		     }
	        }
	        outfile<<line<<endl;
            
	       
        }//endofwhile
     
    myfile.close();
    outfile.close();
    return 1;
     } //endof if
     else
     {
     cout<<"cannot open file"<<endl;
     return 0;
     }
    }//endof if checkkey
    else
    {
        cout<<"you have entered wrong pin!"<<endl;
        return 0;
    }
}//endofif checkfilename
    else
    {
        cout<<"you have entered wrong filename!"<<endl;
    }
}//end of method
