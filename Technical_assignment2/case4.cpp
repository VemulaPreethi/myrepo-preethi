// C++ implementation of the approach 
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std; 
  
// Function to return a vector that contains 
// all the generated letter combinations 
vector<string> letterCombinationsUtil(const int number[], 
                                      int n, 
                                      const string table[]) 
{ 
    // To store the generated letter combinations 
    vector<string> list; 
  
    queue<string> q; 
    q.push(""); 
  
    while (!q.empty()) { 
        string s = q.front(); 
        q.pop(); 
  
        // If complete word is generated 
        // push it in the list 
        if (s.length() == n) 
            list.push_back(s); 
        else
  
            // Try all possible letters for current digit 
            // in number[] 
            for (auto letter : table[number[s.length()]]) 
                q.push(s + letter); 
    } 
  
    // Return the generated list 
    return list; 
} 
  
// Function that creates the mapping and 
// calls letterCombinationsUtil 
void letterCombinations(const int number[], int n) 
{ 
  
    // table[i] stores all characters that 
    // corresponds to ith digit in phone 
    string table[10] 
        = { "", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz" }; 
  
    vector<string> list 
        = letterCombinationsUtil(number, n, table); 
  
    // Print the contents of the vector 
    for (auto word : list) 
        cout << word << " "; 
  
 
} 
  
// Driver program 
int main() 
{ 
     int no_of_numb;
    
    cout<<"Enter no of digits you want to check the combination"<<endl;
    cin>>no_of_numb;
    int number[no_of_numb];
    cout<<"Enter digits"<<endl;
    for(int icount=0;icount<no_of_numb;icount++)
    {
        cout<<"Enter the numbers:"<<endl;
        cin>>number[icount];
    }
    //int number[] = { 2, 3 }; 
    int n = ((sizeof(number)) / (sizeof(number[0]))); 
    cout<<n<<endl;
    letterCombinations(number, n); 
  
    return 0; 
}
