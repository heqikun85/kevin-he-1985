
	
//Programmer: Ethan Yi Chiang
//Programmer's ID: 1538719

#include <algorithm>// swap()
#include <iostream>
#include <vector>
using namespace std;

#include <cstring>

//class
class Leg
{
	const char* const startCity;
	const char* const endCity;
	const double distance;

	public:
	friend class Route;
	double getDistance() const {return distance;}
	void output(ostream&);
	Leg& operator=(const Leg&);// for swap()
	Leg(const char* const, const char* const, double);
};

class Route
{
	vector<const Leg*> legs; // bag of legs
	const double totalDis;

	public:
	double getDistance() const {return totalDis;}
	void output(ostream&);
	Route& operator=(const Route&);
	Route(const Leg&);
	Route(const Route&, const Leg&);
};

const int size = 8;// Leg array size is 8

int main()
{
	cout << "Programmer: Ethan Yi Chiang\n"
			 << "Programmer's ID: 1538719\n"
			 << "File: " << __FILE__ << "\n\n";

	Leg l[] =
	{
		Leg("PLeasnat Hill", "Concord", 1.1),
		Leg("Concord", "Walnut Creek", 2.1),
		Leg("Walnut Creek", "Fremont", 20.1),
		Leg("Fremont", "San Ramon", 15.1),
		Leg("San Ramon", "Pleasanton", 6.7),
		Leg("Pleasanton", "Livermore", 4.2),
		Leg("Livermore", "Tracy", 10.2),
		Leg("Tracy", "Stockton", 20.2)
	};

	Route r[] =
	{
		Route(l[0]),
		Route(r[0], l[1]),
		Route(r[1], l[2]),
		Route(r[2], l[3]),
		Route(r[3], l[4]),
		Route(r[4], l[5]),
		Route(r[5], l[6]),
		Route(r[6], l[7])
	};

	//sorting loop
	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if(r[i].getDistance() < r[j].getDistance())
				swap(r[i], r[j]);
		}
	}

	//output sorted legs
	for(int i = 0; i < size; i++)
	{
		r[i].output(cout);
	}

	return 0;
}

//getter functions
void Leg::output(ostream& out)
{
	out << "Leg: " << startCity << " to " << endCity
			<< ", " << distance << " miles\n";
}

void Route::output(ostream& out)
{
	out << "Leg: " << legs[0]->startCity;

	for(int i = 0; i < legs.size(); i++)
	{
		out << " to " << legs[i]->endCity;      
	}

	out << ", " << totalDis << " miles\n";
}

//constructor
Leg::Leg(const char* const startCity, const char* const endCity, double distance)
:startCity(startCity), endCity(endCity), distance(distance)
{
}

Route::Route(const Leg& newLeg)
:totalDis(newLeg.distance)
{
	legs.push_back(&newLeg);
}

Route::Route(const Route& exRoute, const Leg& newLeg)
:totalDis(exRoute.totalDis + newLeg.distance)
{
	legs = exRoute.legs;

	try
	{
		if(strcmp(exRoute.legs.back()->endCity, newLeg.startCity) != 0)
			throw "Cities don't match!";
	}
	catch(string error)
	{
		cout << error << endl;
	}

	legs.push_back(&newLeg); // add new leg to route
}

//assignment operator
Leg& Leg::operator=(const Leg& copyThis)
{
	Leg& host = *this;
	if (this != &copyThis)
	{
		const_cast<const char*&>(host.startCity) = copyThis.startCity;
		const_cast<const char*&>(host.endCity) = copyThis.endCity;
		const_cast<double&>(host.distance) = copyThis.distance;
	}
	return host;
}

Route& Route::operator=(const Route& copyThis)
{
	Route& host = *this;
	if (this != &copyThis)
	{
		host.legs = copyThis.legs;
		const_cast<double&>(host.totalDis) = copyThis.getDistance();
	}
	return host;
}
