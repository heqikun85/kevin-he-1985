//Programmer: Siming Zhang
//Programmer ID: 1712438

//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <iterator>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

#include "pShapes.h"

//constructors with Initializer Lists
Square::Square(const vector<string>& tokens)
: side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0)
{
}

comsc::Rectangle::Rectangle(const vector<string>& tokens)
: length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
	width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0)
{
}

Circle::Circle(const vector<string>& tokens)
: radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0)
{
}

Triangle::Triangle(const vector<string>& tokens)
: side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0)
{
}

Cube::Cube(const vector<string>& tokens)
: Square(tokens)
{
}

Box::Box(const vector<string>& tokens)
: Rectangle(tokens), height(tokens.size() > 3 ? atof(tokens[3].c_str()) : 0)
{
}

Cylinder::Cylinder(const vector<string>& tokens)
: Circle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0)
{
}

Prism::Prism(const vector<string>& tokens)
: Triangle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0)
{
}

// output functions
void Square::output(ostream& out) const
{
	out << roundingOff << "SQUARE side=" << side;
	out << roundingTwo << " area=" << side * side << " perimeter=" << side * 4 << endl;
}

void comsc::Rectangle::output(ostream& out) const
{
	out << roundingOff << "RECTANGLE length=" << length << " width=" << width;
	out << roundingTwo << " area=" << length * width << " perimeter=" << 2 * (length + width) << endl;
}

void Circle::output(ostream& out) const
{
	out << roundingOff << "CIRCLE radius=" << radius;
	out << roundingTwo << " area=" << 3.14159 * radius * radius << " perimeter=" << 3.14159 * 2 * radius << endl;
}

void Triangle::output(ostream& out) const
{
	out << roundingOff << "TRIANGLE side=" << side;
	out << roundingTwo << " area=" << sqrt(3.0) / 4 * side * side << " perimeter=" << side * 3 << endl;
}

void Cube::output(ostream& out) const
{
	out << roundingOff << "CUBE side=" << side;
	out << roundingTwo << " surface area=" << side * side *6 << " volume=" << pow(side, 3.0) << endl;
}

void Box::output(ostream& out) const
{
	out << roundingOff << "BOX length=" << length << " width=" << width << " height=" << height;
	out << roundingTwo << " surface area=" << 2 * (length * width + width * height + length * height) << " volume=" << length * width * height << endl;
}

void Cylinder::output(ostream& out) const
{
	out << roundingOff << "CYLINDER radius=" << radius;
	out << " height=" << height;
	out << roundingTwo << " surface area=" << 3.14159 * pow(radius, 2.0) * 2 + height * 2 * 3.14159 * radius << " volume=" << 3.14159 * pow(radius, 2.0) * height << endl;
}

void Prism::output(ostream& out) const
{
	out << roundingOff << "PRISM side=" << side;
	out << " height=" << height;
	out << roundingTwo << " surface area=" << sqrt(3.0) / 4 * pow(side, 2.0) * 2 + side * height * 3 << " volume=" << sqrt(3.0) / 4 * pow(side, 2.0) * height << endl;
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

comsc::Rectangle& comsc::Rectangle::operator=(const Rectangle& copyThis)
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

// Manipulator Function definition
ostream& roundingTwo(ostream& out)
{
	out.setf(ios::fixed);
	out.precision(2); // 2 decimal digits
	return out;
}

ostream& roundingOff(ostream& out)// unset
{
	out.unsetf(ios::fixed);
	out.precision(6); // keep the C++ default 
	return out;
}

ostream& operator<< (ostream& out, const Shape* const s)
{
	s->output(out);
	return out;
}