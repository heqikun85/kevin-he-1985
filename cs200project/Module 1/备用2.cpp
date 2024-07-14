#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include <cmath>
#include <cstdlib>

vector<string> parseString(string);
void checkShape(vector<string>&, ofstream&);
void calcShape(vector<string>&, ofstream&);

const double PI = 3.14159;

int main(){

	ifstream fin;
	ofstream fout;
	fin.open("Shapes.input.txt");
	fout.open("beiyong3.output.txt");

	while(fin.good()){
		string curLine;
		getline(fin, curLine);
		vector<string> lineElems = parseString(curLine);
		if(lineElems.size()!=0){
			checkShape(lineElems, fout);
		}
	}
	fin.close();
	fout.close();
}

void calcShape(vector<string>& lineWords, ofstream& fout){
	string shapeType = lineWords.at(0);

	if(shapeType == "SQUARE"){
		double side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double area = side * side;
		double perim = side * 4.0;
		cout << "SQUARE side=" << side;
		fout << "SQUARE side=" << side;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " area=" << area << " perimeter=" << perim << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " area=" << area << " perimeter=" << perim << endl;
	}
	else if(shapeType=="RECTANGLE"){
		double length = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double width = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		double area = length * width;
		double perim = (2.0 * length) + (2.0 * width);
		cout << "RECTANGLE length=" << length << " width=" << width;
		fout << "RECTANGLE length=" << length << " width=" << width;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " area=" << area << " perimeter=" << perim << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " area=" << area << " perimeter=" << perim << endl;
	}
	else if(shapeType == "CIRCLE"){
		double radius = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double area = PI * radius * radius;
		double perim = 2 * PI * radius;
		cout << "CIRCLE radius=" << radius;
		fout << "CIRCLE radius=" << radius;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " area=" << area << " perimeter=" << perim << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " area=" << area << " perimeter=" << perim << endl;
	}
	else if(shapeType == "TRIANGLE"){
		double side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double area = (pow(3.0, 0.5) / 4.0) * pow(side, 2.0);
		double perim = side * 3.0;
		cout << "TRIANGLE side=" << side;
		fout << "TRIANGLE side=" << side;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " area=" << area << " perimeter=" << perim << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " area=" << area << " perimeter=" << perim << endl;
	}
	else if(shapeType == "CUBE"){
		double side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double surfaceArea = 6.0 * pow(side, 2.0);
		double volume = pow(side, 3.0);
		cout << "CUBE side=" << side;
		fout << "CUBE side=" << side;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " surface area=" << surfaceArea << " volume=" << volume << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " surface area=" << surfaceArea << " volume=" << volume << endl;
	}
	else if(shapeType == "BOX"){
		double length = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double width = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		double height = lineWords.size() >= 4 ? atof(lineWords.at(3).c_str()) : 0;
		double surfaceArea = 2.0 * ((length * width) + (length * height) + (width * height));
		double volume = length * width * height;
		cout << "BOX length=" << length << " width=" << width << " height=" << height;
		fout << "BOX length=" << length << " width=" << width << " height=" << height;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " surface area=" << surfaceArea << " volume=" << volume << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " surface area=" << surfaceArea << " volume=" << volume << endl;
	}
	else if(shapeType == "CYLINDER"){
		double radius = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double height = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		double surfaceArea = (2.0 * (PI * pow(radius, 2.0))) + (2.0 * PI * radius * height);
		double volume = PI * pow(radius, 2.0) * height;
		cout << "CYLINDER radius=" << radius << " height=" << height;
		fout << "CYLINDER radius=" << radius << " height=" << height;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " surface area=" << surfaceArea << " volume=" << volume << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " surface area=" << surfaceArea << " volume=" << volume << endl;
	}
	else if(shapeType == "PRISM"){
		double side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		double height = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		double surfaceArea = (2.0 * ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0) ) ) + (3.0 * (side * height));
		double volume = ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0)) * height;
		cout << "PRISM side=" << side << " height=" << height;
		fout << "PRISM side=" << side << " height=" << height;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << " surface area=" << surfaceArea << " volume=" << volume << endl;
		fout.setf(ios::fixed);
		fout.precision(2);
		fout << " surface area=" << surfaceArea << " volume=" << volume << endl;
	}
	else{
		//end of file, do nothing
	}

	cout.unsetf(ios::fixed);
	cout.precision(6);
	fout.unsetf(ios::fixed);
	fout.precision(6);
}

void checkShape(vector<string>& lineWords, ofstream& fout){
	string validShapes[] = {"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"};
	bool valShape = false;

	for(auto& i : validShapes){
		if(lineWords.at(0) == i){
			valShape = true;
		}
	}

	if(valShape == true){
		calcShape(lineWords, fout);
	}
	else{
		if(lineWords.at(0)!="EOF"){
			cout << lineWords.at(0) << " invalid shape" << endl;
		}
	}
}

vector<string> parseString(string str){
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}