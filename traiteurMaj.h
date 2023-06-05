#ifndef TRAITEURMAJ_H_INCLUDED
#define TRAITEURMAJ_H_INCLUDED
#include "traiteur.h"
#include <iostream>
#include<vector>

class TraiteurMaj: public Traiteur
{
public:
    TraiteurMaj():Traiteur(){};
    ~TraiteurMaj(){};
    void traitement(vector<string> &mots);      //remplacer tous les caracteres d'un mot en minuscule
};



#endif // TRAITEURMAJ_H_INCLUDED
