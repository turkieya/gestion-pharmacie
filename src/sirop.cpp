#include "sirop.h"
#include <iostream>
#include<fstream>

using namespace std;
sirop::sirop(){}
sirop::~sirop()
{
    //dtor
}
ostream& operator<<(ostream&out,sirop&s)
{
    medicament*m=&s;
    out<<*m;
   // out<<"Quantite : ";
    out<<s.quantite<<endl;
    return out;
}
istream& operator>>(istream&im,sirop&s)
{
    medicament*m=&s;
    im>>*m;
  //  cout<<"Quantit\x82 : "<<endl;
  cout<<"                 ";
    im>>s.quantite;
    return im;
}
void sirop::ajouter_sr()
{
    medicament::ajouter_med();
    cout<<"                              Quantit\x82 : ";
    cin>>quantite;
}
void sirop::afficher()
{
    medicament::afficher();
    cout<<"                              Quantit\x82(ml) : "<<quantite<<endl;
}
int sirop::getquantite()
{
    return quantite;
}
void sirop::setquantite(int q)
{
    quantite=q;
}
void sirop::remplir()
{
    ofstream f("sirop.txt",ios::app);
    if (!f)
        cout<<"erreur fichier";
    f<<*this;
    cin.ignore(1,'\n');
    f.close();


}
void sirop::charger()
{    sirop *s;

    char ch;
    ifstream f("sirop.txt");
     while(!f.eof())
       {
        //  f.get(ch);
         // cout<<ch;
            s= new sirop();
             cin>>*s;
             cout<<*s;
       }
    f.close();

}
