#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
int max(int a, int b) {return (a>b)? a:b;}

int MemoizedCutRod_Aux(int *p, int n,int *r)
{
    if(r[n-1] > 0)
        return r[n-1];
    if(n == 1)
        return p[0];

    int q=INT_MIN;
    for(int i=1; i<n; i++)
    {
        int c=max(p[n-1],p[i-1]+MemoizedCutRod_Aux(p,n-i,r));
        q=max(q,c);
    }
    r[n-1]=q;
  return q;
}

int MemoizedCutRod(int *p,int n)
{
    int r[n];
    for(int i=0; i<n; i++)
        r[i]=INT_MIN;
    return MemoizedCutRod_Aux(p,n,r);
}

int BottomUpCutRod(int *p,int n)
{
    int r[n+1];
    r[0]=0;

    for(int j=1; j<=n; j++)
    {
        int q=INT_MIN;
        for(int i=0; i<j; i++)
            q=max(q,p[i]+r[j-i-1]);
        r[j]=q;
    }
    return r[n];
}

int main()
{
    int a[]={1,5,8,9,10,17,17,20};
    cout<<BottomUpCutRod(a,8)<<endl;
    cout<<MemoizedCutRod(a,8);
    return 0;
}
