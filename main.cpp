#include"postac.h"
int main()
{
    Obiekt* o1 = new Postac('P');
    Obiekt* o2 = new Przedmiot('#',"mur");

    Plansza p(3,5);

    cout<<p<<endl;

    p.dodaj(0,0,o1);
    p.dodaj(2,4,o2);

    cout<<p<<endl;

    p-='#';

    cout<<p<<endl;

    return 0;
}
