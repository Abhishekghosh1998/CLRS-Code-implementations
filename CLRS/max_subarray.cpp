#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &A, int p, int r)
{
	if(p>r)
		return INT_MIN;
	if(p==r)
		return A[p];
	int q=(p+r)/2;
	int left = maxSum(A,p,q);
	int right = maxSum(A,q+1,r);
	int maximum=INT_MIN;
	int sum=0;
	int i;
	for(i=q;i>=p;i--)
	{
		sum+=A[i];
		if(sum>maximum)
			maximum=sum;
	}
	sum=maximum;
	maximum=INT_MIN;
	int sum1=0;
	for(i=q+1;i<=r;i++)
	{
		sum1+=A[i];
		if(sum1>maximum)
			maximum=sum1;
	}
	sum1=maximum;
	int mid=sum1+sum;
	return max(max(left,right),mid);
}

int main()
{
	int n;
	cin>>n;
	vector<int> A(n);
	for(int &e: A)
		cin >>e;
	cout<<maxSum(A,0,n-1)<<endl;
}


