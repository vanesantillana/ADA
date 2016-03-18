#include <iostream>

using namespace std;

int * insertsort(int a[],int n)
{
    for(int j=1;j<n;j++)
    {
        int key=a[j];
        int i=j-1;
        
        while(i>=0 and a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
    return a;
}
int main()
{
    int n=6;
    int a[]={31,3000,59,26,41,58};
    int *b=insertsort(a,n);

    for(int u=0; u<n; u++)
        cout<<b[u]<<" ";
    return 0;
}
