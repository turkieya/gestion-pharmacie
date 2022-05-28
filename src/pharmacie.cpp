#include "pharmacie.h"
#include "fournisseur.h"
#include"stock.h"
#include"commande.h"
#include"string"
#include"medicament.h"
#include"sirop.h"
#include"comprime.h"
#include"pellicule.h"
#include"pomade.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<typeinfo>


using namespace std;

pharmacie::pharmacie()
{
    //ctor
}

pharmacie::~pharmacie()
{

        for (int i=0 ; i<tab.size() ; i++)
        delete tab[i] ;
    tab.clear() ;
    for (int i=0 ; i<clients.size() ; i++)
        delete clients[i] ;
    clients.clear() ;

}

void pharmacie::afficherCLT(){
for (int i=0 ; i<clients.size() ; i++) {
    cout<<clients[i] ;
}
}

void pharmacie::ecrireFichierClients(fstream& f) {
f.open("Clients.txt", ios::in | ios::out | ios::app);
if (! f.is_open())
    exit (-1) ;

for (int i=0 ; i<clients.size() ; i++){

    f<<"------------------" <<endl ;
    f<<"l id est: "<<clients[i]->getID() <<endl ;
    f<<"le nom est: "<<clients[i]->getNom() <<endl ;
    f<<"le prenom est: "<<clients[i]->getPrenom() <<endl ;

}
f.close() ;
}
/*pharmacie::pharmacie(const pharmacie& ph){
            Client* clt;
            for (unsigned int i=0;i<ph.clients.size();i++)
            {//if (typeid(*ph.tab[i])==typeid(Client))
    //{
                clt=new Client(*ph.clients[i]);
    //}else{
      //   M=new Mforfait(static_cast<const Mforfait&>(*S.tab[i]));
    //}
                clients.push_back(clt);
            }
            }*/
void pharmacie::ajouterClient()
            {int x=0 ;
    int a=0;
    do {
    x=clients.size() ;
    Client *CLT = new Client() ;
    clients.insert(clients.begin()+x , CLT) ;
    cout<<"voulez vous faire un autre saisie ? 1) oui 2)non" <<endl ;
    cin>>a ;
    } while (a==1) ;
            }

            void pharmacie::chercherClients(int identity) {
for (int i=0 ; i<clients.size() ; i++) {
    if (clients[i]->getID()==identity){
        cout<<clients[i];
        cout<<"positon de ce client est "<<i <<endl ;
        }
}

}
void pharmacie::lireFileClients(fstream& f) {
f.open("client.txt", ios::in | ios::out | ios::app);
Client*cl ;
while (1) {
        if (f.eof() )
            break ;
        cl=new Client() ;
        f>>*cl ;
        clients.push_back(cl) ;
}
tab.pop_back() ;
f.close() ;
}
/*void pharmacie::lireFileClients(fstream& FileCLT) {
FileCLT.open("clients.txt", ios::in | ios::out | ios::app);
//Client *clt ;
while (1) {
        if (FileCLT.eof() )
            break ;
   Client*    clt=new Client() ;
        FileCLT>>clt ;
        clients.push_back(clt) ;
}
clients.pop_back() ;
FileCLT.close() ;
}*/
int pharmacie::trouverPositionCLT(int identity) {
for (int i=0 ; i<clients.size() ; i++) {
    if (clients[i]->getID()==identity){
        return(i+1);}
}

return(0) ;
}
void pharmacie :: supprimerClt(int x) {
int y=trouverPositionCLT(x) ;
chercherClients(x) ;
if (y==0)
    cout<<"Client inexistant"<<endl ;
delete clients[y-1] ;
clients.erase(clients.begin()+(y-1)) ;
}
void pharmacie::modifierCLT(int y) {
    int a=trouverPositionCLT(y) ;
    chercherClients(y) ;
    int x ,id;
string nom , prenom;
    cout<<"Qu'est ce que vous voulez changer ? \n 1) id 2)prenom 3)nom" <<endl ;
    cin>>x ;
    switch(x) {
    case 3:
    cout<<"donnez le nouveau nom " <<endl ;
    cin>>nom  ;
clients[a-1]->setNom(nom);
    break;
    case 2:
    cout<<"donnez le nouveau prenom " <<endl ;
    cin>>prenom;
    clients[a-1]->setPrenom(prenom);
    break;
    case 1:
    cout<<"donnez le nouveau id " <<endl ;
    cin>>id;
    clients[a-1]->setId(id) ;

    break;
  default:
    cout<<"Vérifier votre saisie"<<endl ;
}

}
void pharmacie::ecrireFirstCLT(fstream& fileclt) {
fileclt.open("clients.txt", ios::in | ios::out | ios::app);
if (! fileclt.is_open())
    exit (-1) ;

for (int i=0 ; i<clients.size() ; i++){

   fileclt<<*clients[i]<<endl  ;

}

fileclt.close() ;
}
//------------------------------------------------------------------------------------------------------------------------------------

