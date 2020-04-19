/*file name	:	storageclasses.cpp
  program name	:	Program that explains storage classes
  written by	:	preethi
  date		:	13/04/2020
  */
#include<iostream>
#include<string.h>
using namespace std;
//declaring variable for extern
int i_var;
int Storageclasses()
{ 
    //takes no returntype
    auto a_var=3;
    
    //declaring it as extern
    extern int i_var;
    //initializing extern variable
    i_var=5;
    
    register char c_var='R';
    
    cout<<"--------------------Storage classes------------------"<<endl;
    
    cout<<"Auto variable        :    "<<a_var<<endl;
    cout<<"Extern variable      :    "<<i_var<<endl;
    cout<<"Register variable    :    "<<c_var<<endl;
    
}

// Function containing static variables 
// memory is retained during execution 
int staticFun() 
{ 
    cout << "For static variables  :    "; 
    static int count = 0;  
    count++; 
    return count; 
} 
  
// Function containing non-static variables 
// memory is destroyed 
int nonStaticFun() 
{ 
    cout<<"For Non-Static variables  :  ";
  
    int count = 0; 
    count++; 
    return count; 
} 
int main(int argc,char *argv[])       
{
    if(argc>2) 

	{
	        //creating help command
		if(strcmp(argv[1],"-h")==0)    
        {
			cout<<"\n Usage of file --> \n"<<endl;
			cout<<" Program used to demonstrate types of storage classes"<<endl;
		}	
	}
    else
    {
    Storageclasses();
    
    // Calling the static parts 
    cout<<staticFun()<<endl;
    cout<<staticFun()<<endl;
  
    // Calling the non-static parts 
    cout << nonStaticFun() <<endl;
    cout << nonStaticFun() <<endl;
    }
    return 0;      
}
