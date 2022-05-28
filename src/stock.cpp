#include "stock.h"
#include<typeinfo>
#include"sirop.h"
#include"comprime.h"
#include"pellicule.h"
#include"pomade.h"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

stock::stock()
{
    //ctor
}
stock::stock(const stock&s)
{
    medicament*m;
    for (int i=0;i<s.tab_med.size();i++)
    {
        if (typeid(*s.tab_med[i])==typeid(medicament))
        {
            m=new medicament(*s.tab_med[i]);
        }
        else if (typeid(*s.tab_med[i])==typeid(sirop))
        {
            m=new sirop(static_cast<sirop&>(*s.tab_med[i]));

        }
        else if (typeid(*s.tab_med[i])==typeid(comprime))
        {
            m=new comprime(static_cast<comprime&>(*s.tab_med[i]));
        }
        else if (typeid(*s.tab_med[i])==typeid(pellicule))
        {
            m=new pellicule(static_cast<pellicule&>(*s.tab_med[i]));
        }
        else if (typeid(*s.tab_med[i])==typeid(pomade))
        {
            m=new pomade(static_cast<pomade&>(*s.tab_med[i]));
        }
        tab_med.push_back(m);}
}

stock::~stock()
{
    //dtor
}
/*void stock::ajouter_stock(medicament&m)
{
    medicament*med;
    //if (typeid(m)==typeid(medicament))
//        med=new medicament(med);
     if (typeid(m)==typeid(sirop))
     {
          med=new sirop(static_cast<const sirop&>(m));
          tab_sr.push_back(med);
     }

    else if (typeid(m)==typeid(comprime))
    {
        med=new comprime(static_cast<const comprime&>(m));
        tab_cm.push_back(med);
    }

    tab_med.push_back(med);

}*/

void stock::afficher_stock()
{
    for (int i=0;i<tab_med.size();i++)
    {
            tab_med[i]->afficher();
    }
}
void stock::afficher_sr()
{
    for (int i=0;i<tab_sr.size();i++)
    {
            tab_sr[i]->afficher();
    }
}
void stock::afficher_cm()
{
    for (int i=0;i<tab_cm.size();i++)
    {
            tab_cm[i]->afficher();
    }
}
void stock::afficher_pl()
{
    for (int i=0;i<tab_pl.size();i++)
    {
            tab_pl[i]->afficher();
    }
}
void stock::afficher_pm()
{
    for (int i=0;i<tab_pm.size();i++)
    {
            tab_pm[i]->afficher();
    }
}
medicament stock::afficher(int cd)
{
    tab_med[cd]->afficher();
}
sirop stock::afficher_s(int cd)
{
    tab_sr[cd]->afficher();
}
void stock::rechercher()
{
    int rep,cd,i;

    do{
        try{

        cout<<"Saisir un code : ";
        cin>>cd;
        while ((i<tab_med.size())&&(tab_med[i]->getcode()!= cd))
            i++;

        if (i<tab_med.size())
            tab_med[i]->afficher() ;
        else throw -1;


    }catch(int x)
    {
        cout<<endl<<"                           Medicament n'existe pas ! Vous devez verifier le code saisie !"<<endl<<endl;
        cout<<"                           Voulez-vous saisir un nouveau code ?"<<endl;
        cout<<"                              1/Oui"<<endl;
        cout<<"                              2/Non"<<endl;
        cout<<endl<<"                           Entrer Votre Choix  \t";
        cin>>rep;
    }
    }while (rep==1);

}

