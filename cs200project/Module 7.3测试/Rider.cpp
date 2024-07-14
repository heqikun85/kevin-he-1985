

#include "Rider.h"

#include<iostream>
using namespace std;

Rider::Rider(int a, int b)
:from(a) , to(b)
{
}

Rider& Rider::operator=(const Rider& r)
{
  Rider& host = *this;
  if (this != &r)
  {
    host.from = r.from;
    host.to = r.to;
  }

  return host;
}
