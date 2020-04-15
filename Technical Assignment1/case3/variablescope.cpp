#include<iostream>

#include<string.h>

#include<stdlib.h>

using namespace std;

int iGvar = 5;           //global variable 

inline void display()        // accesing of variable

{ 

	cout<<iGvar<<endl; 

} 

int main(int argc,char *argv[])        // main function

{

    if(argc>2) 

	{

		if(strcmp(argv[1],"-h")==0)     //created help command

        {

			cout<<"\n Usage of file --> \n"

				"\t filename.exe & enter"<<endl<<

				" Program used to demonstrate Variable Scope "<<endl;

		}	

	}

	else

	{

	   	cout<<"Global value: ";         // prints the var iGar

		display();  

		iGvar=55;       // changing value of iGvar by assigning value locally


		cout<<"Local value: ";    //declaring local variable with same name as global variable (uses precedence)

		display(); 

	} 

}
