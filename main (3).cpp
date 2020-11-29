#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <windows.h>
#include "field.h"
#include "oceanliver.h"
#include "plankton.h"
#include "predator.h"
#include "angrypredator.h"

#define fi first
#define se second

using namespace std;



void addPlankton(Plankton P, vector<Plankton> &v, vector<sf::RectangleShape> &V, sf::RectangleShape &S, int &K)
{
    int j=-1; for(int i=0; i<v.size(); i++)if(!v[i].getalive()){ j=i; break; }
    if(j>=0)v[j]=P,V[j]=S; else v.push_back(P),V.push_back(S); K++;
}

void addPredator(Predator P, vector<Predator> &v, vector<sf::RectangleShape> &V, sf::RectangleShape &S, int &K)
{
    int j=-1; for(int i=0; i<v.size(); i++)if(!v[i].getalive()){ j=i; break; }
    if(j>=0)v[j]=P,V[j]=S; else v.push_back(P),V.push_back(S); K++;
}

void addAngryPredator(AngryPredator P, vector<AngryPredator> &v, vector<sf::RectangleShape> &V, sf::RectangleShape &S, int &K)
{
    int j=-1; for(int i=0; i<v.size(); i++)if(!v[i].getalive()){ j=i; break; }
    if(j>=0)v[j]=P,V[j]=S; else v.push_back(P),V.push_back(S); K++;
}



