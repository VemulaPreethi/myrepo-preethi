
#include<iostream>
//including the container
//#include<vector>
#include<list>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class student{
    char c_Key[500];
    char c_Value[100];
public:
	void getkey()
    {
        cout<<"Enter key:";
        getchar();
        cin.get(c_Key,500,'\n');
    }
	void getvalue()
    {
        cout<<"Enter value:";
        getchar();
        cin.get(c_Value,100,'\n');
    }
	char* outkey()
    {
        return c_Key;
    }
	char* outvalue()
    {
        return c_Value;
    }
    void display()
    {
        cout<<c_Key<<"\t"<<c_Value<<endl;
    }
};
void removefile()
{
    student s;
    int iCount;
    ifstream in("note.ini",ios::in);
    while(1)
    {
        //reading the contents in file
        in.read((char*)&s,sizeof(s));
        iCount++;
        //checking for end of file
        if(in.eof())break;
    }
    if(iCount==0)
    {
        cout<<"file is removed"<<endl;
        //to remove file
        remove("note.ini");
    }
}
int searchupdate(list<student> &std,char* cOption)
{
    student s;
    //iterator creation to go word to word in file
    vector<student>:: iterator it;
    //inorder to write updated value opened in write mode
    ofstream outfile("note.ini",ios::trunc|ios::out);
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),cOption)==0)
        {
            //the value is been deleted
            std.erase(it);
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            //the new value is pushed into file
            std.push_back(s);
            return 1;
        }
    }
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        //the file again written with updated values
        outfile<<s.outkey()<<"="<<s.outvalue()<<endl;
    }
    outfile.close();
}


void addtofile(list<student> &std)
{
    student s;
    vector<student>:: iterator it;
    char cOption='y';
    while(cOption=='y')
    {
        ofstream outfile("note.ini",ios::trunc|ios::out);
        s.getkey();
        if(searchupdate(std,s.outkey())==1)
            //checking for if the key is already present in the file or not
            cout<<"updated"<<endl;
        else
        {
            s.getvalue();
            std.push_back(s);
            for(it=std.begin();it!=std.end();it++)
            {
                s=*it;
                outfile<<s.outkey()<<"="<<s.outvalue()<<endl;
            }
        }
        cout<<"Do you want to append student data(y/n)?";
        cin>>cOption;
        outfile.close();
    }
}
void deletefromfile(list<student> &std)
{
    char ckey[500];
    student s;
    vector<student>:: iterator it;
    ofstream outfile("note.ini",ios::trunc|ios::out);
    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,500,'\n');
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),ckey)==0)
        {
            std.erase(it);
            cout<<"Deleted"<<endl;
        }
    }
    removefile();
    for(it=std.begin();it!=std.end();it++)
    {
            s=*it;
            outfile<<s.outkey()<<"="<<s.outvalue()<<"\n";
    }
    outfile.close();
}
void showfromfile()
{
    student s;
    ifstream in("note.ini",ios::in);
    char cdata[500];
    if(!in.eof())
    {
        in.getline(cdata,500);
        cout<<cdata<<endl;
    }
}
void searching(list<student> &std)
{
    student s;
    char cCheck;
    char cSearch_key[500];
    char cSearch_value[100];
    vector<student>:: iterator it;
    ifstream in("note.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>cCheck;
    if(cCheck=='k')
    {
        cout<<"Enter key u want to search:";
        getchar();
        cin.get(cSearch_key,500,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_key,s.outkey())==0)
                cout<<s.outkey()<<"="<<s.outvalue()<<endl;
        }
    }
    else if(cCheck=='v')
    {
        cout<<"Enter value u want to search:";
        getchar();
        cin.get(cSearch_value,100,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_value,s.outvalue())==0)
                cout<<s.outkey()<<"="<<s.outvalue()<<endl;
        }
    }
    else
        cout<<"Enter k or v"<<endl;
}

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
        vector<student> std;
        vector<student>:: iterator it;
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.add 2.delete 3.display 4.search 5.exit"<<endl;
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
