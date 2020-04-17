/* filename          :     case2.cpp
   program name      :     creating formula for a given series to obtain the output.
   written by        :     preethi
    date             :     11/04/2020
*/

#include<bits/stdc++.h>

using namespace std;
//funtion to calculate
int sqsum(int n)

{
    //returning the value after calculation
    return(n*(n+1)/2)*(2*n+1)/3;
}

int main()

{

    int n=4;
    
    //calling function
    cout<<sqsum(n)<<endl;

    return 0;

}
