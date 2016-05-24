#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <time.h>
using namespace std;
int max(int a, int b) {return (a>b)? a:b;}

int CutRod(int *p,int n)
{
    if(n<=0) return 0;
    int q=INT_MIN;

    for(int i=0; i<n ; i++)
        q=max(q,p[i]+CutRod(p,n-(i+1)));
    return q;
}


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
    int a[]={1,2,3,5,8,9,10,11,12,13,17,17,20,45,3,5,8,9,10,11,12,13,17,24,34,38,40,2,42,47,48};
    int n=20;
    clock_t start = clock();
    CutRod(a,n);
    printf("Tiempo transcurrido: %f",((double)clock() - start)/CLOCKS_PER_SEC);
    cout<<"\nResultado CutRod: "<<CutRod(a,n)<<endl;

    clock_t start1 = clock();
    MemoizedCutRod(a,n);
    printf("Tiempo transcurrido: %f",((double)clock() - start1)/CLOCKS_PER_SEC);
    cout<<"\nResultado Memoized: "<<MemoizedCutRod(a,n)<<endl;
    
    clock_t start2 = clock();
    BottomUpCutRod(a,n);
    printf("Tiempo transcurrido: %f",((double)clock() - start2)/CLOCKS_PER_SEC);
    
    cout<<"\nResultado Bottom: "<<BottomUpCutRod(a,n)<<endl;
    return 0;
}
