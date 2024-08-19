#define _CRT_SECURE_NO_WARNINGS 1
#include "Double linked list.h"

//Double linked list��˫����

//����һ���µĽڵ㣺Create a new node
DLL* Cnew_node(int x)
{
	DLL* newnode = (DLL*)malloc(sizeof(DLL));
	if (newnode == NULL)
	{
		perror("malloc fail");
		//exit(-1);//��������ڴ�ʧ�ܣ�����ֹ����
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}


//��ʼ���յ�˫��ѭ����������ָ��ͷ����ָ�룬initialize����ʼ��
DLL* init_list()
{
	DLL* phead = Cnew_node(-1);

	phead->next = phead;
	phead->prev = phead;

	return phead;
}


//��ӡ��������
void print(DLL* phead)
{
	assert(phead);

	printf("<->head<->");
	DLL* temp = phead->next;

	while (temp != phead)
	{
		printf("%d<->", temp->data);
		temp = temp->next;
	}

	printf("\n");
}


//��������Ƿ�Ϊ��:Check if the linked list is empty
bool empty(DLL* phead)
{
	assert(phead);

	return phead->next == phead;
}


//β�壺Tail plugging
void tail_plug(DLL* phead, int x)
{
	assert(phead);

	insert(phead, x);
}


//ͷ�壺Header
void header(DLL* phead, int x)
{
	assert(phead);

	insert(phead->next, x);
}


//�ڸ�����λ�� pos ����һ������ x ���½ڵ�:Insert a new node containing x at the given location pos
void insert(DLL* pos, int x)
{
	assert(pos); // ȷ�� pos ���� NULL

	DLL* prev = pos->prev; // ��ȡ pos �ڵ��ǰһ���ڵ�
	DLL* newnode = Cnew_node(x); // ����һ���������� x ���½ڵ�

	// ���� prev �ڵ�� next ָ�룬ʹ��ָ���½ڵ�
	prev->next = newnode;

	// �����½ڵ�� prev ָ�룬ʹ��ָ�� prev �ڵ�
	newnode->prev = prev;

	// �����½ڵ�� next ָ�룬ʹ��ָ�� pos �ڵ�
	newnode->next = pos;

	// ���� pos �ڵ�� prev ָ�룬ʹ��ָ���½ڵ�
	pos->prev = newnode;
}


