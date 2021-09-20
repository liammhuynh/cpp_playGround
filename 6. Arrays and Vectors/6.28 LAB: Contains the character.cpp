/* Write a program that reads an integer, a list of words, and a character. The integer signifies how many words are in the list. 
The output of the program is every word in the list that contains the character at least once. For coding simplicity, follow each output word by a comma, even the last one. 
Assume at least one word in the list will contain the given character.
Ex: If the input is:
4 hello zoo sleep drizzle z
then the output is:
zoo,drizzle,
To achieve the above, first read the list into a vector. Keep in mind that the character 'a' is not equal to the character 'A'. */



#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    string st;char c;
    vector<string> arr;
    vector<string> op;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        arr.push_back(st);
    }
    cin>>c;
    for(int i=0;i<arr.size();i++)
    {
        
        if(arr[i].find(c)!=string::npos)
            op.push_back(arr[i]);
    }
    for(int i=0;i<op.size();i++)
    {
        cout<<op[i]<<",";
    }
}
