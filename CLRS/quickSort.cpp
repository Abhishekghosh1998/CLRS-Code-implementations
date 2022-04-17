#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int p, int r)
{
	int pivot=A[r];
	int i=p-1;
	int j;
	for(j=p;j<r;j++)
		if(A[j]<A[r])
		{
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	int temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	return i+1;
}

void quickSort(vector<int> &A, int p, int r)
{
	if(p>=r)
		return;
	int q=partition(A,p,r);
	quickSort(A,p,q-1);
	quickSort(A,q+1,r);
}

int main()
{
	int n;
	cout<<" N ? ";
	cin>>n;
	vector<int> A(n+1);
	int i;
	cout<<"ENTER ELEMENTS INTO THE ARRAY : "<<endl;
	for(i=1;i<=n;i++)
		 cin>>A[i];
	quickSort(A,1,n);
	cout<<"ARRAY AFTER QUICK SORT : "<<endl;
	for(i=1;i<=n;i++)
		 cout<<A[i]<<" ";
	cout<<endl;
}