/*pharmacie::~pharmacie()
{
        for (int i=0 ; i<tab.size() ; i++)
        delete tab[i] ;
    tab.clear() ;
}
*/


void pharmacie::ajouterFR()
{
int x=0 ;
    int a=0;
    do {
    x=tab.size() ;
    fournisseur *f = new fournisseur() ;

    cout<<"donner le code / nom / prenom  "<<endl ;
    cin>>*f;
    tab.insert(tab.begin()+x , f) ;
    cout<<"voulez vous faire un autre saisie ? 1) oui 2)non" <<endl ;
    cin>>a ;
    } while (a==1) ;
} ;

void pharmacie::chercherFR(int identity) {
for (int i=0 ; i<tab.size() ; i++) {
    if (tab[i]->getID()==identity){
        tab[i]->affichageF() ;
        cout<<"positon de ce client est "<<i <<endl ;
        }
}

}

int pharmacie::trouverPosition(int identity) {
for (int i=0 ; i<tab.size() ; i++) {
    if (tab[i]->getID()==identity){
        return(i+1);}
}

return(0) ;
}

void pharmacie :: supprimerFR(int x) {
int y=trouverPosition(x) ;
chercherFR(x) ;
if (y==0)
    cout<<"fournisseur n existe pas"<<endl ;
delete tab[y-1] ;
tab.erase(tab.begin()+(y-1)) ;
}



void pharmacie::afficherFR(){
for (int i=0 ; i<tab.size() ; i++) {
    tab[i]->affichageF() ;
}
}

void pharmacie::modifierFR(int y) {
    int a=trouverPosition(y) ;
    chercherFR(y) ;
    int x , id;
    string nom , prenom ;
    cout<<"Qu'est ce que vous voulez changer ? \n 1) id 2)prenom 3)nom" <<endl ;
    cin>>x ;
    switch(x) {
    case 3:
    cout<<"donnez le nouveau nom " <<endl ;
    cin>>nom ;
    tab[a-1]->setNom(nom) ;
    break;
    case 2:
    cout<<"donnez le nouveau prenom " <<endl ;
    cin>>prenom ;
    tab[a-1]->setPrenom(prenom) ;
    break;
    case 1:
    cout<<"donnez le nouveau id " <<endl ;
    cin>>id ;
    tab[a-1]->setId (id ) ;
    break;
  default:
    cout<<"Vérifier votre saisie"<<endl ;
}

}

void pharmacie::ecrireFichier(fstream& f) {
f.open("fournisseur.txt", ios::in | ios::out | ios::trunc);
if (! f.is_open())
    exit (-1) ;

for (int i=0 ; i<tab.size() ; i++){

    f<<*tab[i]<<endl  ;

}

f.close() ;
}

void pharmacie::ecrireFirst(fstream& f) {
f.open("fournisseur.txt", ios::in | ios::out | ios::app);
if (! f.is_open())
    exit (-1) ;

for (int i=0 ; i<tab.size() ; i++){

    f<<*tab[i]<<endl  ;

}

f.close() ;
}
void pharmacie::lire(fstream& F2) {
F2.open("fournisseur.txt", ios::in | ios::out | ios::app);
fournisseur *fr ;
while (1) {
        if (F2.eof() )
            break ;
        fr=new fournisseur() ;
        F2>>*fr ;
        tab.push_back(fr) ;
}
tab.pop_back() ;
F2.close() ;
}
// --------------------------------------------------------------------------------------------------------------------------

pharmacie::pharmacie(const pharmacie&p)
{
    commande*c;
    for (int i=0;i<p.tab_com.size();i++)
        c=new commande(*p.tab_com[i]);
    tab_com.push_back(c);

}
istream& operator>>(istream&im,pharmacie&p)
{
    commande*cm=new commande();
    im>>*cm;
    p.tab_com.push_back(cm);
    cout<<endl<<"              Commande pass\x82 avec succ\x82s !"<<endl<<endl;
}

void pharmacie::enregistrer_com()
{
    fstream f("commande.txt",ios::out|ios::app);
    for (int i=0 ; i<tab_com.size() ; i++)
        f<<*tab_com[i]<<endl  ;
}

void pharmacie::enregistrer_com_modifier()
{
    fstream f("commande.txt",ios::out|ios::trunc);
    for (int i=0 ; i<tab_com.size() ; i++)
        f<<*tab_com[i]<<endl  ;
}

void pharmacie::lire()
{
    commande*c;
    int val;
    ifstream f("commande.txt");
    if(!f) cout<<"erreur";
    while(1)
    {
        f>>val;
        if (f.eof()) break;
         if (val==0)
         {
             c=new commande();
             f>>*c;
              tab_com.push_back(c);

             //cout<<*m;
         }
    }
}

 void pharmacie::chercher_com()
 {
     int cd,i;
     cout<<"Saisir un numero : ";
     cin>>cd;
     while ((i<tab_com.size())&&(tab_com[i]->getnum_com()!= cd))
        i++;

     if (i<tab_com.size())
        tab_com[i]->afficher_com();
     else
        cout<<endl<<"                           Commande n'existe pas ! Vous devez verifier le numero saisie !"<<endl;
 }
