#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> add(vector<vector<int>> &A,int ar1,int ar2,int ac1, int ac2, vector<vector<int>> &B, int br1, int br2)
{
	int n=ar2-ar1+1;
	vector<int> temp(n+1);
	vector<vector<int>> C(n+1, temp);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			C[i][j]=A[ar1+i-1][ac1+j-1]+B[br1+i-1][bc1+j-1];
	return C;
}
vector<vector<int>> sub(vector<vector<int>> &A,int ar1,int ar2,int ac1, int ac2, vector<vector<int>> &B, int br1, int br2)
{
	int n=ar2-ar1+1;
	vector<int> temp(n+1);
	vector<vector<int>> C(n+1, temp);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			C[i][j]=A[ar1+i-1][ac1+j-1]-B[br1+i-1][bc1+j-1];
	return C;
}

vector<vector<int>> multiply(vector<vector<int>> &A,int ar1,int ar2,int ac1, int ac2, vector<vector<int>> &B, int br1, int br2)
{
	int n=ar2-ar1+1;
	S1=sub(B,
}
int main()
{
	int n;
	cin>>n;
	vector<int> temp(n+1);
	vector<vector<int>> A(n+1,temp);
	
	vector<vector<int>> B(n+1,temp);
	
	cout<<"ENTER ELEMENTS INTO THE FIRST MATRIX : "<<endl;
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>A[i][j];
	cout<<"ENTER ELEMENTS INTO THE SECOND MATRIX : "<<endl;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>B[i][j];
}
