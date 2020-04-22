#include<iostream>

//using container

#include<vector>

#include<fstream>

#include<stdio.h>

#include<string.h>

using namespace std;

class Employee{

    char c_Key[500];

    char c_Value[100];

public:



/*Function Name :getkey

  Parameters    :no parameter

  Return Type   :no return type

  Usage         :to get the input of key the private member*/



    void getkey()

    {

        cout<<"Enter key:";

        getchar();

        cin.get(c_Key,500,'\n');

    }



/*Function Name :getvalue

  Parameters    :no parameter

  Return Type   :no return type

  Usage         :to get the input of value the private member*/



    void getvalue()

    {

        cout<<"Enter value:";

        getchar();

        cin.get(c_Value,100,'\n');

    }



/*Function Name :outkey

  Parameters    :no parameter

  Return Type   :char return type

  Usage         :to return the key*/



    char* outkey()

    {

        return c_Key;

    }



/*Function Name :outvalue

  Parameters    :no parameter

  Return Type   :string return type

  Usage         :to return value*/



    char* outvalue()

    {

        return c_Value;

    }

    void display()

    {

        cout<<c_Key<<"\t"<<c_Value<<endl;

    }

};



/*Function Name :removefile

  Parameters    :no parameter

  Return Type   :no return type

  Usage         :to remove file if file is empty*/



void removefile()

{

    Employee e;

    int iCount=0;

    ifstream in("note.ini",ios::in);

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

        remove("note.ini");

    }

}



/*Function Name :searchupdate

  Parameters    :two parameter(vector object and char)

  Return Type   :int return type

  Usage         :to update the duplicate values*/



int searchupdate(vector<Employee> &std,char* cOption)

{

    Employee e;

    //iterator creation to go word to word in file

    vector<Employee>:: iterator it;

    //inorder to write updated value opened in write mode

    ofstream outfile("note.ini",ios::trunc|ios::out);

    for(it=std.begin();it!=std.end();it++)

    {

        e=*it;

        if(strcmp(e.outkey(),cOption)==0)

        {

            //the value is been deleted

            std.erase(it);

            cout<<"Enter value to update"<<endl;

            e.getvalue();

            //the new value is pushed into file

            std.push_back(e);

            for(it=std.begin();it!=std.end();it++)

            {

                e=*it;

                //the file again written with updated values

                outfile<<e.outkey()<<"="<<e.outvalue()<<endl;

            }

            return 1;

            outfile.close();

        }

    }

}



/*Function Name :addtofile

  Parameters    :one vector object parameter

  Return Type   :no return type

  Usage         :to add records in to file and store them in to a vector*/



void addtofile(vector<Employee> &std)

{

    Employee e;

    vector<Employee>:: iterator it;

    char cOption='y';

    while(cOption=='y')

    {

        ofstream outfile("note.ini",ios::trunc|ios::out);

        e.getkey();

        if(searchupdate(std,e.outkey())==1)

            //checking for if the key is already present in the file or not

            cout<<"updated"<<endl;

        else

        {

            e.getvalue();

            std.push_back(e);

            for(it=std.begin();it!=std.end();it++)

            {

                e=*it;

                outfile<<e.outkey()<<"="<<e.outvalue()<<endl;

            }

        }

        cout<<"Do you want to append student data(y/n)?";

        cin>>cOption;

        outfile.close();

    }

}



/*Function Name :deletefromfile

  Parameters    :one vector object parameter

  Return Type   :no return type

  Usage         :to delete a record from file*/



void deletefromfile(vector<Employee> &std)

{

    char ckey[500];

    Employee e;

    int iCount=0;

    vector<Employee>:: iterator it;

    ofstream outfile("note.ini",ios::trunc|ios::out);

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



/*Function Name :showfromfile

  Parameters    :no parameter

  Return Type   :no return type

  Usage         :to display the contents in the file*/



void showfromfile()

{

    Employee e;

    ifstream in("note.ini",ios::in);

    char cdata[500];

    while(!in.eof())

    {

        in.getline(cdata,500);

        cout<<cdata<<endl;

    }

    removefile();

}



/*Function Name :searching

  Parameters    :one vector object parameter

  Return Type   :no return type

  Usage         :to search for a key or value and displaying
  */

void searching(vector<Employee> &std)

{

    Employee e;

    char cCheck;

    char cSearch_key[500];

    char cSearch_value[100];

    vector<Employee>:: iterator it;

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

            e=*it;

            if(strcmp(cSearch_key,e.outkey())==0)

                cout<<e.outkey()<<"="<<e.outvalue()<<endl;

        }

    }

    else if(cCheck=='v')

    {

        cout<<"Enter value u want to search:";

        getchar();

        cin.get(cSearch_value,100,'\n');

        for(it=std.begin();it!=std.end();it++)

        {

            e=*it;

            if(strcmp(cSearch_value,e.outvalue())==0)

                cout<<e.outkey()<<"="<<e.outvalue()<<endl;

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
