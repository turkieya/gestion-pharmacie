
#include <pharmacie.h>
#include <fournisseur.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"stock.h"
#include"sirop.h"
#include"comprime.h"
#include"medicament.h"
#include"commande.h"
#include<typeinfo>

using namespace std;

int main()
{
    stock s;
    int a,b;
    pharmacie fr,p ;
    fstream F2 ;
    int choix,choix1,choix2,choix3,choix4,choix5,choix6,choix7,choix8,choix9,choix10,choix11,mn,rep,rep3,choix_m,cd;
    int c,m;
    //sirop*sr;
    //comprime*cm;
       pharmacie CLT;
    fstream fileCLT;
    int idclt,posCLT;
    system("COLOR F5");

	cout<<"\n\n                                                 GESTION PHARMACIE \n\n";cout<<"\n";

do{
		cout<<"                            ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                            º   -----------------------------------------------------  º"<<endl;
		cout<<"                            º     | 1 | Espace Pharmacie                               º"<<endl;
        cout<<"                            º                                                          º"<<endl;
        cout<<"                            º     | 2 | Espace Client                                  º"<<endl;
        cout<<"                            º                                                          º"<<endl;
        cout<<"                            º     | 3 | Espace Fournisseur                             º"<<endl;
        cout<<"                            º                                                          º"<<endl;
	    cout<<"                            º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                            º   -----------------------------------------------------  º"<<endl;
        cout<<"                            ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;

    do{
        cout<<"                            *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                           ";
        cin>>choix1;
    }while(choix1<0 ||choix1>3);
    if (choix1==0)
        exit( EXIT_SUCCESS );
    if (choix1==1)
    {
        system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | G\x82rer Clients                                  º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | G\x82rer Fournisseurs                             º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | G\x82rer Medicaments                              º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 4 | G\x82rer Commandes                                º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;

   do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                          ";
        cin>>choix2;
    }while(choix2<0 ||choix2>5);
    if(choix2==1)
    {   system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Ajouter Client                                 º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | Liste des Clients                              º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | Chercher Client                                º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 4 | Modifier Client                                º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 5 | Supprimer Client                               º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
    do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                             ";
        cin>>choix3;
    }while(choix3<0 ||choix3>5);
    if(choix3==1)
    {
       //ajout client system("cls");
         CLT.ajouterClient();

       CLT.afficherCLT();
        CLT.ecrireFirstCLT(fileCLT) ;
        system("PAUSE");
        system("cls");
    }
    if(choix3==2)
    {
                CLT.lireFileClients(fileCLT) ;
        CLT.afficherCLT();
        system("PAUSE");
        system("cls");
    }
    if(choix3==3)
    {
      CLT.lireFileClients(fileCLT) ;
        cout<<"Donner id du Client recherch้ "<<endl ;
        cin>>idclt ;
        posCLT=CLT.trouverPositionCLT(idclt) ;
        if (posCLT==0)
        cout<<"Client Inexistant"<<endl ;
        else
        {   CLT.chercherClients(idclt) ;
           CLT.ecrireFichierClients(fileCLT) ; }
        system("PAUSE");
        system("cls");
    }
    if(choix3==4)
    {
       CLT.lireFileClients(fileCLT) ;
                do {
            cout<<"donner id du client a modifier "<<endl ;
            cin>>idclt ;
            posCLT=CLT.trouverPositionCLT(idclt) ;
            if (posCLT==0)
            cout<<"client Inexistant"<<endl ;
             } while (posCLT==0) ;

        CLT.modifierCLT(idclt) ;
        CLT.ecrireFichierClients(fileCLT) ;
        CLT.afficherCLT() ;
        system("PAUSE");
        system("cls");

    }
    if(choix3==5)
    {
        CLT.lireFileClients(fileCLT) ;
        do {
            cout<<"donner id du Client a supprimer "<<endl ;
            cin>>idclt ;
            posCLT=CLT.trouverPositionCLT(idclt) ;
            if (posCLT==0)
            cout<<"Client Inexistant"<<endl ;
             } while (posCLT==0) ;
        CLT.supprimerClt(idclt) ;
        system("cls");
        CLT.ecrireFichierClients(fileCLT) ;
        CLT.afficherCLT();
        system("PAUSE") ;
        system("cls");
    }

}
//**************Partie SYRINE **********//
if(choix2==2)
    {   system("cls");

        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Ajouter Fournisseur                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | Liste des Fournisseurs                         º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | Chercher Fournisseur                           º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 4 | Modifier Fournisseur                           º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 5 | Supprimer Fournisseur                          º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
    do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                             ";
        cin>>choix4;
    }while(choix4<0 ||choix4>5);
    if(choix4==1)
    {
        fr.ajouterFR() ;
        fr.afficherFR() ;
        fr.ecrireFirst(F2) ;
        system("PAUSE");
        system("cls");
    }
    if(choix4==2)
    {
        fr.lire(F2) ;
        fr.afficherFR() ;
        system("PAUSE");
        system("cls");
    }
    if(choix4==3){
        fr.lire(F2) ;
        cout<<"donner l id de fournisseur a rechercher "<<endl ;
        cin>>a ;
        b=fr.trouverPosition(a) ;
        if (b==0)
        cout<<"fournisseur Inexistant"<<endl ;
        else
        {   fr.chercherFR(a) ;}
        system("PAUSE");
        system("cls");
    }
    if(choix4==4)
    {
        fr.lire(F2) ;
                do {
            cout<<"donner l id de fournisseur a modifier "<<endl ;
            cin>>a ;
            b=fr.trouverPosition(a) ;
            if (b==0)
            cout<<"fournisseur Inexistant"<<endl ;
             } while (b==0) ;

        fr.modifierFR(a) ;
        fr.ecrireFichier(F2) ;
       // fr.afficherFR() ;
        system("PAUSE");
        system("cls");

    }
    if(choix4==5)
    {
        fr.lire(F2) ;
        do {
            cout<<"donner l id de fournisseur a supprimer "<<endl ;
            cin>>a ;
            b=fr.trouverPosition(a) ;
            if (b==0)
            cout<<"fournisseur Inexistant"<<endl ;
             } while (b==0) ;
        fr.supprimerFR(a) ;
        system("cls");
        fr.ecrireFichier(F2) ;
        fr.afficherFR() ;
        system("PAUSE") ;
        system("cls");
    }

system("cls");
    }

