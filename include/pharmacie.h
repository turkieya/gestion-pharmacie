#ifndef PHARMACIE_H
#define PHARMACIE_H
#include "fournisseur.h"
#include"commande.h"
#include <vector>
#include"Client.h"

class pharmacie
{
    public:
        pharmacie();
        virtual ~pharmacie();
        void ajouterFR() ;
        void chercherFR(int) ;
        int trouverPosition(int) ;
        void supprimerFR (int) ;
        void afficherFR() ;
        void modifierFR(int) ;
        void ecrireFichier(fstream&) ;
        void ecrireFirst(fstream&) ;
        void lire(fstream&);
//************************************************************************************************************
        void ajouterClient();
        void chercherClients(int);
        bool Enregistrer();
        void ecrireFichierClients(fstream&);
        void lireFileClients(fstream& ) ;
        int trouverPositionCLT(int);
        void supprimerClt(int ) ;
        void modifierCLT(int);
        void ecrireFirstCLT(fstream& );
        void afficherCLT() ;
//*************************************************************************************************************
        friend istream& operator>> (istream&,pharmacie&);
        void enregistrer_com();
        void chercher_com();
        int chercher_com(int);
        void annuler_com();
        void afficher_liste_comm();
        void enregistrer_com_modifier();
        void lire();
        void accepter_com(int);
        pharmacie(const pharmacie&);
        void lire_med();
        int rechercher_m(int);
        void aff();
        void modifier_quantite(int);
        void modifier_fichier();

    protected:

    private:
        vector <fournisseur*> tab ;
        vector <commande*> tab_com ;
        vector <Client*> clients;
        vector <medicament*>tab_m;

};

#endif // PHARMACIE_H
