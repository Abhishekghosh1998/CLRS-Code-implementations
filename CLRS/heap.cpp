#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int heapSize=0;

vector<int> A(MAX+1);

void Heapify(int i)
{
	int left=2*i;
	int right=2*i+1;
	int index=i;
	if(left<=heapSize && A[left]<A[i])
		index=left;
	if(right<=heapSize && A[right]<A[index])
		index=right;
	if(index!=i)
	{
		int temp=A[i];
		A[i]=A[index];
		A[index]=temp;
		Heapify(index);
	}
}

int ExtractMin()
{
	int data=A[1];
	A[1]=A[heapSize];
	heapSize--;
	Heapify(1);
	return data;
}

void DecreaseKey(int i, int key)
{
	if(A[i]<key)
	{
		cout<<"ERROR: ATTEMPT TO INCREASE KEY INSTEAD OF DECREASE"<<endl;	
		return;
	}
	A[i]=key;
	int parent=i/2;
	while(parent>=1 && A[parent]>A[i])
	{
		int temp=A[parent];
		A[parent]=A[i];
		A[i]=temp;
		i=parent;
		parent=i/2;
	}	
}

void InsertKey(int key)
{
	A[++heapSize]=INT_MAX;
	DecreaseKey(heapSize, key);	
}

void BuildHeap()
{
	int i;
	for(i=heapSize/2;i>=1;i--)
		Heapify(i);
}

int main()
{
	int n;
	cin>>n;
	cout<<"ENTER THE ELEMENTS INTO ARRAY : "<<endl;
	int i;
	for(i=1;i<=n;i++)
		cin>>A[i];
	heapSize=n;
	BuildHeap();
	cout<<"LEVEL ORDER TRAVERSAL OF THE MIN HEAP : "<<endl;
	for(i=1;i<=heapSize;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	while(1)
	{
		int ch;
		cout<<"1. InsertKey "<<endl;
		cout<<"2. DecreaseKey "<<endl;
		cout<<"3. ExtractMin "<<endl;
		cout<<"4. Level Order Traversal "<<endl;
		cout<<"ENTER YOUR CHOICE : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: {
				cout<< "ENTER THE KEY TO INSERT : ";
				int x;
				cin>>x;
				InsertKey(x);
				break;
			}
			case 2:{
				 cout<< "ENTER THE INDEX OF KEY TO DECREASE : ";
				int index;
				cin>>index;
				cout<< "ENTER THE DECREASED KEY : ";
				int k;
				cin>>k;
				DecreaseKey(index,k);
				break;
			}
			case 3:{
				int data=ExtractMin();
				cout<<"EXTRACTED DATA : "<<data<<endl;
				break;
			}
			case 4:{
				cout<<"LEVEL ORDER TRAVERSAL OF THE MIN HEAP : "<<endl;
				for(i=1;i<=heapSize;i++)
					cout<<A[i]<<" ";
				cout<<endl;
				break;
			}
			default:cout<<"WRONG CHOICE"<<endl;
		}
	}
}
