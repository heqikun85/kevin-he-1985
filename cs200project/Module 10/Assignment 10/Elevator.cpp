//Programmer: Siming Zhang
//Programmer ID: 1712438

#include "Elevator.h"
#include "Panel.h"
#include "Building.h"
#include "Floor.h"

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

Elevator::Elevator(unsigned int capacity, int speed, int start)
:speed(speed), CAPACITY(capacity), location(Building::floors[start])
{
	start = Building::floors[start];
	direction = IDLE;
	timer = 0;
	atFloorIndex = -1;

	for(int i = 0; i < Building::FLOORS; i++)
	{
		panel.addButton(Building::floors[i].label);
	}
}

ostream& operator<<(ostream& out, const Elevator& e)
{
	cout << "Elevator at ";
	cout.width(5);
	cout << e.location;

	cout.width(11);
	switch(e.direction)
	{
		case 1:
		  cout << "going UP";
		  break;
		case -1:
		  cout << "going DOWN";
		  break;
		case 0:
		  cout << "IDLE";
		  break;
	}

	cout.width(3);
	cout << e.riders.size() << " riders";

	cout.width(15);
	if(e.atFloorIndex != -1)
		cout << " door is OPEN|" << e.timer;
	else
	{
		cout.width(15);
		cout << " ";
	}
	cout << " " << e.panel;

	return out;
}

void Elevator::openDoorTo(int thisFloor)
{
	//this function is for opening door and clearing the specific button on the floor.
	panel.clear(Building::floors[thisFloor].label);
	atFloorIndex = thisFloor;//set atFloorIndex to the referenced floor's index
	resetTimer(); //resetting timer 
}

void Elevator::board(const Rider& r)
{
	riders.push_back(r);
	panel.press(Building::floors[r.to].label);

	if(r.to > r.from) direction = Elevator::UP;
	else direction = Elevator::DOWN;

	resetTimer(); //resetting timer 
}

bool Elevator::hasRiderForFloor() const
{
	if(atFloorIndex == -1)//atFloorIndex equals -1 means the door is closed.
		return false;

	for(int i = 0; i < riders.size(); i++)
	//(.to member) equals the elevator's current floor ( atFloorIndex member)
		if(riders[i].to == atFloorIndex)
			return true; // find rider for floor

	return false; // end of function
}

void Elevator::removeRider()
{
	for(vector<Rider>::iterator it = riders.begin(); it != riders.end(); ++it)
	{
		if(it->to == atFloorIndex)
		{
			//clear the host elevator's panel button for the elevator's current floor
			panel.clear(Building::floors[it->to].label);
			riders.erase(it);// erase that rider
			resetTimer();
			break;
		}
	}
}
