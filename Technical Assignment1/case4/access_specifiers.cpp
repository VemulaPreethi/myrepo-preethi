#include <iostream>

#include<string.h>

using namespace std;

class base//base class

{

 	private:

        int J;

 	protected:

 	    int K;

 	public:

 	    int L;

 	base() //base constructor

 	{

 	   J = 1;

 	   K = 2;

 	   L = 3;

 	}

};

class derived:private base//k and l becomes private members of class derived and j remains as private 					

{

 	public:

 	    void showdata()

 	    {

 	        cout << "Using Accessmode as private " << endl;

            cout << "j cannot be not accessible because we declared as private"<<endl;

            cout <<  "value of k is"<<K<<endl;

            cout <<  "value of l is"<<L<<endl;

 	    }

};

class derived1:protected base//k and l becomes protected members of class derived1 and j remains as private 

{

 	public:

 	    void showdata()

 	    {

 	        cout<<"Using Accessmode as protected"<< endl;

 	        cout <<"j is not Accessible because we declared as private"<< endl;

            cout <<"value of k is"<<K<<endl;

            cout <<"value of l is"<< L << endl;

 	    }

};

class derived2:public base//k and l becomes public members of class derived2 and j remains as private 

{

 	public:

 	    void showdata()

 	    {

 	        cout<<"Using Accessmode as public"<<endl;

 	        cout<<"j is not Accessible because we declared as private" << endl;

            cout<<"value of k is"<<K<<endl;

            cout<<"value of l is"<<L<<endl;

 	    }

};

int main(int argc,char *argv[])

{

    if(argc>=2)

    {

	    if(strcmp(argv[1],"-h")==0)//if loop for comparing the input string with "-h"				

	    {

            cout<<"	usage of access specifiers	"<<endl;

	    }

    }

	else

	{

		derived a;//derived object creation

    	derived1 b;

    	derived2 c;

    	a.showdata();//accessing data using object

    	b.showdata();

    	c.showdata();

    	return 0;

	}

}
