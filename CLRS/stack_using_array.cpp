#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
#define MAX 100

struct stack{
	vector<int> A;
	int top;
};

typedef struct stack* Stack;

int pop(Stack s)
{
	if(s->top==-1)
	{
		cout<<"UNDERFLOW!!"<<endl;
		return INT_MAX;
	}
	return s->A[(s->top--)];
}

void push(Stack s, int data)
{
	if(s->top==MAX-1)
	{
		cout<<"OVERFLOW!!!"<<endl;
		return;
	}
	s->A[(++s->top)]=data;
}

int isEmpty(Stack s)
{
	return (s->top==-1);
}

int main()
{
	struct stack a;
	a.A.resize(MAX);
	a.top=-1;
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
