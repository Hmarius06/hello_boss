#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct nod
{
    int nr;
    nod* urm;
};
nod *cap;
nod *ultim;

void adaug_prim(nod* &cap, nod* &ultim, int x)
{
    nod* p;
    p= new nod;
    p->nr=x;
    p->urm=NULL;
    cap=ultim=p;

}



void afisare(nod* cap)
{
    nod* p;
    for(p=cap;p!=NULL;p=p->urm)
    {
        cout<<p->nr<<" ";
    }
    cout<<endl;
}

void adaug_d_ultim(nod* &ultim,int x)
{
    nod* p;
    p=new nod;
    p->nr=x;
    p->urm=NULL;
    ultim->urm=p;
    ultim=p;
}
void creare_lista()
{
    int nr;
    ifstream f("numere.in");
    f>>nr;
    adaug_prim(cap,ultim,nr);
    while(f>>nr) adaug_d_ultim(ultim,nr);
}
