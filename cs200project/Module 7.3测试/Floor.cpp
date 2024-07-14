//Programmer: Siming Zhang
//Programmer ID: 1712438

#include "Floor.h"
#include "Rider.h"
#include "Panel.h"

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
:elevation(elevation) , name(name), label(label)
{
  panel.addButton(UP);
  panel.addButton(DOWN);
  if (TOP < elevation) TOP = elevation;
  if (elevation < BOTTOM) BOTTOM = elevation;
}

ostream& operator<<(ostream& out, const Floor& floor)
{
  out << setw(2) << floor.label << setw(15) << floor.name << " at" << setw(8) << floor.elevation << "\" Up/Down:  " << setw(2) << floor.upRiders.size() << "/" << floor.downRiders.size() << setw(12) << "Buttons: " << floor.panel;
  return out;
}
