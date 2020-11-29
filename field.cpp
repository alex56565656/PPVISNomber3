#include <bits/stdc++.h>
#include "field.h"

      Field::Field(){}
      Field::Field(int n, int m)
      {
          subarea q; q.type=0; q.id=-1;
          area Q; Q.x1=q; Q.x2=q; Q.x3=q; Q.x4=q;
          vector<area> ff; for(int o=0; o<m; o++)ff.push_back(Q);
          for(int o=0; o<n; o++)F.push_back(ff);
      }
      int Field::getArea(int x, int y)
      {
          if(F[x][y].x1.id==-1)return 1; else if(F[x][y].x2.id==-1)return 2; else
          if(F[x][y].x3.id==-1)return 3; else if(F[x][y].x4.id==-1)return 4; else return 0;
      }
      int Field::getSubType(int x, int y, int sb)
      {
          if(sb==1)return F[x][y].x1.type; else
          if(sb==2)return F[x][y].x2.type; else
          if(sb==3)return F[x][y].x3.type; else
          if(sb==4)return F[x][y].x4.type;
      }
      void Field::setArea(int x, int y, int tp, int I, int sub)
      {
          if(sub==1){ F[x][y].x1.id=I; F[x][y].x1.type=tp; } else
          if(sub==2){ F[x][y].x2.id=I; F[x][y].x2.type=tp; } else
          if(sub==3){ F[x][y].x3.id=I; F[x][y].x3.type=tp; } else
          if(sub==4){ F[x][y].x4.id=I; F[x][y].x4.type=tp; }
      }
