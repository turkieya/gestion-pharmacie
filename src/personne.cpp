#include "personne.h"
#include <iostream>
using namespace std;


istream& operator>>(istream& in , personne& fr ) {
cout<<"    " ;
in>>fr.id;
in.ignore() ;
cout<<"    " ;
in>>fr.prenom;
in.ignore() ;
cout<<"    " ;
in>>fr.nom;
in.ignore() ;
 return in ;
 }

 ostream& operator<<(ostream& out , personne& fr ) {
out<<fr.id <<endl<<fr.prenom<<endl<<fr.nom ;
return out ;
 }


personne::personne()
{


}

personne::~personne()
{
}
