#include <iostream>
#include "vector"
#include "string"
using namespace std;

int A[11]={1,2,3,4,5,6,7,8,9,10,11};
vector<int> act;

int RActivitySelector(int *s,int *f,int k,int n)
{
    int m=k;
    while(m<n && s[m]<f[k])
        m++;
    if(m<n)
    {
        act.push_back(A[m]);
        act.push_back(RActivitySelector(s,f,m,n));
        return 1;
    }
    else return 0;
}

vector<int> GreedyActivitySelector(int *s,int *f,int n)
{
    vector<int> acti;
    acti.push_back(A[0]);
    int k=0;
    for(int m=1; m<n; m++)
    {
        if(s[m]>=f[k])
        {
            acti.push_back(A[m]);
            k=m;
        }
    }
    return acti;
}
void imprime(vector<int> n)
{
    for(int i=0; i<n.size();i++)
        cout<<n[i]<<" ";
}
int main()
{
    int s[11]={1,3,0,5,3,5,6,8,8,2,12};
    int f[11]={3,5,6,7,9,9,10,11,12,14,16};
    act.push_back(A[0]);

    RActivitySelector(s,f,0,11);
    imprime(act);
    cout<<endl;
    vector<int> result=GreedyActivitySelector(s,f,11);
    imprime(result);
    return 0;
}
