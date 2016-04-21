#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

class heap
{
public:
	vector<int> a;
	int heapsize;

    void max_heapify(int);
	void build_max_heap(vector<int>);

	void print(){
		for (int i=1;i<=heapsize;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
};

int left(int i){return i*2;}
int right(int i){return i*2+1;}
int parent(int i){return i/2;}

void heap::max_heapify(int i)
{
    int l=left(i);
    int r=right(i);
	int largest;

	if (l<=heapsize && a[l]>a[i])
		largest=l;
	else largest=i;

	if (r<=heapsize && a[r]>a[largest])
		largest=r;
	if (largest!= i) {
		swap(a[i],a[largest]);
		max_heapify(largest);
	}
}

void heap::build_max_heap(vector<int> b)
{
	a=b;
	a.insert(a.begin(),0);
	heapsize=a.size()-1;
	for(int i=heapsize/2; i>=1; i--)
		max_heapify(i);
}

vector<int> heapsort(vector<int> A)
{
	heap h;
	h.build_max_heap(A);
	vector<int> result;

	for(int i=h.heapsize; h.heapsize>0; i--) {
		result.push_back(h.a[1]);
		swap(h.a[1],h.a[h.heapsize]);
		h.heapsize-=1;
		h.max_heapify(1);
	}
	return result;
}

class priority_q {
public:
    heap h;

    int heap_maximum(){return h.a[1];}
    int heap_extract_Max();
    void heap_increase_Key(int, int);
    void max_heap_insert(int);
};

int priority_q::heap_extract_Max() {
    if (h.heapsize <= 0)
        return -1;

    int max_h = h.a[1];
    swap(h.a[1], h.a[h.heapsize]);
    h.heapsize-=1;
    h.max_heapify(1);

    return max_h;
}

void priority_q::heap_increase_Key(int i, int key) {

    if(key<h.a[i])
    h.a[i]=key;
    while(i>0 && h.a[parent(i)]<h.a[i]) {
        swap(h.a[i],h.a[parent(i)]);
        i=parent(i);
    }
}

void priority_q::max_heap_insert(int i) {
    h.heapsize+=1;
   // h.a.push_back(INT_MIN);
   // heap_increase_Key(h.a,h.heapsize,key);
    h.a.push_back(i);
    int j=h.heapsize;
    while(parent(j)>0 && h.a[parent(j)]<h.a[j])
    {
        swap(h.a[parent(j)],h.a[j]);
        j = parent(j);
    }
}

int main()
{
	int a[]={16,14,10,8,7,9,3,2,4,1};
	vector<int> A(a,a+sizeof(a)/sizeof(int));
	vector<int> resultado=heapsort(A);

    cout<<"Heap: ";
	for (int i=0;i<A.size();i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	cout<<"Resultado: ";
	for (int i=0;i<resultado.size();i++) {
		cout<<resultado[i]<<" ";
	}
	return 0;
}
