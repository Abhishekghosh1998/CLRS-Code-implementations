#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<pair<int,int>>> adj(MAX);

vector<vector<int>> edgeList;


int handle[MAX];

long long int d[MAX];

struct node{
	long long int d;
	int vertex;
};

typedef struct node Node;

Node A[MAX];

int heapSize=0;

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
		swap(i,index);
		Heapify(index);
	}
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
	while(p>=1 && A[p].d>A[i].d)
	{	
		swap(i,p);
		i=p;
		p=p/2;
	}
}

int extractMin()
{
	swap(1,heapSize);
	heapSize--;
	Heapify(1);
	return A[heapSize+1].vertex;
}

void dijkstra(int s, int n, vector<int> &dist)
{
	int v;
	heapSize=n;
	for(v=1;v<=n;v++)
	{
		A[v].d=INT_MAX;
		A[v].vertex=v;
		handle[v]=v;
	}
	decreaseKey(handle[s],0);
	while(heapSize)
	{
		int u=extractMin();
		dist[u]=A[handle[u]].d-(d[s]-d[u]);
		for(auto e: adj[u])
		{	
			int v,w;
			v=e.first;
			w=e.second;
			if(A[handle[u]].d+w<A[handle[v]].d)
				decreaseKey(handle[v],A[handle[u]].d+w);
		}
	}
}

void BellmanFord(int s, int n)
{
	int v;
	for(v=1;v<=n-1;v++)
		d[v]=INT_MAX;
	d[s]=0;	
	int i;
	for(i=1;i<n;i++)
		for(auto e: edgeList)
		{
			int u=e[0];
			int v=e[1];
			int w=e[2];
			
			if(d[v]>d[u]+w)
				d[v]=d[u]+w;
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
		int u,v,w;
		cin>>u>>v>>w;
		vector<int>temp;
		temp.push_back(u);
		temp.push_back(v);
		temp.push_back(w);
		edgeList.push_back(temp);
	}
	for(i=1;i<=n;i++)
		edgeList.push_back({0,i,0});
	BellmanFord(0,n+1);
	for (auto e: edgeList)
	{
		int u=e[0];
		int v=e[1];
		int w=e[2];
		if(!u)
			continue;
		adj[u].push_back({v,w+d[u]-d[v]});
	}
	
	vector<vector<int>> M(n+1, vector<int> (n+1));
	
	for(i=1;i<=n;i++)
		dijkstra(i,n,M[i]);
	
	cout<<"The shortest path distances are as follows : "<<endl;
	
	int j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<M[i][j]<<"\t";
		cout<<endl;
	}
}
