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

#include "iShapes.h"

//prototypes
vector<string> parseString(string);// function for parse string into tokens
int checkShape(string);// check the shape valid or not
void fillBag(vector<string>&, vector<const Shape*>&, vector<int>&);// function for fill the bag

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
	vector<int> myBagType; // its companion array

	while(!fin.eof()) // first loop for getting data from input file and fill the bag
	{
		getline(fin, str);// get string from file
		tokens = parseString(str);
		if(tokens.size() != 0)// empty line
		fillBag(tokens, myBag, myBagType); // fill the bag
	}
	
	fin.close();// close

	for(int i = 0; i < myBag.size(); i++)// second loop for console output
	{
		if(myBagType[i] == 1)// Square
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			const Square& rSquare = *pSquare;
			rSquare.output(cout);
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			const Rectangle& rRectangle = *pRectangle;
			rRectangle.output(cout);
		}
		else if(myBagType[i] == 3)// Circle
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			const Circle& rCircle = *pCircle;
			rCircle.output(cout);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
			const Triangle& rTriangle = *pTriangle;
			rTriangle.output(cout);
		}
		else if(myBagType[i] == 5)// Cube
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
			const Cube& rCube = *pCube;
			rCube.output(cout);
		}
		else if(myBagType[i] == 6)// Box
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
			const Box& rBox = *pBox;
			rBox.output(cout);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			const Cylinder& rCylinder = *pCylinder;
			rCylinder.output(cout);
		}
		else if(myBagType[i] == 8)// Prism
		{
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			const Prism& rPrism = *pPrism;
			rPrism.output(cout);
		}
		else;
	}

	fout.open("Shapes.output.txt");// open

		for(int i = 0; i < myBag.size(); i++)// third loop for txt output
	{
		if(myBagType[i] == 1)// if it's Square then fout
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			const Square& rSquare = *pSquare;
			rSquare.output(fout);
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			const Rectangle& rRectangle = *pRectangle;
			rRectangle.output(fout);
		}
		else if(myBagType[i] == 3)// Circle
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			const Circle& rCircle = *pCircle;
			rCircle.output(fout);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
			const Triangle& rTriangle = *pTriangle;
			rTriangle.output(fout);
		}
		else if(myBagType[i] == 5)// Cube
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
			const Cube& rCube = *pCube;
			rCube.output(fout);
		}
		else if(myBagType[i] == 6)// Box
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
			const Box& rBox = *pBox;
			rBox.output(fout);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			const Cylinder& rCylinder = *pCylinder;
			rCylinder.output(fout);
		}
		else if(myBagType[i] == 8)// Prism
		{
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			const Prism& rPrism = *pPrism;
			rPrism.output(fout);
		}
		else;
	}

	fout << "EOF";// end of file
	fout.close();// close

	for(int i = 0; i < myBag.size(); i++)// fourth loop for deallocation
	{
		if(myBagType[i] == 1)
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			delete pSquare;
		}
		else if(myBagType[i] == 2)
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			delete pRectangle;
		}
		else if(myBagType[i] == 3)
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			delete pCircle;
		}
		else if(myBagType[i] == 4)
		{
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
			delete pTriangle;
		}
		else if(myBagType[i] == 5)
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
			delete pCube;
		}
		else if(myBagType[i] == 6)
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
			delete pBox;
		}
		else if(myBagType[i] == 7)
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			delete pCylinder;
		}
		else if(myBagType[i] == 8)
		{
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			delete pPrism;
		}
		else;
	}

	return 0;// end of main
}

// functions
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
void fillBag(vector<string>& tokens, vector<const Shape*>& myBag, vector<int>& myBagType)
{
	switch(checkShape(tokens[0]))
	{
		case -1:// EOF
			break;

		case 0:// invalid shape 
			cout << tokens[0] << " invalid object" << endl;
			break;

		case 1:// square
		{
			myBag.push_back(new Square(tokens));
			myBagType.push_back(1);
			break;
		}

		case 2:// rectangle
		{
			myBag.push_back(new Rectangle(tokens));
			myBagType.push_back(2);
			break;
		}

		case 3:// circle
		{
			myBag.push_back(new Circle(tokens));
			myBagType.push_back(3);
			break;
		}

		case 4:// triangle
		{
			myBag.push_back(new Triangle(tokens));
			myBagType.push_back(4);
			break;
		}

		case 5:// cube
		{
			myBag.push_back(new Cube(tokens));
			myBagType.push_back(5);
			break;
		}

		case 6:// box
		{
			myBag.push_back(new Box(tokens));
			myBagType.push_back(6);
			break;		
		}

		case 7:// cylinder
		{
			myBag.push_back(new Cylinder(tokens));
			myBagType.push_back(7);
			break;
		}

		case 8:// prism
		{
			myBag.push_back(new Prism(tokens));
			myBagType.push_back(8);
			break;
		}
	}
}

//end