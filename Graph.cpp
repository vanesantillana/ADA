#include <vector>
#include <iostream>
#include <string>

using namespace std;

class GNodo
{
    public:

        string nombre;

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
    int peso=0;
    Arista(GNodo * i,GNodo *f,int p)
    {
        ini=i;
        fin=f;
        peso=p;
    }
};

class Grafo
{
    public:
    vector<GNodo * > nodos;
    vector<Arista> aristas;

    void CreoNodos(string nom)
    {
        GNodo* nuevo=new GNodo(nom);
        nodos.push_back(nuevo);
    }
    void CreoAristas(string n1, string n2,int peso)
    {
        for(int i=0;i<nodos.size();i++)
        {
            if(nodos[i]->nombre==n1)
                for(int j=0;j<nodos.size();j++)
                    if(nodos[j]->nombre==n2)
                    {
                        Arista p(nodos[i],nodos[j],peso);
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
};


int main()
{
    Grafo v;
    v.CreoNodos("A");
    v.CreoNodos("B");
    v.CreoNodos("C");
    v.CreoNodos("D");

    v.CreoAristas("A","B",2);
    v.CreoAristas("A","C",3);
    v.CreoAristas("C","B",4);
    v.CreoAristas("B","D",9);
    v.CreoAristas("D","C",5);

    v.showGrafo();

    return 0;
}
