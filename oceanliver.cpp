#include <bits/stdc++.h>
#include "field.h"
#include "oceanliver.h"

      Oceanliver::Oceanliver()
      {
          hpm=0; sub=0; id=-1; x=-1; y=-1; hp=0; hps=0; birth=2e9; alive=0;
      }
      Oceanliver::Oceanliver(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE)
      {
          sub=0; id=ID; x=X; y=Y; hp=HP; hps=HPS; hpm=hp; birth=BIRTH; alive=ALIVE;
      }
      void Oceanliver::setsub(int u){ sub=u; }
      int Oceanliver::getsub(){ return sub; }
      void Oceanliver::setid(int d){ id=d; }
      int Oceanliver::getid(){ return id; }
      void Oceanliver::setcoord(int xx, int yy){ x=xx; y=yy; }
      int Oceanliver::getX(){ return x; }
      int Oceanliver::getY(){ return y; }
      void Oceanliver::sethp(int q){ hp=q; }
      int Oceanliver::gethp(){ return hp; }
      void Oceanliver::sethps(int q){ hps=q; }
      int Oceanliver::gethps(){ return hps; }
      void Oceanliver::setalive(bool a){ alive=a; }
      bool Oceanliver::getalive(){ return alive; }
      void Oceanliver::setbirth(int bb){ birth=bb; }
      int Oceanliver::getbirth(){ return birth; }
      int Oceanliver::gethpm(){ return hpm; }
