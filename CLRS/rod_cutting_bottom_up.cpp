#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the length of the rod : ";
	cin>>n;
	vector<int> p(n+1);
	int i;
	cout<<"Enter the cost of the rod pieces "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"P[ "<<i<<"] ? ";
		cin>>p[i];
	}
	vector<int> cost(n+1);
	vector<int> s(n+1);
	cost[0]=0;
	cost[1]=p[1];
	s[1]=1;
	
	int l,j;//l stands of size of rod or length
	for(l=2;l<=n;l++)
	{
		int i;
		int maximum=0;
		int index=0;
		for(j=1;j<=l;j++)
			if(maximum<p[j]+cost[l-j])
			{
				maximum=p[j]+cost[l-j];
				index=j;
			}
		cost[l]=maximum;
		s[l]=index;	
	}
	
	cout<<"The cost is : "<<cost[n]<<endl;
	cout<<"The required cutting is : "<<endl;
	l=n;
	while(l)
	{
		cout<<s[l]<<" ";
		l=l-s[l];
	}	
	cout<<endl;
}
