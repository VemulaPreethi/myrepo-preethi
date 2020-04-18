#include<string.h>

#include<stdlib.h>

using namespace std;



// global variable 

int iGlobal = 5; 



// variable accessed from 

inline display() 

{ 

	cout<<iGlobal<<endl; 

} 



// main function

int main(int argc,char *argv[])

{

    if(argc>2) 

	{

		if(strcmp(argv[1],"-h")==0)     
