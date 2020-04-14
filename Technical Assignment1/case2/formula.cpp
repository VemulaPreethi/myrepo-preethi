#include<bits/stdc++.h>

using namespace std;

int sqsum(int n)

{

    return(n*(n+1)/2)*(2*n+1)/3;

}

int main()

{

    int n=4;

    cout<<sqsum(n)<<endl;

    return 0;

}
