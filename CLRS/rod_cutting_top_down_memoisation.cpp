#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int p[MAX+1];
int cost[MAX+1];
int s[MAX+1];

int calculate(int n)
{
	if(cost[n]>=0)
		return cost[n];
	if(n==0)
		return 0;
	if(n==1)
		return p[1];
	int i;
	int index=0;
	int maximum=0;
	for(i=1;i<=n;i++)
	{
		int val=p[i]+calculate(n-i);
		if(maximum<val)
		{
			maximum=val;
			index=i;	
		}
	}
	cost[n]=maximum;
	s[n]=index;
	return cost[n];
}

void display(int n)
{	
	while(n)
	{
		cout<<s[n]<<" ";
		n=n-s[n];
	}
}

int main()
{
	int n;
	cout<<"Enter the length of the rod : ";
	cin>>n;
	memset(cost,-1,sizeof(int)*MAX);
	int i;
	cout<<"Enter the cost of the rod pieces "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"P[ "<<i<<"] ? ";
		cin>>p[i];
	}
	cout<<"Result : "<<calculate(n)<<endl;
	display(n);
	cout<<endl;
}
