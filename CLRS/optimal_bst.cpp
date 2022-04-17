#include<bits/stdc++.h>
using namespace std;
#define MAX 100
double p[MAX];
double q[MAX];
double w[MAX][MAX];
double e[MAX][MAX];
int root[MAX][MAX];

void display(int i, int j, int parent, int bit)
{
	
	string s;
	if(parent==-1)
	{
		cout<<"k"<<root[i][j]<<" is the root"<<endl;
		display(i,root[i][j]-1, root[i][j],0);
		display(root[i][j]+1,j, root[i][j],1);
		return;
	}
	if(bit==0)//left
		s= " is left child of k";
	else
		s= " is right child of k";
	if(j==i-1)
		cout<<"d"<<i-1<<s<<parent<<" "<<endl;
	else{
		cout<<"k"<<root[i][j]<<s<<parent<<" "<<endl;
		display(i,root[i][j]-1, root[i][j],0);
		display(root[i][j]+1,j, root[i][j],1);
	}	
}
void optimalBST(int n)
{
	int i;
	for(i=1;i<=n+1;i++)
	{
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
	}
	int l;
	for(l=1;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			int k;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			double minimum=DBL_MAX;
			int index;
			for(k=i;k<=j;k++)
			{
				double val=e[i][k-1]+e[k+1][j]+w[i][j];
				if(val<minimum)
				{
					minimum=val;
					index=k;
				}
			}
			e[i][j]=minimum;
			root[i][j]=index;
		}
	}
	cout<<"The optimal cost is : "<<e[1][n]<<endl;
	display(1,n,-1,0);	
}
int main()
{
	int n;
	cout<<"Enter the number of key : ";
	cin>>n;
	cout<<"Enter the probabilities of the keys"<<endl;
	int i;
	for(i=1;i<=n;i++)
	{	
		cout<<"Probability of k"<<i<<" : ";	
		cin>>p[i];
	}
	cout<<"Enter the probabilities of the dummies "<<endl;
	for(i=0;i<=n;i++)
	{
		cout<<"Probability of d"<<i<<" : ";
		cin>>q[i];
	}
	optimalBST(n);
}
