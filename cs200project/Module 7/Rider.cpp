//Programmer: Siming Zhang
//Programmer ID: 1712438

#include "Rider.h"
#include "Building.h"

Rider::Rider(int a, int b)
:to(b), from(a), goingUp(Building::floors[to] > Building::floors[from]),
goingDown(Building::floors[to] < Building::floors[from])
{
}

Rider& Rider::operator=(const Rider& r)
{
	Rider& host = *this;
	if (this != &r)
	{
	  host.from = r.from;
	  host.to = r.to;
	  const_cast<bool&>(host.goingDown) = r.goingDown;//two newly added const bool
	  const_cast<bool&>(host.goingUp) = r.goingUp;
	}
  return host;
}
