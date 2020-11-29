#include <bits/stdc++.h>
#include "field.h"
#include "oceanliver.h"
#include "plankton.h"

#ifndef PREDATOR_H_INCLUDED
#define PREDATOR_H_INCLUDED

using namespace std;

class Predator : public Oceanliver
{
    protected:
      int ssize,hung,hungm; bool gender;
    public:
      Predator();
      Predator(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE, int SSIZE, int HUNG, int HUNGM, bool GENDER);
      void setssize(int ss);
      int getssize();
      void sethung(int h);
      int gethung();
      void sethungm(int h);
      int gethungm();
      void setgender(bool ggg);
      bool getgender();
      void eat(Plankton &p, Field &ff);
      void eat(Predator &p, Field &ff);
};

#endif // PREDATOR_H_INCLUDED
