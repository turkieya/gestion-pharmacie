#include "commande.h"
#include<typeinfo>
#include"sirop.h"
#include"comprime.h"
#include"pellicule.h"
#include"pomade.h"
#include "iostream"
#include"stock.h"
#include"pharmacie.h"
#include <stdio.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

commande::commande()
{
    //ctor
}

commande::~commande()
{
    //dtor
}
int commande::rechercher_m(int cd)
{
    int a=-1;
    for (int i=0;i<tab_med.size();i++)
    {
        if (tab_med[i]->getcode()== cd)
            a=i;
        }
        return a;
}
int commande::chercherFR(int cd)
{
    int a=-1;
    for (int i=0 ; i<tab.size() ; i++)
    {
        if (tab[i]->getID()==cd)
            a=i;
    }
    return a;
}
ostream& operator<<(ostream&out,commande&c)
{
    out<<c.num_commande<<endl;
    out<<c.code_f<<endl;
    for (int i=0 ; i<c.tab_med.size() ; i++)
    {
            if (typeid(*(c.tab_med[i]))==typeid(sirop))
            {
                 out<<"2 "<<static_cast< sirop&>(*(c.tab_med[i]))<<endl;
            }
            else if (typeid(*(c.tab_med[i]))==typeid(comprime))
            {
                 out<<"3 "<<static_cast< comprime&>(*(c.tab_med[i]))<<endl;
            }
            else if (typeid(*(c.tab_med[i]))==typeid(pellicule))
            {
                 out<<"4 "<<static_cast< pellicule&>(*(c.tab_med[i]))<<endl;
            }
            else if (typeid(*(c.tab_med[i]))==typeid(pomade))
            {
                 out<<"5 "<<static_cast< pomade&>(*(c.tab_med[i]))<<endl;
            }
    }

    return out;
}
istream& operator>>(istream&im,commande&c)
{
    int choix,rep,x,y,f;
         c.lire_fourn();

    cout<<"saisir le numero de commande";
    im>>c.num_commande;
    c.lire_fourn();
    cout<<endl<<"              choisir un fournisseur "<<endl;
   // do{
        cout<<"              saisir le code ";
        im>>c.code_f;
        cout<<c.code_f<<endl;
        f=c.chercherFR(c.code_f);
        cout<<f;
        if (f==-1)
        {
            cout<<endl<<"                           Fournisseur n'existe pas ! Vous devez verifier le code saisie !"<<endl<<endl;
            /*cout<<"                           Voulez-vous saisir un nouveau code ?"<<endl;
            cout<<"                              1/Oui"<<endl;
            cout<<"                              2/Non"<<endl;
            cout<<endl<<"                           Entrer Votre Choix  \t";
            cin>>rep;*/
        }
       // }while (rep==1);
       else{
    do
        {

            cout<<"                           ษออออออออออออออออออออออออMEDICAMENTSอออออออออออออออออออออออป"<<endl;
            cout<<"                           บ   -----------------------------------------------------  บ"<<endl;
            cout<<"                           บ     | 1 | Ajouter Sirop                                  บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 2 | Ajouter Comprim\x82                               บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 3 | Ajouter Pellicule                              บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 4 | Ajouter Pomade                                 บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 0 | EXIT                                           บ"<<endl;
            cout<<"                           บ   -----------------------------------------------------  บ"<<endl;
            cout<<"                           ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"<<endl;
            do{
                cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
                cout<<"                                                          ";
                cin>>choix;
                }while(choix<0 ||choix>4);
    try {
     if (choix==1)
    {
        sirop*sr=new sirop();
        cout<<endl<<endl<<"              Saisir les information du Sirop - Code - Nom - Nb boites - Prix - Quantit\x82 - "<<endl;
        im>>*sr;
        x=sr->getcode();
        y=c.rechercher_m(x);
        if (y==-1)
        {
            c.tab_med.push_back(sr);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl<<endl;
        }

        else
            throw siro;
            //cout<<endl<<"              Medicament existe d\x82ja !"<<endl<<endl;

    }
    else if (choix==2)
    {
        comprime*cm=new comprime();
        cout<<endl<<endl<<"              Saisir les information du Comprim\x82 - Code - Nom - Nb boites - Prix - Nb comprim\x82s - "<<endl;
        im>>*cm;
        x=cm->getcode();
        y=c.rechercher_m(x);
        if (y==-1)
        {
            c.tab_med.push_back(cm);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl;
        }
        else
            throw compr;

    }
    else if (choix==3)
    {
        pellicule*pl=new pellicule();
        cout<<endl<<endl<<"              Saisir les information du Pellicule - Code - Nom - Nb boites - Prix - Nb pellicules - "<<endl;
        im>>*pl;
        x=pl->getcode();
        y=c.rechercher_m(x);
        if (y==-1)
        {
            c.tab_med.push_back(pl);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl;
        }
        else
            throw peli;

    }
    else if (choix==4)
    {
        pomade*pm=new pomade();
        cout<<endl<<endl<<"              Saisir les information du Pomade - Code - Nom - Nb boites - Prix - Quantit\x82 - "<<endl;
        im>>*pm;
        x=pm->getcode();
        y=c.rechercher_m(x);
        if (y==-1)
        {
            c.tab_med.push_back(pm);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl;
        }
        else
            throw poma;

    }
     }
        catch (Erreur_c e)
        {
            if (e==siro)
                cerr<<endl<<"              Le sirop d\x82ja command\x82 !"<<endl<<endl;
            else if (e==compr)
                cout<<endl<<"              Le comprim\x82 d\x82ja command\x82 !"<<endl<<endl;
            else if (e==peli)
                cout<<endl<<"              Le pellicule d\x82ja command\x82 !"<<endl<<endl;
            else if (e==poma)
                cout<<endl<<"              La pomade d\x82ja command\x82 !"<<endl<<endl;
        }

            cout<<"                                   Voulez-vous ajouter un autre medicament ?"<<endl;
            cout<<"                                       1/Oui "<<endl;
            cout<<"                                       2/Non "<<endl;
            cout<<endl<<"                                     Entrer Votre Choix  \t";
            cin>>rep;
            system("cls");
        } while (rep==1);}

        return im;
}

 void commande::lire_fourn()
 {
     ifstream f("fournisseur.txt");
    fournisseur *fr ;
    while (1)
        {
            if (f.eof() )
            break ;
            fr=new fournisseur() ;
            f>>*fr ;
            tab.push_back(fr) ;
        }
    //tab.pop_back() ;
   f.close() ;
 }

void commande::afficherFR()
{
    for (int i=0 ; i<tab.size() ; i++)
        tab[i]->affichageF() ;
}

int commande::getnum_com()
{
    return num_commande;
}

int commande::getcode_f()
{
    return code_f;
}
void commande::afficher_com()
{
    cout<<"                        Les information du commande sont : "<<endl;
    cout<<"                              Numero Commande : "<<num_commande<<endl;
    cout<<"                              Code Fournisseur : "<<code_f<<endl;
    cout<<"                              Liste des Medicaments : "<<endl;
    for (int i=0 ; i<tab_med.size() ; i++)
    {
        cout<<"                              Medicament Nฐ "<<i+1<<endl;
        tab_med[i]->afficher() ;
    }


}
