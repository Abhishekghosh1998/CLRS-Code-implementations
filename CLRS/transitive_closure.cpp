#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of vertices in the graph : ";
	cin>>n;
	int e;
	cout<<"Enter the number of edges in the graph : ";
	cin>>e;
	int i;
	
	vector<vector<bool>> M(n+1, vector<bool>(n+1,false));
	
	for(i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		M[x][y]=true;
	}
	
	int j,k;
	
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				M[i][j]=M[i][j]||(M[i][k] && M[k][j]);
	cout<<"The transitive closure : "<<endl;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
		
}