//***********Fin partie SYRINE ************
if(choix2==3)
    {   system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Ajouter Medicament                             º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | Chercher Medicament                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | Modifier Medicament                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 4 | Supprimer Medicament                           º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 5 | Afficher Stock                                 º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
    do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                             ";
        cin>>choix5;
    }while(choix5<0 ||choix5>5);
     if(choix5==1)
    {
        system("cls");
        cin>>s;
        s.enregistrer();
    }
    if(choix5==2)
    {
        system("cls");
        s.lire();
        s.rechercher();
    }
    if(choix5==3){
        system("cls");

do
        {

            cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMEDICAMENTSÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
            cout<<"                           º   -----------------------------------------------------  º"<<endl;
            cout<<"                           º     | 1 | Modifier Sirop                                 º"<<endl;
            cout<<"                           º                                                          º"<<endl;
            cout<<"                           º     | 2 | Modifier Comprim\x82                              º"<<endl;
            cout<<"                           º                                                          º"<<endl;
            cout<<"                           º     | 3 | Modifier Pellicule                             º"<<endl;
            cout<<"                           º                                                          º"<<endl;
            cout<<"                           º     | 4 | Modifier Pomade                                º"<<endl;
            cout<<"                           º                                                          º"<<endl;
            cout<<"                           º     | 0 | EXIT                                           º"<<endl;
            cout<<"                           º   -----------------------------------------------------  º"<<endl;
            cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
            do{
                cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
                cout<<"                                                           ";
                cin>>choix_m;
                }while(choix_m<0 ||choix_m>4);
            s.lire();
            if (choix_m==1)
            {
                cout<<"                                Saisir un code : ";
                cin>>cd;
                c=s.rechercher_sr(cd);
                m=s.rechercher_m(cd);
                if (c != -1)
                {
                    s.modifier_sr(c,m);
                }
            }
            if (choix_m==2)
            {
                cout<<"                                Saisir un code : ";
                cin>>cd;
                c=s.rechercher_cm(cd);
                m=s.rechercher_m(cd);
                if (c != -1)
                {
                   s.modifier_cm(c,m);
                }
            }
            if (choix_m==3)
            {
                cout<<"                                Saisir un code : ";
                cin>>cd;
                c=s.rechercher_pl(cd);
                m=s.rechercher_m(cd);
                if (c != -1)
                {
                   s.modifier_pl(c,m);
                }
            }
            if (choix_m==4)
            {
                cout<<"                                Saisir un code : ";
                cin>>cd;
                c=s.rechercher_pm(cd);
                m=s.rechercher_m(cd);
                if (c != -1)
                {
                   s.modifier_pm(c,m);
                }
            }
        } while (rep==1);


    }
    if(choix5==4)
    {
        system("cls");

        s.supprimer();

    }
    if(choix5==5)
    {
         system("cls");
         s.lire();
         s.charger_medicaments();
         //sr->charger();
        // s.afficher_stock();
    }

}
if(choix2==4)
    {   system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | G\x82rer Commandes Clients                        º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | G\x82rer Commandes Fournisseurs                   º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
    do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                            ";
        cin>>choix6;
    }while(choix6<0 ||choix6>5);
    if(choix6==1)
    {
        system("cls");
    }
    if(choix6==2)
    {
        system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Passer Commandes                               º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | Rechercher Commande                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | Annuler Commande                               º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 4 | Liste des Commandes                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
        do{
            cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
            cout<<"                                                             ";
            cin>>choix11;
        }while(choix11<0 ||choix11>5);
     if(choix11==1)
    {
       system("cls");
       cin>>p;
       p.enregistrer_com();

    }
    if(choix11==2)
    {
        system("cls");
        p.chercher_com();

    }
    if(choix11==3)
    {
         system("cls");
         p.annuler_com();
    }
    if(choix11==4)
    {
         system("cls");
        // p.lire();
         p.afficher_liste_comm();
    }
    }

}
}
if (choix1==2)
    {
        system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Modifier Informations                          º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | G\x82rer Commandes                                º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;

   do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                          ";
        cin>>choix7;
    }while(choix7<0 ||choix7>3);
    if (choix7==1)
    {
        system("cls");
    }
    if (choix7==2)
    {
        system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Passer Commandes                               º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | Rechercher Commande                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | Liste des Commandes                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
    do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                             ";
        cin>>choix8;
    }while(choix8<0 ||choix8>4);
     if(choix8==1)
    {
       system("cls");

    }
    if(choix8==2)
    {
        system("cls");

    }
    if(choix8==3)
    {
         system("cls");
    }
    }
    }
    if (choix1==3)
    {
        system("cls");
        fr.lire(F2) ;
        do {
                cout<<"Saisir votre ID :  "<<endl ;
                cin>>a ;
                b=fr.trouverPosition(a) ;
                if (b==0)
                    cout<<"ID Inexistant"<<endl ;
            } while (b==0) ;
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Modifier Informations                          º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | G\x82rer Commandes                                º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;

   do{
        cout<<"                           *                    Entrer Votre Choix                    *\t"<<endl;
        cout<<"                                                          ";
        cin>>choix9;
    }while(choix9<0 ||choix9>3);
    if (choix9==1)
    {
        system("cls");

        fr.modifierFR(a) ;
        fr.ecrireFichier(F2) ;

    }
    if (choix9==2)
    {
        system("cls");
        cout<<"                           ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍMENUÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
		cout<<"                           º   -----------------------------------------------------  º"<<endl;
		cout<<"                           º     | 1 | Accepter Commandes                             º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 2 | Rechercher Commande                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
        cout<<"                           º     | 3 | Liste des Commandes                            º"<<endl;
        cout<<"                           º                                                          º"<<endl;
	    cout<<"                           º     | 0 | EXIT                                           º"<<endl;
	    cout<<"                           º   -----------------------------------------------------  º"<<endl;
        cout<<"                           ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
    do{
        cout<<"                           *                    Entrer Votre Choix                    *\t";
        cout<<endl<<"                                                           ";
        cin>>choix10;
    }while(choix10<0 ||choix10>4);
     if(choix10==1)
    {
       system("cls");
       p.lire_med();
       p.accepter_com(a);

    }
    if(choix10==2)
    {
        system("cls");

    }
    if(choix10==3)
    {
         system("cls");
         p.lire_med();
         p.aff();
         //int j=p.rechercher_m(9);
        // cout<<j;
    }
    }
    }
     if (choix1==0)
    exit( EXIT_SUCCESS );
    cout<<endl<<"                           Voulez-vous retourner au menu principale ?"<<endl;
    cout<<"                              1/Oui"<<endl;
    cout<<"                              2/Non"<<endl;
    cout<<endl<<"                           Entrer Votre Choix  \t";
    cin>>mn;
    if (mn==2)
    {
        system("cls");
        cout<<"    Merci !! Au revoir monsiour/Madamme !! ";
    }
    if (mn==1) system("cls");
    } while(mn==1);
getch();
    }
