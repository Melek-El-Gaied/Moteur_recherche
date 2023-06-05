#ifndef ANALYSEUR_FREQ_H_INCLUDED
#define ANALYSEUR_FREQ_H_INCLUDED
#include"Analyseur.h"
#include<vector>

class Analyseur_Freq : public Analyseur
{
public:
    Analyseur_Freq():Analyseur(){};
    ~Analyseur_Freq(){};
    vector<Stat> analyser(string cheminFile,vector<string> mots);    //statistique utilise : calcule frequantielle du mot
};


#endif // ANALYSEUR_FREQ_H_INCLUDED
