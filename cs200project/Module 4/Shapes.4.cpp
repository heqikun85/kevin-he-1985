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

// Put the constructor functions into the class
class Square
{
	const double side;
	
	public:
	Square(const vector<string>&);
	Square& operator=(const Square&); 
	void output(ostream&) const;
};

class Rectangle
{
	const double length;
	const double width;
	
	public:
	Rectangle(const vector<string>&);
	Rectangle& operator=(const Rectangle&);
	void output(ostream&) const;
};

class Circle
{
	const double radius;

	public:
	Circle(const vector<string>&);
	Circle& operator=(const Circle&);
	void output(ostream&) const;
};

class Triangle
{
	const double side;
	
	public:
	Triangle(const vector<string>&);
	Triangle& operator=(const Triangle&);
	void output(ostream&) const;
};

class Cube
{
	const double side;
	
	public:
	Cube(const vector<string>&);
	Cube& operator=(const Cube&);
	void output(ostream&) const;
};

class Box
{
	const double length;
	const double width;
	const double height;

	public:
	Box(const vector<string>&);
	Box& operator=(const Box&);
	void output(ostream&) const;
};

class Cylinder
{
	const double radius;
	const double height;

	public:
	Cylinder(const vector<string>&);
	Cylinder& operator=(const Cylinder&);
	void output(ostream&) const;
};

class Prism
{
	const double side;
	const double height;
	
	public:
	Prism(const vector<string>&);
	Prism& operator=(const Prism&);
	void output(ostream&) const;
};

// prototypes
vector<string> parseString(string);// function for parse string into tokens
void calculate(vector<string>&,ofstream&);// calculation function and output
int checkShape(string);// check the shape valid or not
double turnToNum(string);// convert token string into numbers
void fillBag(vector<string>&, vector<const void*>&, vector<int>&);// function for fill the bag
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
	
	vector<const void*> myBag; // the bag
	vector<int> myBagType; // its companion array

	while(!fin.eof()) // first loop for getting data from input file and fill the bag
	{
		getline(fin, str);// get string from file
		tokens = parseString(str);
		if(tokens.size() != 0)// empty line
		fillBag(tokens, myBag, myBagType); // fill the bag
	}

	fin.close();// close
	
	//nested-for-loop sorting code block for Module 4
	for(int i = 0; i < myBag.size(); i++)
		for(int j = i + 1; j < myBag.size(); j++)
			if(myBagType[j] < myBagType[i])
			{
				swap(myBag[i], myBag[j]);
				swap(myBagType[i], myBagType[j]);
			}

	for(int i = 0;i < myBag.size();i++)// second loop for console output 
	{
		if(myBagType[i] == 1)// if it's Square then cout
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]); 
			const Square& rSquare = *pSquare; 
			(*pSquare).output(cout);// function call
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]); 
			const Rectangle& rRectangle = *pRectangle; 
			(*pRectangle).output(cout);
		}
		else if(myBagType[i] == 3)// Circle
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]); 
			const Circle& rCircle = *pCircle; 
			(*pCircle).output(cout);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]); 
			const Triangle& rTriangle = *pTriangle; 
			(*pTriangle).output(cout);
		}
		else if(myBagType[i] == 5)// Cube
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]); 
			const Cube& rCube = *pCube; 
			(*pCube).output(cout);
		}
		else if(myBagType[i] == 6)// Box
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]); 
			const Box& rBox = *pBox; 
			(*pBox).output(cout);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]); 
			const Cylinder& rCylinder = *pCylinder; 
			(*pCylinder).output(cout);
		}
		else if(myBagType[i] == 8)// Prism
		{
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]); 
			const Prism& rPrism = *pPrism; 
			(*pPrism).output(cout);
		}
		else;
	}

	fout.open("Shapes.output.txt");// open

	for(int i = 0;i < myBag.size();i++)// third loop for txt output
	{
		if(myBagType[i] == 1)// if it's Square then fout
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]); 
			const Square& rSquare = *pSquare; 
			(*pSquare).output(fout);
		}
		else if(myBagType[i] == 2)// Rectangle
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]); 
			const Rectangle& rRectangle = *pRectangle; 
			(*pRectangle).output(fout);
		}
		else if(myBagType[i] == 3)// Circle
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]); 
			const Circle& rCircle = *pCircle; 
			(*pCircle).output(fout);
		}
		else if(myBagType[i] == 4)// Triangle
		{
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]); 
			const Triangle& rTriangle = *pTriangle; 
			(*pTriangle).output(fout);
		}
		else if(myBagType[i] == 5)// Cube
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]); 
			const Cube& rCube = *pCube; 
			(*pCube).output(fout);
		}
		else if(myBagType[i] == 6)// Box
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]); 
			const Box& rBox = *pBox; 
			(*pBox).output(fout);
		}
		else if(myBagType[i] == 7)// Cylinder
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]); 
			const Cylinder& rCylinder = *pCylinder; 
			(*pCylinder).output(fout);
		}
		else if(myBagType[i] == 8)// Prism
		{
			const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]); 
			const Prism& rPrism = *pPrism; 
			(*pPrism).output(fout);
		}
		else;
	}

	fout << "EOF";// end of file
	fout.close();// close

	for(int i = 0;i < myBag.size();i++)// fourth loop for deallocation
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

