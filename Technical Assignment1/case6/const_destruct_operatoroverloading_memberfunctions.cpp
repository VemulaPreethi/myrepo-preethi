/*filename      :   case6.cpp
  program name  :   program that describes  constructors/destructor/operator overloading/member functions.
  written by    :   preethi
  date          :   18/04/2020
  */

#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Data
{
//private member variables
private:
	char cName[20];
	int *iVal;
public:
	//default constructor
	Data()
	{
		cout<<"Default constructor invoked"<<endl;
	}
	//parametrized constructor
	Data(char *name)
	{
		cout<<"Parametrised constructor invoked"<<endl;
		strcpy(cName,name);//coping string
	}
	//Displaying value
	void DisplayValue()
	{
		cout<<"value: "<<*iVal<<endl;
	
	}
	//displaying name
	void DisplayName()
	{
	    	cout<<"Name: "<<cName<<endl;
	}
	

	//overloading oprator'+'
	Data operator+(Data s)
	{
	    Data temp=cName;
		strcat(temp.cName,s.cName);	//adding two strings
		return temp;
	}
	//setValue function
	void setValue(int *inum)
	{
		iVal=inum;
	}

	//destructor 
	~Data()
	{
		cout<<"Destructor invoked"<<endl;
	}
};

int main(int argc,char **argv)
{
	if(argc==2) 
	{
		if(strcmp(argv[1],"-h")==0)     //created a help command
        {
			cout<<"\n Usage of file --> \n"
					"\t filename.exe & enter"<<endl<<
					"\t Program used to access pointer to integer and char variables. "<<endl<<
					"\t insert an integer and any two strings. ";
		}	
	}
	else
	{	
		int in; //declaring integer value
		char first_name[30],last_name[30]; //declaring character value
		cout<<"enter integer value:";
		cin>>in;
		cout<<"First Name: ";
		cin>>first_name;
		cout<<"Last Name: ";
		cin>>last_name;
		//object declaration for class "Name"
		Data obj1;
		Data obj2=(first_name);
		Data obj3=(last_name);
		obj1=obj2+obj3;
		
		Data obj4;
		obj4.setValue(&in);
		
		obj4.DisplayValue();
		obj1.DisplayName();
	}
}
