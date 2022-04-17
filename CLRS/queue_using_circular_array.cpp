#include<iostream>
#include<climits>
using namespace std;
#define MAX 100
struct queue{
	int front;
	int rear;
	int A[MAX];
};

typedef struct queue* Queue;

void init(Queue q)
{
	q->front=q->rear=MAX-1;
}

void enqueue(Queue q, int data)
{
	if((q->rear+1)%MAX==q->front)
	{
		cout<<"OVERFLOW!!!"<<endl;
		return;
	}
	q->rear=(q->rear+1)%MAX;
	q->A[q->rear]=data;
}

int dequeue(Queue q)
{
	if(q->rear==q->front)
	{
		cout<<"UNDERFLOW!!!"<<endl;
		return INT_MAX;
	}
	q->front=(q->front+1)%MAX;
	return q->A[q->front];
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
