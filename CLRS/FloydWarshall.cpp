#include<bits/stdc++.h>
using namespace std;
void display(int x,int y, vector<vector<long long int>> &pred)
{
	int n=pred.size()-1;
	if(x==y)
		cout<<x;
	else if(pred[x][y]==0)
		cout<<"Error Path does not exist!"<<endl;
	else{
		display(x,pred[x][y],pred);
		cout<<"->"<<y;
	}
}
int main()
{
	int n;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	vector<vector<long long int>> A(n+1, vector<long long int> (n+1,INT_MAX)) ;
	vector<vector<long long int>> pred(n+1, vector<long long int> (n+1,0)) ;
	
	cout<<"Enter the number of edges : ";
	int e;
	cin>>e;
	int i,j;
	for(i=1;i<=e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		A[x][y]=w;
		pred[x][y]=x;
	}
	for(i=1;i<=n;i++)
		A[i][i]=0;
	
	int k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					pred[i][j]=pred[k][j];		
				}
	
	cout<<"The matrix: "<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<A[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"The predecessor matrix: "<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<pred[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"The shortest paths : "<<endl;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cout<<i<<"->"<<j<<" : ";
			display(i,j,pred);
			cout<<endl;
		}		
}
