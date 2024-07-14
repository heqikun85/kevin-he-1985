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

// Put the member functions into the structs
struct Square
{
	double side;
	void outputSquare(ostream&) const;
};

struct Rectangle
{
	double length;
	double width;
	void outputRectangle(ostream&) const;
};

struct Circle
{
	double radius;
	void outputCircle(ostream&) const;
};

struct Triangle
{
	double side;
	void outputTriangle(ostream&) const;
};

struct Cube
{
	double side;
	void outputCube(ostream&) const;
};

struct Box
{
	double length;
	double width;
	double height;
	void outputBox(ostream&) const;
};

struct Cylinder
{
	double radius;
	double height;
	void outputCylinder(ostream&) const;
};

struct Prism
{
	double side;
	double height;
	void outputPrism(ostream&) const;
};

// prototypes
vector<string> parseString(string);// function for parse string into tokens
void calculate(vector<string>&,ofstream&);// calculation function and output
int checkShape(string);// check the shape valid or not
double turnToNum(string);// convert token string into numbers
void fillBag(vector<string>&, vector<void*>&, vector<int>&);// function for fill the bag
ostream& roundingTwo(ostream&);// Manipulator Prototypes
ostream& roundingOff(ostream&);


int main()
{
	cout << "Programmer: Siming Zhang" << endl;// programmer's Info
	cout << "Programmer's ID: 1712438" << endl;
	cout << endl;

	ifstream fin;// intput file object
	ofstream fout;// output
	fin.open("Shapes.input.txt");// open file

	string str; // to store a single line of input from file
	vector<string> tokens; // store tokens
	
	vector<void*> myBag; // the bag
	vector<int> myBagType; // its companion array

	while(!fin.eof()) // first loop for getting data from input file and fill the bag
	{
		getline(fin, str);// get string from file
		tokens = parseString(str);
		if(tokens.size() != 0)// empty line
		fillBag(tokens, myBag, myBagType); // fill the bag
	}

	fin.close();// close

	for(int i = 0;i < myBag.size();i++)// second loop for console output 
	{
		if(myBagType[i] == 1)// if it's Square then cout
		{
			Square* pSquare = reinterpret_cast<Square*>(myBag[i]); 
			Square& rSquare = *pSquare; 
			(*pSquare).outputSquare(cout);// function call
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); 
			Rectangle& rRectangle = *pRectangle; 
			(*pRectangle).outputRectangle(cout);
		}
		else if(myBagType[i] == 3)// Circle
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); 
			Circle& rCircle = *pCircle; 
			(*pCircle).outputCircle(cout);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			Triangle& rTriangle = *pTriangle; 
			(*pTriangle).outputTriangle(cout);
		}
		else if(myBagType[i] == 5)// Cube
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			Cube& rCube = *pCube; 
			(*pCube).outputCube(cout);
		}
		else if(myBagType[i] == 6)// Box
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			Box& rBox = *pBox; 
			(*pBox).outputBox(cout);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); 
			Cylinder& rCylinder = *pCylinder; 
			(*pCylinder).outputCylinder(cout);
		}
		else if(myBagType[i] == 8)// Prism
		{
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); 
			Prism& rPrism = *pPrism; 
			(*pPrism).outputPrism(cout);
		}
		else;
	}

	fout.open("Shapes.output.txt");// open

	for(int i = 0;i < myBag.size();i++)// third loop for txt output
	{
		if(myBagType[i] == 1)// if it's Square then fout
		{
			Square* pSquare = reinterpret_cast<Square*>(myBag[i]); 
			Square& rSquare = *pSquare; 
			(*pSquare).outputSquare(fout);
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); 
			Rectangle& rRectangle = *pRectangle; 
			(*pRectangle).outputRectangle(fout);
		}
		else if(myBagType[i] == 3)// Circle
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); 
			Circle& rCircle = *pCircle; 
			(*pCircle).outputCircle(fout);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			Triangle& rTriangle = *pTriangle; 
			(*pTriangle).outputTriangle(fout);
		}
		else if(myBagType[i] == 5)// Cube
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			Cube& rCube = *pCube; 
			(*pCube).outputCube(fout);
		}
		else if(myBagType[i] == 6)// Box
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			Box& rBox = *pBox; 
			(*pBox).outputBox(fout);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); 
			Cylinder& rCylinder = *pCylinder; 
			(*pCylinder).outputCylinder(fout);
		}
		else if(myBagType[i] == 8)// Prism
		{
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); 
			Prism& rPrism = *pPrism; 
			(*pPrism).outputPrism(fout);
		}
		else;
	}

	fout << "EOF";// end of file
	fout.close();// close

	for(int i = 0;i < myBag.size();i++)// fourth loop for deallocation
	{
		if(myBagType[i] == 1)
		{
			Square* pSquare = reinterpret_cast<Square*>(myBag[i]); 
			delete pSquare;
		}
		else if(myBagType[i] == 2)
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); 
			delete pRectangle;
		}
		else if(myBagType[i] == 3)
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); 
			delete pCircle;
		}
		else if(myBagType[i] == 4)
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			delete pTriangle;
		}
		else if(myBagType[i] == 5)
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			delete pCube;
		}
		else if(myBagType[i] == 6)
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			delete pBox;
		}
		else if(myBagType[i] == 7)
		{
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); 
			delete pCylinder;
		}
		else if(myBagType[i] == 8)
		{
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); 
			delete pPrism;
		}
		else;
	}

	return 0;// end of main
}

