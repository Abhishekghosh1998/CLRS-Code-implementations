#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1000

#define FORWARD 0
#define TREE 1
#define BACK 2
#define CROSS 3

string s[]={"Forward Edge", "Tree Edge", "Back Edge", "Cross Edge"};

vector<unordered_set<int>> adj(MAX);
map<pair<int,int>,int> edgeType;

int color[MAX];
int d[MAX];
int f[MAX];
int pred[MAX];
int Time=0;
void dfsVisit(int u)
{
	cout<<u<<" ";
	d[u]=Time++;
	color[u]=GRAY;
	for(int v: adj[u])
		if(color[v]==WHITE)
		{
			edgeType[{u,v}]=TREE;
			pred[v]=u;
			dfsVisit(v);
		}
		else if(color[v]==GRAY)
			edgeType[{u,v}]=BACK;
		else if(d[u]<d[v])
				edgeType[{u,v}]=FORWARD;
		else if (d[v]<d[u])
				edgeType[{u,v}]=CROSS;
				
	f[u]=Time++;
	color[u]=BLACK;		
}

void dfs(int n)
{
	int v;
	for(v=1;v<=n;v++)
	{
		color[v]=WHITE;
		pred[v]=0;
		
	}
	Time=1;
	for(v=1;v<=n;v++)
		if(color[v]==WHITE)
			dfsVisit(v);
}


int main()
{
	int n;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	int e;
	cout<<"Enter the number of edges in the graph : ";
	cin>>e;
	int i;
	for(i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].insert(y);//edges are directed
	}
	dfs(n);
	cout<<endl;
	cout<<"vertex\tdisc.\tfinish"<<endl;
	for(i=1;i<=n;i++)
		cout<<i<<"\t"<<d[i]<<"\t"<<f[i]<<endl;
	cout<<"Edge classifications : "<<endl;
	for(auto e: edgeType)
	{
		pair<int, int> p=e.first;
		cout<<"("<<p.first<<","<<p.second<<") : "<< s[e.second]<<endl;	
	}
	
}
