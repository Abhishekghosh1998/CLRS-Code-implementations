#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

struct node {
	int data;
	struct node * parent;
	int rank;
	};

typedef struct node* Node;

Node handle[MAX];

void makeSet(int x)
{
	Node newnode=(Node) malloc(sizeof(struct node));
	newnode->data=x;
	newnode->parent=newnode;
	newnode->rank=0;
	handle[x]=newnode;
}

Node findSet(Node x)
{
	if(x->parent==x)
		return x;
	else{
		x->parent=findSet(x->parent);
		return x->parent;
	}	
}

void Union(Node x, Node y)
{
	if(x->rank<y->rank)
	{
		Node temp=x;
		x=y;
		y=temp;	
	}
	y->parent=x;
	if(x->rank==y->rank)
		y->rank++;
}

int main()
{
	int n;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	int i;
	for(i=1;i<=n;i++)
		makeSet(i);
	cout<<"Enter the number of edges : ";
	int e;
	cin>>e;
	cout<<"Enter the edges [as pair of vertices - space separated] "<<endl;
	int union_count=0;
	for(i=1;i<=e;i++)
	{	
		int x,y;
		cin>>x>>y;
		Node x_rep=findSet(handle[x]);
		Node y_rep=findSet(handle[y]);
		if(x_rep!=y_rep)
		{
			Union(x_rep,y_rep);
			union_count++;
		}
	}
	cout<<"The number of connected components are : "<<n-union_count<<endl;
	unordered_map<int,set<int>> m;
	for(i=1;i<=n;i++)
	{
		int i_rep=findSet(handle[i])->data;
		m[i_rep].insert(i);
	}	
	cout<<"The connected components are as follows: "<<endl;
	for(auto e : m)
	{
		for(auto x: e.second)
			cout<<x<<" ";
		cout<<endl;
	}
}
