/*file name	:	construct_destructor_using_virtual.cpp
  program name	:	Order of construction and destruction of objects using virtual 
  written by	:	preethi
  date		:	16/04/2020
  */
#include<iostream>
#include<string.h>
using namespace std;

class A //class creation
{
public:
    A() {
    }
    virtual void virtual_function()//virtual function 
	{
        cout<<"A::virtual_function called"<<endl;
    }
    virtual ~A()//virtual destructor 

    {

    }

};

class B : public A 
{
public:
    // override virtual function in A
    void virtual_function()
    {
        cout<<"B::virtual_function called"<<endl;
    }
};

int main(int argc, char **argv)
{
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
    {
        cout<<"This program desribes the Order of  construction and destruction of objects with virtual  "<<endl;
    }
    else{
    // Call to virtual_function during construction doesn't

    // behave like normal virtual function call.

    // Print statement shows it invokes A::virtual_function,

    // even though we are constructing an instance of B, not A.

     B obj;


    // This call behaves like a normal virtual function call.

    // Print statement shows it invokes B::virtual_function.

    obj.virtual_function();

}

}
