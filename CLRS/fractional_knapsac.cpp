#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<int> p(MAX,0);
vector<int> w(MAX,0);

void fractionalKS(int n,int m)
{
	//n is number of elements
	//m is capacity of the knapsack;
	vector<pair<double,int>> parameter;
	parameter.push_back({0.0,0});
	int i;
	for(i=1;i<=n;i++)
	{
		double value=p[i]/w[i];
		parameter.push_back({value,i});
	}
	sort(parameter.begin()+1,parameter.end()+n+1,
	[](pair<double,int> x, pair<double, int> y)->bool
	{	return (x.first>=y.first);});
	
	double total=0.0;
	for(i=1;i<=n;i++)
	{
		if(m<w[parameter[i].second])
			break;
		m-=w[parameter[i].second];
		total+=p[parameter[i].second];
	}
	if(i<=n)
	{
		total+=(double(m)/w[parameter[i].second])*(p[parameter[i].second]);
	}
	cout<<total<<endl;
}
int main()
{
	int n;
	cout<<"Enter the number of objects : ";
	cin>>n;
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<"P [ "<<i<<"] ? ";
		cin>>p[i];
	}
	for(i=1;i<=n;i++)
	{
		cout<<"W [ "<<i<<"] ? ";
		cin>>w[i];
	}
	cout<<"Enter weight of the knapsack : ";
	int m;
	cin>>m;
	fractionalKS(n,m);
}
