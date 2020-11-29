#include <bits/stdc++.h>
#include "field.h"

#ifndef OCEANLIVER_H_INCLUDED
#define OCEANLIVER_H_INCLUDED

using namespace std;

class Oceanliver
{
    protected:
      int id,hpm,hp,hps,x,y,birth,sub; bool alive;
    public:
      Oceanliver();
      Oceanliver(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE);
      void setsub(int u);
      int getsub();
      void setid(int d);
      int getid();
      void setcoord(int xx, int yy);
      int getX(); int getY();
      void sethp(int q);
      int gethp();
      void sethps(int q);
      int gethps();
      void setalive(bool a);
      bool getalive();
      void setbirth(int bb);
      int getbirth();
      int gethpm();
};



#endif // OCEANLIVER_H_INCLUDED
