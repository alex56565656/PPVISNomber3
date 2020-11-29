#include <bits/stdc++.h>

#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

using namespace std;

class Field
{
    protected:
      struct subarea
      {
          int type,id;
      };
      struct area
      {
          subarea x1,x2,x3,x4;
      };
      int N,M; vector< vector<area> > F;
    public:
      Field();
      Field(int n, int m);
      int getArea(int x, int y);
      int getSubType(int x, int y, int sb);
      void setArea(int x, int y, int tp, int I, int sub);
};

#endif // FIELD_H_INCLUDED
