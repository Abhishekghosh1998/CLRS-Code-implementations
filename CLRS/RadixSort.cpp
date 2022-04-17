#include<bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int> &A, int pos)
{
	int n=A.size()-1;
	vector<int> C(10,0);
	vector<int> B(n+1);
	int i;
	int pow=1;
	for(i=1;i<=pos;i++)
		pow*=10;
	for(i=1;i<=n;i++)
		C[(A[i]/pow)%10]++;
	for(i=1;i<=9;i++)
		C[i]=C[i]+C[i-1];
	for(i=n;i>=1;i--)
		B[C[(A[i]/pow)%10]--]=A[i];
	return B;
}

void RadixSort(vector<int> &A)
{
	int n=A.size()-1;
	int maximum=*max_element(++A.begin(), A.end());
	int d=0;
	while(maximum)
	{
		d++;
		maximum/=10;
	}
	int i;
	for(i=0;i<d;i++)
	{	cout<<endl;
		int j;
		for(j=1;j<=n;j++)
			cout<<A[j]<<" ";
		cout<<endl;
		A=countSort(A,i);}
}

int main()
{
	int n;
	cout<<" N ? ";
	cin>>n;
	int i;
	vector<int> A(n+1);
	cout<<"ENTER ELEMENTS INTO THE ARRAY : "<<endl;
	for(i=1;i<=n;i++)
		cin>>A[i];
	cout<<"ARRAY AFTER RADIX SORT : "<<endl;
	RadixSort(A);
	for(i=1;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