int main()
{
    srand(time(0)); string S; int DELAY=1000,p,p1,p2,p3,p4,dx,dy,i,j,ii,jj,sq,n=1,m=1,PlN=0,PrN=0,ApN=0,ID,X,Y,HP,HPS,BIRTH,SSIZE,AIM,HUNG,HUNGM,kk,g; bool ALIVE,GENDER,WORK;
    ifstream input; input.open("data.txt"); input >> n >> m; Field f(n,m); pair<int,int> D[4] { {1,0},{-1,0},{0,1},{0,-1} }; vector< pair<int,int> > vv;
    ofstream output; output.open("ata.txt"); //output << "ok1" << endl; output << "ok2" << endl;
    vector<Plankton> vPl,Pl; vector<Predator> vPr,Pr; vector<AngryPredator> vAp,Ap; vector<sf::RectangleShape> plan,pr,ap;

    sf::Image bgi,areai,plani,pri,api,pfi,afi;
    sf::Texture bgt,areat,plant,prt,apt,pft,aft;
    sf::RectangleShape bg,plank,prk,apk,pfk,afk,arear[n][m];

    int sizeX=GetSystemMetrics(SM_CXSCREEN); int sizeY=GetSystemMetrics(SM_CYSCREEN);
    srand(time(0)); sf::ContextSettings settings; settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(sizeX,sizeY), "LABA3",sf::Style::Fullscreen, settings);

    bgi.loadFromFile("bg.jpg"); bgt.loadFromImage(bgi); bg.setTexture(&bgt); bg.setSize(sf::Vector2f(sizeX,sizeY));
    areai.loadFromFile("area.png"); areat.loadFromImage(areai);

    sq=sizeX/m; if(sq*n>sizeY)sq=sizeY/n;

    plani.loadFromFile("plan.jpg");
    plani.createMaskFromColor(plani.getPixel(0,0));
    plant.loadFromImage(plani);f.setArea(vPl[i].getX(),vPl[i].getY(),0,-1,vPl[i].getsub());
    plank.setTexture(&plant);
    plank.setSize(sf::Vector2f(sq/2,sq/2));

    pri.loadFromFile("sm.jpg");
    pri.createMaskFromColor(pri.getPixel(0,0));
    prt.loadFromImage(pri);
    prk.setTexture(&prt);
    prk.setSize(sf::Vector2f(sq/2,sq/2));

    pfi.loadFromFile("sf.jpg");
    pfi.createMaskFromColor(pfi.getPixel(0,0));
    pft.loadFromImage(pfi);
    pfk.setTexture(&pft);
    pfk.setSize(sf::Vector2f(sq/2,sq/2));

    api.loadFromFile("asm.jpg");
    api.createMaskFromColor(api.getPixel(0,0));
    apt.loadFromImage(api);
    apk.setTexture(&apt);
    apk.setSize(sf::Vector2f(sq/2,sq/2));

    afi.loadFromFile("asf.jpg");
    afi.createMaskFromColor(afi.getPixel(0,0));
    aft.loadFromImage(afi);
    afk.setTexture(&aft);
    afk.setSize(sf::Vector2f(sq/2,sq/2));


    input >> kk; for(i=0; i<kk; i++)
    {
        input >> X >> Y >> HP >> HPS >> BIRTH;
        addPlankton(Plankton(PlN,X,Y,HP,HPS,BIRTH,1),vPl,plan,plank,PlN);
    }
    //int SSIZE, int AIM, int HUNG, int HUNGM, bool GENDER

    input >> kk; for(i=0; i<kk; i++)
    {
        input >> X >> Y >> HP >> HPS >> SSIZE >> HUNG >> HUNGM >> g;
        if(g)addPredator(Predator(PrN,X,Y,HP,HPS,0,1,SSIZE,HUNG,HUNGM,1),vPr,pr,prk,PrN);
        else addPredator(Predator(PrN,X,Y,HP,HPS,0,1,SSIZE,HUNG,HUNGM,0),vPr,pr,pfk,PrN);
    }
    input >> kk; for(i=0; i<kk; i++)
    {
        input >> X >> Y >> HP >> HPS >> SSIZE >> HUNG >> HUNGM >> g;
        if(g)addAngryPredator(AngryPredator(ApN,X,Y,HP,HPS,0,1,SSIZE,HUNG,HUNGM,1,-1),vAp,ap,apk,ApN);
        else addAngryPredator(AngryPredator(ApN,X,Y,HP,HPS,0,1,SSIZE,HUNG,HUNGM,0,-1),vAp,ap,afk,ApN);
    }


    for(i=0; i<n; i++)for(j=0; j<m; j++)
    {

        arear[i][j].setTexture(&areat);
        arear[i][j].setSize(sf::Vector2f(sq,sq));
        arear[i][j].setPosition(j*sq,i*sq);
    }
    for(i=0; i<vPl.size(); i++)
    {
        if(vPl[i].getalive())vPl[i].setsub(f.getArea(vPl[i].getX(),vPl[i].getY()));
        f.setArea(vPl[i].getX(),vPl[i].getY(),1,vPl[i].getid(),vPl[i].getsub());
    }
    for(i=0; i<vPr.size(); i++)
    {
        if(vPr[i].getalive())vPr[i].setsub(f.getArea(vPr[i].getX(),vPr[i].getY()));
        f.setArea(vPr[i].getX(),vPr[i].getY(),2,vPr[i].getid(),vPr[i].getsub());
    }
    for(i=0; i<vAp.size(); i++)
    {
        if(vAp[i].getalive())vAp[i].setsub(f.getArea(vAp[i].getX(),vAp[i].getY()));
        f.setArea(vAp[i].getX(),vAp[i].getY(),3,vAp[i].getid(),vAp[i].getsub());
    }

    while (window.isOpen())
    {
        sf::Event okno;
        while (window.pollEvent(okno))
        {

           /* if(!pesnya && Alive)
            {
                pesnya=1;
                sound.play();
            }
*/


            if(okno.type==sf::Event::Closed)window.close();
            if(okno.type==sf::Event::KeyPressed)
            {
                //if(okno.key.code==sf::Keyboard::Num1)DELAY-=100; else
                if(okno.key.code==sf::Keyboard::Q){} else
                if(okno.key.code==sf::Keyboard::Space)WORK=!WORK; else
                if(okno.key.code==sf::Keyboard::Escape)exit(0);


            }
        }
        for(i=0; i<vPl.size(); i++)for(j=0; j<vPl.size(); j++)if(i!=j && vPl[i].getX()==vPl[j].getX() && vPl[i].getY()==vPl[j].getY())vPl[j].setalive(0);
        for(i=0; i<vPr.size(); i++)for(j=0; j<vPr.size(); j++)if(i!=j && vPr[i].getX()==vPr[j].getX() && vPr[i].getY()==vPr[j].getY())vPr[j].setalive(0);
        for(i=0; i<vAp.size(); i++)for(j=0; j<vAp.size(); j++)if(i!=j && vAp[i].getX()==vAp[j].getX() && vAp[i].getY()==vAp[j].getY())vAp[j].setalive(0);

        for(i=0; i<vPl.size(); i++)if(vPl[i].getalive())
        {
            plan[i].setPosition(sq*vPl[i].getY()+sq*((vPl[i].getsub()-1)%2)/2,sq*vPl[i].getX()+sq*((vPl[i].getsub()-1)/2)/2);
        }
        for(i=0; i<vPr.size(); i++)if(vPr[i].getalive())
        {
            pr[i].setPosition(sq*vPr[i].getY()+sq*((vPr[i].getsub()-1)%2)/2,sq*vPr[i].getX()+sq*((vPr[i].getsub()-1)/2)/2);
        }
        for(i=0; i<vAp.size(); i++)if(vAp[i].getalive())
        {
            ap[i].setPosition(sq*vAp[i].getY()+sq*((vAp[i].getsub()-1)%2)/2,sq*vAp[i].getX()+sq*((vAp[i].getsub()-1)/2)/2);
        }
        window.clear(); window.draw(bg);
        for(i=0; i<n; i++)for(j=0; j<m; j++)window.draw(arear[i][j]);
        for(i=0; i<vPl.size(); i++)if(vPl[i].getalive())window.draw(plan[i]);
        for(i=0; i<vPr.size(); i++)if(vPr[i].getalive())window.draw(pr[i]);
        for(i=0; i<vAp.size(); i++)if(vAp[i].getalive())window.draw(ap[i]);

        if(WORK){
        Pl.clear();
        for(i=0; i<vPl.size(); i++)if(vPl[i].getalive())
        {
            S="0000"; for(;;)
            {
                if(S=="1111")break; g=rand()%4; dx=D[g].fi; dy=D[g].se; S[g]='1';
                if(vPl[i].getX()+dx<0 || vPl[i].getX()+dx>=n || vPl[i].getY()+dy<0 || vPl[i].getY()+dy>=m){continue;}else
                {
                    if(f.getArea(vPl[i].getX()+dx,vPl[i].getY()+dy)==0 || f.getSubType(vPl[i].getX()+dx,vPl[i].getY()+dy,1)==1
                    || f.getSubType(vPl[i].getX()+dx,vPl[i].getY()+dy,2)==1 || f.getSubType(vPl[i].getX()+dx,vPl[i].getY()+dy,3)==1
                    || f.getSubType(vPl[i].getX()+dx,vPl[i].getY()+dy,4)==1 )continue;
                    f.setArea(vPl[i].getX(),vPl[i].getY(),0,-1,vPl[i].getsub());
                    vPl[i].setcoord(vPl[i].getX()+dx,vPl[i].getY()+dy);
                    vPl[i].setsub( f.getArea(vPl[i].getX(),vPl[i].getY()) );
                    f.setArea(vPl[i].getX(),vPl[i].getY(),1,vPl[i].getid(),f.getArea(vPl[i].getX(),vPl[i].getY())); break;
                }
            }

            S="0000"; if(rand()%vPl[i].getbirth()==0) for(;;)
            {
                if(S=="1111")break; g=rand()%4; dx=D[g].fi; dy=D[g].se; S[g]='1';
                if(vPl[i].getX()+dx<0 || vPl[i].getX()+dx>=n || vPl[i].getY()+dy<0 || vPl[i].getY()+dy>=m){continue;}else
                {
                    if(f.getArea(vPl[i].getX()+dx,vPl[i].getY()+dy)==0)continue;
                    Pl.push_back(Plankton(PlN,vPl[i].getX()+dx,vPl[i].getY()+dy,vPl[i].gethpm(),vPl[i].gethps(),vPl[i].getbirth(),1)); break;
                }
            }

            vPl[i].sethp(vPl[i].gethp()-vPl[i].gethps()); if(vPl[i].gethp()<=0)vPl[i].setalive(0);
        }
        for(i=0; i<Pl.size(); i++)if(f.getArea(Pl[i].getX(),Pl[i].getY())!=0)
        {
            kk=0; for(j=1; j<=4; j++)if(f.getSubType(Pl[i].getX(),Pl[i].getY(),j)==1)kk=1;
            if(kk==0)addPlankton(Pl[i],vPl,plan,plank,PlN);
        }
        Pr.clear(); for(i=0; i<vPr.size(); i++)if(vPr[i].getalive())
        {
            S="0000"; for(;;)
            {
                if(S=="1111")break; g=rand()%4; dx=D[g].fi; dy=D[g].se; S[g]='1';
                if(vPr[i].getX()+dx<0 || vPr[i].getX()+dx>=n || vPr[i].getY()+dy<0 || vPr[i].getY()+dy>=m){continue;}else
                {
                    if(f.getArea(vPr[i].getX()+dx,vPr[i].getY()+dy)==0)continue;
                    f.setArea(vPr[i].getX(),vPr[i].getY(),0,-1,vPr[i].getsub());
                    vPr[i].setcoord(vPr[i].getX()+dx,vPr[i].getY()+dy);
                    vPr[i].setsub( f.getArea(vPr[i].getX(),vPr[i].getY()) );
                    f.setArea(vPr[i].getX(),vPr[i].getY(),1,vPr[i].getid(),f.getArea(vPr[i].getX(),vPr[i].getY())); break;
                }
            }

            for(j=0; j<vPl.size(); j++)if(vPl[j].getalive() && vPl[j].getX()==vPr[i].getX() && vPl[j].getY()==vPr[i].getY())vPr[i].eat(vPl[j],f);

           /* for(j=0; j<vPr.size(); j++)if(i!=j && vPr[i].getX()==vPr[j].getX() && vPr[i].getY()==vPr[j].getY()
            && f.getArea(vPr[i].getX(),vPr[i].getY())!=0)
            {
                //if(vPr[i].getgender()!=vPr[j].getgender())
                //Pr.push_back(Predator(PrN,vPr[i].getX()+dx,vPr[i].getY()+dy,vPr[i].gethpm(),vPr[i].gethps(),vPr[i].getbirth(),1,vPr[i].getssize(),0,vPr[i].gethungm(),rand()%2));
                //else
                vPr[i].eat(vPr[j],f);
            }*/


            vPr[i].sethp(vPr[i].gethp()-vPr[i].gethps()); if(vPr[i].gethp()<=0)vPr[i].setalive(0);
            vPr[i].sethung(vPr[i].gethung()+1); if(vPr[i].gethung()==vPr[i].gethungm())vPr[i].setalive(0);
        }
        for(i=0; i<vPr.size(); i++)if(vPr[i].getalive())
        for(j=0; j<vPr.size(); j++)if(i!=j && vPr[i].getX()==vPr[j].getX() && vPr[i].getY()==vPr[j].getY()
        && f.getArea(vPr[i].getX(),vPr[i].getY())!=0)
        {
            if(vPr[i].getgender()!=vPr[j].getgender())
            Pr.push_back(Predator(PrN,vPr[i].getX(),vPr[i].getY(),vPr[i].gethpm(),vPr[i].gethps(),vPr[i].getbirth(),1,vPr[i].getssize(),0,vPr[i].gethungm(),rand()%2));
            else
            vPr[i].eat(vPr[j],f);
        }
        for(i=0; i<Pr.size(); i++)if(f.getArea(vPr[i].getX(),vPr[i].getY())!=0)addPredator(Pr[i],vPr,pr,prk,PrN);
        Ap.clear();
        for(i=0; i<vAp.size(); i++)if(vAp[i].getalive())
        {
            if(vAp[i].getaim()==-1)
            {
                for(j=0; j<vPr.size(); j++)if(vPr[j].getalive())break;
                if(vPr[j].getalive())vAp[i].setaim(j);

            }

            S="0000"; for(;;)
            {
                if(S=="1111")break;
                //if(vAp[i].getaim()>-1 && vAp[i].getX()<vPr[vAp[i].getaim()].getX() && S[0]=='0'){S[0]='1';dx=D[0].fi;dy=D[0].se;}else
                //if(vAp[i].getaim()>-1 && vAp[i].getX()>vPr[vAp[i].getaim()].getX() && S[1]=='0'){S[1]='1';dx=D[1].fi;dy=D[1].se;}else
                //if(vAp[i].getaim()>-1 && vAp[i].getY()<vPr[vAp[i].getaim()].getY() && S[2]=='0'){S[2]='1';dx=D[2].fi;dy=D[2].se;}else
                //if(vAp[i].getaim()>-1 && vAp[i].getY()>vPr[vAp[i].getaim()].getY() && S[3]=='0'){S[3]='1';dx=D[3].fi;dy=D[3].se;}else
                {g=rand()%4; dx=D[g].fi; dy=D[g].se; S[g]='1';}
                if(vAp[i].getX()+dx<0 || vAp[i].getX()+dx>=n || vAp[i].getY()+dy<0 || vAp[i].getY()+dy>=m){continue;}else
                {
                    if(f.getArea(vAp[i].getX()+dx,vAp[i].getY()+dy)==0)continue;
                    f.setArea(vAp[i].getX(),vAp[i].getY(),0,-1,vAp[i].getsub());
                    vAp[i].setcoord(vAp[i].getX()+dx,vAp[i].getY()+dy);
                    vAp[i].setsub( f.getArea(vAp[i].getX(),vAp[i].getY()) );
                    f.setArea(vAp[i].getX(),vAp[i].getY(),1,vAp[i].getid(),f.getArea(vAp[i].getX(),vAp[i].getY())); break;
                }
            }
            vAp[i].sethp(vAp[i].gethp()-vAp[i].gethps()); if(vAp[i].gethp()<=0)vAp[i].setalive(0);
            vAp[i].sethung(vAp[i].gethung()+1); if(vAp[i].gethung()==vAp[i].gethungm())vAp[i].setalive(0);
            for(j=0; j<vPl.size(); j++)
            if(vPl[j].getalive() && vPl[j].getX()==vAp[i].getX() && vPl[j].getY()==vAp[i].getY())vAp[i].eat(vPl[j],f);
            for(j=0; j<vPr.size(); j++)
            if(vPr[j].getalive() && vPr[j].getX()==vAp[i].getX() && vPr[j].getY()==vAp[i].getY())vAp[i].eat(vPr[j],f);
            for(j=0; j<vAp.size(); j++)
            if(vAp[j].getalive() && vAp[j].getX()==vAp[i].getX() && vAp[j].getY()==vAp[i].getY() && i!=j)vAp[i].eat(vAp[j],f);
        }

        }
        window.display();
        Sleep(1000);
            /*for(i=0; i<vPl.size(); i++)if(vPl[i].getalive())
            {
                S="0000";
                for(;;)
                {
                    g=rand()%4; dx=D[g].fi; dy=D[g].se; S[g]='1';
                    try
                    {
                        if(vPl[i].getX()+dx<0 || vPl[i].getX()+dx>=n || vPl[i].getY()+dy<0 || vPl[i].getY()+dy>=m)throw 228;
                        if(f.getArea(vPl[i].getX()+dx,vPl[i].getY()+dy)==0)continue;
                        f.setArea(vPl[i].getX(),vPl[i].getY(),0,-1,vPl[i].getsub());
                        vPl[i].setcoord(vPl[i].getX()+dx,vPl[i].getY()+dy);
                        vPl[i].setsub( f.getArea(vPl[i].getX(),vPl[i].getY()) );
                        f.setArea(vPl[i].getX(),vPl[i].getY(),1,vPl[i].getid(),vPl[i].getsub()); break;
                    }
                    catch(int cc)
                    {
                        continue;

                    }
                    if(S=="1111")break;

                }
                //if(kk==1)continue;
            }*/

        //Sl*=0.999;



    }

    return 0;
}
