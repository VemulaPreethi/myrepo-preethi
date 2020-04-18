/* filename          :     case2.cpp
   program name      :     creating formula for a given series to obtain the output.
   written by        :     preethi
    date             :     11/04/2020
*/

#include<iostream>
#include<string.h>
using namespace std;
int
SumofSquares (int inum)
{

  int isum;

  //returning the value after calculation
  isum = (inum * (inum + 1) / 2) * (2 * inum + 1) / 3;

  return isum;
   
}

int main (int argc, char *argv[])
{

  int inum;
  int iresult;

  if (argc == 2)

    {
      //created a help command

      if (strcmp (argv[1], "-h") == 0)

	    {

	        cout << "Input:Integer" << endl;

	    }

    }

     else

    {

      cout << "enter a number:";

      cin >> inum;

      if (inum > 0)

	    {

	        iresult = SumofSquares (inum);

	        cout << "Output:" << iresult;

        }

      else

	        cout << "Enter Positive Integer" << endl;

    }

  return 0;

}
