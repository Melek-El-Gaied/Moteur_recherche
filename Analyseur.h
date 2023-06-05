#ifndef ANALYSEUR_H_INCLUDED
#define ANALYSEUR_H_INCLUDED
#include "stat.h"
#include <vector>

using namespace std ;

class Analyseur {
public:
    Analyseur(){};
    virtual ~Analyseur(){};
    virtual vector<Stat> analyser(string cheminFile,vector<string> mots)=0;     //calcule des statistiques des mots apartir du vecteur mots et de chemin de fichier de ce vecteur

};


#endif // ANALYSEUR_H_INCLUDED
