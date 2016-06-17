#include <vector>
#include <iostream>
#include <string>
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <queue>

using namespace std;

class GNodo
{
    public:
    string nombre;
    int color=0,d=0,f=0;
    string pi;
    int time=0;

    GNodo(string nom)
    {
        nombre=nom;
    }
};

class Arista
{
    public:
    GNodo * ini;
    GNodo * fin;

    Arista(GNodo * i,GNodo *f)
    {
        ini=i;
        fin=f;
    }
};

class Grafo
{
    public:
    vector<GNodo * > nodos;
    vector<Arista> aristas;
    queue<string> cola;

    void CreoNodos(string nom)
    {
        GNodo* nuevo=new GNodo(nom);
        nodos.push_back(nuevo);
    }
    void CreoAristas(string n1, string n2)
    {
        for(int i=0;i<nodos.size();i++)
        {
            if(nodos[i]->nombre==n1)
                for(int j=0;j<nodos.size();j++)
                    if(nodos[j]->nombre==n2)
                    {
                        Arista p(nodos[i],nodos[j]);
                        aristas.push_back(p);
                    }
        }
    }
    void deleteNodo(string a)
    {
        for(int i=0;i<nodos.size();i++)
            if(nodos[i]->nombre==a)
                nodos.erase(nodos.begin()+i);
    }

    void showGrafo()
    {
        for(int i=0;i<aristas.size();i++)
        {
            cout<<aristas[i].ini->nombre<<"->"<<aristas[i].fin->nombre<<endl;
        }
    }
    int busca(string a)
    {
        for(int i=0;i<nodos.size();i++)
            if(nodos[i]->nombre==a)
                return i;
    }

    void bfs(string s)
    {
        int i;
        for(i=0;i<nodos.size();i++)
            if(nodos[i]->nombre==s)
            {
                nodos[i]->color=1;// es gris
                nodos[i]->d=0;
                nodos[i]->pi="nil";
            }
        cola.push(s);
        while(!cola.empty())
        {
            string u=cola.front();
            cola.pop();
            int iter=busca(u);
            for(int j=0;j<aristas.size();j++)
            {
                if(aristas[j].ini->nombre==u)
                {
                    if(aristas[j].fin->color==0)//es blanco
                    {
                        aristas[j].fin->color=1;
                        aristas[j].fin->d=nodos[iter]->d+1;
                        aristas[j].fin->pi=u;
                        cola.push(aristas[j].fin->nombre);
                    }
                }

            }
            nodos[iter]->color=2;//negro
            cout<<nodos[iter]->nombre<<" es negro"<<endl;
        }
    }
    void dfs(string s)
    {
        int i,j;
        for(i=0;i<nodos.size();i++)
            if(nodos[i]->nombre==s)
                nodos[i]->color=0;

        nodos[i]->time=0;

        for(j=0;j<aristas.size();j++)
        {
            if(aristas[j].ini->nombre==s)
            {
                if(aristas[j].fin->color==0)//es blanco
                {
                    dfs_visit(s);
                }
            }

        }

    }

    void dfs_visit(string s)
    {
        int j,i;
        for(i=0;i<nodos.size();i++)
            if(nodos[i]->nombre==s)
            {
                nodos[i]->time+=1;
                nodos[i]->d=nodos[i]->time;
                nodos[i]->color=1;
            }
        for(j=0;j<aristas.size();j++)
        {
            if(aristas[j].ini->nombre==s)
            {
                if(aristas[j].fin->color==0)//es blanco
                {
                    aristas[j].fin->color=1;
                    aristas[j].fin->pi=s;
                    dfs_visit(aristas[j].fin->nombre);
                }
            }

        }
        nodos[i]->color=2;
        cout<<nodos[i]->nombre<<" es negro"<<endl;
        nodos[i]->time+=1;
        nodos[i]->f=nodos[i]->time;

    }

};


int main()
{
    Grafo v;
    v.CreoNodos("A");
    v.CreoNodos("B");
    v.CreoNodos("C");
    v.CreoNodos("D");

    v.CreoAristas("A","B");
    v.CreoAristas("A","C");
    v.CreoAristas("C","B");
    v.CreoAristas("B","D");
    v.CreoAristas("D","C");

    v.showGrafo();
    v.bfs("A");
    //v.dfs("A");

    return 0;
}
