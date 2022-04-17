#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A,int p, int r, int element)
{
	int i,index;
	for(i=p;i<=r;i++)
		if(A[i]==element)
		{
			index=i;
			break;
		}
	int temp=A[r];
	A[r]=A[index];
	A[index]=temp;
	
	i=p-1;
	int j;
	for(j=p;j<r;j++)
		if(A[j]<=A[r])
		{
			i++;
			temp=A[j];
			A[j]=A[i];
			A[i]=temp;
		}
	temp=A[r];
	A[r]=A[i+1];
	A[i+1]=temp;
	return i+1;
}

void insertionSort(vector<int> &A, int x, int y)
{
	int i;
	for(i=x+1;i<=y;i++)
	{
		int temp=A[i];
		int j=i-1;
		while(j>=x && A[j]>temp)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
	}
}
int select(vector<int> &A, int p, int r, int k)
{
	if(p==r)
		return A[p];
		
	int i;
	vector<int> B;
	B.push_back(0);
	for(i=p;i<=r;i+=5)
	{
		int end ;
		if(i+4<=r)
			end=i+4;
		else
			end=r;
		insertionSort(A, i,end);
		B.push_back(A[(i+end)/2]);
	}
	int median_of_median=select(B, 1, B.size()-1, B.size()/2);
	int index = partition(A, p, r, median_of_median);
	if(p+k-1==index)
		return A[index];
	else if(p+k-1<index)
		return select(A,p,index-1,k);
	else
		return select(A,index+1,r,k-(index-p+1));	
}

int main()
{
	int n;
	cout<<"N ? ";
	cin>>n;
	int i;
	vector<int> A(n+1);
	for(i=1;i<=n;i++)
		cin>>A[i];
	int index;
	cout<<"ENTER THE INDEX OF THE i TH MINIMUM WHICH YOU WANT : ";
	cin>>index;
	cout<<"THE i TH MINIMUM : "<<select(A,1,n,index)<<endl;
	return 0;
}
