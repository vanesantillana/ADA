#include <iostream>

using namespace std;

int caso_base=10;

class max_subarray
{
    unsigned left,right;
    int sum;
};

max_subarray find_max_crossing_subarray(int *A,int l,int m,int h)
{
    max_subarray result={-1,-1,0};
    int sum=0;
    int left_sum=INT_MIN;

    for(int i=m; i>=l; i--)
    {
        sum+=A[i];
        if(sum>left_sum)
            left_sum=sum;result.left=i;
    }
    sum=0;
    int right_sum=INT_MIN;

    for (int i=m+1; i<=h; i++)
    {
        sum+=A[i];
        if (sum>right_sum)
            right_sum=sum;result.right=i;
    }
    result.sum=left_sum + right_sum;
    return result;
}

max_subarray find_max_subarray(int *A,int l,int h)
{
    if (l+1==h)max_subarray result={l,h,A[l]}
        return result;

    int m=(l+h)/2;
    
    max_subarray left_Sum=find_max_subarray(A,l,m);
    max_subarray right_Sum=find_max_subarray(A,m+1,h);
    max_subarray cross_Sum=find_max_crossing(A,l,m,h);

    if (left_Sum >= right_Sum && left_Sum >= cross_Sum)
        return left_Sum;

    else if (right_Sum >= left_Sum && right_Sum >= cross_Sum)
        return right_Sum;

    else
        return cross_Sum;
}

max_subarray find_maximum_subarray_brute(int *A, unsigned low, unsigned high)
{
    max_subarray result={0, 0,INT_MIN};

    for(int i=low; i<high; i++)
    {
        int suma=0;
        for(int j=i; j<high; j++)
        {
            suma+=A[j];
            if(result.sum<suma)
            {
                result.left=i;
                result.right=j + 1;
                result.sum=suma;
            }
        }
    }

    return result;
}

max_subarray find_maximum_subarray_mixed(int A[], unsigned low, unsigned high)
{
    if (high-low<caso_base)
        return find_maximum_subarray_brute(A,low,high);
    else
    {
        mid=(low+high)/2;
        max_subarray left=find_maximum_subarray_mixed(A,low,mid);
        max_subarray right=find_maximum_subarray_mixed(A,mid,high);
        max_subarray cross=find_max_crossing_subarray(A,low,mid,high);

        if(left.sum>=right.sum && left.sum>=cross.sum)
            return left;
        else if (right.sum>=left.sum && right.sum>=cross.sum)
            return right;
        else
            return cross;
    }
}
