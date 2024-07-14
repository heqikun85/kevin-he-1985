
	
// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include <cmath>
#include <cstdlib>

struct Square{
	double side;
};
void squareOutput(ostream&, const Square&);

struct Rectangle{
	double length;
	double width;
};
void rectangleOutput(ostream&, const Rectangle&);

struct Circle{
	double radius;
};
void circleOutput(ostream&, const Circle&);

struct Triangle{
	double side;
};
void triangleOutput(ostream&, const Triangle&);

struct Cube{
	double side;
};
void cubeOutput(ostream&, const Cube&);

struct Box{
	double length;
	double width;
	double height;
};
void boxOutput(ostream&, const Box&);

struct Cylinder{
	double radius;
	double height;
};
void cylinderOutput(ostream&, const Cylinder&);

struct Prism{
	double side;
	double height;
};
void prismOutput(ostream&, const Prism&);

vector<string> parseString(string);
void checkShape(vector<string>&, vector<void*>&, vector<string>&);
void calcShape(vector<string>&, vector<void*>&, vector<string>&);

const double PI = 3.14159;

int main(){
	cout << "Programmer: Dhanush Patel\n";
	cout << "Programmer's ID: 1553428\n";
	cout << "File: " << __FILE__ << endl;

	ifstream fin;
	fin.open("Shapes.input.txt");
	vector<void*> shapesBag;
	vector<string> shapesTypeBag;

	while (fin.good()){
		string curLine;
		getline(fin, curLine);
		vector<string> lineElems = parseString(curLine);
		if(lineElems.size() != 0){
		 checkShape(lineElems, shapesBag, shapesTypeBag);
		}
	}

	fin.close();

	for (int i = 0; i < shapesBag.size(); i++){
		if (shapesTypeBag[i] == "SQUARE"){
			Square* ps = reinterpret_cast<Square*>(shapesBag[i]);
			Square& rs = *ps;
			squareOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "RECTANGLE"){
			Rectangle* ps = reinterpret_cast<Rectangle*>(shapesBag[i]);
			Rectangle& rs = *ps;
			rectangleOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "CIRCLE"){
			Circle* ps = reinterpret_cast<Circle*>(shapesBag[i]);
			Circle& rs = *ps;
			circleOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "TRIANGLE"){
			Triangle* ps = reinterpret_cast<Triangle*>(shapesBag[i]);
			Triangle& rs = *ps;
			triangleOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "CUBE"){
			Cube* ps = reinterpret_cast<Cube*>(shapesBag[i]);
			Cube& rs = *ps;
			cubeOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "BOX"){
			Box* ps = reinterpret_cast<Box*>(shapesBag[i]);
			Box& rs = *ps;
			boxOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "CYLINDER"){
			Cylinder* ps = reinterpret_cast<Cylinder*>(shapesBag[i]);
			Cylinder& rs = *ps;
			cylinderOutput(cout, rs);
		}
		else if (shapesTypeBag[i] == "PRISM"){
			Prism* ps = reinterpret_cast<Prism*>(shapesBag[i]);
			Prism& rs = *ps;
			prismOutput(cout, rs);
		}
		else {
			//this shouldn't happen
		}
	}

	ofstream fout;
	fout.open("Shapes.output.txt");

	for (int i = 0; i < shapesBag.size(); i++){
		 if (shapesTypeBag[i] == "SQUARE"){
			 Square* ps = reinterpret_cast<Square*>(shapesBag[i]);
			 Square& rs = *ps;
			 squareOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "RECTANGLE"){
			 Rectangle* ps = reinterpret_cast<Rectangle*>(shapesBag[i]);
			 Rectangle& rs = *ps;
			 rectangleOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "CIRCLE"){
			 Circle* ps = reinterpret_cast<Circle*>(shapesBag[i]);
			 Circle& rs = *ps;
			 circleOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "TRIANGLE"){
			 Triangle* ps = reinterpret_cast<Triangle*>(shapesBag[i]);
			 Triangle& rs = *ps;
			 triangleOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "CUBE"){
			 Cube* ps = reinterpret_cast<Cube*>(shapesBag[i]);
			 Cube& rs = *ps;
			 cubeOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "BOX"){
			 Box* ps = reinterpret_cast<Box*>(shapesBag[i]);
			 Box& rs = *ps;
			 boxOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "CYLINDER"){
			 Cylinder* ps = reinterpret_cast<Cylinder*>(shapesBag[i]);
			 Cylinder& rs = *ps;
			 cylinderOutput(fout, rs);
		 }
		 else if (shapesTypeBag[i] == "PRISM"){
			 Prism* ps = reinterpret_cast<Prism*>(shapesBag[i]);
			 Prism& rs = *ps;
			 prismOutput(fout, rs);
		 }
		 else {
			 //this shouldn't happen
		 }
	 }

	fout.close();

	for (int i = 0; i < shapesBag.size(); i++){
		 if (shapesTypeBag[i] == "SQUARE"){
			 Square* ps = reinterpret_cast<Square*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "RECTANGLE"){
			 Rectangle* ps = reinterpret_cast<Rectangle*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "CIRCLE"){
			 Circle* ps = reinterpret_cast<Circle*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "TRIANGLE"){
			 Triangle* ps = reinterpret_cast<Triangle*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "CUBE"){
			 Cube* ps = reinterpret_cast<Cube*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "BOX"){
			 Box* ps = reinterpret_cast<Box*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "CYLINDER"){
			 Cylinder* ps = reinterpret_cast<Cylinder*>(shapesBag[i]);
			 delete ps;
		 }
		 else if (shapesTypeBag[i] == "PRISM"){
			 Prism* ps = reinterpret_cast<Prism*>(shapesBag[i]);
			 delete ps;
		 }
		 else {
			 //this shouldn't happen
		 }
	 }
}