void pharmacie::afficher_liste_comm()
{
    for (int i=0 ; i<tab_com.size() ; i++)
        tab_com[i]->afficher_com();

}
int pharmacie::chercher_com(int cd)
{
    int a=-1;
    for (int i=0;i<tab_com.size();i++)
    {
        if (tab_com[i]->getnum_com()== cd)
            a=i;
        }
        return a;

}
void pharmacie::annuler_com()
{
    int c,cd,rep2;

        //lire();
        cout<<"                                Saisir un code : ";
        cin>>c;
        cd=chercher_com(c);
        if (cd != -1)
        {
            tab_com[cd]->afficher_com();
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
                    tab_com.erase(tab_com.begin()+cd);
                    enregistrer_com_modifier();
                    //lire();
                    cout<<"                        Commande supprim\x82 avec succ\x82s !"<<endl;
                }

    }
    else
            cout<<endl<<"                           Commande n'existe pas ! Vous devez verifier le numero saisie !"<<endl<<endl;
}
void pharmacie::lire_med()
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
            tab_m.push_back(s);


         }
         else if (val==2)
         {
             s= new sirop();
             f>>*s;
            tab_m.push_back(s);

        }
         else if (val==3)
         {
             c= new comprime();
             f>>*c;
             tab_m.push_back(c);

         }
        else if (val==4)
         {
             pl= new pellicule();
             f>>*pl;
             tab_m.push_back(pl);

         }
        else if (val==5)
         {
             pm= new pomade();
             f>>*pm;
             tab_m.push_back(pm);
         }
       }
    f.close();}
    catch (int x){cout<<"                           Fichier N'existe Pas ! "<<endl<<endl;
    exit(-1);}
}
void pharmacie::accepter_com(int id_f)
{
    int rep,code,c,nb_b,n,nboites;
        for (int i=0 ; i<tab_com.size() ; i++)
        {
            if (tab_com[i]->getcode_f()== id_f)
                tab_com[i]->afficher_com();
            do{
            cout <<"                           Voulez vous accepter cette commande ?";
            cout<<"                              1/Oui"<<endl;
            cout<<"                              2/Non"<<endl;
            cout<<endl<<"                           Entrer Votre Choix  \t";
            cin>>rep;
            }while(rep<1 ||rep>2);
            if (rep==1)
            {
                for (int j=0 ; j<tab_com[i]->tab_med.size() ; j++)
                {
                    code=tab_com[i]->tab_med[j]->getcode(); // get code -> rech code dans tab_m --> modification quatité --> modification fichier // vect sr cp pel pom
               // cout<<"code"<<code<<endl;
                 c=rechercher_m(code);
                // cout <<"pos"<<c<<endl;
                 n=tab_m[c]->getnb_boite();
                //cout <<"qte tab_m"<<n<<endl;
                nb_b=tab_com[i]->tab_med[j]->getnb_boite();
              //  cout <<"qte tabcom"<<nb_b<<endl;
                nboites=n+nb_b;
              //  cout <<"nb boites"<<nboites<<endl;
                tab_m[c]->setnb_boite(nboites);

                modifier_fichier();
                tab_m[c]->afficher();
                }
            }
        }

}
int pharmacie::rechercher_m(int cd)
{
    int a=-1;
    for (int i=0;i<tab_m.size();i++)
    {
        if (tab_m[i]->getcode()== cd)
            a=i;
        }
        return a;
}
void pharmacie::aff()
{
    for (int i=0;i<tab_m.size();i++)
        tab_m[i]->afficher();
}
 void pharmacie::modifier_fichier()
 {
      try {
     fstream f("stock.txt",ios::out);

    if (!f)
       throw -1;
    for (int i=0;i<tab_m.size();i++)
        {
            if (typeid(*tab_m[i])==typeid(medicament))
            {
                 f<<"1 "<<endl<<*tab_m[i]<<endl;
            }
            else if (typeid(*tab_m[i])==typeid(sirop))
            {
                 f<<"2 "<<static_cast< sirop&>(*tab_m[i])<<endl;
            }
            else if (typeid(*tab_m[i])==typeid(comprime))
            {
                 f<<"3 "<<static_cast< comprime&>(*tab_m[i])<<endl;
            }
                        else if (typeid(*tab_m[i])==typeid(pellicule))
            {
                 f<<"4 "<<static_cast< pellicule&>(*tab_m[i])<<endl;
            }
            else if (typeid(*tab_m[i])==typeid(pomade))
            {
                 f<<"5 "<<static_cast< pomade&>(*tab_m[i])<<endl;
            }
        }
    cin.ignore(1,'\n');
    f.close();}
    catch (int x){cout<<"                           Erreur Fichier ! "<<endl<<"                           Erreur Number "<<x<<endl;
    exit(-1);}
 }