// functions for fill the bag
void fillBag(vector<string>& tokens, vector<void*>& myBag, vector<int>& myBagType)
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
			Square* s = new Square;// dynamic object
			myBag.push_back(s);
			myBagType.push_back(1);
			s->side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			break;
		}

		case 2:// rectangle
		{
			Rectangle* r = new Rectangle;
			myBag.push_back(r);
			myBagType.push_back(2);
			r->length = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			r->width = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
			break;
		}

		case 3:// circle
		{
			Circle* c = new Circle;
			myBag.push_back(c);
			myBagType.push_back(3);
			c->radius = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			break;
		}

		case 4:// triangle
		{
			Triangle* t = new Triangle;
			myBag.push_back(t);
			myBagType.push_back(4);
			t->side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			break;
		}

		case 5:// cube
		{
			Cube* c = new Cube;
			myBag.push_back(c);
			myBagType.push_back(5);
			c->side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			break;
		}

		case 6:// box
		{
			Box* b = new Box;
			myBag.push_back(b);
			myBagType.push_back(6);
			b->length = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			b->width = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
			b->height = tokens.size() >= 4 ? turnToNum(tokens[3]) : 0;
			break;
		}

		case 7:// cylinder
		{
			Cylinder* c = new Cylinder;
			myBag.push_back(c);
			myBagType.push_back(7);
			c->radius = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			c->height = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
			break;
		}

		case 8:// prism
		{
			Prism* p = new Prism;
			myBag.push_back(p);
			myBagType.push_back(8);
			p->side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
			p->height = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
			break;
		}
	}
}

// Manipulator Function definition
ostream& roundingTwo(ostream& out)
{
	out.setf(ios::fixed);
	out.precision(2); // 2 decimal digits
	return out;
}

ostream& roundingOff(ostream& out)
{
	out.unsetf(ios::fixed); 
	out.precision(6); // keep the C++ default 
	return out;
} 

// member functions
void Square::outputSquare(ostream& out) const
{
	out << roundingOff << "SQUARE side=" << side;// using roundingOff to keep default
	out << roundingTwo << " area=" << side * side << " perimeter=" << side * 4 << endl;
}

void Rectangle::outputRectangle(ostream& out) const
{
	out << roundingOff << "RECTANGLE length=" << length << " width=" << width;
	out << roundingTwo << " area=" << length * width << " perimeter=" << 2 * (length + width) << endl;
}

void Circle::outputCircle(ostream& out) const
{
	out << roundingOff << "CIRCLE radius=" << radius;
	out << roundingTwo << " area=" << 3.14159 * radius * radius << " perimeter=" << 2 * 3.14159 * radius << endl;
}

void Triangle::outputTriangle(ostream& out) const
{
	out << roundingOff << "TRIANGLE side=" << side;
	out << roundingTwo << " area=" << sqrt(3.0) / 4 * side * side << " perimeter=" << side * 3 << endl;
}

void Cube::outputCube(ostream& out) const
{
	out << roundingOff << "CUBE side=" << side;
	out << roundingTwo << " surface area=" << side * side * 6 << " volume=" << pow(side, 3.0) << endl;
}

void Box::outputBox(ostream& out) const
{
	out << roundingOff << "BOX length=" << length << " width=" << width << " height=" << height;
	out << roundingTwo << " surface area=" << 2 * (length * width + width * height + length * height) << " volume=" << length * width * height << endl;
}

void Cylinder::outputCylinder(ostream& out) const
{
	out << roundingOff << "CYLINDER radius=" << radius;
	out << roundingOff << " height=" << height;

	out << roundingTwo << " surface area=" << 3.14159 * pow(radius, 2.0) * 2 + height * 2 * 3.14159 * radius << " volume=" << 3.14159 * pow(radius, 2.0) * height << endl;
}

void Prism::outputPrism(ostream& out) const
{
	out << roundingOff << "PRISM side=" << side;
	out << roundingOff << " height=" << height;

	out << roundingTwo << " surface area=" << sqrt(3.0)/4 * pow(side, 2.0) * 2 + side * height * 3 << " volume=" << sqrt(3.0) / 4 * pow(side, 2.0) * height << endl;
}

// tokens function
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

double turnToNum(string token)
{
	//convert string to numbers
	return atof(token.c_str());
}