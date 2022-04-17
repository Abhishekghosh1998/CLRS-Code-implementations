#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 1000

vector<unordered_set<int>> adj(MAX);
int color[MAX];
int pred[MAX];
int d[MAX];

void BFS(int s, int n)
{
	int v;
	for(v=1;v<=n;v++)
	{
		color[v]=WHITE;
		pred[v]=0;
		d[v]=INT_MAX;
	}
	queue<int> q;
	q.push(s);
	color[s]=GRAY;
	d[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<u<<" : "<<d[u]<<endl;
		for(int v: adj[u])
			if(color[v]==WHITE)
			{
				pred[v]=u;
				d[v]=d[u]+1;
				color[v]=GRAY;
				q.push(v);
			}
		color[u]=BLACK;
	} 	
}

void printPath(int v,int s)
{	
	if(v==s)
		cout<<s;
	else if (pred[v]==0)
		cout<<"Path does not exist"<<endl;
	else{
		printPath(pred[v],s);
		cout<<"->"<<v; 
	}
}
int main()
{
	int n;
	cout<<"Enter the number of vertices : "<<endl;
	cin>>n;
	int e;
	cout<<"Enter the number of edges in the graph : ";
	cin>>e;
	int i;
	for(i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	BFS(1,n);
	while(1)
	{
		cout<<"Enter a vertex to find shortest path from source to it (0 to end) : ";
		int v;
		cin>>v;
		if(!v) break;
		printPath(v,1);
		cout<<endl<<endl;	
	}
}
