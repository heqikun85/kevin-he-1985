//Programmer: Siming Zhang
//Programmer ID: 1712438

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
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
	double getDistance() const {return distance;}
	void output(ostream&) const;
	friend class Route;// friend class
};

class Route
{
	vector<const Leg*> legs;// bag of legs
	const double totalDis;

	public:
	Route(const Leg&);
	Route(const Route&, const Leg&);
	Route& operator=(const Route&);
	double getDistance() const {return totalDis;}
	void output(ostream&) const;
};

int main()
{
	cout << "Programmer: Siming Zhang" << endl;// programmer's Info
	cout << "Programmer's ID: 1712438" << endl;
	cout << endl;

	Leg l[] = 
	{
		Leg("San Leandro", "Hayward", 7.8),
		Leg("Hayward", "Union City", 6.9), 
		Leg("Union City", "Milpitas", 8.4),
		Leg("Milpitas", "Sunnyvale", 9.3),
		Leg("Sunnyvale", "Cupertino", 16.4),
		Leg("Cupertino", "San Jose", 3.6),
		Leg("San Jose", "Cupertino", 7.5),
		Leg("Cupertino", "Santa Cruz", 30.5),
		Leg("Santa Cruz", "Fremont", 40.5),
		Leg("Fremont", "Walnut Creek", 30.8),
		Leg("Walnut Creek", "Pleasant Hill", 8.3),
		Leg("Pleasant Hill", "Lafayette", 7.9),
		Leg("Lafayette", "Concord", 3),
		Leg("Concord", "Pleasanton", 16.7),
		Leg("Pleasanton", "Livermore", 4.2),
		Leg("Livermore", "Tracy", 10.2),
		Leg("Tracy", "Stockton", 20.2),
		Leg("Stockton", "Martinez", 4.9),
		Leg("Martinez", "Benicia", 11.5),
		Leg("Benicia", "Vallejo", 10.2),
		Leg("Vallejo", "Fairfield", 25),
		Leg("Fairfield", "Vacaville", 14.9),
		Leg("Vacaville", "Davis", 13.1),
		Leg("Davis", "Sacramento", 14.2),
		Leg("Sacramento", "San Rafael", 6.2),
		Leg("San Rafel", "Marin", 30.8),
		Leg("Marin", "Richmond", 14.9),
		Leg("Richmond", "Oakland", 15.2),
		Leg("Oakland", "Pacheco", 40.1),
		Leg("Pacheco", "Concord", 3.1),
		Leg("Concord", "Alameda", 16.1),
		Leg("Alameda", "Berkeley", 8.3),
		Leg("Berkeley", "Emeryville", 8.3),
		Leg("Emeryville", "El Cerrito", 8.3),
		Leg("El Cerrito", "Morgan Hill", 25.2),
		Leg("Morgan Hill", "Gilroy", 9.8),
		Leg("Gilroy", "Daly City", 12.6),
		Leg("Daly City", "San Mateo", 14.5),
		Leg("San Mateo", "San Francisco", 20.8),
		Leg("San Francisco", "Napa", 48),
		Leg("San Jose", "Santa Cruz", 30.5),	
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
		Route(r[6], l[7]),
		Route(r[7], l[8]),
		Route(r[8], l[9]),
		Route(r[9], l[10]),
		Route(r[10], l[11]),
		Route(r[11], l[12]),
		Route(r[12], l[13]),
		Route(r[13], l[14]),
		Route(r[14], l[15]),
		Route(r[15], l[16]),
		Route(r[16], l[17]),
		Route(r[17], l[18]),
		Route(r[18], l[19]),
		Route(r[19], l[20]),
		Route(r[20], l[21]),
		Route(r[21], l[22]),
		Route(r[22], l[23]),
		Route(r[23], l[24]),
		Route(r[24], l[25]),
		Route(r[25], l[26]),
		Route(r[26], l[27]),
		Route(r[27], l[28]),
		Route(r[28], l[29]),
		Route(r[29], l[30]),
		Route(r[30], l[31]),
		Route(r[31], l[32]),
		Route(r[32], l[33]),
		Route(r[33], l[34]),
		Route(r[34], l[35]),
		Route(r[35], l[36]),
		Route(r[36], l[37]),
		Route(r[37], l[38]),
		Route(r[38], l[39])
		
	};
	
	//help get the size of Leg objects array
	const int routeSize = sizeof(r)/sizeof(Route);
	
	cout << "************ There are total " << routeSize << " routes *************" << endl;
	
	//sorting loop
	for (int i = 0; i < routeSize; i++)
	{
		for (int j = i+1 ; j < routeSize; j++)
		{
			if (r[i].getDistance() < r[j].getDistance())
			{
				swap(r[i], r[j]);
			}
		}
	}
			
	//output sorted legs
	for (int i = 0; i < routeSize; i++)
	{
		r[i].output(cout);
	}
	return 0;
		
}

//getter functions
void Route::output(ostream& out) const
{
	out << "/nRoutes: " << legs[0]->startCity << " to ";
	for(int i = 0 ; i < legs.size() ; i++)
	{
		if (i < (legs.size() - 1)) 
			out << legs[i]->endCity << " to ";
		else
			out << legs[i]->endCity << ", ";
	}
	out << totalDis << " miles.";
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
:totalDis(strcmp(exRoute.legs.back()->endCity, newLeg.startCity) == 0 ? exRoute.totalDis + newLeg.distance : exRoute.totalDis)
{
	legs = exRoute.legs;

	try
	{
		if(strcmp(exRoute.legs.back()->endCity, newLeg.startCity) != 0)
			throw "Cities don't match!";
			legs.push_back(&newLeg); // add new leg to route
	}
	catch(const char* error)
	{
		cout << error << endl;
	}

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


