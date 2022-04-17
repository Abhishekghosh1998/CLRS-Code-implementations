#include<bits/stdc++.h>
using namespace std;
int heapSize;

void Heapify(vector<int> &A, int i)
{
	int left=2*i;
	int right=2*i+1;
	int index=i;
	if(left<=heapSize && A[left]>A[i])
		index=left;
	if(right<=heapSize && A[right]>A[index])
		index=right;
	if(index!=i)
	{
		int temp=A[i];
		A[i]=A[index];
		A[index]=temp;
		Heapify(A,index);
	}
}

int extractMax(vector<int>&A)
{
	int data=A[1];
	A[1]=A[heapSize];
	heapSize--;
	Heapify(A,1);
	return data;
}

void buildHeap(vector<int>&A)
{
	int i;
	for(i=heapSize/2;i>=1;i--)
		Heapify(A,i);
}
void HeapSort(vector<int>&A, int n)
{
	heapSize=n;
	buildHeap(A);
	int i;
	for(i=n;i>=2;i--)
		A[i]=extractMax(A);
		
}

int main()
{
	int n;
	cout<<" N ? ";
	cin>>n;
	vector<int> A(n+1);
	int i;
	cout<<"ENTER ELEMENTS INTO THE ARRAY : "<<endl;
	for(i=1;i<=n;i++)
		 cin>>A[i];
	HeapSort(A,n);
	cout<<"ARRAY AFTER HEAP SORT : "<<endl;
	for(i=1;i<=n;i++)
		 cout<<A[i]<<" ";
	cout<<endl;
}
