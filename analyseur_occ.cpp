#include "stat.h"
#include "analyseur_occ.h"
#include <vector>

#include<bits/stdc++.h>

using namespace std;

vector<Stat> Analyseur_Occ::analyser(string cheminFile,vector<string> mots)
{
    vector<Stat> vecstat;
    Stat s;
    vector<string> tmp;             //utiliser pour assurer l'unicite d'un mot dans le vecteur vecstat
    vector<string>::iterator it;
    for(string& m : mots )
    {
        auto itr =find(tmp.begin(),tmp.end(),m);
        if(itr==tmp.end())
        {
            s.set_statMot(count(mots.begin(),mots.end(),m));    //calcule du nombre d'occurrence du mot
            s.set_mot(m);
            s.set_cheminFile(cheminFile);
            vecstat.push_back(s);
            tmp.push_back(m);
        }
    }
    tmp.clear();
    return vecstat;

}
