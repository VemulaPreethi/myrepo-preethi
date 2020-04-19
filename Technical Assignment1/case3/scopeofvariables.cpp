/* filename          :     scopeofvariables.cpp
   program name      :     Program that explains scope of variables.
   written by        :     preethi
    date             :     12/04/2020

*/
#include<iostream>
#include<string.h>
using namespace std;
//declaring global variable
int iGlobal=10;

void display() 
{ 
    int iLocal=20;
    
    //can access global variable anywhere in the program
    cout<<"Global value  :  "<<iGlobal<<endl;
    
    //only accessed within the function
    cout<<"Local value   :  "<<iLocal<<endl;

} 

int main(int argc,char *argv[])        // main function
{
    if(argc>2) 
	{
		if(strcmp(argv[1],"-h")==0)     //creating help command
        {
			cout<<"\n Usage of file --> \n"<<endl;
			cout<<" Program used to demonstrate Variable Scope "<<endl;
		}	
	}
    else
    {
        
        //declaring  local variable with same name as that of global variable 
        int iGlobal=5;
        
        //compiler gives preference to local variable
        cout<<"local varaibale declared with same name as global variable    :   "<<iGlobal<<endl; 
        display();
    
    
        //changing lobal variable from  main 
        iGlobal=20;
        cout<<"Global value after changing   :   "<<iGlobal<<endl;
    }
}
