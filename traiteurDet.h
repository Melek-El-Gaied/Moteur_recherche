#ifndef TRAITEURDET_H_INCLUDED
#define TRAITEURDET_H_INCLUDED
#include"traiteur.h"
#include<vector>
#include<set>

using namespace std;


class TraiteurDet: public Traiteur
{
public:
    set<string> det {"this","that","these","those","the","a","an"};
    TraiteurDet():Traiteur(){};
    ~TraiteurDet(){};
    void traitement(vector<string> &mots);  //supprimer tous les mots du vecteur qui appartiennent a la liste det
};


#endif // TRAITEURDET_H_INCLUDED
