/* filename	: case1.cpp
   program name	: Decrypting data after verification of key 
   written by	: preethi
   date		: 10/05/2020
*/
#include<bits/stdc++.h> 
#include<iostream>
#include<string.h>
#include<fstream>
#include<cstring>
using namespace std; 
class Decryption
{
    public:
    string str;
   string skey;
   
    void decrypt(char* key,char* filename) 
    { 
    //opening input file
    ifstream myfile ("encrypt.txt");
   string str;
   string skey;
  
   //opening output file
   ofstream outfile ("decrypt.txt");
  if (outfile.is_open())
  {
       string key_value=key;
		   if (myfile.is_open())
		   {
		      //key verification
		      getline (myfile,skey);
		 if(strcmp(filename,"encrypt.txt")==0)
		 {
		    
	   if(strcmp(key_value.c_str(),skey.c_str())==0)
			{
			    //while end of samplefile
			while (myfile)
				
			    {
			        //taking line by line until end of file
				    for(int p=0;p<=100;p++)
				{
				getline (myfile,str);
					
				 //logic  for decrypting data	
					int len=str.length();
                	int iword=0;
        	            for(int icount=0;icount<len;icount++)
                	    {
	        	            if(str[icount]=='$')
	            	        {
			                    reverse(str.begin()+iword,str.begin()+icount);
		            	        str[icount]=' ';
		            	        iword=icount+1;
	        	            }
		                    else if(icount==len-1)
	            	        {
			
		        	            reverse(str.begin()+iword,str.end());
		                    }
	                    }
	               //writing the result to the file     
                 outfile<<str<<endl;
	             break;				
				}//end of for loop
			 }//end of while loop
	   	}//end of if (keyverification)
			else
			{
			    cout<<"you have entered wrong key"<<endl;
			}
		myfile.close();	
		 }//closing if(verifyfilename)
		 else
		 {
		     cout<<"you have entered wrong filename"<<endl;
		 }
	}//end of input file
	
	//if the file is not open		
		else
		{
		    cout<<"cannot open file"<<endl; 
		}
		outfile.close();
  }//closing outfile
  //if the file is not open 
else
{
    cout << "Unable to open file";
}

}
//end of class
};
