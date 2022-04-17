#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &A)
{
	int n=A.size();
	int i;
	for(i=0;i<n;i++)
	{
		int minimum=A[i];
		int index=i;
		int j;
		for(j=i+1;j<n;j++)
			if(A[j]<minimum)
			{
				minimum=A[j];
				index=j;
			}
		int temp=A[i];
		A[i]=A[index];
		A[index]=temp;
	}
}

int main()
{
	int n;
	cout<<" N ? ";
	cin>>n;
	vector<int> A(n);
	for(int &e:A)
		cin>>e;
	selectionSort(A);
	cout<<"ARRAY AFTER SORTING : "<<endl;
	for(int e: A)
		cout<<e<<" ";
	cout<<endl;
}
