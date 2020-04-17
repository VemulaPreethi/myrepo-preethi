/* filename	: case1.cpp
   program name	: Finding the datatype and size of a value using commandline arguments
   written by	: preethi
   date		: 10/04/2020
*/
  
#include <iostream> 

#include<string.h>

#include<stdlib.h>

#include<typeinfo>

#include<cctype>

#include<bits/stdc++.h>

using namespace std; 

int main(int argc, char** argv) 

{ 
    //Declaring character datatype
    char ch;	
    
    //Declaring integer datatype
    int c,i;
    
    //Declaring double datatype
    double d;
	
    cout << "You have entered " << argc 

         << " arguments:" << "\n";
         	cout<<"TYPE"<<"    "<<"value"<<"  "<<"size"<<endl;
	
	//for loop to increase the i value with respect to argument counter
 for(i=1;i<argc;i++)
	  
     {
	//if condition for checking whether the value greater than zero or not
        if(argv[i]>=0)
	{
	      //atol function accepts a string and convert to integer
	       c=atoi(argv[i]);
		
	       //atof function accepts a string and convert to float
	       d=atof(argv[i]);//atof function accepts a string and convert to float

	       if(c==d) //if condition for comparing the values

	      {

                cout<<"Integer"<<"   "<<c<<"    "<<sizeof(int)<<endl;
             
	       }

	  else

	      {

		  cout<<"Double"<<"   "<<d<<"    "<<sizeof(double)<<endl;
	       }

         }

	else

	{
	 
	     ch=atoi(argv[i]);

              if((ch==1))

	     {

	   	 cout<<sizeof(char);

	      }

	   else

	    {

	   	cout<<sizeof(wchar_t);

	    }

	}
}

   return 0; 

}
