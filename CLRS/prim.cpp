#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
int handle[MAX];
int pred[MAX];

struct node{
	int d;
	int vertex;
	};

typedef struct node Node;

Node A[MAX];
int heapSize=0;

vector<vector<pair<int,int>>> adj(MAX);

void Heapify(int i)
{
	int left=2*i;
	int right=2*i+1;
	int index=i;
	if(left<=heapSize && A[left].d<A[i].d)
		index=left;
	if(right<=heapSize && A[right].d<A[index].d)
		index=right;
	if(index!=i)
	{
		Node temp=A[index];
		A[index]=A[i];
		A[i]=temp;
		
		handle[A[index].vertex]=index;
		handle[A[i].vertex]=i;
		Heapify(index);
	}
}

int extractMin()
{
	Node temp=A[1];
	A[1]=A[heapSize];
	A[heapSize]=temp;
	handle[A[1].vertex]=1;
	handle[A[heapSize].vertex]=heapSize;
	heapSize--;
	Heapify(1);
	return A[heapSize+1].vertex;
}

void decreaseKey(int i, int key)
{
	if(A[i].d<=key)
	{
		cout<<"Error"<<endl;
		return;
	}
	A[i].d=key;
	int p=i/2;
	while(p>=1 && A[p].d > A[i].d)
	{
		Node temp=A[p];
		A[p]=A[i];
		A[i]=temp;
		handle[A[p].vertex]=p;
		handle[A[i].vertex]=i;
		i=p;
		p=p/2;
	}
}
int present(int v)
{
	return (handle[v]<=heapSize);
}
void prim(int s, int n)
{
	int v;
	heapSize=n;
	for(v=1;v<=n;v++)
	{
		A[v].d=INT_MAX;
		A[v].vertex=v;
		handle[v]=v;
		pred[v]=0;
	}
	decreaseKey(handle[s], 0);
	vector<pair<int,int>> T;
	int total=0;
	while(heapSize)
	{
		int u=extractMin();
		if(u!=s){
			total+=A[handle[u]].d;
			T.push_back({pred[u],u});
		}
		for(auto e: adj[u])
		{
			int v=e.first;
			int w=e.second;
			if(w<A[handle[v]].d && present(v))
			{
				decreaseKey(handle[v],w);
				pred[v]=u;
			}
		}
	}
	
	cout<<"The total cost : "<<total<<endl;
	
	cout<<"The MST : "<<endl;
	
	for(auto p: T)
		cout<<"{"<<p.first<<","<<p.second<<"}"<<endl;
	
	
}

int main()
{
	int n;
	cout<<"Enter the number vertices : ";
	cin>>n;
	int e;
	cout<<"Enter the number of edges : ";
	cin>>e;
	cout<<"Enter the edge and its weight"<<endl;
	int i;
	for(i=1;i<=e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	prim(1,n);
}