int stock::rechercher_m(int cd)
{
    int a=-1;
    for (int i=0;i<tab_med.size();i++)
    {
        if (tab_med[i]->getcode()== cd)
            a=i;
        }
        return a;
}
int stock::rechercher_sr(int cd)
{
    int a=-1;
    for (int i=0;i<tab_sr.size();i++)
    {
        if (tab_sr[i]->getcode()== cd)
            a=i;
        }
      return a;
}
int stock::rechercher_cm(int cd)
{
    int a=-1;
    for (int i=0;i<tab_cm.size();i++)
    {
        if (tab_cm[i]->getcode()== cd)
            a=i;
        }
      return a;
}
int stock::rechercher_pl(int cd)
{
    int a=-1;
    for (int i=0;i<tab_pl.size();i++)
    {
        if (tab_pl[i]->getcode()== cd)
            a=i;
        }
      return a;
}
int stock::rechercher_pm(int cd)
{
    int a=-1;
    for (int i=0;i<tab_pm.size();i++)
    {
        if (tab_pm[i]->getcode()== cd)
            a=i;
        }
      return a;
}
void stock::supprimer()
{
    int c,cd,rep2;
    int rep;
    do{
        lire();
        cout<<"                                Saisir un code : ";
        cin>>c;
        cd=rechercher_m(c);
        if (cd != -1)
        {
            tab_med[cd]->afficher();
            do
            {
                cout<<endl<<"                           Voulez-vous supprimer ce medicament ?"<<endl;
                cout<<"                              1/Oui "<<endl;
                cout<<"                              2/Non "<<endl;
                cout<<"                           Entrer Votre Choix  \t";
                cin>>rep2;
                }while ((rep2<0)||(rep2>1));
                if (rep2==1)
                {
                    tab_med.erase(tab_med.begin()+cd);
                    modifier_fichier();
                    lire();
                    cout<<"           Medicament supprim\x82 avec succ\x82s !"<<endl;
                }

    }
    else
        {
            cout<<endl<<"                           Medicament n'existe pas ! Vous devez verifier le code saisie !"<<endl<<endl;
        cout<<"                           Voulez-vous saisir un nouveau code ?"<<endl;
        cout<<"                              1/Oui"<<endl;
        cout<<"                              2/Non"<<endl;
        cout<<endl<<"                           Entrer Votre Choix  \t";
            cin>>rep;
        }

     }while (rep==1);
}
void stock::modifier_sr(int c,int m)
{
    int cd,choix,nb,q;
    float p;
    string n;
        system("cls");
        cout<<"                           ษออออออออออออออออออออออออMEDICAMENTSอออออออออออออออออออออออป\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           บ     | 1 | Modifier Code                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 2 | Modifier Nom                                   บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 3 | Modifier Nombres des Boites                    บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 4 | Modifier Prix                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 5 | Modifier Quantit\x82                              บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 0 | EXIT                                           บ\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
        do
        {
            cout<<"                           *                    Entrer Votre Choix                    *\t";
            cout<<"\n                                                         ";
            cin>>choix;
        }while(choix<0 ||choix>5);
        if (choix==1)
        {
            cout<<"                           Saisir le nouveau code : ";
            cin>>cd;
            tab_sr[c]->setcode(cd);
            tab_med[m]->setcode(cd);
        }
        else if (choix==2)
        {
            cout<<"                           Saisir le nouveau nom : ";
            cin>>n;
            tab_sr[c]->setnom(n);
            tab_med[m]->setnom(n);

        }
        else if (choix==3)
        {
            cout<<"                           Saisir le nouveau nombre des boites : ";
            cin>>nb;
            tab_sr[c]->setnb_boite(nb);
            tab_med[m]->setnb_boite(nb);
        }
        else if (choix==4)
        {
            cout<<"                           Saisir le nouveau prix : ";
            cin>>p;
            tab_sr[c]->setprix(p);
            tab_med[m]->setprix(p);
        }
        else if (choix==5)
        {
            cout<<"                           Saisir la nouvelle quantit\x82 : ";
            cin>>q;
          //  tab_sr[c]->setquantite(q);
//            tab_med[m]->setquantite(q);
        }
        modifier_fichier();
        lire();
        cout<<endl<<"                           Apres changement :"<<endl;
        afficher(m);
}
void stock::modifier_cm(int c,int m)
{
    int cd,choix,nb,nb_c,q;
    float p;
    string n;
        system("cls");
        cout<<"                           ษออออออออออออออออออออออออMEDICAMENTSอออออออออออออออออออออออป\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           บ     | 1 | Modifier Code                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 2 | Modifier Nom                                   บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 3 | Modifier Nombres des Boites                    บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 4 | Modifier Prix                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 5 | Modifier Nombre des Comprim\x82s                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 0 | EXIT                                           บ\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
        do
        {
            cout<<"                           *                    Entrer Votre Choix                    *\t";
            cout<<"\n                                                         ";
            cin>>choix;
        }while(choix<0 ||choix>5);
        if (choix==1)
        {
            cout<<"                           Saisir le nouveau code : ";
            cin>>cd;
            tab_cm[c]->setcode(cd);
            tab_med[m]->setcode(cd);
        }
        else if (choix==2)
        {
            cout<<"                           Saisir le nouveau nom : ";
            cin>>n;
            tab_cm[c]->setnom(n);
            tab_med[m]->setnom(n);

        }
        else if (choix==3)
        {
            cout<<"                           Saisir le nouveau nombre des boites : ";
            cin>>nb;
            tab_cm[c]->setnb_boite(nb);
            tab_med[m]->setnb_boite(nb);
        }
        else if (choix==4)
        {
            cout<<"                           Saisir le nouveau prix : ";
            cin>>p;
            tab_cm[c]->setprix(p);
            tab_med[m]->setprix(p);
        }
        else if (choix==5)
        {
            cout<<"                           Saisir la nouvelle quantit\x82 : ";
            cin>>q;
        //    tab_sr[c]->setquantite(q);
//            tab_med[m]->setquantite(q);
        }
        modifier_fichier();
        lire();
        cout<<endl<<"                           Apres changement :"<<endl;
        afficher(m);
}
void stock::modifier_pl(int c,int m)
{
    int cd,choix,nb,nb_p;
    float p;
    string n;
        system("cls");
        cout<<"                           ษออออออออออออออออออออออออMEDICAMENTSอออออออออออออออออออออออป\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           บ     | 1 | Modifier Code                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 2 | Modifier Nom                                   บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 3 | Modifier Nombres des Boites                    บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 4 | Modifier Prix                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 5 | Modifier Nombre des Pellicules                    บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 0 | EXIT                                           บ\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
        do
        {
            cout<<"                           *                    Entrer Votre Choix                    *\t";
            cout<<"\n                                                         ";
            cin>>choix;
        }while(choix<0 ||choix>5);
        if (choix==1)
        {
            cout<<"                           Saisir le nouveau code : ";
            cin>>cd;
            tab_pl[c]->setcode(cd);
            tab_med[m]->setcode(cd);
        }
        else if (choix==2)
        {
            cout<<"                           Saisir le nouveau nom : ";
            cin>>n;
            tab_pl[c]->setnom(n);
            tab_med[m]->setnom(n);

        }
        else if (choix==3)
        {
            cout<<"                           Saisir le nouveau nombre des boites : ";
            cin>>nb;
            tab_pl[c]->setnb_boite(nb);
            tab_med[m]->setnb_boite(nb);
        }
        else if (choix==4)
        {
            cout<<"                           Saisir le nouveau prix : ";
            cin>>p;
            tab_pl[c]->setprix(p);
            tab_med[m]->setprix(p);
        }
        else if (choix==5)
        {
            cout<<"                           Saisir la nouvelle quantit\x82 : ";
           // cin>>q;
          //  tab_sr[c]->setquantite(q);
//            tab_med[m]->setquantite(q);
        }
        modifier_fichier();
        lire();
        cout<<endl<<"                           Apres changement :"<<endl;
        afficher(m);
}
void stock::modifier_pm(int c,int m)
{
    int cd,choix,nb,nb_p;
    float p;
    string n;
        system("cls");
        cout<<"                           ษออออออออออออออออออออออออMEDICAMENTSอออออออออออออออออออออออป\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           บ     | 1 | Modifier Code                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 2 | Modifier Nom                                   บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 3 | Modifier Nombres des Boites                    บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 4 | Modifier Prix                                  บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 5 | Modifier Quantit\x82                              บ\n";
        cout<<"                           บ                                                          บ\n";
        cout<<"                           บ     | 0 | EXIT                                           บ\n";
        cout<<"                           บ   -----------------------------------------------------  บ\n";
        cout<<"                           ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
        do
        {
            cout<<"                           *                    Entrer Votre Choix                    *\t";
            cout<<"\n                                                         ";
            cin>>choix;
        }while(choix<0 ||choix>5);
        if (choix==1)
        {
            cout<<"                           Saisir le nouveau code : ";
            cin>>cd;
            tab_pm[c]->setcode(cd);
            tab_med[m]->setcode(cd);
        }
        else if (choix==2)
        {
            cout<<"                           Saisir le nouveau nom : ";
            cin>>n;
            tab_pm[c]->setnom(n);
            tab_med[m]->setnom(n);

        }
        else if (choix==3)
        {
            cout<<"                           Saisir le nouveau nombre des boites : ";
            cin>>nb;
            tab_pm[c]->setnb_boite(nb);
            tab_med[m]->setnb_boite(nb);
        }
        else if (choix==4)
        {
            cout<<"                           Saisir le nouveau prix : ";
            cin>>p;
            tab_pm[c]->setprix(p);
            tab_med[m]->setprix(p);
        }
        else if (choix==5)
        {
            cout<<"                           Saisir la nouvelle quantit\x82 : ";
           // cin>>q;
          //  tab_sr[c]->setquantite(q);
//            tab_med[m]->setquantite(q);
        }
        modifier_fichier();
        lire();
        cout<<endl<<"                           Apres changement :"<<endl;
        afficher(m);
}
ostream& operator<<(ostream&out,stock&s)
{
    for (int i=0;i<s.tab_med.size();i++)
    {
        if (typeid(*s.tab_med[i])==typeid(medicament))
        {
            out<<*s.tab_med[i]<<endl;
        }
        else if (typeid(*s.tab_med[i])==typeid(sirop))
        {
            out<<static_cast<sirop&>(*s.tab_med[i])<<endl;

        }
        else if (typeid(*s.tab_med[i])==typeid(comprime))
        {
            out<<static_cast<comprime&>(*s.tab_med[i])<<endl;
        }
        return out;
}}
istream& operator>>(istream&im,stock&s)
{
    int choix,rep,x,y;
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
        y=s.rechercher_m(x);
        if (y==-1)
        {
            s.tab_med.push_back(sr);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl<<endl;
        }

        else
            throw sir;
            //cout<<endl<<"              Medicament existe d\x82ja !"<<endl<<endl;

    }
    else if (choix==2)
    {
        comprime*cm=new comprime();
        cout<<endl<<endl<<"              Saisir les information du Comprim\x82 - Code - Nom - Nb boites - Prix - Nb comprim\x82s - "<<endl;
        im>>*cm;
        x=cm->getcode();
        y=s.rechercher_m(x);
        if (y==-1)
        {
            s.tab_med.push_back(cm);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl;
        }
        else
            throw comp;

    }
    else if (choix==3)
    {
        pellicule*pl=new pellicule();
        cout<<endl<<endl<<"              Saisir les information du Pellicule - Code - Nom - Nb boites - Prix - Nb pellicules - "<<endl;
        im>>*pl;
        x=pl->getcode();
        y=s.rechercher_m(x);
        if (y==-1)
        {
            s.tab_med.push_back(pl);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl;
        }
        else
            throw pel;

    }
    else if (choix==4)
    {
        pomade*pm=new pomade();
        cout<<endl<<endl<<"              Saisir les information du Pomade - Code - Nom - Nb boites - Prix - Quantit\x82 - "<<endl;
        im>>*pm;
        x=pm->getcode();
        y=s.rechercher_m(x);
        if (y==-1)
        {
            s.tab_med.push_back(pm);
            cout<<endl<<"              Medicament ajout\x82 avec succ\x82s !"<<endl;
        }
        else
            throw pom;

    }
     }
        catch (Erreur e)
        {
            if (e==sir)
                cerr<<endl<<"              Le sirop existe d\x82ja !"<<endl<<endl;
            else if (e==comp)
                cout<<endl<<"              Le comprim\x82 existe d\x82ja !"<<endl<<endl;
            else if (e==pel)
                cout<<endl<<"              Le pellicule existe d\x82ja !"<<endl<<endl;
            else if (e==pom)
                cout<<endl<<"              La pomade existe d\x82ja !"<<endl<<endl;
        }

            cout<<"                                   Voulez-vous ajouter un autre medicament ?"<<endl;
            cout<<"                                       1/Oui "<<endl;
            cout<<"                                       2/Non "<<endl;
            cout<<endl<<"                                     Entrer Votre Choix  \t";
            cin>>rep;
            system("cls");
        } while (rep==1);
    return im;
}

