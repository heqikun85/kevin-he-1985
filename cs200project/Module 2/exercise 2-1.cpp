#include<iostream>

#include<iomanip>

using namespace std;

struct Square
{
  double length;
};

void calculateAreaAndPerimeter(ostream &out, const Square &s);

int main(){

Square s;

s.length = 4.5;

calculateAreaAndPerimeter(cout, s);

return 0;

}

void calculateAreaAndPerimeter(ostream &out, const Square &s)
{

double area, perimeter;




area = s.length * s.length;

perimeter = 4 * s.length;



out.setf(ios::fixed);
out.precision(2);


out << "Area: "<<area<<endl;

out << "Perimeter: "<<perimeter<<endl;

out.unsetf(ios::fixed);// keep our default number
out.precision(6);

}

