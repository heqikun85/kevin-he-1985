#include "Building.h"
#include "Floor.h"
#include "Rider.h"
#include "Panel.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits


Floor::Floor(const int elevation, const char* const name, const char* const label)
:name(name), label(label), elevation(elevation)
{
	panel.addButton(UP);
	panel.addButton(DOWN);
	if (TOP < elevation) TOP = elevation;
	if (elevation < BOTTOM) BOTTOM = elevation;
}

ostream& operator<<(ostream& out, const Floor& floor)
{
	out.width(3);
	out << floor.label;
	out.width(15);
	out << floor.name << " at";
	out.width(6);
	out << floor.elevation;
	out << "\" Up/Down:";
	out.width(4);
	out << floor.upRiders.size() << "/" << floor.downRiders.size()
			<< "   Button:  " << floor.panel;
	return out;
}

void Floor::addRider(const Rider& r)
{
	if(r.goingUp)
		{
			this->upRiders.push(r);
			panel.press(UP);
		}
	else if(r.goingDown)
		{
			this->downRiders.push(r);
			panel.press(DOWN);
		}
	else throw "ADD_RIDER ERROR!";
}




////////////////////////////

#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include "Panel.h"
#include "Rider.h"

class Floor
{
	queue<Rider> upRiders, downRiders;
	
	public:
	Floor(const int, const char* const, const char* const); // elevation (inches above ground) of floor, name and label
	operator int() const {return elevation;}
	bool hasUpRider( ) const {return !upRiders.empty() ? true : false;}
	bool hasDownRider( ) const {return !downRiders.empty() ? true : false;}
	void addRider(const Rider&); 
	
	static const char* const UP;
	static const char* const DOWN;
	static int TOP, BOTTOM;
	
	Panel panel;
	const string name; // name of floor, for example: Mezzanine
	const string label; // as it appears on the button panel
	const int elevation; // inches above ground level

	// for external reporting
	friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};
#endif