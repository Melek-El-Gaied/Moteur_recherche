#include "stat.h"
#include "analyseur_freq.h"
#include <vector>

#include<bits/stdc++.h>

using namespace std;

vector<Stat> Analyseur_Freq::analyser(string cheminFile,vector<string> mots)
{
    vector<Stat> vecstat;
    int n=mots.size();
    vector<string> tmp;      //utuliser pour assurer l'unicite d'un mot dans le vecteur vecstat
    Stat s;
    vector<string>::iterator it;
    for(string &m : mots )
    {
        auto itr =find(tmp.begin(),tmp.end(),m);
        if(itr==tmp.end())
        {
            s.set_statMot(double(count(mots.begin(),mots.end(),m))/n);      //calcule frequantielle du mot
            s.set_mot(m);
            s.set_cheminFile(cheminFile);
            vecstat.push_back(s);
            tmp.push_back(m);
        }
    }
    tmp.clear();
    return vecstat;

}
