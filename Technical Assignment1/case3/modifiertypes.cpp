/* filename          :     Modifiertypes.cpp
   program name      :     Program that explains type of modifiers.
   written by        :     preethi
    date             :     12/04/2020

*/
#include<iostream>
#include<string.h>
using namespace std;

void Modifiertypes()
{
	signed iSint=-78;
	unsigned int iUSint=65479;
	long double lDou=8347659;
	short signed sSint=100;
	
	cout<<" --------------------MODIFIER TYPES------------------------"<<endl;
	cout<<"signed int value     : "<<iSint<<endl;
	cout<<"unsigned int value   : "<<iUSint<<endl;
	cout<<"long double value    : "<<lDou<<endl; 
	cout<<"short signed value   : "<<sSint<<endl;
}


int main(int argc,char *argv[])        // main function
{
    if(argc>2) 
	{
		if(strcmp(argv[1],"-h")==0)     //created help command

        {
		cout<<"\n Usage of file --> \n"<<endl;
		cout<<" Program used to demonstrate types of modifiers"<<endl;
			
	}	

}

    else
    {

    	Modifiertypes();
    	return 0;
    }
}
