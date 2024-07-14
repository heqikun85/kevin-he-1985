#include "Elevator.h"
#include "Panel.h"

#include <iostream>
#include <vector>
using namespace std;

#include <cstdlib>

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

	cout.width(16);
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

