#include "pomade.h"
#include <iostream>
#include<fstream>

using namespace std;
pomade::pomade()
{
    //ctor
}

pomade::~pomade()
{
    //dtor
}
ostream& operator<<(ostream&out,pomade&p)
{
    medicament*m=&p;
    out<<*m;
   // out<<"Quantite : ";
    out<<p.quantite<<endl;
    return out;
}
istream& operator>>(istream&im,pomade&p)
{
    medicament*m=&p;
    im>>*m;
    cout<<"                 ";
    im>>p.quantite;
    return im;
}
void pomade::afficher()
{
    medicament::afficher();
    cout<<"                              Quantit\x82(ml) : "<<quantite<<endl;
}
void pomade::remplir()
{
    ofstream f("pomade.txt",ios::app);
    if (!f)
        cout<<"erreur fichier";
    f<<*this;
    cin.ignore(1,'\n');
    f.close();


}
void pomade::charger()
{    medicament *m;

    char ch;
    ifstream f("pomade.txt");
     while(!f.eof())
       {
            m= new pomade();
             cin>>*m;
             cout<<*m;
       }
    f.close();

}
