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

// Structs for each of the eight shapes and double data type for each elements
// supporting functions
struct Square
{
	double side;
};

void outputSquare(ostream&, const Square&);

struct Rectangle
{
	double length;
	double width;
};

void outputRectangle(ostream&, const Rectangle&);

struct Circle
{
	double radius;
};

void outputCircle(ostream&, const Circle&);

struct Triangle
{
	double side;
};

void outputTriangle(ostream&, const Triangle&);

struct Cube
{
	double side;
};

void outputCube(ostream&, const Cube&);

struct Box
{
	double length;
	double width;
	double height;
};

void outputBox(ostream&, const Box&);

struct Cylinder
{
	double radius;
	double height;
};

void outputCylinder(ostream&, const Cylinder&);

struct Prism
{
	double side;
	double height;
};

void outputPrism(ostream&, const Prism&);

// prototypes
vector<string> parseString(string);// function for parse string into tokens
void calculate(vector<string>&,ofstream&);// calculation function and output
int checkShape(string);// check the shape valid or not
double turnToNum(string);// convert token string into numbers
void fillBag(vector<string>&, vector<void*>&, vector<int>&);// function for fill the bag

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
			outputSquare(cout, rSquare);
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); 
			Rectangle& rRectangle = *pRectangle; 
			outputRectangle(cout, rRectangle);
		}
		else if(myBagType[i] == 3)// Circle
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); 
			Circle& rCircle = *pCircle; 
			outputCircle(cout, rCircle);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			Triangle& rTriangle = *pTriangle; 
			outputTriangle(cout, rTriangle);
		}
		else if(myBagType[i] == 5)// Cube
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			Cube& rCube = *pCube; 
			outputCube(cout, rCube);
		}
		else if(myBagType[i] == 6)// Box
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			Box& rBox = *pBox; 
			outputBox(cout, rBox);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); 
			Cylinder& rCylinder = *pCylinder; 
			outputCylinder(cout, rCylinder);
		}
		else if(myBagType[i] == 8)// Prism
		{
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); 
			Prism& rPrism = *pPrism; 
			outputPrism(cout, rPrism);
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
			outputSquare(fout, rSquare);
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]); 
			Rectangle& rRectangle = *pRectangle; 
			outputRectangle(fout, rRectangle);
		}
		else if(myBagType[i] == 3)// Circle
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]); 
			Circle& rCircle = *pCircle; 
			outputCircle(fout, rCircle);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]); 
			Triangle& rTriangle = *pTriangle; 
			outputTriangle(fout, rTriangle);
		}
		else if(myBagType[i] == 5)// Cube
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]); 
			Cube& rCube = *pCube; 
			outputCube(fout, rCube);
		}
		else if(myBagType[i] == 6)// Box
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[i]); 
			Box& rBox = *pBox; 
			outputBox(fout, rBox);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]); 
			Cylinder& rCylinder = *pCylinder; 
			outputCylinder(fout, rCylinder);
		}
		else if(myBagType[i] == 8)// Prism
		{
			Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]); 
			Prism& rPrism = *pPrism; 
			outputPrism(fout, rPrism);
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

// supporting functions for 8 shapes
void outputSquare(ostream& out, const Square& s)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "SQUARE side=" << s.side;

	out.setf(ios::fixed);
	out.precision(2);

	out << " area=" << s.side * s.side << " perimeter=" << s.side * 4 << endl;
}

void outputRectangle(ostream& out, const Rectangle& r)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "RECTANGLE length=" << r.length << " width=" << r.width;

	out.setf(ios::fixed);
	out.precision(2);

	out << " area=" << r.length * r.width << " perimeter=" << 2 * (r.length + r.width) << endl;
}

void outputCircle(ostream& out, const Circle& c)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "CIRCLE radius=" << c.radius;

	out.setf(ios::fixed);
	out.precision(2);

	out << " area=" << 3.14159 * c.radius * c.radius << " perimeter=" << 2 * 3.14159 * c.radius << endl;
}

void outputTriangle(ostream& out, const Triangle& t)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "TRIANGLE side=" << t.side;

	out.setf(ios::fixed);
	out.precision(2);
 
	out << " area=" << sqrt(3.0) / 4 * t.side * t.side << " perimeter=" << t.side * 3 << endl;
}

void outputCube(ostream& out, const Cube& c)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "CUBE side=" << c.side;

	out.setf(ios::fixed);
	out.precision(2);

	out << " surface area=" << c.side * c.side * 6 << " volume=" << pow(c.side, 3.0) << endl;
}

void outputBox(ostream& out, const Box& b)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "BOX length=" << b.length << " width= " << b.width << " height= " << b.height;

	out.setf(ios::fixed);
	out.precision(2);

	out << " surface area=" << 2 * (b.length * b.width + b.width * b.height + b.length * b.height) << " volume=" << b.length * b.width * b.height << endl;
}

void outputCylinder(ostream& out, const Cylinder& c)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "CYLINDER radius=" << c.radius;
	out << " height=" << c.height;

	out.setf(ios::fixed);
	out.precision(2);

	out << " surface area=" << 3.14159 * pow(c.radius, 2.0) * 2 + c.height * 2 * 3.14159 * c.radius << " volume=" << 3.14159 * pow(c.radius, 2.0) * c.height << endl;
}

void outputPrism(ostream& out, const Prism& p)
{
	out.unsetf(ios::fixed);
	out.precision(6);

	out << "PRISM side=" << p.side;
	out << " height=" << p.height;

	out.setf(ios::fixed);
	out.precision(2);

	out << " surface area=" << sqrt(3.0)/4 * pow(p.side, 2.0) * 2 + p.side * p.height * 3 << " volume=" << sqrt(3.0) / 4 * pow(p.side, 2.0) * p.height << endl;
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