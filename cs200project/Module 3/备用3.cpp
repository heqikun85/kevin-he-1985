//Programmer: Siming Zhang
//Student ID: 1712438

#include<fstream>
#include<iostream>
#include<iterator>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// C library code block
#include<cstdlib>
#include<cmath>

//the following are the struct definitions
struct Square
{
	double sides;
	void calcAndOutSQUARE(ostream&);
};

struct Rectangle
{
	double length;
	double width;
	void calcAndOutRECTANGLE(ostream&);
};

struct Circle
{
	double radius;
	void calcAndOutCIRCLE(ostream&);
};

struct Triangle
{
	double sides;
	void calcAndOutTRIANGLE(ostream&);
};

struct Cube
{
	double sides;
	void calcAndOutCUBE(ostream&);
};

struct Box
{
	double length;
	double width;
	double height;
	void calcAndOutBOX(ostream&);
};

struct Cylinder
{
	double radius;
	double height;
	void calcAndOutCYLINDER(ostream&);
};

struct Prism
{
	double sides;
	double height;
	void calcAndOutPRISM(ostream&);
};

vector<string> parseString(string);
ostream& roundingOn(ostream&);
ostream& roundingOff(ostream&);

const double PI = atan(1.0) * 4; // global CONSTANT!

int main()
{
	// identification output code block
	cout << endl << "Programmer: Siming Zhang" << endl;
	cout << "Programmer's ID: 1712438" << endl;

	string finput;

	//opening input file
	ifstream fin;
	fin.open("Shapes.input.txt");

	//opening output file
	ofstream fout;
	fout.open("Shapes.output.txt");

	//creating the bag
	vector<void*> myBag;
	vector<char> myBagType; // companion array for tracking

	while (fin.good())
	{
		//getting input from file and testing input files
		getline(fin, finput);
		vector<string> tokens = parseString(finput); //parsing input file

		//checking inputs
		if(tokens.size() == 0) continue; //continue if blank line

		if(tokens[0] == "EOF") break; //break if it is the end of file

		//SQUARE
		else if(tokens[0] == "SQUARE")
		{
			//determining the values of dimensions
			double side = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Square* s1 = new Square;
			s1->sides = side;
			myBag.push_back(s1);
			myBagType.push_back('S');
		}//elseSQUARE

		//RECTANGLE
		else if(tokens[0] == "RECTANGLE")
		{
			//determining the values of dimensions
			double width = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
			double length = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Rectangle* rect = new Rectangle;
			rect->width = width;
			rect->length = length;
			myBag.push_back(rect);
			myBagType.push_back('R');
		}//elseRECTANGLE

		//CIRCLE
		else if(tokens[0] == "CIRCLE")
		{
			//determining the values of dimensions
			double rad = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			Circle* circ = new Circle;
			circ->radius = rad;
			myBag.push_back(circ);
			myBagType.push_back('C');
		}//CIRCLE

		//TRIANGLE
		else if(tokens[0] == "TRIANGLE")
		{
			//determining the values of dimensions
			double side = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Triangle* tri = new Triangle;
			tri->sides = side;
			myBag.push_back(tri);
			myBagType.push_back('T');
		}//TRIANGLE

		//CUBE
		else if(tokens[0] == "CUBE")
		{
			//determining the values of dimensions
			double side = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Cube* cub = new Cube;
			cub->sides = side;
			myBag.push_back(cub);
			myBagType.push_back('1'); // since there are duplicate 'c' I use integers for the other c's
		}//elseCUBE

		//BOX
		else if(tokens[0] == "BOX")
		{
			//determining the values of dimensions
			double height = tokens.size() < 4 ? 0 : atof(tokens[3].c_str());
			double width = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
			double length = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Box* boxx = new Box;
			boxx->length = length;
			boxx->width = width;
			boxx->height = height;
			myBag.push_back(boxx);
			myBagType.push_back('B');
		}//elseBOX

		//CYLINDER
		else if(tokens[0] == "CYLINDER")
		{
			//determining the values of dimensions
			double height = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
			double rad = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Cylinder* Cyl = new Cylinder;
			Cyl->radius = rad;
			Cyl->height = height;
			myBag.push_back(Cyl);
			myBagType.push_back('2');// since there are duplicate 'c' I use integers for the other c's
		}//elseCYLINDER

		//PRISM
		else if(tokens[0] == "PRISM")
		{
			//determining the values of dimensions
			double sides = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
			double height = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

			//creating the object and adding it to the bag
			Prism* pris = new Prism;
			pris->sides = sides;
			pris->height = height;
			myBag.push_back(pris);
			myBagType.push_back('P');
		}//elsePRISM

		else cout << tokens[0] << " Invalid Object.\n";
	}//while

	for(unsigned int i = 0 ; i < myBag.size() ; i++)
	{
		//the following conditionals are for determining the type of objects
		//and calculating the data members then output it to the console output
		if(myBagType[i] == 'S')
		{
			Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
			(*pSquare).calcAndOutSQUARE(cout);
		}
		else if(myBagType[i] == 'R')
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
			(*pRectangle).calcAndOutRECTANGLE(cout);
		}
		else if(myBagType[i] == 'C')
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
			(*pCircle).calcAndOutCIRCLE(cout);
		}
		else if(myBagType[i] == 'T')
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
			(*pTriangle).calcAndOutTRIANGLE(cout);
		}
		else if(myBagType[i] == '1')
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
			(*pCube).calcAndOutCUBE(cout);
		}
		else if(myBagType[i] == 'B')
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[i]);
			(*pBox).calcAndOutBOX(cout);
		}
		else if(myBagType[i] == '2')
		{
			Cylinder* pCyl = reinterpret_cast<Cylinder*>(myBag[i]);
			(*pCyl).calcAndOutCYLINDER(cout);
		}
		else if(myBagType[i] == 'P')
		{
			Prism* pPris = reinterpret_cast<Prism*>(myBag[i]);
			(*pPris).calcAndOutPRISM(cout);
		}
	}//for

	for(unsigned int j = 0 ; j < myBag.size() ; j++)
	{
		//the following conditionals are for determining the type of objects
		//and calculating the data members then output it to the file
		if(myBagType[j] == 'S')
		{
			Square* psquare = reinterpret_cast<Square*>(myBag[j]);
			(*psquare).calcAndOutSQUARE(fout);
		}
		else if(myBagType[j] == 'R')
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[j]);
			(*pRectangle).calcAndOutRECTANGLE(fout);
		}
		else if(myBagType[j] == 'C')
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[j]);
			(*pCircle).calcAndOutCIRCLE(fout);
		}
		else if(myBagType[j] == 'T')
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[j]);
			(*pTriangle).calcAndOutTRIANGLE(fout);
		}
		else if(myBagType[j] == '1')
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[j]);
			(*pCube).calcAndOutCUBE(fout);
		}
		else if(myBagType[j] == 'B')
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[j]);
			(*pBox).calcAndOutBOX(fout);
		}
		else if(myBagType[j] == '2')
		{
			Cylinder* pCyl = reinterpret_cast<Cylinder*>(myBag[j]);
			(*pCyl).calcAndOutCYLINDER(fout);
		}
		else if(myBagType[j] == 'P')
		{
			Prism* pPris = reinterpret_cast<Prism*>(myBag[j]);
			(*pPris).calcAndOutPRISM(fout);
		}
	}//for

	for(unsigned int j = 0 ; j < myBag.size() ; j++)
	{

		if(myBagType[j] == 'S')
		{
			Square* psquare = reinterpret_cast<Square*>(myBag[j]);
			delete psquare;
		}
		else if(myBagType[j] == 'R')
		{
			Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[j]);
			delete pRectangle;
		}
		else if(myBagType[j] == 'C')
		{
			Circle* pCircle = reinterpret_cast<Circle*>(myBag[j]);
			delete pCircle;
		}
		else if(myBagType[j] == 'T')
		{
			Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[j]);
			delete pTriangle;
		}
		else if(myBagType[j] == '1')
		{
			Cube* pCube = reinterpret_cast<Cube*>(myBag[j]);
			delete pCube;
		}
		else if(myBagType[j] == 'B')
		{
			Box* pBox = reinterpret_cast<Box*>(myBag[j]);
			delete pBox;
		}
		else if(myBagType[j] == '2')
		{
			Cylinder* pCyl = reinterpret_cast<Cylinder*>(myBag[j]);
			delete pCyl;
		}
		else if(myBagType[j] == 'P')
		{
			Prism* pPris = reinterpret_cast<Prism*>(myBag[j]);
			delete pPris;
		}
	}//for

	fin.close();
	fout.close();
}//main

