#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right, *parent;
};

typedef struct node* Node;

Node insert(Node root, int data)
{
	if(root==0)
	{
		Node newnode=(Node) malloc (sizeof(struct node));
		newnode->data=data;
		newnode->right=newnode->left=0;
		
		return newnode;
	}
	else if(data<root->data)
	{
		root->left=insert(root->left, data);
		root->left->parent=root;
	}
	else{
		root->right=insert(root->right,data);
		root->right->parent=root;
	}
	return root;	
}

Node search(Node root, int data)
{
	if(root==0)
		return 0;
	if(root->data==data)
		return root;
	else if(data<root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

Node deleteNode(Node root, int data)
{
	Node x=search(root, data);
	if(x==0)
		return root;
	if(!x->right && !x->left)
	{
		if(!x->parent)
		{
			free(x);	
			return 0;//returning root of the tree as NULL
		}
		if(x->parent->left==x)
			x->parent->left=0;
		else
			x->parent->right=0;
	}
	else if(x->right && !x->left)
	{
		if(!x->parent)
		{
			free(x);	
			return x->right;
		}
		if(x->parent->left==x)
			x->parent->left=x->right;
		else
			x->parent->right=x->right;
	}
	else if(!x->right && x->left)
	{
		if(!x->parent)
		{
			free(x);	
			return x->left;
		}
		if(x->parent->left==x)
			x->parent->left=x->left;
		else
			x->parent->right=x->left;
	}	
	else{
		//find in-order successor
		Node p=x->right;
		Node q=0;
		while(p)
		{	
			q=p;
			p=p->left;
		}
		if(q->parent->right==q)
			q->parent->right=q->right;
		else 
			q->parent->left=q->right;
		q->right=x->right;
		q->left=x->left;
		if(!x->parent)
		{	
			free(x);	
			return q;
		}
		if(x->parent->left==x)
			x->parent->left=q;
		else
			x->parent->right=q;
				
	}
	free(x);
	return root;	
}

void inorder(Node root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}

Node minimum(Node root)
{
	Node p=root;
	Node q=0;
	while(p)
	{
		q=p;
		p=p->left;
	}
	return q;
	
}

Node maximum(Node root)
{
	Node p=root;
	Node q=0;
	while(p)
	{
		q=p;
		p=p->right;
	}
	return q;
}

Node successor(Node x)
{
	Node p=x->right;
	Node q=0;
	while(p)
	{
		q=p;
		p=p->left;
	}
	if(q)
		return q;
	p=x->parent;
	q=x;
	while(p && p->right==q)
	{
		q=p;
		p=p->parent;
	}
	return p;
}

Node predecessor(Node x)
{
	Node p=x->left;
	Node q=0;
	while(p)
	{
		q=p;
		p=p->right;
	}
	if(q)
		return q;
	p=x->parent;
	q=x;
	while(p && p->left==q)
	{
		q=p;
		p=p->parent;
	}
	return p;
}

int main()
{
	Node root=0;
	while(1)
	{
		cout<<endl<<endl<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Inorder Traversal"<<endl;
		cout<<"5. Predecessor "<<endl;
		cout<<"6. Successor "<<endl;
		cout<<"7. Minimum "<<endl;
		cout<<"8. Maximum "<<endl;
		cout<<"Enter your choice : ";
		int ch;
		cin>>ch;
		switch(ch){
		case 1: {
				cout<<"Enter the element you want to enter : ";
				int data;
				cin>>data;
				root=insert(root, data);
				break;
			}
		case 2: {
				cout<<"Enter the element you want to delete : ";
				int data;
				cin>>data;
				root=deleteNode(root, data);
				break;
			}
		case 3: {
				cout<<"Enter the element you want to search : ";
				int data;
				cin>>data;
				Node x=search(root, data);
				if(x)
					cout<<"Element is found !"<<endl;
				else 	
					cout<<"Element is not found !"<<endl;
				break;
		}
		case 4: {
				cout<<"The inorder traversal : "<<endl;
				inorder(root);
				cout<<endl;
				break;
			}
		case 5: {
				cout<<"Enter the element whose predecessor you want to find : ";
				int data;
				cin>>data;
				Node x=search(root, data);
				if(!x)
					cout<<"Element not found!!"<<endl;
				else{
					x=predecessor(x);
					if(!x)
						cout<<"Predecessor does not exist !!"<<endl;
					else
						cout<<"The predecessor is : "<<x->data<<endl;
				}
				break;
		}
		case 6: {
				cout<<"Enter the element whose successor you want to find : ";
				int data;
				cin>>data;
				Node x=search(root, data);
				if(!x)
					cout<<"Element not found!!"<<endl;
				else{
					x=successor(x);
					if(!x)
						cout<<"Successor does not exist !!"<<endl;
					else
						cout<<"The successor is : "<<x->data<<endl;
				}
				break;
		}
		
		case 7: {
				if(!root)
					cout<<"Tree Empty !"<<endl;
				else
					cout<<"The minimum element : "<<minimum(root)->data<<endl;
				break;
		}
		case 8: {
				if(!root)
					cout<<"Tree Empty !"<<endl;
				else
					cout<<"The maximum element : "<<maximum(root)->data<<endl;
				break;
		}		
		default: cout<<"Wrong Choice !"<<endl;
		}
	}
}
