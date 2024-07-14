#include<iostream>
#include <vector>
#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <sstream>
#include <algorithm>
using namespace std;
string get_input()
{
// (a) prompt the user to enter some text (with space-separated words),
cout<<"ENTER THE SOME TEXT: "<<endl;
string s;
getline(cin,s);
return s;
}
vector<string> tokernize(string s)
{ //(b) parse the text into tokens stored in an STL vector,
stringstream ss(s);
std::istream_iterator<std::string> it(ss);
std::istream_iterator<std::string> end;
std::vector<std::string> results(it, end);
return results;
}
void printTokens(vector<string> tokens)
{ //c) output the tokens to the console, one per line.
cout<<"TOKENS OF THE STRING ARE: "<<endl;
for(int i = 0; i<tokens.size();i++)
{
cout<<tokens[i]<<endl;
}
}
int main()
{
string s = get_input();
// cout<<s<<endl;
std::vector<string> tokens = tokernize(s);
printTokens(tokens);
}