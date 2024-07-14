#include <iostream>
using namespace std;

// function prototype
void sum(int, int);

int main() 
{
	sum(2, 2);
	return 0;
}

void sum(int a, int b) 
{
	cout << (a + b);
}