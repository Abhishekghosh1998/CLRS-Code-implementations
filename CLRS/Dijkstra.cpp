#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<pair<int,int>>> adj(MAX);

int handle[MAX];

struct node{
	long long int d;
	int vertex;
};

typedef struct node Node;

Node A[MAX];
int heapSize=0;

int d[MAX];
int pred[MAX];


void swap(int i, int j)
{
	Node temp=A[i];
	A[i]=A[j];
	A[j]=temp;
	handle[A[i].vertex]=i;
	handle[A[j].vertex]=j;
}

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
		swap(index,i);
		Heapify(index);
	}
}

int extractMin()
{
	swap(1,heapSize);
	heapSize--;
	return A[heapSize+1].vertex;	
}

void decreaseKey(int i, int key)
{
	if(A[i].d<key)
	{
		cout<<"Error! Attempt to increase key!"<<endl;
		return;
	}
	A[i].d=key;
	int p=i/2;
	while(p>=1 && A[p].d > A[i].d)
	{
		swap(p,i);
		i=p;
		p=p/2;
	}
}

void display(int v, int s)
{
	if(v==s)
		cout<<s;
	else if(pred[v]==0)
		cout<<"No path exist!"<<endl;
	else{
		display(pred[v],s);
		cout<<"->"<<v;
	}
}

void dijkstra(int s, int n)
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
	decreaseKey(handle[s],0);
	while(heapSize)
	{
		int u=extractMin();
		for(auto e: adj[u])
		{
			int v=e.first;
			int w=e.second;
			if(A[handle[v]].d>A[handle[u]].d+w)
			{
				decreaseKey(handle[v], A[handle[u]].d+w);
				pred[v]=u;
			}
		}
	}
	for(v=1;v<=n;v++)
	{
		cout<<"d["<<v<<"] : "<<A[handle[v]].d<<" Path : ";		
		display(v,s);
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	int e;
	cout<<"Enter the number of edges : ";
	cin>>e;
	int i;
	for(i=1;i<=e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
	}
	dijkstra(1,n);
}
