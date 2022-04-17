#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int p, int r)
{
	int i=p-1;
	int j;
	for(j=p;j<r;j++)
		if(A[j]<=A[r])
		{
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	int temp=A[r];
	A[r]=A[i+1];
	A[i+1]=temp;
	return i+1;
}

int randomizedPartition(vector<int> &A, int p, int r)
{
	int i=p+(rand()%(r-p+1));
	int temp=A[i];
	A[i]=A[r];
	A[r]=temp;
	return partition(A, p,r);
}

int randomSelect(vector<int>&A, int p, int r, int k)
{
	int i=randomizedPartition(A,p,r);
	if(p+k-1==i)
		return A[i];
	else if(p+k-1<i)
		return randomSelect(A, p,i-1,k);
	else
		return randomSelect(A, i+1,r, k-(i-p+1));
}

int main()
{
	int n;
	cout<<"N ? ";
	cin>>n;
	int i;
	vector<int> A(n+1);
	for(i=1;i<=n;i++)
		cin>>A[i];
	int index;
	cout<<"ENTER THE INDEX OF THE i TH MINIMUM WHICH YOU WANT : ";
	cin>>index;
	cout<<"THE i TH MINIMUM : "<<randomSelect(A,1,n,index)<<endl;
	return 0;
}
