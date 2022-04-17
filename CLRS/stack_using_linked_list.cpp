#include<iostream>
#include<limits.h>
using namespace std;

struct node{
	int data;
	struct node* next;
	};
	
typedef struct node* Node;

struct stack{
	Node top;
};

typedef struct stack* Stack;

void push(Stack s, int data)
{
	Node newnode=(Node) malloc (sizeof (struct node));
	newnode->data=data;
	newnode->next=s->top;
	s->top=newnode;
}

int pop(Stack s)
{
	if(s->top==0)
	{
		cout<<"UNDERFLOW "<<endl;
		return INT_MAX;
	}
	int data=s->top->data;
	Node temp=s->top;
	s->top=s->top->next;
	free(temp);
	return data;
}

int isEmpty(Stack s)
{
	return (s->top==0);
}

int main()
{
	struct stack a;
	a.top=0;
	Stack s=&a;
	while(1)
	{
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"ENTER YOUR CHOICE : ";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1: { 
				cout<<"ENTER THE DATA TO PUSH : ";
				int data;
				cin>>data;
				push(s,data);
				break;
			}
			case 2: {
				int data=pop(s);
				cout<<"POPPED DATA : "<<data<<endl;
				break;
			}
			default: cout<<"WRONG CHOICE !!!"<<endl;
		}
	}
}
