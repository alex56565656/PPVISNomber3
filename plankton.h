#include <bits/stdc++.h>
#include "field.h"
#include "oceanliver.h"

#ifndef PLANKTON_H_INCLUDED
#define PLANKTON_H_INCLUDED

using namespace std;

class Plankton : public Oceanliver
{
    public:
      Plankton();
      Plankton(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE);
};

#endif // PLANKTON_H_INCLUDED
