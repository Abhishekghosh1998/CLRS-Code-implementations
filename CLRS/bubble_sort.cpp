#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &A)
{
	int n=A.size();
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
}

int main()
{
	int n;
	cout<<"N ? ";
	cin>>n;
	int i;
	vector<int> A(n);
	for(i=0;i<n;i++)
		cin>>A[i];
	cout<<"ARRAY AFTER BUBBLE SORT : "<<endl;
	bubbleSort(A);
	for(int e: A)
		cout<<e<<" ";
	cout<<endl;
	return 0;
	
}
