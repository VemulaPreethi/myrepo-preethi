#include"function.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(int argc,char* argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"select required option"<<endl;
        }
    }
    else
    {
        vector<Employee> std;
        vector<Employee>:: iterator it;
        char cOpt;
        while(1)
        {
            cout<<"Select your option:"<<endl<<"1.add"<<endl<<"2.delete"<<endl<<"3.display"<<endl <<"4.search "<<endl<<"5.exit"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                       addtofile(std);
                        break;
                case '2':

                        deletefromfile(std);
                        break;
                case '3':
                        showfromfile();
                        break;
                case '4':
                        searching(std);
                        break;
                case '5':
                            exit(0);
                default:
                        return 0;
            }
        }
    }
    
    return 0;
}
