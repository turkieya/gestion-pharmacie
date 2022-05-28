#include "fournisseur.h"
#include <iostream>
fournisseur::fournisseur()
{

}

fournisseur::~fournisseur()
{

}

int fournisseur::getID() {
return id ;
}

string fournisseur::getNom() {
return nom ;
}

string fournisseur::getPrenom() {
return prenom ;
}

void fournisseur::setId (int a) {
id =a ;
}

void fournisseur::setNom (string b ) {
nom =b ;
}
void fournisseur::setPrenom (string c) {
prenom=c ;
}

void fournisseur::affichageF() {
cout<<"l id de fournisseur est " <<id <<endl;
cout <<"le prenom de fournisseur est " << prenom <<endl;
cout << "l nom de fournisseur est " << nom <<endl ;
}
