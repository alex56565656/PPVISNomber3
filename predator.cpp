#include <bits/stdc++.h>
#include "field.h"
#include "oceanliver.h"
#include "plankton.h"
#include "predator.h"

      Predator::Predator() : Oceanliver()
      {
          ssize=0; hung=0; hungm=0; gender=0;
      }
      Predator::Predator(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE, int SSIZE, int HUNG, int HUNGM, bool GENDER) : Oceanliver(ID,X,Y,HP,HPS,BIRTH,ALIVE)
      {
          ssize=SSIZE; hung=HUNG; hungm=HUNGM; gender=GENDER;
      }
      void Predator::setssize(int ss){ ssize=ss; }
      int Predator::getssize(){ return ssize; }
      void Predator::sethung(int h){ hung=h; }
      int Predator::gethung(){ return hung; }
      void Predator::sethungm(int h){ hungm=h; }
      int Predator::gethungm(){ return hungm; }
      void Predator::setgender(bool ggg){ gender=ggg; }
      bool Predator::getgender(){ return gender; }
      void Predator::eat(Plankton &p, Field &ff)
      {
          hung=0; p.setalive(0); ff.setArea(p.getX(),p.getY(),0,-1,p.getsub());
      }
      void Predator::eat(Predator &p, Field &ff)
      {
          if(ssize>p.getssize()){ sethung(0); p.setalive(0); ff.setArea(p.getX(),p.getY(),0,-1,p.getsub()); } else
          if(ssize<p.getssize()){ p.sethung(0); setalive(0); ff.setArea(x,y,0,-1,sub); }
      }
