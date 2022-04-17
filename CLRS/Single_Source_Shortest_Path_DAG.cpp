#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<pair<int,int>> adj[MAX];

stack <int> stk;

long long int d[MAX];
int pred[MAX];
int color[MAX];

void dfsVisit(int u)
{
	color[u]=GRAY;
	for(auto e: adj[u])
	{
		int v=e.first;
		if(color[v]==WHITE)
			dfsVisit(v);
	}
	color[u]=BLACK;
	stk.push(u);
}

void dfs(int n)
{
	int v;
	for(v=1;v<=n;v++)
		color[v]=WHITE;
		
	for(v=1;v<=n;v++)
		if(color[v]==WHITE)
			dfsVisit(v);	
}

void display(int v, int s)
{
	if(v==s)
		cout<<s;
	else if(pred[v]==0)
		cout<<"Path does not exist !!!";
	else{
		display(pred[v],s);
		cout<<"->"<<v;	
	}
}

void calculate(int s,int n)
{
	dfs(n);
	int v;
	for(v=1;v<=n;v++)
		d[v]=INT_MAX;
	d[s]=0;
	while(!stk.empty())
	{	
		int u=stk.top();
		stk.pop();
		for(auto e: adj[u])
		{
			int v=e.first;
			int w=e.second;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				pred[v]=u;
			}
		}
			
	}
	for(v=1;v<=n;v++)
	{
		cout<<"d["<<v<<"] : "<<d[v]<<" Path : ";
		display(v,s);
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter the number of edges : ";
	int e;
	cin>>e;
	int i;
	cout<<"Enter the edges as pair of vertices, space separated and weight"<<endl;
	for(i=1;i<=e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
	}
	calculate(1,n);	
}
