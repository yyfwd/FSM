#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

//按顺序创建N个节点的链表
LinkList create(int n)
{
	int i;
	LinkList head,node,end;
	head = (LinkList)malloc(sizeof(Node));
	if(head == NULL)
	{
		printf("malloc head memory failed\n");
		exit(0);
	}
	end = head;
	for(i=0;i<n;i++)
	{
		node = (LinkList)malloc(sizeof(Node));
		if(node == NULL)
		{
			printf("malloc node memory failed\n");
			exit(0);
		}
		scanf("%d",&node->data);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

//查找链表中某一位置的数据
int search_linklist_L(LinkList head,int location)
{
	int i=1;
	LinkList ptr = head;
	ptr = ptr->next;   //去掉头节点
	while(i!=location && ptr)
	{
		ptr = ptr->next;	
		i++;
	}
	if(ptr!=NULL)
	{
		printf("search linklist location %d data:%d\n",location,ptr->data);
		return (ptr->data);
	}
	else
	{
		goto error;	
	}
	error:
		 printf("search linklist failed\n");
		 return -1;
}

//查找链表中某数据在链表中的位置
int search_linklist_D(LinkList head,int data)
{
	int i = 0,j=1;
	int sum = 0;
	LinkList ptr = head;
	ptr = ptr->next;
	while(ptr)
	{
		if(ptr->data == data)
		{
			printf("%d.search linklist data %d location:%d\n",++i,data,j);
			sum++;
		}
		j++;
		ptr = ptr->next;
	}
	if(!sum)
	{
		printf("not search data from linklist\n");
	}
	return sum;
}

//按顺序打印输出链表
void print_linklist(LinkList head)
{
	LinkList p = head;
	int j = 1;
	p = p->next;
	while(p != NULL)
	{
		printf("%d.\t%d\n",j,p->data);
		p = p->next;
		j++;
	}
}

//删除链表中指定位置的节点
void delete_node(LinkList head,int n)
{
	int i = 0;
	LinkList p,ptr;
	p = head;         //两个指针指向同一个地址
	ptr = head;
	while(i<n&&p!=NULL)
	{
		ptr = p;            //跳出while时将ptr指针指向指针P的前一个地址          
		p = p->next;
		i++;
	}
	if(p!=NULL)
	{
		ptr->next = p->next;
		free(p);	
		p = NULL;      	  //释放指针后将指针清空避免成野指针
	}
	else
	{
		printf("delete node not exist\n");
	}
	
}
//在对应位置插入相应的节点
void insert_node(LinkList head,int n)
{
	int i=0;
	LinkList p,ptr;
	p = head;
	ptr = (LinkList)malloc(sizeof(Node));
	if(ptr == NULL)
	{
		printf("insert fun malloc node failed\n");
		exit(0);
	}
	printf("input data:");
	scanf("%d",&ptr->data);
	while(i<n&&p!=NULL)
	{
		p = p->next;
		i++;
	}
	if(p != NULL)      
	{
		ptr->next = p->next;
		p->next = ptr;
	}
	else
	{
		printf("insert node location is failed\n");
	}
}
//按顺序释放整个链表地址
void free_linklist(LinkList head)
{
	LinkList p;
	while(head!=NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
	p = NULL;  //释放完后将指针清空，避免成野指针,这里可要可不要，但是养成习惯每次释放指针的时候将指针指为空地址。
}

//主函数
int main(int argc,char *argv[])
{
	int lnum = 0,location = 0,data1 = 0;
	char c;
	LinkList mylist = NULL;  			  //指针在使用时一定得初始化，要么指向空要么只想存在的内存地址
	printf("you want to create linklist len:");
	scanf("%d",&lnum);
	mylist = create(lnum);                //创建链表
	print_linklist(mylist);
	
	printf("you want insert node location:");
	scanf("%d",&location);
	insert_node(mylist,location);         //插入节点到链表中
	print_linklist(mylist);
	
	
	printf("you want delete node location:");
	scanf("%d",&location);
	delete_node(mylist,location);         //从链表中删除节点
	print_linklist(mylist);
	
	printf("you want search node location:");
	scanf("%d",&location);
	search_linklist_L(mylist,location);  //查询链表某位置节点的数据
	
	printf("you want search node data:");
	scanf("%d",&data1);
	search_linklist_D(mylist,data1);     //查询链表中某个数据在链表中的位置

	free_linklist(mylist);
	return 0;
}

