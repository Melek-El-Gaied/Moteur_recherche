#include<iostream>
#include<vector>
#include<string>
#include"stat.h"
#include"ordonnanceur1.h"
#include<map>

vector<string> Ordonnanceur1::ordonnanceur(map <string,vector<Stat> >m)
{
    vector<string> resultat;
    map<string,double> tmp;
    for( auto itrmap=m.begin();itrmap!=m.end();itrmap++)
    {
        for (auto itrvec=(itrmap->second).begin();itrvec!=(itrmap->second).end();itrvec++)
        {
            auto itrtmp=tmp.find(itrvec->get_cheminFile());
            if(itrtmp!=tmp.end())
            {
                tmp[itrvec->get_cheminFile()]+=itrvec->get_statMot();
            }
            else
            {
                tmp.insert({itrvec->get_cheminFile(),itrvec->get_statMot()});
            }
        }
    }

    multimap<double, string> mmtmp;

    for (auto& it : tmp) {
        mmtmp.insert({ it.second, it.first });
    }
    for (auto& itrmm : mmtmp)
    {
        resultat.insert(resultat.begin(),itrmm.second);
    }

    return resultat;

}




















