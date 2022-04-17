#include<bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int> &A)
{	
	int n=A.size()-1;
	int maximum=*max_element(++A.begin(), A.end());
	vector<int> C(maximum+1,0);
	vector<int> B (n+1);
	int i;
	for(i=1;i<=n;i++)
		C[A[i]]++;
	for(i=1;i<=maximum;i++)
		C[i]=C[i]+C[i-1];
	for(i=n;i>=1;i--)
		B[C[A[i]]--]=A[i];
	return B;
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
	cout<<"ARRAY AFTER COUNT SORTING : "<<endl;
	vector<int> B= countSort(A);
	for(i=1;i<=B.size()-1;i++)
		cout<<B[i]<<" ";
	cout<<endl;
}
