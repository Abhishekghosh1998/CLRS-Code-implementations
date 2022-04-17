#include<bits/stdc++.h>
using namespace std;

struct node{
	double data;
	struct node* next;
};

typedef struct node* Node;

Node insert(double data, Node p)
{
	Node newnode=(Node) malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=0;
	if(!p)
		return newnode;
	if(data<p->data)
	{
		newnode->next=p;
		return newnode;
	}
	Node a=p;
	Node b=p->next;
	while(b && data>=b->data)
	{
		a=b;
		b=b->next;
	}
	newnode->next=a->next;
	a->next=newnode;
	return p;
}

void BucketSort(vector<double> &A)
{
	int n=A.size()-1;
	vector<Node> B(n);
	int i;
	for(i=1;i<=n;i++)
		B[int(A[i]*n)]=insert(A[i],B[int(A[i]*n)]);
	int k=1;
	for(i=0;i<n;i++)
	{
		Node temp=B[i];
		while(temp)
		{
			A[k++]=temp->data;
			temp=temp->next;
		}
	}
}

int main()
{
	int n;
	cout<<" N ? ";
	cin>> n;
	vector<double> A(n+1);
	int i;
	cout<< "ENTER ELEMENTS IN THE RANGE [0,1) INTO THE ARRAY : "<<endl;
	for(i=1;i<=n;i++)
		cin>>A[i];
	cout<<" ARRAY AFTER BUCKER SORTING : "<<endl;
	BucketSort(A);
	for(i=1;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
