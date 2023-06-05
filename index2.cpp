#include"index2.h"
#include"stat.h"
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<map>
#include<string>
#include<set>

void Index2::indexer(vector < Stat > vec)
{
    vector<Stat>::iterator itr1;
    fichiers_indexes.insert(vec.begin()->get_cheminFile());
    for(vector<Stat>::iterator itr= vec.begin();itr!=vec.end();itr++)   //parcour du vec (vector stat)
    {
        itr1=find(ind2.begin(),ind2.end(),*itr);                        //recheche du chemin du fichier dans l'index
        if((itr1!=ind2.end())&&(itr1->get_mot()==itr->get_mot()))
        {
            itr1->set_statMot(itr->get_statMot());
        }
        else
        {
            ind2.push_back(*itr);
        }


    }
}

void Index2::affichierindex()const
{

    cout<<"\t\t***********Index du moteur de recherche***********"<<endl;
    for(auto& s:ind2)
    {
        //cout<<"Mot :"<<s.get_mot()<<"\tFichier :"<<s.get_cheminFile()<<"\tStat :"<<s.get_statMot()<<endl;
        cout<<s.get_mot()<<"\t"<<s.get_cheminFile()<<"\t"<<s.get_statMot()<<endl;
    }
    cout<<"\t\t**************************************************"<<endl;

}

void Index2::affichierfichiersindexes()const
{
    cout<<"\t\t***********Fichiers indexes du moteur de recherche***********"<<endl;
    for(auto& v:fichiers_indexes)
    {
        cout<<v<<endl;
    }
    cout<<"\t\t**************************************************"<<endl;
}

void Index2::supprimefichierdelindex(string cheminFile)
{
    Stat s;
    s.set_cheminFile(cheminFile);
    s.set_mot("aaa");                //test d'egalite se fait seulemant sur le chemin de la stat
    s.set_statMot(0);
    auto f=find(ind2.begin(),ind2.end(),s);
    if(f!=ind2.end())
    {
        fichiers_indexes.erase(cheminFile);
        ind2.erase(std::remove(ind2.begin(),ind2.end(), s),ind2.end());
    }
    cout<<"Fichier supprime de l'index"<<endl;
}

void Index2::sauvgarderindex()const
{
    ofstream stream("Index2.txt");
    for(auto itr=ind2.begin();itr!=ind2.end();itr++ )
    {
        stream<<itr->get_mot()<<"|"<<itr->get_cheminFile()<<"|"<<to_string(itr->get_statMot())<<"|\n";
    }
    stream.close();
    cout<<"Index sauvgarde"<<endl;
}

void Index2::restaurerindex()
{
    string line,mot,file,stat;
    int i;
    Stat s;
    ifstream stream1("Index2.txt");
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
        file="";
        while(line[i]!='|')
        {
            file+=line[i];
            i++;
        }
        s.set_cheminFile(file);
        i++;
        stat="";
        while((line[i]!='|'))
        {
            stat+=line[i];
            i++;
        }
        s.set_statMot(stod(stat));
        ind2.push_back(s);
    }
    stream1.close();
    cout<<"Index restaure"<<endl;
}

void Index2::restaurerfichiersindexes()
{
    string line;
    ifstream stream1("fichiers_indexes2.txt");
    while(getline(stream1,line))
    {
        fichiers_indexes.insert(line);
    }
    stream1.close();
    cout<<"Fichiers indexes restaures"<<endl;
}

void Index2::sauvgarderfichiersindexes()const
{
    ofstream stream("fichiers_indexes2.txt");
    for(auto& v:fichiers_indexes)
    {
        stream<<v<<endl;
    }
    stream.close();
    cout<<"Fichiers indexes sauvgarde"<<endl;
}

vector<Stat> Index2::get_ind()const
{
    return ind2;
}

map<string,vector<Stat> > Index2::rechercheind(vector<string> vects)const
{
    map<string,vector<Stat> > result;
    for (auto& m : ind2)
    {
        auto itr=find(vects.begin(),vects.end(),m.get_mot());
        if(itr!=vects.end())
        {
            Stat s;
            s.set_cheminFile(m.get_cheminFile());
            s.set_mot(m.get_mot());
            s.set_statMot(m.get_statMot());
            vector<Stat> tmp;
            tmp.push_back(s);
            result.insert({m.get_mot(),tmp});
        }
    }
    return result;
}
















