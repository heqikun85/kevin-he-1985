#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
using namespace std;

#include "Rider.h"
#include "Floor.h"
#include "Panel.h"

class Elevator
{
	static const int IDLE = 0; 
	static const int UP = 1;
	static const int DOWN = -1;
	static const int COURTESY_WAIT_TIME = 3;

	// elevator metrics
	int location; // inches above ground level
	int direction; // equal to IDLE, UP, DOWN
	int atFloorIndex;
	int timer;

	vector<Rider> riders;
	
	public:
		
	const int speed; // inches per second, up or down
	const unsigned int CAPACITY; 
	
	Elevator(unsigned int, int, int);
	operator int() const {return location;}
	Panel panel;
	
	// count-down timer before closing door
	void resetTimer() {timer = COURTESY_WAIT_TIME;}
	void tickTimer() {timer--;}
	bool timedOut() const {return timer == 0;}
	
	bool isOpen() const {return atFloorIndex >= 0;}
	void openDoorTo(int);
	void board(const Rider&);// adds a Rider to the Elevator
	
	bool hasRiderForFloor() const;
	void removeRider();
	bool isFull() const {return CAPACITY == riders.size();}
	bool goingUp() const {return direction == UP;}
	bool goingDown() const {return direction == DOWN;}
	int getFloorIndex() const {return atFloorIndex;}
	unsigned int getNumberOfRiders() const {return riders.size();}
 
	// friend function
	friend ostream& operator<<(ostream&, const Elevator&); 
};

#endif
