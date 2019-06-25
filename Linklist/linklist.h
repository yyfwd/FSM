#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef struct node
{
	int data;
	struct node *next;
}Node,*LinkList;

LinkList create(int n);
void print_linklist(LinkList head);
void delete_node(LinkList head,int n);
void free_linklist(LinkList head);
void insert_node(LinkList head,int n);
int search_linklist_L(LinkList head,int location);
int search_linklist_D(LinkList head,int data);
#endif