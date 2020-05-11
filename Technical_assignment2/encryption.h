#include<bits/stdc++.h> 
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std; 
class Encryption
{
    public:
     string str;
     //to store an alphanuemeric character
     char cvar;
     
 /* Function  :   encrypt
  Usage     :   to encrypt the data from sample text file
*/

  void encrypt(char* ckey) 
    { 
        //opening sample for reading data
        ifstream myfile ("inputfile.txt");
  
        //asking user an alphaneumeric character to replace space
        cout<<"enter an alphaneumeric character:";
        cin>>cvar;
   
        //opening file to write encrypted data
         ofstream outfile ("encrypt.txt");
        if (outfile.is_open())
         {
            //setting the key for further decryption
             outfile<<ckey<<endl;
 	        if (myfile.is_open())
		     {
				    while (! myfile.eof())	
			        {
			        //to continue line by line
				        for(int p=0;p<=20;p++)
			        	{
		                  //gets first line of the file
				        	getline (myfile,str);
				
			    	        //logic for for encrypting data	
				            int len=str.length();
	                        int iword=0;	
        	                for(int icount=0;icount<len;icount++)
            	             {
	        	                if(str[icount]==' ')
	            	             {
			                         reverse(str.begin()+iword,str.begin()+icount);
			                      //replaces space with alphaneumeric character
		            	              str[icount]=cvar;
		            	              iword=icount+1;
	        	                 }
		                         else if(icount==len-1)
	                            {
		        	                    reverse(str.begin()+iword,str.end());
		                          }
	                         }
	                   //writes the encrypted data line by line to the outfile 
                       outfile<<str<<endl;
	                     break;				
			        	}
			    //end of file
			        }
			//closing sample file
			myfile.close();
        
	    	}
		 //if file is not open
		else
		{
		    cout<<"cannot open file"<<endl; 
		}
	outfile.close();	
   //closing outfile
    }	
   //if file is not open
 else
  {
    cout << "Unable to open file";
  }
  
 }
 //end of class
};
