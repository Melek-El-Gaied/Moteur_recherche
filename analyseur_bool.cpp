#include "stat.h"
#include "analyseur_bool.h"
#include <vector>
#include<bits/stdc++.h>

using namespace std;

vector<Stat> Analyseur_Bool::analyser(string cheminFile,vector<string> mots)
{
    vector<Stat> vecstat;
    Stat s;
    vector<string> tmp;             //utiliser pour assurer l'unicite d'un mot dans le vecteur vecstat
    vector<string>::iterator it;

    for(auto& m : mots)
    {
        auto itr =find(tmp.begin(),tmp.end(),m);
        if(itr==tmp.end())
        {
            s.set_statMot(1);
            s.set_mot(m);
            s.set_cheminFile(cheminFile);
            vecstat.push_back(s);
            tmp.push_back(m);
        }
    }
    tmp.clear();

    return vecstat;

}
