/*file name     :   privatemem_var.cpp
  program name  :   Program to initialize in private memeber variable in a different way
  written by    :   preethi
  date          :   15/4/2020
  */

#include<iostream>
#include<string.h>
using namespace std;

class A//class Declaration

{

    private://private data member

    int a,c;
    double b,d;

    public:
    A() : a{1},b{2} //directly initialize our member variables
    { }

    A(int a1,double b1):c{a1},d{b1}//directly initialize our member variables
    { }
    void print()//print function
    {
        cout<<c<<endl<<d<<endl;
    }
    void display()//display function
    {
        cout<<a<<endl<<b<<endl;
    }
};

int main(int argc,char **argv)
{
    if(argc == 2 && strcmp(argv[1], "-h")==0)// creating help command 
    {

        cout<<"The main purpose of this program is to how to use & Declare Different way to initialize the private member variables in a class"<<endl;
    }
    else
    {
        A ob;

        ob.display();// trying to access private data member directly outside the class

        A A(10,20.12);//c=10,d=20.12

        A.print();

    }
    return 0;
}