ostream& roundingOn(ostream& out)
{
	out.setf(ios::fixed);
	out.precision(2);
	return out;
}

ostream& roundingOff(ostream& out)
{
	out.unsetf(ios::fixed);
	out.precision(6);
	return out;
}

void Square::calcAndOutSQUARE(ostream& out)
{
	// geometry calculation
	double area = sides * sides;
	double peri = 4 * sides;

	//writing on the file and console screen
	out << roundingOff << "SQUARE sides=" << sides;
	out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//SQUARE

void Rectangle::calcAndOutRECTANGLE(ostream& out)
{
	// geometry calculation
	double area = length * width;
	double peri = (2 * length) + (2 * width);

	//writing on the file
	out << roundingOff << "RECTANGLE length=" << length << " width=" << width;
	out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//RECTANGLE

void Circle::calcAndOutCIRCLE(ostream& out)
{
	// geometry calculation
	double area = PI * radius * radius;
	double peri = PI * 2 * radius;

	//writing on the file and console screen
	out << roundingOff << "CIRCLE sides=" << radius;
	out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//CIRCLE

void Triangle::calcAndOutTRIANGLE(ostream& out)
{
	// geometry calculation
	double area = (sqrt(3)/4) * sides * sides;
	double peri = 3 * sides;

	//writing on the file and console screen
	out << roundingOff << "TRIANGLE sides=" << sides;
	out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//TRIANGLE

void Cube::calcAndOutCUBE(ostream& out)
{
	// geometry calculation
	double vol = sides * sides * sides;
	double sa = 6 * sides* sides;

	//writing on the file
	out << roundingOff << "CUBE sides=" << sides;
	out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}//cube

void Box::calcAndOutBOX(ostream& out)
{
	// geometry calculation
	double vol = length * width * height;
	double sa = (2 * length * width) + (2 * length * height) + (2 * width * height);

	//writing on the file and console screen
	out << roundingOff << "BOX length=" << length << " width=" << width << " height=" << height;
	out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}//box

void Cylinder::calcAndOutCYLINDER(ostream& out)
{
	// geometry calculation
	double vol = PI * radius * radius * height;
	double sa = (2.0 * PI * radius * height) + (2.0 * PI * radius * radius);

	//writing on the file and console screen
	out << roundingOff << "CYLINDER radius=" << radius << " height=" << height;
	out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}//CYLINDER

void Prism::calcAndOutPRISM(ostream& out)
{
	// geometry calculation
	double vol = (sqrt(3)/4) * sides * sides * height;
	double sa = (2* (sqrt(3)/4) * sides * sides) + (3 * sides * height);

	//writing on the file and console screen
	out << roundingOff << "PRISM sides=" << sides << " height=" << height;
	out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}

vector<string> parseString(string str)
{
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin,end);
}//parseString