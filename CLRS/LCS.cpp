#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define UP 0
#define LEFT 1
#define DIAG 2
int C[MAX][MAX];
int B[MAX][MAX];

void display(string X, int i, int j)
{
	if(i==0 || j==0)
		return;
	if(B[i][j]==DIAG)
	{
		display(X,i-1,j-1);
		cout<<X[i];
	}
	else if(B[i][j]==LEFT)
		display(X,i,j-1);
	else
		display(X,i-1,j);
}
void LCS(string X, string Y)
{
	int m=X.size()-1;
	int n=Y.size()-1;
	int i,j;
	for(i=0;i<=n;i++)
		C[0][i]=0;
	for(j=1;j<=m;j++)
		C[j][0]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(X[i]==Y[j])
			{
				C[i][j]=1+C[i-1][j-1];
				B[i][j]=DIAG;
			}
			else{
				if(C[i][j-1]>C[i-1][j])
				{
					C[i][j]=C[i][j-1];
					B[i][j]=LEFT;
				}
				else{
					C[i][j]=C[i-1][j];
					B[i][j]=UP;
				}
				
			}
	cout<<C[m][n]<<endl;
	cout<<"The LCS : ";
	display(X,Y,m,n);
	cout<<endl;		
}

int main()
{
	cout<<"ENTER FIRST STRING : ";
	string X;
	cin>>X;
	cout<<"ENTER THE SECOND STRING : ";
	string Y;
	cin>>Y;
	X=" "+X;
	Y=" "+Y;
	LCS(X,Y);
}
