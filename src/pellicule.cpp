#include "pellicule.h"
#include <iostream>

using namespace std;
pellicule::pellicule()
{
    //ctor
}

pellicule::~pellicule()
{
    //dtor
}
ostream& operator<<(ostream&out,pellicule&p)
{
    medicament*m=&p;
    out<<*m;
    out<<p.nb_pel<<endl;
    return out;
}
istream& operator>>(istream&im,pellicule&p)
{
    medicament*m=&p;
    im>>*m;
    cout<<"                 ";
    im>>p.nb_pel;
    return im;
}

void pellicule::afficher()
{
    medicament::afficher();
    cout<<"                              Nombre pellicules : "<<nb_pel<<endl;
}
