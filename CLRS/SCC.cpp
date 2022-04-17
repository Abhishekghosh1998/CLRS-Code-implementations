#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1000

stack <int> s;

void dfsVisit(vector<unordered_set<int>> &adj, int * color, int n, int u, vector<int> &temp)
{
	temp.push_back(u);
	color[u]=GRAY;
	for(int v: adj[u])
		if(color[v]==WHITE)
			dfsVisit(adj, color, n, v, temp);
	color[u]=BLACK;
	s.push(u);
}

void dfs(vector<unordered_set<int>> &adj,int * color,int n, stack<int> &s, vector<vector<int>> &lst)
{
	int v;
	for(v=1;v<=n;v++)
		color[v]=WHITE;
	while(!s.empty())
	{
		vector<int> temp;
		v=s.top();
		s.pop();
		if(color[v]==WHITE)
			dfsVisit(adj, color, n, v,temp);
		if(temp.size())
			lst.push_back(temp);
	}
}


int main()
{
	cout<<"Enter the number of vertices : ";
	int n;
	cin>>n;
	vector<unordered_set<int>> G(n+1);
	vector<unordered_set<int>> G1(n+1);
	int color[n+1];
	int color1[n+1];
	stack<int> dummy;
	int i;
	for(i=n;i>=1;i--)
		dummy.push(i);
	cout<<"Enter the number of edges in graph : ";
	int e;
	cin>>e;
	cout<<"Enter the edges as pair of vertices, space separated "<<endl;
	for(i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].insert(y);
		G1[y].insert(x);
	}
	vector<vector<int>> lst;
	dfs(G,color,n,dummy, lst);
	vector<vector<int>> SCC;
	dfs(G1,color,n,s, SCC);
	cout<<"The strongly connected components are : "<<endl;
	for(auto e: SCC)
	{
		for(auto x: e)
			cout<<x<<" ";
		cout<<endl;
	}
}		

