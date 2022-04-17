#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<unordered_set<int>> adj(MAX);

int color[MAX];
int d[MAX];
int f[MAX];
int pred[MAX];
int Time =0;
stack<int> s;
void dfsVisit(int u)
{
	d[u]=Time++;
	color[u]=GRAY;
	for(int v : adj[u])
		if(color[v]==WHITE)
		{
			pred[v]=u;
			dfsVisit(v);
		}
	f[u]=Time++;
	color[u]=BLACK;
	s.push(u);
}
void dfs(int n)
{
	int v;
	for(v=1;v<=n;v++)
	{
		color[v]=WHITE;
		pred[v]=0;
	}
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
	cout<<"Enter the number of edges : ";
	cin>>e;
	int i;
	cout<<"In the next "<<e<<" lines, enter the edges as pair of vertices ";
	for(i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].insert(y);
	}
	dfs(n);
	cout<<"The topological sorting is as follows : ";
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
