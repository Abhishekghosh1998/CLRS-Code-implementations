#include<iostream>
#include<limits.h>
using namespace std;

struct node {
	int data;
	struct node* next;
	};

typedef struct node* Node;

struct queue{
	Node front, rear;
};

typedef struct queue* Queue;

void init(Queue q)
{
	q->front=q->rear=0;
}

void enqueue(Queue q, int data)
{
	Node newnode=(Node) malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=0;
	if(q->rear==0)
		q->front=q->rear=newnode;
	else
	{
		q->rear->next=newnode;
		q->rear=newnode;
	}
}

int dequeue(Queue q)
{
	if(q->front==0)
	{
		cout<<"UNDERFLOW!!!"<<endl;
		return INT_MAX;
	}
	Node temp=q->front;
	q->front=temp->next;
	int data=temp->data;
	free(temp);
	if(q->front==0)
		q->rear=0;
	return data;
}

int isEmpty(Queue q)
{
	return (q->front==0);
}

int main()
{
	struct queue a;
	Queue q=&a;
	init(q);
	while(1)
	{
		cout<<"1. ENQUEUE"<<endl;
		cout<<"2. DEQUEUE"<<endl;
		cout<<"ENTER YOUR CHOICE : ";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1: { 
				cout<<"ENTER THE DATA TO ENQUEUE : ";
				int data;
				cin>>data;
				enqueue(q,data);
				break;
			}
			case 2: {
				int data=dequeue(q);
				cout<<"DEQUEUED DATA : "<<data<<endl;
				break;
			}
			default: cout<<"WRONG CHOICE !!!"<<endl;
		}
	}
}
