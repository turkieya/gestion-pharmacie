#include "comprime.h"
#include <iostream>

using namespace std;
comprime::comprime(){}
comprime::~comprime()
{
    //dtor
}
ostream& operator<<(ostream&out,comprime&c)
{
    medicament*m=&c;
    out<<*m;
    out<<c.nb_comp<<endl;
    return out;
}
istream& operator>>(istream&im,comprime&c)
{
    medicament*m=&c;
    im>>*m;
  //  cout<<"Nombre comprim\x82 : "<<endl;
    cout<<"                 ";
    im>>c.nb_comp;
    return im;
}
void comprime::ajouter_cm()
{
    medicament::ajouter_med();
    cout<<"                              Nombre comprim\x82 : ";
    cin>>nb_comp;
}
void comprime::afficher()
{
    medicament::afficher();
    cout<<"                              Nombre comprim\x82 : "<<nb_comp<<endl;
}
