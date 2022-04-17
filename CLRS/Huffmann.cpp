#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
struct node{
	int freq;
	char ch;
	struct node* left, *right;
};

typedef struct node* Node;

Node A[MAX];
int heapSize = 0;

void heapify(int i)
{
	int left=2*i;
	int right=2*i+1;
	int index=i;
	if(left<=heapSize && A[left]->freq<A[i]->freq)
		index=left;
	if(right<=heapSize && A[right]->freq<A[index]->freq)
		index=right;
	if(index!=i)
	{
		Node temp=A[i];
		A[i]=A[index];
		A[index]= temp;
		heapify(index);
	}
}

void buildHeap()
{
	int i;
	for(i=heapSize/2;i>=1;i--)
		heapify(i);
}

Node extractMin()
{
	Node x=A[1];
	A[1]=A[heapSize];
	heapSize--;
	heapify(1);
	return x;
}

void insert(Node x)
{
	heapSize++;
	A[heapSize]=x;
	int i=heapSize;
	int p=heapSize/2;
	while(p>=1 && A[p]->freq > A[i]->freq)
	{
		Node temp=A[i];
		A[i]=A[p];
		A[p]=temp;
		i=p;
		p=p/2;
	}
}

void display(Node root, string s)
{
	if(root->left==0 && root->right==0)
	{
		cout<<root->ch<< " : "<<s<<endl;
		return;
	}
	display(root->left, s+"0");
	display(root->right,s+"1");
}
int main()
{
	int n;
	cout<<"Enter the number of characters : ";
	cin>>n;
	heapSize=n;
	int i;
	cout<<"In the next "<<n<<" lines enter a character and its frequency seperated by space"<<endl;
	for(i=1;i<=n;i++)
	{	
		char ch;
		int freq;
		cin>>ch>>freq;
		Node newnode=(Node) malloc(sizeof(struct node));
		newnode->ch=ch;
		newnode->freq=freq;
		newnode->left=newnode->right=0;
		A[i]=newnode;
	}

	buildHeap();
	
	for(i=1;i<=n-1;i++)
	{
		Node x=extractMin();
		Node y=extractMin();
		Node z=(Node) malloc(sizeof(struct node));
		z->left=x;
		z->right=y;
		z->freq=x->freq+y->freq;
		insert(z);
	}
	Node root=A[1];
	cout<<"The encoding is as follows : "<<endl;
	display(root,"");
	
}
