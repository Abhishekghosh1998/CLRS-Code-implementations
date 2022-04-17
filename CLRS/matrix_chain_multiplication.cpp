#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int cost[MAX][MAX];
int p[MAX];
int s[MAX][MAX];

int  matrixChainMultiplication()
{
	int i;
	for(i=1;i<=n;i++)
		cost[i][i]=0;//matrix chain of length 1
	int l,j,k;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;//i..j chain of length l
			int minimum=INT_MAX;
			int index=i;
			for(k=i;k<j;k++)
			{
				int value=cost[i][k]+cost[k+1][j]+p[i-1]*p[k]*p[j];
				if(value<minimum)
				{
					minimum=value;
					index=k;
				}
			}
			cost[i][j]=minimum;
			s[i][j]=index;		
		}
	}
	return cost[1][n];
}

void display(int i, int j)
{
	if(i==j)
	{
		cout<<"A"<<i;
		return;
	}
	cout<<"(";
	int k=s[i][j];
	display(i,k);
	display(k+1,j);
	cout<<")";
}
	

int main()
{
	cout<<"ENTER THE NUMBER OF MATRICES : ";
	cin>>n;
	int i;
	cout<<"ENTER THE DIMENSIONS OF THE MATRICES : "<<endl;
	cout<<"M1 ? ";
	cin>>p[0]>>p[1];
	for(i=2;i<=n;i++)
	{
		cout<<"M"<<i<<" ? ";
		int x,y;
		cin>>x>>y;
		if(x!=p[i-1])
		{
			cout<<"Matrices incompatible for multiplication !!!"<<endl;
			return 0;
		}
		p[i]=y;
	}
	int result=matrixChainMultiplication();
	cout<<"Cost of the optimal matrix chain multiplication : "<<result<<endl;
	cout<<"The optimal parenthesization is : "<<endl;
	display(1,n);
	cout<<endl;
}