// functions for fill the bag
void fillBag(vector<string>& tokens, vector<const void*>& myBag, vector<int>& myBagType)
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

//constructors with Initializer Lists
Square::Square(const vector<string>& tokens)
: side(tokens.size() >= 2 ? turnToNum(tokens[1]) : 0)
{
}

Rectangle::Rectangle(const vector<string>& tokens)
: length(tokens.size() >= 2 ? turnToNum(tokens[1]) : 0),
  width(tokens.size() >= 3 ? turnToNum(tokens[2]) : 0)
{
}

Circle::Circle(const vector<string>& tokens)
: radius(tokens.size() >= 2 ? turnToNum(tokens[1]) : 0)
{
}

Triangle::Triangle(const vector<string>& tokens)
: side(tokens.size() >= 2 ? turnToNum(tokens[1]) : 0)
{
}

Cube::Cube(const vector<string>& tokens)
: side(tokens.size() >= 2 ? turnToNum(tokens[1]) : 0)
{
}

Box::Box(const vector<string>& tokens)
: length (tokens.size() >= 2 ? turnToNum(tokens[1]) : 0),
  width (tokens.size() >= 3 ? turnToNum(tokens[2]) : 0),
  height (tokens.size() >= 4 ? turnToNum(tokens[3]) : 0)
{
}

Cylinder::Cylinder(const vector<string>& tokens)
: radius (tokens.size() >= 2 ? turnToNum(tokens[1]) : 0),
  height (tokens.size() >= 3 ? turnToNum(tokens[2]) : 0)
{
}

Prism::Prism(const vector<string>& tokens)
: side(tokens.size() >= 2 ? turnToNum(tokens[1]) : 0),
  height(tokens.size() >= 3 ? turnToNum(tokens[2]) : 0)
{
}

void Square::output(ostream& out) const
{
	out << roundingOff << "SQUARE side=" << side;// using roundingOff to keep default
	out << roundingTwo << " area=" << side * side << " perimeter=" << side * 4 << endl;
}

void Rectangle::output(ostream& out) const
{
	out << roundingOff << "RECTANGLE length=" << length << " width=" << width;
	out << roundingTwo << " area=" << length * width << " perimeter=" << 2 * (length + width) << endl;
}

void Circle::output(ostream& out) const
{
	out << roundingOff << "CIRCLE radius=" << radius;
	out << roundingTwo << " area=" << 3.14159 * radius * radius << " perimeter=" << 2 * 3.14159 * radius << endl;
}

void Triangle::output(ostream& out) const
{
	out << roundingOff << "TRIANGLE side=" << side;
	out << roundingTwo << " area=" << sqrt(3.0) / 4 * side * side << " perimeter=" << side * 3 << endl;
}

void Cube::output(ostream& out) const
{
	out << roundingOff << "CUBE side=" << side;
	out << roundingTwo << " surface area=" << side * side * 6 << " volume=" << pow(side, 3.0) << endl;
}

void Box::output(ostream& out) const
{
	out << roundingOff << "BOX length=" << length << " width=" << width << " height=" << height;
	out << roundingTwo << " surface area=" << 2 * (length * width + width * height + length * height) << " volume=" << length * width * height << endl;
}

void Cylinder::output(ostream& out) const
{
	out << roundingOff << "CYLINDER radius=" << radius;
	out << roundingOff << " height=" << height;

	out << roundingTwo << " surface area=" << 3.14159 * pow(radius, 2.0) * 2 + height * 2 * 3.14159 * radius << " volume=" << 3.14159 * pow(radius, 2.0) * height << endl;
}

void Prism::output(ostream& out) const
{
	out << roundingOff << "PRISM side=" << side;
	out << roundingOff << " height=" << height;

	out << roundingTwo << " surface area=" << sqrt(3.0)/4 * pow(side, 2.0) * 2 + side * height * 3 << " volume=" << sqrt(3.0) / 4 * pow(side, 2.0) * height << endl;
}

//assignment opeartor 
Square& Square::operator=(const Square& copyThis)
{
	Square& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.side) = copyThis.side;
	}
	return host; // returns a "self-reference"
}

Rectangle& Rectangle::operator=(const Rectangle& copyThis)
{
	Rectangle& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
	}
	return host; 
}

Circle& Circle::operator=(const Circle& copyThis)
{
	Circle& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.radius) = copyThis.radius;
	}
	return host; 
}

Triangle& Triangle::operator=(const Triangle& copyThis)
{
	Triangle& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.side) = copyThis.side;
	}
	return host; 
}

Cube& Cube::operator=(const Cube& copyThis)
{
	Cube& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.side) = copyThis.side;
	}
	return host; 
}

Box& Box::operator=(const Box& copyThis)
{
	Box& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; 
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis)
{
	Cylinder& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.radius) = copyThis.radius;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; 
}

Prism& Prism::operator=(const Prism& copyThis)
{
	Prism& host = *this; 
	if (this != &copyThis) 
	{
		const_cast<double&>(host.side) = copyThis.side;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; 
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