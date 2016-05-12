#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void lis(vector<int>& d)
{
    vector< vector<int> > l(d.size());
    l[0].push_back(d[0]);
    for(int i=1; i<d.size();i++)
    {
        for(int j=0; j<i; j++)
        {
            if((d[j]<d[i]) && (l[i].size() < l[j].size()+1))
                l[i]=l[j];
        }
        l[i].push_back(d[i]);
    }
    for(int x=0; x<l.size();x++)
    {
        for(int y=0;y<l[x].size();y++)
            cout<<l[x][y]<<" ";
        cout<<endl;
    }
}

int main()
{
    int arr1[] = {3,2,6,4,5,1};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(*arr1));
    lis(vec1);
    
    return 0;
}

