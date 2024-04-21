#ifndef ZPO
#define ZPO

#include<iostream>
using namespace std;

class Obiekt
{
private:
    char znak;
public:
    Obiekt(char znak): znak(znak) {}
    virtual ~Obiekt()=default;
    virtual void print() = 0;
    char getznak() {return znak;}
};

class Postac : public Obiekt
{
public:
    Postac(char znak) : Obiekt(znak) {}
    ~Postac()
    {
        cout<<"\n("<<getznak()<<") deleted"<<endl;
    }

    void print() override
    {
        cout<<getznak()<<" ";
    }
};

class Przedmiot : public Obiekt
{
private:
    string nazwa;
public:
    Przedmiot(char znak, string nazwa) : Obiekt(znak), nazwa(nazwa) {}
    ~Przedmiot()
    {
        cout<<endl<<nazwa<<" ("<<getznak()<<") deleted"<<endl;
    }
    void print() override
    {
        cout<<getznak()<<" ";
    }
};

class Plansza
{
private:
    int x;
    int y;
    Obiekt* **tab;
public:
    Plansza(int x, int y) : x(x), y(y)
    {
        tab = new Obiekt* *[x];
        for(int i=0; i<x;i++)
        {

            tab[i]=new Obiekt*[y];
            for(int j=0;j<y;j++)
            {
                tab[i][j]=nullptr;
            }
        }
    }
    ~Plansza()
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(tab[i][j]!=nullptr) delete tab[i][j];
            }
            delete []tab[i];
        }
        delete []tab;

    }

    void dodaj(int x, int y, Obiekt* o)
    {
        tab[x][y]=o;
    }

    friend ostream& operator<<(ostream& os, const Plansza& pl)
    {
        for(int i=0; i<pl.x; i++)
        {
            for(int j=0; j<pl.y; j++)
            {
                if(pl.tab[i][j]!=nullptr)
                {
                    pl.tab[i][j]->print();
                }
                else os<<". ";
            }
            os<<endl;
        }
        return os;
    }

    void operator-=(char znak)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(tab[i][j]!=nullptr && tab[i][j]->getznak()==znak)
                    {
                        delete tab[i][j];
                        tab[i][j]=nullptr;
                    }
            }
        }
    }

};

#endif // ZPO
