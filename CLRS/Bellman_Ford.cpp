#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

vector<vector<int>> edgeList;

int d[MAX];
int pred[MAX];
int BellmanFord(int s, int n)
{
	int v;
	for(v=1;v<=n;v++)
	{
		d[v]=INT_MAX;
		pred[v]=0;
	}
	int i;
	d[s]=0;
	for(i=1;i<=n-1;i++)
		for(auto e: edgeList)
		{
			int u,v,w;
			u=e[0];
			v=e[1];
			w=e[2];
			if(d[u]+w<d[v])
			{
				pred[v]=u;
				d[v]=d[u]+w;
			}
			
		}
	for(auto e: edgeList)
	{
		int u,v,w;
		u=e[0];
		v=e[1];
		w=e[2];
		if(d[u]+w<d[v])
		 	return 0;
	}
	return 1;	
}
void display(int s, int v)
{
	if(v==s)
		cout<<s;
	else if(pred[v]==0)
		cout<<"No path exists!"<<endl;
	else{
		display(s,pred[v]);
		cout<<"->"<<v;
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
		int x, y,w;
		cin>>x>>y>>w;
		vector<int> temp;
		temp.push_back(x);
		temp.push_back(y);
		temp.push_back(w);
		edgeList.push_back(temp);
	}
	int value=BellmanFord(1,n);
	if(!value)
	{
		cout<<"The graph contains negative cycle!!"<<endl;
		return 0;
	}
	int v;
	for(v=1;v<=n;v++)
	{
		cout<<"d["<<v<<"] : "<<d[v]<<" Path : ";
		display(1,v);
		cout<<endl;
	}	
}
