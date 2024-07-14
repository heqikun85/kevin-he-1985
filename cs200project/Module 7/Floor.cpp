//Programmer: Siming Zhang
//Programmer ID: 1712438

#include "Floor.h"
#include "Rider.h"
#include "Panel.h"
#include "Building.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label)
: elevation(elevation), name(name), label(label)
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
  out.width(14);
  out << floor.name << " at";
  out.width(6);
  out << floor.elevation;
  out << "\" Up/Down:";
  out.width(4);
  out << floor.upRiders.size() << "/" << floor.downRiders.size() << "   Button:  " << floor.panel;
  
  return out;
}
// add for Assignment 7
void Floor::addRider(const Rider& r)
{
  if(r.goingDown)
  {
    downRiders.push(r);
    panel.press(DOWN);
  }
  else
  {
    upRiders.push(r);
    panel.press(UP);
  }
}