void calcShape(vector<string>& lineWords, vector<void*>& shapesBag, vector<string>& shapesTypeBag){
	string shapeType = lineWords.at(0);

	if (shapeType == "SQUARE"){
		Square* s = new Square;
		s->side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		shapesBag.push_back(s);
		shapesTypeBag.push_back("SQUARE");
	}
	else if (shapeType=="RECTANGLE"){
		Rectangle* r = new Rectangle;
		r->length = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		r->width = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		shapesBag.push_back(r);
		shapesTypeBag.push_back("RECTANGLE");
	}
	else if (shapeType == "CIRCLE"){
		Circle* c = new Circle;
		c->radius = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		shapesBag.push_back(c);
		shapesTypeBag.push_back("CIRCLE");
	}
	else if (shapeType == "TRIANGLE"){
		Triangle* t = new Triangle;
		t->side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		shapesBag.push_back(t);
		shapesTypeBag.push_back("TRIANGLE");
	}
	else if (shapeType == "CUBE"){
		Cube* c = new Cube;
		c->side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		shapesBag.push_back(c);
		shapesTypeBag.push_back("CUBE");
	}
	else if (shapeType == "BOX"){
		Box* b = new Box;
		b->length = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		b->width = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		b->height = lineWords.size() >= 4 ? atof(lineWords.at(3).c_str()) : 0;
		shapesBag.push_back(b);
		shapesTypeBag.push_back("BOX");
	}
	else if (shapeType == "CYLINDER"){
		Cylinder* c = new Cylinder;
		c->radius = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		c->height = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		shapesBag.push_back(c);
		shapesTypeBag.push_back("CYLINDER");
	}
	else if (shapeType == "PRISM"){
		Prism* p = new Prism;
		p->side = lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0;
		p->height = lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0;
		shapesBag.push_back(p);
		shapesTypeBag.push_back("PRISM");
	}
	else {
		//end of file, do nothing
	}
}

void squareOutput(ostream& os, const Square& s){
		double area = s.side * s.side;
		double perim = s.side * 4.0;
		os << "SQUARE side=" << s.side;
		os.setf(ios::fixed);
		os.precision(2);
		os << " area=" << area << " perimeter=" << perim << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void rectangleOutput(ostream& os, const Rectangle& r){
		double area = r.length * r.width;
		double perim = (2.0 * r.length) + (2.0 * r.width);
		os << "RECTANGLE length=" << r.length << " width=" << r.width;
		os.setf(ios::fixed);
		os.precision(2);
		os << " area=" << area << " perimeter=" << perim << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void circleOutput(ostream& os, const Circle& c){
		double area = PI * c.radius * c.radius;
		double perim = 2 * PI * c.radius;
		os << "CIRCLE radius=" << c.radius;
		os.setf(ios::fixed);
		os.precision(2);
		os << " area=" << area << " perimeter=" << perim << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void triangleOutput(ostream& os, const Triangle& t){
		double area = (pow(3.0, 0.5) / 4.0) * pow(t.side, 2.0);
		double perim = t.side * 3.0;
		os << "TRIANGLE side=" << t.side;
		os.setf(ios::fixed);
		os.precision(2);
		os << " area=" << area << " perimeter=" << perim << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void cubeOutput(ostream& os, const Cube& c){
		double surfaceArea = 6.0 * pow(c.side, 2.0);
		double volume = pow(c.side, 3.0);
		os << "CUBE side=" << c.side;
		os.setf(ios::fixed);
		os.precision(2);
		os << " surface area=" << surfaceArea << " volume=" << volume << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void boxOutput(ostream& os, const Box& b){
		double surfaceArea = 2.0 * ((b.length * b.width) + (b.length * b.height) + (b.width * b.height));
		double volume = b.length * b.width * b.height;
		os << "BOX length=" << b.length << " width=" << b.width << " height=" << b.height;
		os.setf(ios::fixed);
		os.precision(2);
		os << " surface area=" << surfaceArea << " volume=" << volume << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void cylinderOutput(ostream& os, const Cylinder& c){
		double surfaceArea = (2.0 * (PI * pow(c.radius, 2.0))) + (2.0 * PI * c.radius * c.height);
		double volume = PI * pow(c.radius, 2.0) * c.height;
		os << "CYLINDER radius=" << c.radius << " height=" << c.height;
		os.setf(ios::fixed);
		os.precision(2);
		os << " surface area=" << surfaceArea << " volume=" << volume << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}

void prismOutput(ostream& os, const Prism& p){
		double surfaceArea = (2.0 * ((pow(3.0, 0.5) / 4.0) * pow(p.side, 2.0) ) ) + (3.0 * (p.side * p.height));
		double volume = ((pow(3.0, 0.5) / 4.0) * pow(p.side, 2.0)) * p.height;
		os << "PRISM side=" << p.side << " height=" << p.height;
		os.setf(ios::fixed);
		os.precision(2);
		os << " surface area=" << surfaceArea << " volume=" << volume << endl;
		os.unsetf(ios::fixed);
		os.precision(6);
}


void checkShape(vector<string>& lineWords, vector<void*>& shapesBag, vector<string>& shapesTypeBag){
	string validShapes[] = {"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"};
	bool valShape = false;

	for(auto& i : validShapes){
		if(lineWords.at(0) == i){
			valShape = true;
		}
	}

	if(valShape == true){
		calcShape(lineWords, shapesBag, shapesTypeBag);
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
