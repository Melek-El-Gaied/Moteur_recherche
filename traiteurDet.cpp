#include"traiteurDet.h"
#include<bits/stdc++.h>


using namespace std;

void TraiteurDet::traitement(vector<string> &mots)
{

    for(string &s : mots)
    {
        const bool test = det.find(s) != det.end();
        if(test)
        {
            auto itr=remove(mots.begin(),mots.end(),s);
        }
    }
    while(mots.back()=="")
    {
        mots.pop_back();
    }
}
