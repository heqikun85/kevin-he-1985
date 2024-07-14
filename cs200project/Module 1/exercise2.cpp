#include <iostream>
using namespace std;
 
int sum(int, int);
 
int main ()
{
	int a = 1;
	int b = 2;
	int result;
 
	result = sum(a, b);
	cout << result << endl;
 
	return 0;
}

int sum(int a, int b)
{
	int result;
	result = a + b;
	return (result);
}