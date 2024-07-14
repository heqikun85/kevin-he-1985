//Programmer: Siming Zhang
//Programmer ID: 1712438

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//class
class Leg
{
	const char* const startCity;
	const char* const endCity;
	const double distance;

	public:
	Leg(const char* const, const char* const, const double);
	Leg& operator=(const Leg&);
	double getDistance() const;
	void output(ostream&) const;
};

int main()
{
	cout << "Programmer: Siming Zhang" << endl;// programmer's Info
	cout << "Programmer's ID: 1712438" << endl;
	cout << endl;

	Leg ary[] = 
	{
		Leg("Hayward", "Union City", 6.9),//40 legs 
		Leg("Marin", "San Rafael", 2.9),
		Leg("Pleasant Hill", "Pacheco", 3.9),
		Leg("Pleasant Hill", "Concord", 3),
		Leg("San Ramon", "Pleasanton", 6.7),
		Leg("Pleasanton", "Livermore", 4.2),
		Leg("Livermore", "Tracy", 10.2),
		Leg("Tracy", "Stockton", 20.2),
		Leg("Martinez", "Pleasant Hill", 4.9),
		Leg("Novato", "San Rafael", 6.2),
		
		Leg("Fremont", "Walnut Creek", 30.8),
		Leg("Pleasanton", "San Rafael", 10.9),
		Leg("Fremont", "Pacheco", 40.1),
		Leg("Pacheco", "Concord", 3.1),
		Leg("San Jose", "Santa Cruz", 30.5),
		Leg("Marin", "Richmond", 14.9),
		Leg("Oakland", "Richmond", 15.2),
		Leg("Emeryville", "Berkeley", 16.9),
		Leg("Davis", "Sacramento", 14.2),
		Leg("Fairfield", "Davis", 24.8),
		
		Leg("Concord", "Walnut Creek", 2.1),
		Leg("Alameda", "Oakland", 4.3),
		Leg("San Jose", "Cupertino", 7.5),
		Leg("El Cerrito", "Richmond", 5.2),
		Leg("San Leandro", "Hayward", 7.8),
		Leg("Union City", "Milpitas", 8.4),
		Leg("Milpitas", "Sunnyvale", 9.3),
		Leg("Morgan Hill", "Gilroy", 9.8),
		Leg("Benicia", "Vallejo", 10.2),
		Leg("Martinez", "Benicia", 11.5),
		
		Leg( "Vallejo", "Fairfield", 25),
		Leg("Morgan Hill", "San Jose", 11.6),
		Leg("San Francisco", "Daly City", 12.6),
		Leg("Vacaville", "Davis", 13.1),
		Leg("Fremont", "Milpitas", 13.6),
		Leg("Daly City", "San Mateo", 14.5),
		Leg("Fairfield", "Vacaville", 14.9),
		Leg("Sunnyvale", "Cupertino", 16.4),
		Leg("San Rafael", "San Francisco", 20.8),
		Leg("Vallejo", "Napa", 26)
		
	};

	//help get the size of Leg objects array
	const int legSize = sizeof(ary)/sizeof(Leg);
	
	//sorting loop
	for (int i = 0; i < legSize; i++)
	{
		for (int j = i+1 ; j < legSize; j++)
		{
			if (ary[i].getDistance() > ary[j].getDistance())
			{
				swap(ary[i], ary[j]);
			}
		}
	}
		
	//output sorted legs
	for (int k = 0; k < legSize; k++)
	{
		ary[k].output(cout);
	}
	
	return 0;
	
}

//getter functions
double Leg::getDistance() const
{
	return distance;
}

void Leg::output(ostream& out) const
{
	out << "Leg: " << startCity << " to " << endCity << ", " << distance << " miles" << endl;
}

//constructor
Leg::Leg(const char* const startCity, const char* const endCity, double distance)
:startCity(startCity), endCity(endCity), distance(distance) 
{
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