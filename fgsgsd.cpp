#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct nod
    {
        int util;
        nod *urm;
    };
nod* vf;
nod* vf2;
nod* vf3;


void adaug(nod* &vf,int x)
{
    nod* p;
    p=new nod;//aloc memorie noului elem
    p->util=x;//completez informatie utila
    if(vf)
    {
        p->urm=vf;
        vf=p;
    }
    else
    {
        p->urm=NULL;
        vf=p;
    }
}

void afisare(nod *vf)
{
    nod* p;
    p=vf;
    if(p!=NULL)
    while(p)
    {
        cout<<p->util<<" ";
        p=p->urm;
    }
    else cout<<"Stiva vida!!"<<endl;
}
void sterg(nod*&vf)
{
    nod *q;
    if(vf)
    {
        q=vf;
        vf=vf->urm;
        delete q;
    }
    else cout<<"\nStiva vida!";
}
void imps(nod* &vf, nod* &vf2, nod* &vf3)
{
    nod* p;
    p=vf;
    while(p)
    {
        if(p->util%2==0)
        {
            adaug(vf2,p->util);
        }
        else adaug(vf3,p->util);
        p=p->urm;
        sterg(vf);
    }
}

int main()
{
    int x;
    vf=NULL;vf2=NULL;vf3=NULL;
    ifstream f("numere.in");
    while(f>>x)adaug(vf,x);
    cout<< "Stiva initiala: "<<endl;
    afisare(vf);
    cout<<endl;
    imps(vf,vf2,vf3);
    cout<<"A doua stiva: "<<endl;
    afisare(vf2);
    cout<<endl;
    cout<<"A treia stiva: "<<endl;
    afisare(vf3);
    cout<<endl;
    cout<<"Stiva intiala dupa modificari: "<<endl;
    afisare(vf);

    return 0;
}
