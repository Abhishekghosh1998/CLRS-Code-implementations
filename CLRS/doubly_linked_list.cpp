#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* prev, *next;
	};

typedef struct node * Node;

struct list{
	Node nil;
};

typedef struct list* List;

void init(List l)
{
	Node newnode=(Node) malloc(sizeof(struct node));
	newnode->next=newnode->prev=newnode;
	l->nil=newnode;
}

void insert(List l, int data)
{
	Node newnode=(Node) malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=l->nil->next;
	newnode->next->prev=newnode;
	l->nil->next=newnode;
	newnode->prev=l->nil;	
}

Node search(List l, int data)
{
	Node temp=l->nil->next;
	while(temp!=l->nil)
	{
		if(temp->data==data)
			break;
		temp=temp->next;
	}
	return temp;	
}

void deleteElement(Node x)
{
	x->next->prev=x->prev;
	x->prev->next=x->next;
	free(x);	
}

void display(List l)
{
	Node temp=l->nil->next;
	while(temp!=l->nil)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
	cout<<endl;
}

int main()
{
	struct list a;
	List l=&a;
	init(l);
	while(1)
	{
		cout<<"1. Insert at front "<<endl;
		cout<<"2. Search an element "<<endl;
		cout<<"3. Delete an element "<<endl;
		cout<<"4. Display the list "<<endl;
		cout<<"Enter your choice : ";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1: {
					cout<<"Enter the element you want to insert : ";
					int data;
					cin>>data;
					insert(l,data);
					break;
			}
			case 2: {
					cout<<"Enter the element you want to search : ";
					int data;
					cin>>data;
					Node x=search(l,data);
					if(x==l->nil)
						cout<<"Element is not present in the list! "<<endl;
					else
						cout<<"Element is present in the  list! "<<endl;
					break;
			}
			case 3: {
					cout<<"Enter the element you want to delete : ";
					int data;
					cin>>data;
					Node x=search(l,data);
					if(x==l->nil)
						cout<<"Element is not present in the list! "<<endl;
					else{
						deleteElement(x);
						cout<<"Element successfully deleted ! "<<endl;
					}
					break;
			}
			case 4: {
					cout<<"The list is as follows: "<<endl;
					display(l);
					break;
			}
			default: cout<<"Wrong choice !"<<endl;
		}
	}
}
