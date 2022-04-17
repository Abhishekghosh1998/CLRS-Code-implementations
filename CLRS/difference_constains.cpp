#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

vector<vector<int>> edgeList;
long long int d[MAX];
int BellmanFord(int s, int n)
{
	int v;
	for(v=1;v<=n-1;v++)
		d[v]=INT_MAX;
	d[s]=0;
	int i;
	for(i=1;i<n;i++)
	{
		for(auto e: edgeList)
		{
			int u,v,w;
			u=e[0];
			v=e[1];
			w=e[2];
			if(d[u]+w<d[v])
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
int main()
{
	int n;
	cout<<"Enter the number of variables (n) : ";
	cin>>n;
	cout<<"Enter the number of inequations (m) : ";
	int m;
	cin>> m;
	cout<<"Enter the m x n matrix "<<endl;
	int A[m+1][n+1];
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin>>A[i][j];
	
	cout<<"Enter the B vector "<<endl;
	vector<int> B(m+1);
	for(i=1;i<=m;i++)
		cin>>B[i];
		
	for(i=1;i<=m;i++)
	{
		int x, y;
		
		for(j=1;j<=n;j++)
			if(A[i][j]==1)
				y=j;
			else if(A[i][j]==-1)
				x=j;
		vector<int> temp(3);
		temp[0]=x;
		temp[1]=y;
		temp[2]=B[i];
		edgeList.push_back(temp);
	}
	//adding the 0th node;
	for(i=1;i<=n;i++)
		edgeList.push_back({0,i,0});
	if(!BellmanFord(0, n+1))
	{
		cout<<"Error! Cannot solve."<<endl;
		return 0;
	}
	cout<<"The required solution : "<<endl;
	int v;
	for(v=1;v<=n;v++)
	{
		cout<<"x"<<v<<" : "<<d[v]<<endl;
		
	}
	return 0;
}


