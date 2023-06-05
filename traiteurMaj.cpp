#include"traiteurMaj.h"
#include<cctype>

using namespace std;

void TraiteurMaj::traitement(vector<string> &mots)
{
    for(string &s : mots)
    {
        for(char &c : s)
        {
            c = tolower(c);
        }
    }
}
