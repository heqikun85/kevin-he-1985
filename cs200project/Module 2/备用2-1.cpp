#include <iostream>
#include <vector>
using namespace std;

struct Cat
{
  string age, color;
};

int main()
{
  vector<void*> cats; // the bag
  vector<string> myCatsName; // its companion array

  Cat *c = new Cat();
  cats.push_back(c);
  myCatsName.push_back("Violin");

 
  cats.push_back(c);
  myCatsName.push_back("Saxophone");

}