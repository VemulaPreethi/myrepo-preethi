*******************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;
 //class that explains public,private and protected variables
class Box {

    public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
 
    private:
      double width;
      
    protected:
      double height;
};
// SmallBox is the derived class
class SmallBox:Box { 
   public:
      void setSmallHeight( double hig);
      double getSmallHeight( void );
};
 

 
// Member functions definitions
double Box::getWidth(void) {
   return width ;
}
 
void Box::setWidth( double wid ) {
   width = wid;
}

// Member functions of child class
double SmallBox::getSmallHeight(void) {
   return height ;
}
 
void SmallBox::setSmallHeight( double hig) {
   height = hig;
}

 
int main(int argc,char *argv[])
{
    //creating help command
    if(argc>=2)
    {

	    if(strcmp(argv[1],"-h")==0)				

	    {

            cout<<"	usage of access specifiers	"<<endl;

	    }
    }

	else
    {
        
   Box box;
 
   // setting box length without member function
   box.length = 10.0; // OK: because length is public
   cout << "Length of box (public variable)     : " << box.length <<endl;
 
   // setting box width without member function
   // box.width = 10.0; // Error: because width is private
   box.setWidth(10.0);  // Using member function to set it.
   cout << "Width of box(private variable)      : " << box.getWidth() <<endl;
   
   SmallBox sbox;
 
   // setting box height using member function
   sbox.setSmallHeight(5.0);
   //ok:because height is called from derived class.
   cout << "Height of box(protected variable)   : "<< sbox.getSmallHeight() << endl;
 
   return 0;
    }

}
