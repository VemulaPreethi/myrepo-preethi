#include<iostream>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Employee{

    char c_Key[500];
    char c_Value[100];
public:
    //getting key as input
    void getkey()
    {
        cout<<"Enter key:";
        getchar();
        cin.get(c_Key,500,'\n');
    }

//getting value as input

void getvalue()

    {
        cout<<"Enter value:";
        getchar();

        cin.get(c_Value,100,'\n');
    }

//returning key 

    char* outkey()
    {
        return c_Key;

    }

    //returning value
    char* outvalue()

    {
        return c_Value;
    }

 //displaying key and value

    void display()
    {
        cout<<c_Key<<"\t"<<c_Value<<endl;
    }
};

//removing file if file is empty
void removefile()
{
    Employee e;
    int iCount=0;
    ifstream in("notes.ini",ios::in);
    while(1)
    {
        //reading the contents in file
        in.read((char*)&e,sizeof(e));
        iCount++;

        //checking for end of file

        if(in.eof())break;

    }

    if(iCount==0)

    {

        cout<<"file is removed"<<endl;

        //to remove file

        remove("notes.ini");

    }

}

//adding records to fieand storing them in a vector

void addtofile(vector<Employee> &std)

{

    Employee e;

    vector<Employee>:: iterator it;

    char cOption='y';

    while(cOption=='y')

    {

        //checking for if the key is already present in the file or not

        ofstream outfile("notes.ini",ios::trunc|ios::out);
        e.getvalue();

        {

            e.getvalue();

            std.push_back(e);

            for(it=std.begin();it!=std.end();it++)

            {
                e=*it;
                outfile<<e.outkey()<<"="<<e.outvalue()<<endl;
            }

        }

        cout<<"Do you want to add more data(y/n)?";
        cin>>cOption;

        outfile.close();
    }

}

//deleting record from file

void deletefromfile(vector<Employee> &std)

{

    char ckey[500];
    Employee e;
    int iCount=0;

    vector<Employee>:: iterator it;

    ofstream outfile("notes.ini",ios::trunc|ios::out);

    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,500,'\n');
    for(it=std.begin();it!=std.end();it++)
    {

        e=*it;
        if(strcmp(e.outkey(),ckey)==0)

        {
                std.erase(it);
                cout<<"Deleted"<<endl;
                break;

        }

    }

    removefile();

    for(it=std.begin();it!=std.end();it++)
    {

        e=*it;
        outfile<<e.outkey()<<"="<<e.outvalue()<<'\n';
    }

    outfile.close();

}

//displaying contents in the file

void list()
{
    Employee e;
    ifstream in("notes.ini",ios::in);
    char cdata[500];

    while(!in.eof())
    {

        in.getline(cdata,500);
        cout<<cdata<<endl;

    }

    removefile();

}