void stock::enregistrer()
{
     fstream f("stock.txt",ios::out|ios::app);
     try{

    //if (!f)
      //  cout<<"erreur fichier";
    //f<<*this;
    for (int i=0;i<tab_med.size();i++)
        {
            if (typeid(*tab_med[i])==typeid(medicament))
            {
                 f<<"1 "<<endl<<*tab_med[i]<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(sirop))
            {
                 f<<"2 "<<static_cast< sirop&>(*tab_med[i])<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(comprime))
            {
                 f<<"3 "<<static_cast< comprime&>(*tab_med[i])<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(pellicule))
            {
                 f<<"4 "<<static_cast< pellicule&>(*tab_med[i])<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(pomade))
            {
                 f<<"5 "<<static_cast< pomade&>(*tab_med[i])<<endl;
            }
        }
    cin.ignore(1,'\n');
    f.close();}
    catch (exception e){cerr<<"Erreur Fichier"<<e.what();}
}
void stock::lire()
{
    medicament *m;
    sirop*s;
    comprime*c;
    pellicule*pl;
    pomade*pm;
    int val,choix;
    try{
    ifstream f("stock.txt");
    if(!f) throw -1;
    //Seekg(0);
    while (1)
    {
        f>>val;
        if (f.eof()) break;
         if (val==1)
         {
             m=new medicament();
             f>>*m;
              tab_sr.push_back(m);

             //cout<<*m;
         }
         else if (val==2)
         {
             s= new sirop();
             f>>*s;
            // cout<<*s;
            tab_sr.push_back(s);
            tab_med.push_back(s);

        }
         else if (val==3)
         {
             c= new comprime();
             f>>*c;
             tab_cm.push_back(c);
             tab_med.push_back(c);

         }
        else if (val==4)
         {
             pl= new pellicule();
             f>>*pl;
             tab_pl.push_back(pl);
             tab_med.push_back(pl);

         }
        else if (val==5)
         {
             pm= new pomade();
             f>>*pm;
             tab_pm.push_back(pm);
             tab_med.push_back(pm);

         }

       }
    f.close();}
    catch (int x){cout<<"                           Fichier N'existe Pas ! "<<endl<<endl;
    exit(-1);}
}
void stock::charger_medicaments()
{
    int choix;

            cout<<endl<<"                           ษออออออออออออออออออออออออออ STOCK อออออออออออออออออออออออออป"<<endl;
            cout<<"                           บ   -----------------------------------------------------  บ"<<endl;
            cout<<"                           บ     | 1 | Afficher Sirops                                บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 2 | Afficher Comprim\x82s                             บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 3 | Afficher Pellicules                            บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 4 | Afficher Pomades                               บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 5 | Liste Medicaments                              บ"<<endl;
            cout<<"                           บ                                                          บ"<<endl;
            cout<<"                           บ     | 0 | EXIT                                           บ"<<endl;
            cout<<"                           บ   -----------------------------------------------------  บ"<<endl;
            cout<<"                           ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"<<endl;
            do{
                cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
                cout<<"                                                           ";
                cin>>choix;
                }while(choix<0 ||choix>5);
            try{
            if (choix==1)
            {
                system("cls");
                cout<<"                  ออออออออออออออออออออออออ STOCK SIROPS อออออออออออออออออออออออ"<<endl<<endl;
                afficher_sr();
                if (tab_sr.size() == 0)
                   throw sir;
            }
            else if (choix==2)
            {
                system("cls");
                cout<<"                  ออออออออออออออออออออออออ STOCK COMPRIMES อออออออออออออออออออออออ"<<endl<<endl;
                afficher_cm();
                if (tab_cm.size() == 0)
                   throw comp;
            }
            else if (choix==3)
            {
                system("cls");
                cout<<"                  ออออออออออออออออออออออออ STOCK PELLICULES อออออออออออออออออออออออ"<<endl<<endl;
                afficher_pl();
                if (tab_pl.size() == 0)
                   throw pel;
            }
            else if (choix==4)
            {
                system("cls");
                cout<<"                  ออออออออออออออออออออออออ STOCK POMADES อออออออออออออออออออออออ"<<endl<<endl;
                afficher_pm();
                if (tab_pm.size() == 0)
                   throw pom;
            }
            else if (choix==5)
            {
                system("cls");
                cout<<"                  ออออออออออออออออออออออออ STOCK MEDICAMENTS อออออออออออออออออออออออ"<<endl<<endl;
                afficher_stock();
                if (tab_med.size() == 0)
                   throw med;

            }
            }
            catch (Erreur e)
            {
                if (e==sir)
                    cerr<<endl<<"                                      Stock Sirops est Vide !"<<endl<<endl;
                else if (e==comp)
                    cout<<endl<<"                                      Stock Comprim\x82s est Vide !"<<endl<<endl;
                else if (e==pel)
                    cout<<endl<<"                                      Stock Pellicules est Vide !"<<endl<<endl;
                else if (e==pom)
                    cout<<endl<<"                                      Stock Pomades est Vide !"<<endl<<endl;
                else if (e==med)
                    cout<<endl<<"                                      Stock est Vide !"<<endl<<endl;
            }
}
void stock::modifier_fichier()
{
    try {
     fstream f("stock.txt",ios::out);

    if (!f)
       throw -1;
    for (int i=0;i<tab_med.size();i++)
        {
            if (typeid(*tab_med[i])==typeid(medicament))
            {
                 f<<"1 "<<endl<<*tab_med[i]<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(sirop))
            {
                 f<<"2 "<<static_cast< sirop&>(*tab_med[i])<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(comprime))
            {
                 f<<"3 "<<static_cast< comprime&>(*tab_med[i])<<endl;
            }
                        else if (typeid(*tab_med[i])==typeid(pellicule))
            {
                 f<<"4 "<<static_cast< pellicule&>(*tab_med[i])<<endl;
            }
            else if (typeid(*tab_med[i])==typeid(pomade))
            {
                 f<<"5 "<<static_cast< pomade&>(*tab_med[i])<<endl;
            }
        }
    cin.ignore(1,'\n');
    f.close();}
    catch (int x){cout<<"                           Erreur Fichier ! "<<endl<<"                           Erreur Number "<<x<<endl;
    exit(-1);}

}
