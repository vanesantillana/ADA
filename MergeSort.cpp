#include <iostream>

using namespace std;

int const infinito=10000;

void imprimir(int *b,int n)
{
    for(int u=0; u<n; u++)
        cout<<b[u]<<" ";
    cout<<endl;
}
void Merge(int *a,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int *L=new int[n1+1],
        *R=new int[n2+1];

    for(int i=0; i<n1 ; i++)
        L[i]=a[p+i];
    for(int j=0; j<n2 ; j++)
        R[j]=a[q+j+1];

    L[n1]=infinito;
    R[n2]=infinito;

    int i=0,
        j=0;
    int k;

    for(k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];i++;
        }
        else
        {
            a[k]=R[j];j++;
        }

    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}
void MergeSort(int *a,int p, int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
int main()
{
    int n=10;
    int a[]={5,2,4,7,1,3,6,20,14,0};
    MergeSort(a,0,n-1);
    cout<<"\nResultado:"<<endl;
    imprimir(a,n);

    return 0;
}
