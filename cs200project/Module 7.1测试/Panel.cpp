#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Panel.h"

int Panel::Button::totalNumPress = 0;

ostream& operator<<(ostream& os, const Panel& p){
  for(unsigned int i = 0; i < p.buttons.size(); i++){
    if(p.buttons[i].lit){
      os << "[" << p.buttons[i].label << "]";
    }
  }
  return os;
}

