#include"index1.h"
#include"stat.h"
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<map>
#include<string>
#include<set>


void Index1::indexer(vector < Stat > vec)
{
    map<string,vector<Stat> >::iterator itr1;
    fichiers_indexes.insert((vec.begin())->get_cheminFile());
    for(vector<Stat>::iterator itr= vec.begin();itr!=vec.end();itr++)   //parcour du vec (vector stat)
    {
        itr1=ind1.find(itr->get_mot());    //recheche du mot dans l'index
        if(itr1!=ind1.end())               //si le mot existe dans l'index
        {
            auto f=find(itr1->second.begin(),itr1->second.end(),*itr);
            if(f!=itr1->second.end())      //si le mot existe dans fichier deja indexe on fait une mise a jour a la statistique
            {
                f->set_statMot(itr->get_statMot());
            }
            else                           //sinon on ajoute la statistique
            {
                    (itr1->second).push_back(*itr);
            }
        }
        else                               //si le mot n'existe pas dans l'index
        {
            vector<Stat> tmp;
            tmp.push_back(*itr);
            ind1.insert(pair<string,vector<Stat> >(itr->get_mot(),tmp));
        }


    }
}

void Index1::affichierindex()const
{
    cout<<"\t\t***********Index du moteur de recherche***********"<<endl;
    for(auto& m:ind1)
    {
        cout<<m.first<<endl;
        //cout<<"Mot : "<<m.first<<endl;     //une 2 eme facon d'affichage
        for(auto& s:m.second)
        {
            cout<<"\t"<<s.get_cheminFile()<<"\t\t"<<s.get_statMot()<<endl;
            //cout<<"\tFichier : "<<s.get_cheminFile()<<"\tStat : "<<s.get_statMot()<<endl;     //une 2 eme facon d'affichage
        }
    }
    cout<<"\t\t**************************************************"<<endl;

}

void Index1::affichierfichiersindexes()const
{
    cout<<"\t\t***********Fichiers indexes du moteur de recherche***********"<<endl;
    for(auto& v:fichiers_indexes)
    {
        cout<<v<<endl;
    }
    cout<<"\t\t**************************************************"<<endl;

}

void Index1::supprimefichierdelindex(string cheminFile) //supprime la case du vecteur stat dont le fichier est ce lui qu'on veut supprimer, si la taille du vecteur est null on supprime le mot
                                                        //et supprimer le fichier de l'ensemble des fichiers indexes
{
    Stat s;
    s.set_cheminFile(cheminFile);
    s.set_mot("aaa");                //test d'egalite se fait seulemant sur le chemin de la stat
    s.set_statMot(0);
    for(auto& m:ind1)
    {
        auto f=find(m.second.begin(),m.second.end(),s);
        if(f!=m.second.end())
        {
            fichiers_indexes.erase(cheminFile);
            (m.second).erase(std::remove((m.second).begin(), (m.second).end(), s), (m.second).end());        }
    }
     for(auto& m:ind1)
     {
         if(m.second.size()==0)
         {
             ind1.erase(m.first);
         }
     }
    cout<<"Fichier supprime de l'index"<<endl;


}

void Index1::sauvgarderindex()const
{
    ofstream stream("Index1.txt");
    for(auto& m:ind1)
    {
        stream<<m.first<<"|";
        for(auto itr=m.second.begin();itr!=m.second.end()-1;itr++ )
        {
            stream<<itr->get_cheminFile()<<"`"<<to_string(itr->get_statMot())<<"|";
        }
        stream<<(m.second.end()-1)->get_cheminFile()<<"`"<<to_string((m.second.end()-1)->get_statMot())<<"?\n";
    }
    stream.close();
    cout<<"Index sauvgarde"<<endl;

}

void Index1::restaurerindex()
{
    vector<Stat> vs;
    string line,mot,file,stat;
    int i;
    Stat s;
    ifstream stream1("Index1.txt");
    while(getline(stream1,line))
    {
        mot="";
        i=0;
        while(line[i]!='|')
        {
            mot+=line[i];
            i++;
        }
        s.set_mot(mot);
        i++;
        while(line[i]!='?')
        {
            file="";
            while(line[i]!='`')
            {
                file+=line[i];
                i++;
            }
            i++;
            s.set_cheminFile(file);
            stat="";
            while((line[i]!='|')&&(line[i]!='?'))
            {
                stat+=line[i];
                i++;
            }
            s.set_statMot(stod(stat));
            if(line[i]=='?')
            {
                vs.push_back(s);
                break;
            }
            else
            {
                vs.push_back(s);
                i++;
            }
        }
        ind1.insert(pair <string,vector<Stat> >(mot,vs) );
        vs.clear();
    }
    stream1.close();
    cout<<"Index restaure"<<endl;

}

void Index1::restaurerfichiersindexes()
{
    string line;
    ifstream stream1("fichiers_indexes1.txt");
    while(getline(stream1,line))
    {
        fichiers_indexes.insert(line);
    }
    stream1.close();
    cout<<"Fichiers indexes restaures"<<endl;
}

void Index1::sauvgarderfichiersindexes()const
{
    ofstream stream("fichiers_indexes1.txt");
    for(auto const& v:fichiers_indexes)
    {
        stream<<v<<endl;
    }
    stream.close();
    cout<<"Fichiers indexes sauvgarde"<<endl;

}

map<string,vector<Stat> > Index1::get_ind()const
{
    return ind1;
}

map<string,vector<Stat> > Index1::rechercheind(vector<string> vects)const
{
    map<string,vector<Stat> > result;
    for (auto& m : ind1)
    {
        auto itr=find(vects.begin(),vects.end(),m.first);
        if(itr!=vects.end())
        {
            result.insert({m.first,m.second});
        }
    }
    return result;
}
















