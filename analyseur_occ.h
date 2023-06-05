#ifndef ANALYSEUR_OCC_H_INCLUDED
#define ANALYSEUR_OCC_H_INCLUDED
#include"Analyseur.h"
#include<vector>

class Analyseur_Occ : public Analyseur
{
public:
    Analyseur_Occ():Analyseur(){};
    ~Analyseur_Occ(){};
    vector<Stat> analyser(string cheminFile,vector<string> mots);   //statistique utilise : calcule de nombre d'occurrence

};


#endif // ANALYSEUR_OCC_H_INCLUDED
