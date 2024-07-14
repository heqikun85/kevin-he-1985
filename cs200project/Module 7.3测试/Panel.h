#ifndef Panel_h
#define Panel_h

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Panel
{
  struct Button
  {
    string label;
    bool status;
    int clockTime;
    static int globalClock;
  };
  friend ostream& operator<<(ostream&, const Button&);
  vector<Button> buttons;

public:
  void addButton(string);
  void press(string);
  void clear(string);

  //getter
  string getFirstLit() const;
  bool isLit(string) const;
  bool areAnyLit() const;
  friend ostream& operator<<(ostream&, const Panel&);
};

#endif
