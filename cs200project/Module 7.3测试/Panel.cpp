
#include "Panel.h"

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Panel::Button::globalClock = 0;

ostream& operator<<(ostream& out, const Panel::Button& b)
{
  out << b.label;
  return out;
}

ostream& operator<<(ostream& out, const Panel& p)
{
  for(unsigned int i = 0 ; i < p.buttons.size() ; i++)
  {
    if(p.buttons[i].status)
    {
      out << "[" << p.buttons[i] << "]";
    }
  }
  return out;
}

void Panel::addButton(string addThis)
{
  Button createButton; // create the button

  createButton.label = addThis;
  createButton.status = false;

  buttons.push_back(createButton); //get the newly created button to the bag
}

void Panel::press(string pressed)
{
  //search the bag of buttons and lit a button.
  for(unsigned int i = 0; i < buttons.size() ; i++)
  {
    if(buttons[i].label == pressed && buttons[i].status == 0) buttons[i].status = true;
    Button::globalClock++;
    buttons[i].clockTime = Button::globalClock;
  }
}

void Panel::clear(string clearThis)
{
  //search through the bag and unlit a button.
  for(unsigned int i = 0; i < buttons.size() ; i++)
  {
    if(buttons[i].label == clearThis) buttons[i].status = false;
  }
}

bool Panel::areAnyLit() const
{
  //search through the bag to find for any lit buttons
  // if no lit button returns false, if a lit button is found
  // returns true
  for(unsigned int i = 0; i < buttons.size() ; i++)
  {
    if(buttons[i].status) return true;
  }

  return false;
}

string Panel::getFirstLit() const
{
  int MinClockTime;
  int count = 0;

  // cycles through all the lit buttons, look at the clock time
  // returns the label of the first pressed
  for(unsigned int i = 0; i < buttons.size() ; i++)
  {
    if(buttons[i].status)
    {
      if(count == 0)
      {
        MinClockTime = buttons[i].clockTime;
        count++;
      }
      else if(buttons[i].clockTime < MinClockTime) MinClockTime = buttons[i].clockTime;
    }
  }

  for(unsigned int j = 0; j < buttons.size() ; j++)
  {
    if(MinClockTime == buttons[j].clockTime) return buttons[j].label;
  }

  return "";
}

bool Panel::isLit(string label) const
{
  // cycles through buttons and find the expected label
  // returns true if lit, false otherwise

  for(unsigned int i = 0 ; i < buttons.size() ; i++)
  {
    if(buttons[i].label == label && buttons[i].status) return true;
  }

  return false;
}
