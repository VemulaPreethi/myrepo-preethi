/* filename	: case1.cpp
   program name	: Finding the datatype and size of a value using commandline arguments
   written by	: preethi
   date		: 10/04/2020
*/
  
#include <iostream> 
#include<string.h>
#include<stdlib.h>
#include<cmath>
using namespace std; 
int main(int argc, char** argv) 
{ 
 if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"Enter command line arguments of your choice"<<endl;
        cout<<"The main purpose of this program is to display the value and size of the datatype in which it is stored."<<endl;
    }
    else
    {
        cout<<"Type     "<<"Value       " <<"size       "<<endl;
        cout<<"---------------------------------"<<endl;
        
	for (int i = 1; i < argc; ++i)
	{
	
    if (((strlen(argv[i]))==1) && (*argv[i]>='a'&& *argv[i]<='z') || (*argv[i]>='A' && *argv[i]<='Z'))
   {
       cout<<"char      "<<argv[i]<<"       "<<sizeof(char)<<endl;
   }
   else if((strlen(argv[i]))!=1)
   {
       cout<<"string      "<<argv[i]<<"       "<<sizeof(string)<<endl;
   }
    //atoi function accepts a string and convert to integer
   else if(atoi(argv[i])>=0 && atoi(argv[i])<=9)
   {
       cout<<"Int       "<<argv[i]<<"           "<<sizeof(int)<<endl;
   }
   //atof function accepts a string and convert to float
   else if((atof(argv[i]))==(atof(argv[i])) )
   {
       cout<<"Double      "<<argv[i]<<"       "<<sizeof(double)<<endl;
       
   }
   cout << "\n" ;
	}
	return 0; 
}
}
