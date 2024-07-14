//Programmer: Siming Zhang
//Programmer ID: 1712438

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <cmath>
using namespace std;

#include "pShapes.h"

//prototypes
vector<string> parseString(string);// function for parse string into tokens
int checkShape(string);// check the shape valid or not
//double tokenToNum(string);// convert token string into numbers
void fillBag(vector<string>&, vector<const Shape*>&);// function for fill the bag

int main()
{
	cout << "Programmer: Siming Zhang" << endl;// programmer's Info
	cout << "Programmer's ID: 1712438" << endl;
	cout << endl;

	ifstream fin;// intput file object
	ofstream fout;// output
	fin.open("Shapes.input.txt");// open file

	if(!fin.good()) throw "ERROR!";

	string str; // to store a single line of input from file
	vector<string> tokens; // store tokens
	vector<const Shape*> myBag; // the bag
	
	while(!fin.eof()) // first loop for getting data from input file and fill the bag
	{
		getline(fin, str);// get string from file
		tokens = parseString(str);
		if(tokens.size() != 0)// empty line
		fillBag(tokens, myBag); // fill the bag
	}

	fin.close();// close 

	// for cout loop
	for(int i = 0; i < myBag.size(); i++)
		cout << myBag[i];

	fout.open("Shapes.output.txt");// open

	// for fout loop
	for(int i = 0; i < myBag.size(); i++)
		fout << myBag[i];

	fout << "EOF";// end of file 
	fout.close();// close 

	// fourth loop for deallocation
	for(int i = 0; i < myBag.size(); i++)
		delete myBag[i];

	return 0;// end of main
}

// function
vector<string> parseString(string str)
{
	// from module 1
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

int checkShape(string shape)
{   
	// return 0 if two string are equal
	if(!shape.compare("SQUARE"))
	return 1;
	else if(!shape.compare("RECTANGLE"))
	return 2;
	else if(!shape.compare("CIRCLE"))
	return 3;
	else if(!shape.compare("TRIANGLE"))
	return 4;
	else if(!shape.compare("CUBE"))
	return 5;
	else if(!shape.compare( "BOX"))
	return 6;
	else if(!shape.compare("CYLINDER"))
	return 7;
	else if(!shape.compare( "PRISM"))
	return 8;
	else if (!shape.compare( "EOF"))
	return -1;
	else
	return 0;
}

// functions for fill the bag
void fillBag(vector<string>& tokens, vector<const Shape*>& myBag)
{
	switch(checkShape(tokens[0]))
	{
		case -1://EOF
			break;

		case 0://invalid shape
			cout << tokens[0] << " invalid object\n";
			break;

		case 1://square
			myBag.push_back(new Square(tokens));
			break;

		case 2:// rectangle
			myBag.push_back(new Rectangle(tokens));
			break;

		case 3:// circle
			myBag.push_back(new Circle(tokens));
			break;

		case 4:// triangle
			myBag.push_back(new Triangle(tokens));
			break;

		case 5:// cube
			myBag.push_back(new Cube(tokens));
			break;

		case 6:// box
			myBag.push_back(new Box(tokens));
			break;

		case 7:// cylinder
			myBag.push_back(new Cylinder(tokens));
			break;

		case 8:// prism
			myBag.push_back(new Prism(tokens));
			break;
	}
}