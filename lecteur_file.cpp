#include"lecteur_file.h"
#include <iostream>
#include<vector>
#include <fstream>

using namespace std;

vector<string> LecteurFile::lire(string cheminFile)
{
    vector<string> mots;
    string mot;
    ifstream fichier(cheminFile);
    if (!fichier.is_open()) {
        cerr << "impossible d'ouvrir le fichier " << cheminFile << endl;
    }

    while (fichier >> mot) {
        mots.push_back(mot);
    }
    fichier.close();
    return mots ;
};
