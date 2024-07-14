//Programmer: Siming Zhang
//Programmer ID: 1712438
#include <iostream>
#include <set>
using namespace std;

int main() 
{
	// a set of numbers
	set <int> numbers;   
	
	// insert 
	numbers.insert(1);
	numbers.insert(2);
	numbers.insert(3);

	int min_element;
	if (!numbers.empty())
	min_element = *numbers.begin();
	
	cout << "Programmer: Siming Zhang" << endl;// programmer's Info
	cout << "Programmer's ID: 1712438" << endl;
	cout << endl;
	cout<<"The minimum is "<<min_element;// cout the min

	return 0;
}