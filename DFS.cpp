//bfs and dfs

#include<string.h>
#include<iostream>
#include<bits/stdc++.h> 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;

long int n;
int v_q[10000],v_stack[10000];
int front=-1;
int rear=-1;
int top=-1;
int *visit_time, *low_visit_time;

typedef struct node
{
	long num;
	long parent;
	struct node *next;
	char colour;
}node;

node *graph;

void enq(long ele)
{
	if(front == -1)
	{
		++front;
		++rear;
		v_q[rear]=ele;
	}
	else
	{
		++rear;
		v_q[rear]=ele;
	}
}

long deq()
{
	if(rear == 0)
		--front;
	return v_q[rear--];
}

void push_vertex(long ele)
{
	++top;
	v_stack[top] = ele;
	return;
}

long pop_vertex()
{
	return v_stack[top--];
}

void insert(long num,long index)
{
	node *p,*q;
	p = (node *)malloc(sizeof(node));
	q = &graph[index];
	p->num = num;
	p->next = NULL;
	while(q->next != NULL)
		q = q->next;
	q->next = p;
}

void print()
{
	node *p;
	int i;
	for(i=0;i<n;++i)
	{
		p = &graph[i];
		cout<<graph[i].num;
		while(p->next!=NULL)
		{
			p=p->next;
			cout<<p->num;
		}
		cout<<"\n";
	}
}

void dfs()
{
	long i,u,v;
	node *adj;
	top = -1;
	int v_time = 0;
	visit_time = (int*)calloc(n,sizeof(int));
	low_visit_time  = (int*)calloc(n,sizeof(int));
	for(i=0; i<n; ++i)
		graph[i].colour = 'w';
	push(0);
	graph[0].colour = 'g';
	visit_time[0] = low_visit_time[0] = ++time;

	while(top!=-1)
	{
		u = pop();
		cout<<"\nu="<<u;
		graph[u].colour = 'g';
		adj = graph[u].next;
		while(adj != NULL)
		{
			v = adj->num;
			if(graph[v].colour=='w')
			{
				push(v);
				graph[v].colour='g';
			}
			adj=adj->next;
		}
	}
}

void main()
{

	long i,j;
	char ch,str[4];
	cout<<"Enter the number of vertices : "
	cin>>n;
	graph = (node *)malloc(sizeof(node)*10000);
	for(i=0;i<n;++i)
	{
		graph[i].num=i;
		graph[i].next=NULL;
	}
	cout<<"\nEnter the adjacency list for each vertex : "
	cin>>ch;
	for(i=0;i<n;++i)
	{
		cin>>ch;
		if(ch=='\n')
			continue;
		j=ch-'0';
		cin>>ch;
		insert(j,i);
		while(ch!='\n')
		{
			cin>>j>>ch;
			insert(j,i);
		}
	}
    dfs();
    cout<<"\n";
}

