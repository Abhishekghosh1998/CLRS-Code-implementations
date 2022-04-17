#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

struct node{
	int data;
	int rank;
	struct node* parent;
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
		x->rank++;
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
	cout<<"Enter the edge and its weight"<<endl;
	vector<vector<int>> edgeList;
	for(i=1;i<=e;i++)
	{
		int w,x,y;
		cin>>x>>y>>w;
		vector<int> temp;
		temp.push_back(w);
		temp.push_back(x);
		temp.push_back(y);
		edgeList.push_back(temp);
	}
	sort(edgeList.begin(),edgeList.end());
	vector<pair<int,int>> T;
	int total=0;
	for(auto e: edgeList)
	{
		int x,y;
		x=e[1];
		y=e[2];
		Node x_rep=findSet(handle[x]);
		Node y_rep=findSet(handle[y]);
		if(x_rep!=y_rep)
		{
			T.push_back({x,y});
			total+=e[0];
			Union(x_rep,y_rep);
		}	
	}
	cout<<"The cost of the MST : "<<total<<endl;
	cout<<"The MST is as follows : "<<endl;
	for(auto e: T)
		cout<<"{"<<e.first<<","<<e.second<<"}"<<endl;
}
