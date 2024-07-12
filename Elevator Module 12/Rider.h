#include<iostream>
#include<cstring>
using namespace std;

#ifndef Rider_h
#define Rider_h

struct Rider
{
	int from , to;
	Rider(int, int);
	Rider& operator=(const Rider&);
	
	public:
	const bool goingUp, goingDown;
};

#endif