//Programmer's Name: Siming Zhang
//Programmer's ID:   1712438

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

//prototypes
vector<string> parseString(string);// function for parse string into tokens
void calculate(vector<string>&,ofstream&);// calculation function and output
int checkShape(string);// check the shape valid or not
double turnToNum(string);// convert token string into numbers

int main()
{
	cout << "Programmer's Name: Siming Zhang" << endl;// Programmer's info.
	cout << "Programmer's ID:   1712438" << endl;
	cout << endl;
	
	ifstream fin;// intput file object
	ofstream fout;// output
	fin.open("Shapes.input.txt");
	fout.open("Shapes.output.txt");

	string str; // to store a single line of input from file
	vector<string> tokens; // store tokens

	while(!fin.eof())
	{
	getline(fin,str);// get string from file
	tokens = parseString(str);
		
	if(tokens.size() != 0)// empty line 
	calculate(tokens,fout);
	}

	fin.close();//close input.txt 
	fout.close();//close output.txt 
	return 0;
}

// tokens function
vector<string> parseString(string str)
{
	// from module 1
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

void calculate(vector<string>& tokens,ofstream& fout)
{
	double side,area,perimeter,length,width,radius,height,volume,surface;

	switch(checkShape(tokens[0]))
	{
	// EOF
	case -1:
	  break;

	// invalid shape
	case 0:
	  cout << tokens[0] << " invalid object\n";
	  break;

	// square
	case 1:
	  side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  area = side * side;
	  perimeter = side * 4;

	  fout << "SQUARE side=" << side;// output in txt file
	  cout << "SQUARE side=" << side;// output in console

	  fout.setf(ios::fixed);
	  fout.precision(2);// for output in txt file
	  cout.setf(ios::fixed);
	  cout.precision(2);// for output in console

	  fout << " area=" << area << " perimeter=" << perimeter << endl;
	  cout << " area=" << area << " perimeter=" << perimeter << endl;
	  break;

	// rectangle
	case 2:
	  length = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  width = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
	  area = length * width;
	  perimeter = (length + width) * 2;

	  fout << "RECTANGLE length=" << length << " width=" << width;
	  cout << "RECTANGLE length=" << length << " width=" << width;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " area=" << area << " perimeter=" << perimeter << endl;
	  cout << " area=" << area << " perimeter=" << perimeter << endl;
	  break;

	// circle
	case 3:
	  radius = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  area = 3.14159 * pow(radius,2.0);
	  perimeter = 2 * radius * 3.14159;

	  fout << "CIRCLE radius=" << radius;
	  cout << "CIRCLE radius=" << radius;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " area=" << area << " perimeter=" << perimeter << endl;
	  cout << " area=" << area << " perimeter=" << perimeter << endl;
	  break;

	// triangle
	case 4:
	  side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  area = sqrt(3.0)/4 * pow(side,2.0);
	  perimeter = 3 * side;

	  fout << "TRIANGLE side=" << side;
	  cout << "TRIANGLE side=" << side;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " area=" << area << " perimeter=" << perimeter << endl;
	  cout << " area=" << area << " perimeter=" << perimeter << endl;
	  break;

	// cube
	case 5:
	  side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  volume = pow(side,3.0);
	  surface = pow(side,2.0) * 6;

	  fout << "CUBE side=" << side;
	  cout << "CUBE side=" << side;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " surface area=" << surface << " volume=" << volume << endl;
	  cout << " surface area=" << surface << " volume=" << volume << endl;
	  break;

	// box
	case 6:
	  length = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  width = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
	  height = tokens.size() >= 4 ? turnToNum(tokens[3]) : 0;
	  volume = length * width * height;
	  surface = 2 * (length * width + width * height + length * height);

	  fout << "BOX length=" << length << " width= " << width << " height= " << height;
	  cout << "BOX length=" << length << " width= " << width << " height= " << height;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " surface area=" << surface << " volume=" << volume << endl;
	  cout << " surface area=" << surface << " volume=" << volume << endl;
	  break;

	// cylinder
	case 7:
	  radius = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  height = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
	  surface = 3.14159 * pow(radius,2.0) * 2 + height * 2 * 3.14159 * radius;
	  volume = 3.14159 * pow(radius,2.0) * height;

	  fout << "CYLINDER radius=" << radius;
	  cout << "CYLINDER radius=" << radius;
	  fout << " height=" << height;
	  cout << " height=" << height;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " surface area=" << surface << " volume=" << volume << endl;
	  cout << " surface area=" << surface << " volume=" << volume << endl;
	  break;

	// prism
	case 8:
	  side = tokens.size() >= 2 ? turnToNum(tokens[1]) : 0;
	  height = tokens.size() >= 3 ? turnToNum(tokens[2]) : 0;
	  volume = sqrt(3.0)/4 * pow(side,2.0) * height;
	  surface = sqrt(3.0)/4 * pow(side,2.0) * 2 + side * height * 3;

	  fout << "PRISM side=" << side;
	  cout << "PRISM side=" << side;
	  fout << " height=" << height;
	  cout << " height=" << height;

	  fout.setf(ios::fixed);
	  fout.precision(2);
	  cout.setf(ios::fixed);
	  cout.precision(2);

	  fout << " surface area=" << surface << " volume=" << volume << endl;
	  cout << " surface area=" << surface << " volume=" << volume << endl;
	  break;
	}

	
	fout.unsetf(ios::fixed);// keep our default number
	fout.precision(6);
	cout.unsetf(ios::fixed);// keep our default number
	cout.precision(6);
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