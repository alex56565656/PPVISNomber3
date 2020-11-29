#include <bits/stdc++.h>
#include "field.h"
#include "plankton.h"
#include "predator.h"
#include "angrypredator.h"

      AngryPredator::AngryPredator() : Predator(){ aim=-1; };
      AngryPredator::AngryPredator(int ID, int X, int Y, int HP, int HPS, int BIRTH, bool ALIVE, int SSIZE, int HUNG, int HUNGM, bool GENDER, int AIM) : Predator(ID,X,Y,HP,HPS,BIRTH,ALIVE,SSIZE,HUNG,HUNGM,GENDER){ aim=AIM; };
      void AngryPredator::setaim(int q){ aim=q; }
      int AngryPredator::getaim(){ return aim; }
      void AngryPredator::eat(Plankton &p, Field &ff)
      {
          hung=0; p.setalive(0); ff.setArea(p.getX(),p.getY(),0,-1,p.getsub());
      }
      void AngryPredator::eat(Predator &p, Field &ff)
      {
          if(ssize>p.getssize()){ sethung(0); p.setalive(0); ff.setArea(p.getX(),p.getY(),0,-1,p.getsub()); }
          //else if(ssize<p.getssize()){ p.sethung(0); setalive(0); }
      }
      void AngryPredator::eat(AngryPredator &p, Field &ff)
      {
          if(ssize>p.getssize()){ sethung(0); p.setalive(0); ff.setArea(p.getX(),p.getY(),0,-1,p.getsub()); } else
          if(ssize<p.getssize()){ p.sethung(0); setalive(0); ff.setArea(x,y,0,-1,sub); }
      }
