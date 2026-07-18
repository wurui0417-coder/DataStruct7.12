//
//#define MAX 100

//
//typedef struct {
//	Elemtype* data;
//	int length;
//}SeqList;
//
//SeqList* Initlist()
//{
//	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
//	L->data = (Elemtype*)malloc(sizeof(Elemtype) * MAX);
//	L->length = 0;
//	return L;
//}
//
//void AddElem()
//{
//
//}
//
//
//int main()
//{
//	SeqList* List = Initlist();
//	
//	AddElem(List, 1);
//}
#include<stdlib.h>
#include<stdio.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}Node,*LinkList;

//初始化链表
LinkList iniList()
{
	LinkList head = (LinkList)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//Head insertion
void headinsert(LinkList L, ElemType e)
{
	LinkList l1 = (LinkList)malloc(sizeof(Node));
	l1->data = e;
	l1->next = L->next;
	L->next = l1;
}

//list node
void ListNode(LinkList L)
{
	if (L->next == NULL)
	{
		printf("NONE in list");
	}
	LinkList p = L->next;
	while (p!= 0)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
	printf("\n");
}

//get tail
LinkList get_tail(LinkList L)
{
	LinkList p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

//end insertion
void endinsert(LinkList L, ElemType e)
{
	LinkList tail = get_tail(L);
	LinkList l1 = (LinkList)malloc(sizeof(Node));
	l1->data = e;
	l1->next = NULL;
	tail->next = l1;
}

//delete node by valves
void delbyVal(LinkList L, ElemType target)
{
	LinkList p = L;
	while (p->next != NULL && p->next->data != target)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		printf("NOT FOUND");
		return;
	}
	LinkList del = p->next;
	p->next = p->next->next;
	free(del);
}

//get length
int getlength(LinkList L)
{
	int count = 0;
	while (L->next != NULL)
	{
		count++;
		L = L->next;
	}
	return count;
}

//get element by position
LinkList Getelem(LinkList L, int p)
{
	if (p < 1)
		return NULL;
	LinkList l=L->next;
	int j = 1;
	while (l != NULL && j < p)
	{
		l = l->next;
		j++;
	}
	return l;
}

int main()
{
	LinkList list = iniList();
	headinsert(list, 10);
	headinsert(list, 20);
	headinsert(list, 30);
	endinsert(list, 5);
	ListNode(list);
}