
#include <bits/stdc++.h>
#include "field.h"
#include "predator.h"
#include "plankton.h"

#ifndef ANGRYPREDATOR_H_INCLUDED
#define ANGRYPREDATOR_H_INCLUDED

using namespace std;

class AngryPredator : public Predator
{
    protected:
      int aim;
    public:
      AngryPredator();
      AngryPredator(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE, int SSIZE, int HUNG, int HUNGM, bool GENDER, int AIM);
      void setaim(int q);
      int getaim();
      void eat(Plankton &p, Field &ff);
      void eat(Predator &p, Field &ff);
      void eat(AngryPredator &p, Field &ff);
};

#endif // ANGRYPREDATOR_H_INCLUDED
