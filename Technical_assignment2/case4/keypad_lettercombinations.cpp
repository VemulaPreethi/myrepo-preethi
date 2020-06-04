/* filename          :     keypad_lettercombinations.cpp
   program name      :     Program that gives the possible combinations of 
                            the letters in the phone keypad.
   written by        :     preethi
    date             :     29/05/2020
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std; 
class keypad_lettercombinations
{
    
private:
 
//Function to return a vector that contains all the generated letter combinations 
vector<string> letterCombinationsUtil(const int number[], 
                                      int i_size, 
                                      const string table[]) 
{ 
    // To store the generated letter combinations 
    vector<string> list; 
    queue<string> q; 
    q.push(""); 
    while (!q.empty()) { 
        string s = q.front(); 
        q.pop(); 
        // If complete word is generated pushing it in the list
        if (s.length() == i_size) 
            list.push_back(s); 
        else
            //Trying all possible letters for current digit  in number[] 
            
            for (auto letter : table[number[s.length()]]) 
                q.push(s + letter); 
    } 
    // Returning the generated list 
    return list; 
} 

// Function that creates the mapping and 
// calls letterCombinationsUtil
public:
void letterCombinations(const int number[], int i_size) 
{ 
    // table[i] stores all characters that 
    // corresponds to ith digit in phone 
    string table[10] 

        = { "", "", "abc", "def", "ghi", "jkl", 

            "mno", "pqrs", "tuv", "wxyz" }; 

    vector<string> list 

        = letterCombinationsUtil(number, i_size, table); 
    // Print the contents of the vector 
    for (auto word : list) 
        cout << word << " "; 
} 
};

int main(int argc,char *argv[])      
{
    if(argc>2) 
	{
	    //creating help command
		if(strcmp(argv[1],"-h")==0)     
        {
		cout<<"\n Usage of file --> \n"<<endl;
		cout<<" Program used to demonstrate types of modifiers"<<endl;
	}	
}
else
{ 
    keypad_lettercombinations keypadletters;
     int no_of_numb;
    cout<<"Enter no of digits you want to check the combination"<<endl;
    cin>>no_of_numb;
    int number[no_of_numb];
    for(int icount=0;icount<no_of_numb;icount++)
    {
        cout<<"Enter the number:"<<endl;
        cin>>number[icount];
        //does not take the number which is less than 2 and greater than 9
        if((number[icount]<2)|| (number[icount]>9))
        {
        cout<<"There is no alphabetical format for that number"<<endl;
        cout<<"choose a number from  2 to 9"<<endl;
        icount=icount-1;
        }
    }
    
    int i_size = ((sizeof(number)) / (sizeof(number[0]))); 
    
    keypadletters.letterCombinations(number, i_size); 
    return 0; 
}
