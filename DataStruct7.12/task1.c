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
	LinkList p = L->next;
	while (p!= 0)
	{
		printf("%d\n", *p);
		p = p->next;
	}
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
	LinkList l1 = (LinkList)malloc(sizeof(Node));
	l1->data = e;
	l1->next = L->next;
	L->next = l1;
}

int main()
{
	LinkList list = iniList();
	headinsert(list, 10);
	headinsert(list, 20);
	headinsert(list, 30);
	endinsert(get_tail(list), 5);
	ListNode(list);
}