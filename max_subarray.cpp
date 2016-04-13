#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int max_left=0,max_right=0;

int find_max_crossing(int *A,int l,int m,int h)
{
    int sum=0;
    int left_sum=INT_MIN;

    for(int i=m; i>=l; i--)
    {
        sum+=A[i];
        if(sum>left_sum)
            left_sum=sum;max_left=i;
    }
    sum=0;
    int right_sum=INT_MIN;

    for (int i=m+1; i<=h; i++)
    {
        sum+=A[i];
        if (sum>right_sum)
            right_sum=sum;max_right=i;
    }

    return left_sum + right_sum;
}

int find_max_subarray(int *A,int l,int h)
{
    if (l==h)
        return A[l];

    int m=(l+h)/2;
    int left_Sum = 0, right_Sum = 0, cross_Sum = 0;

    left_Sum=find_max_subarray(A,l,m);
    right_Sum=find_max_subarray(A,m+1,h);
    cross_Sum=find_max_crossing(A,l,m,h);

    if (left_Sum >= right_Sum && left_Sum >= cross_Sum)
        return left_Sum;

    else if (right_Sum >= left_Sum && right_Sum >= cross_Sum)
        return right_Sum;

    else
        return cross_Sum;
}

int main()
{
   int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

   int n=sizeof(a)/sizeof(a[0]);

   cout<<"El maximo del array es: "<<find_max_subarray(a,0,n-1)<<endl;

   return 0;
}
