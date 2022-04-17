#include<bits/stdc++.h>
using namespace std;

#define MAX 100
vector<int> temp(3);//0 th is finish time, 1st start time and 2nd is index
vector<vector<int>> A(MAX,temp);

void activity_scheduling(int n)
{
	sort(++A.begin(),A.begin()+n+1);
	vector<int> lst;
	lst.push_back(1);
	int curr_ftime=A[1][0];
	int i;
	for(i=2;i<=n;i++)
	{
		if(A[i][1]>=curr_ftime)
		{
			lst.push_back(i);
			curr_ftime=A[i][0];
		}
	}
	for(int e:lst)
		cout<<e<<" ";
	cout<<endl;
} 
int main()
{
	int n;
	cout<<"Enter the number of activities : ";
	cin>>n;
	int i;
	cout<<"Enter the details of the activities : "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"For activity "<<i<<" : "<<endl;
		cout<<"Start time : ";
		cin>>A[i][1];
		cout<<"Finish time : ";
		cin>>A[i][0];
		A[i][2]=i;
	}
	activity_scheduling(n);
}
