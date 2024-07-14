//Programmer: Siming Zhang
//Programmer ID: 1712438

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

//class
class Leg
{
	const char* const startCity;
	const char* const endCity;
	const int distance;

	public:
	Leg(const char* const, const char* const, int);
	Leg& operator=(const Leg&);
	int getDistance() const {return distance;}
	void output(ostream&) const;
	friend class Route;// friend class
	friend class ShortestRoute;
};

class Route
{
	vector<const Leg*> legs; // bag of legs
	const int totalDis;

	public:
	Route(const Leg&);
	Route(const Route&, const Leg&);
	Route& operator=(const Route&);
	int getDistance() const {return totalDis;}
	void output(ostream&) const;
	friend bool operator<(const Route&, const Route&); 
};

class ShortestRoute
{
	static const Leg allLegs[];

	public:
	static const Route anyRoute(const char* const, const char* const);
	static const Route shortestRoute(const char* const, const char* const);
};

const Leg ShortestRoute::allLegs [] =
{
	//41 legs
	Leg("Memphis", "Orlando", 684),
	Leg("Miles City", "Fargo", 430),
	Leg("Fargo", "Minneapolis", 214),
	Leg("Fargo", "Chicago", 569),
	Leg("Denver", "Omaha", 484),
	Leg("Denver", "Oklahoma City", 504),
	Leg("Memphis", "Washington", 763),
	Leg("New Orleans", "Orlando", 533),
	Leg("San Francisco", "Las Angeles", 352),
	Leg("Minneapolis", "Cleveland", 630),
	Leg("Chicago", "Cleveland", 307),
	Leg("Cleveland", "Pittsburgh", 115),
	Leg("Pittsburgh", "New York City", 315),
	Leg("Chicago", "Pittsbrugh", 409),
	Leg("San Francisco", "Portland", 536),
	Leg("Reno", "Salt Lake City", 427),
	Leg("Las Angeles", "Phoenix", 357),
	Leg("San Francisco", "Reno", 186),
	Leg("El Paso", "Houston", 674),
	Leg("El Paso", "Oklahoma City", 576),
	Leg("Helena", "Miles City", 294),
	Leg("Helena", "Fargo", 721),
	Leg("Miles City", "Omaha", 606),
	Leg("Reno", "Phoenix", 601),
	Leg("Portland", "Helena", 520),
	Leg("Salt Lake City", "Denver", 371),
	Leg("Salt Lake City", "Miles City", 494),
	Leg("Omaha", "Chicago", 435),
	Leg("Omaha", "St. Louis", 357),
	Leg("Omaha", "Memphis", 531),
	Leg("Oklahoma City", "Memphis", 421),
	Leg("Houston", "Memphis", 485),
	Leg("Houston", "New Orleans", 318),
	Leg("St. Louis", "Philadelphia", 809),
	Leg("Phoenix", "Denver", 586),
	Leg("Phoenix", "El Paso", 345),
	Leg("Chicago", "Philadelphia", 664),
	Leg("Memphis", "Philadelphia", 879),
	Leg("Orlando", "Washington", 759),
	Leg("Washington", "Baltimore", 39),
	Leg("Philadelphia", "New York City", 96),
};

int main()
{
	cout << "Programmer: Siming Zhang" << endl;// programmer's Info
	cout << "Programmer's ID: 1712438" << endl;
	cout << endl;
	
	cout << "Shortest route: " << endl;
	const Route shortestRoute = ShortestRoute::shortestRoute("San Francisco", "New York City");
	shortestRoute.output(cout);
	cout << endl;

	cout << endl << "Any route: " << endl;
	const Route anyRoute = ShortestRoute::anyRoute("San Francisco", "New York City");
	anyRoute.output(cout);
	cout << endl;

	return 0;
}

//functions
const Route ShortestRoute::anyRoute(const char* const start, const char* const end) 
{
	for(int i = 0; i < (sizeof(allLegs)/sizeof(*allLegs)); i++) 
	{
		if(strcmp(ShortestRoute::allLegs[i].endCity, end) == 0) 
		{
			if(strcmp(ShortestRoute::allLegs[i].startCity, start) == 0) 
			{
				Route anyR(allLegs[i]);
				return anyR;
			}
			else 
			{
				Route anyR(ShortestRoute::anyRoute(start, ShortestRoute::allLegs[i].startCity),allLegs[i]);
				return anyR;
			}
		}
	}
	throw "Can't find a possible route!";
}

const Route ShortestRoute::shortestRoute(const char* const start, const char* const end)
{
	set<Route> allRoutes;// auto sort

	for(int i = 0; i < (sizeof(allLegs)/sizeof(*allLegs)); i++) 
	{
		if(strcmp(ShortestRoute::allLegs[i].endCity, end) == 0) 
		{
			if(strcmp(ShortestRoute::allLegs[i].startCity, start) == 0) 
			{
				Route shortestR(allLegs[i]);
				allRoutes.insert(shortestR);
			}
			else 
			{
				Route oneR(ShortestRoute::anyRoute(start, ShortestRoute::allLegs[i].startCity), allLegs[i]);
				allRoutes.insert(oneR); 
			}
		}
	}
	if(!allRoutes.empty()) return *(allRoutes.begin());
	throw "Can't find the shortest route!";
}

bool operator<(const Route& x, const Route& y)
{
	return (x.totalDis < y.totalDis);
}

//getter functions
void Route::output(ostream& out) const
{
	out << legs[0]->startCity << " to ";
	for(int i = 0 ; i < legs.size() ; i++)
	{
		if (i < (legs.size() - 1)) out << legs[i]->endCity << " to ";
		else
		out << legs[i]->endCity << ", ";
	}
	out << totalDis << " miles.";
}

//constructor
Leg::Leg(const char* const startCity, const char* const endCity, int distance)
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
		const_cast<int&>(host.distance) = copyThis.distance;
	}
	return host;
}

Route& Route::operator=(const Route& copyThis)
{
	Route& host = *this;
	if (this != &copyThis)
	{
		host.legs = copyThis.legs;
		const_cast<int&>(host.totalDis) = copyThis.getDistance();
	}
	return host;
}


	
