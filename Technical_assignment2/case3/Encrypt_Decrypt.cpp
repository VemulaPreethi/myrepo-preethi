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

bool Encrypt_Decrypt::Encryption(char* ckey,char* filename)
{
    if(strcmp(filename,"inputfile.txt")==0)
    {
        cout<<"enter an alphaneumeric character:";
        cin>>calph_neu;
        ifstream myfile ("inputfile.txt");
        ofstream outfile ("encrypt.txt");
        
    if (myfile.is_open())
     {
      outfile<<ckey<<endl;
      outfile<<calph_neu<<endl;
      string line;
      while (! myfile.eof())	
        {
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

bool Encrypt_Decrypt::Decryption(char* key,char* filename)
{
    if(strcmp(filename,"encrypt.txt")==0)
    {
       string line,skey,dummyline,salpha_neumeric,sword;
       string sinput_key=key;
       ifstream myfile ("encrypt.txt");
       getline (myfile,skey);
       getline(myfile,salpha_neumeric);
     
       if(strcmp(sinput_key.c_str(),skey.c_str())==0)
       {
        ifstream myfile ("encrypt.txt");
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
			  //replaces space with alphaneumeric character
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
        
  
       
    


