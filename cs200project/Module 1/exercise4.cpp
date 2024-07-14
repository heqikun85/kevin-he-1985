#include<iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
using namespace std;

string getText()
{
  // prompt the user to enter some text.
  cout << "Write your text: " << endl;
  string s;
  getline(cin,s);
  return s;
}

// prototype
vector<string> parseString(string);

vector<string> parseString(string str)
{ 
  // parse the text into tokens stored in an STL vector.
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string> (begin, end);

}

void printTokens(vector<string> tokens)
{ 
  // output the tokens, one per line.
  cout << "Parse the text into tokens: " << endl;

  for(int i = 0; i<tokens.size();i++)
  {
    cout << "tokens[ " << i << " ] = " << "\"" << tokens[i] << "\"\n";
  }
}

int main()
{
  string s = getText();
  std::vector<string> tokens = parseString(s);
  printTokens(tokens);
}