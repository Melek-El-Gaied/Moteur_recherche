#include "traiteurPonct.h"
#include <string>
#include <iostream>
#include<cctype>
#include<bits/stdc++.h>



void traiteurPonct::traitement(vector<string> &mots)
{
    for(string &s : mots)
    {
        for(int i = 0; i < s.size(); i++)
            {
                if(ispunct(s[i]))
                {
                    s.erase(i--,1);
                }
            }
    }
    auto itr=remove(mots.begin(),mots.end(),"");
    while(mots.back()=="")
    {
        mots.pop_back();
    }
}
