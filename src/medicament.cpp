#include "medicament.h"
#include"sirop.h"
#include <iostream>
#include<fstream>
using namespace std;
medicament::~medicament()
{
    //dtor
}
ostream& operator<<(ostream&out,medicament&m)
{
    //out<<"Les informaionts du medicament sont : \n"<<"Code : "<<m.code_med<<"\n"<<"Nom : "<<m.nom_med<<"\n"<<"Libele : "<<m.libelle<<"\n"<<"Prix : "<<m.prix<<endl;
    out<<m.code_med<<endl<<m.nom_med<<endl<<m.nb_boite<<endl<<m.prix<<endl;
    return out;
}
istream& operator>>(istream&im,medicament&m)
{
  //  cout<<"Saisir les information du medicament - code - nom - Libel\x82 - prix  "<<endl;
    //cout<<"Code : "<<endl;
    cout<<"                 ";
    im>>m.code_med;
    im.ignore();
   // cout<<"Nom : "<<endl;
   cout<<"                 ";
    im>>m.nom_med;
    im.ignore();
   // cout<<"Libel\x82 : "<<endl;
   cout<<"                 ";
    im>>m.nb_boite;
    im.ignore();
  //  cout<<"Prix : "<<endl;
  cout<<"                 ";
    im>>m.prix;
    return im;
}
void medicament::ajouter_med()
{
    cout<<"                           Saisir les informations du medicament "<<endl;
    cout<<"                              Code : ";
    cin>>code_med;
    cout<<"                              Nom : ";
    cin>>nom_med;
    cout<<"                              Libel\x82 : ";
    cin>>nb_boite;
    cout<<"                              Prix : ";
    cin>>prix;

}
void medicament::afficher()
{
    cout<<"                        Les information du medicament sont : "<<endl;
    cout<<"                              Code : "<<code_med<<endl;
    cout<<"                              Nom : "<<nom_med<<endl;
    cout<<"                              nombre des boites : "<<nb_boite<<endl;
    cout<<"                              Prix : "<<prix<<endl;
}
int medicament::getcode()
{
    return code_med;
}
void medicament::setcode(int cd)
{
    code_med=cd;
}
void medicament::setnom(string n)
{
    nom_med=n;
}

void medicament::setnb_boite(int nb)
{
    nb_boite=nb;
}
void medicament::setprix(float p)
{
    prix=p;
}
int medicament::getnb_boite()
{
    return nb_boite;
}
float medicament::getprix()
{
    return prix;
}
string medicament::getnom()
{
    return nom_med;
}
int medicament::getqte()
{sirop s;
    return s.getquantite();
}
void medicament::remplir()
{
    ofstream f("medicament.txt",ios::app);
    if (!f)
        cout<<"erreur fichier";
    f<<*this;
    cin.ignore(1,'\n');
    f.close();

}
void medicament::charger()
{
    char ch;
    ifstream f("medicament.txt");
     while(!f.eof())
       {
          f.get(ch);
          cout<<ch;
       }
    f.close();

}
