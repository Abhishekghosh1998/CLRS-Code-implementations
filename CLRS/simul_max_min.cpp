#include<bits/stdc++.h>
using namespace std;

pair<int,int> minMax(vector<int> &A)
{
	int n=A.size()-1;
	int i;
	int minimum,maximum;
	if(n&1)//odd
	{
		minimum=maximum=A[1];
		i=2;
	}
	else{
		if(A[1]>A[2])
		{
			maximum=A[1];
			minimum=A[2];
		}
		else{
			maximum=A[2];
			minimum=A[1];
		}
		i=3;
	}
	for(;i<=n;i+=2)
	{
		int local_max=A[i];
		int local_min=A[i+1];
		if(A[i]<A[i+1])
		{
			local_min=A[i];
			local_max=A[i+1];
		}
		if(local_max>maximum)
			maximum=local_max;
		if(local_min<minimum)
			minimum=local_min;
	}
	return {minimum,maximum};
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
	pair<int,int> p=minMax(A);
	cout<<"Minimum : "<<p.first<<"\nMaximum : "<<p.second<<endl;
	return 0;
}
