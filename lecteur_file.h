#ifndef LECTEUR_LECT_H_INCLUDED
#define LECTEUR_LECT_H_INCLUDED
#include "lecteur.h"
#include <iostream>
#include<vector>
#include <fstream>

using namespace std;

class LecteurFile:public Lecteur
{
    public:
    LecteurFile():Lecteur(){};
    ~LecteurFile(){};
    vector<string> lire(string cheminFile);     //Cette methode permet de lire les mots d'un fichier et les stocker dans un vecteur de string apartir de son chemin.
};


#endif // LECTEUR_LECT_H_INCLUDED
