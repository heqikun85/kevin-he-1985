

#ifndef Rider_h
#define Rider_h

#include<iostream>
using namespace std;

#include<cstring>

struct Rider
{
  int to;
  int from;
  Rider(int, int);
  Rider& operator=(const Rider&);
};

#endif
