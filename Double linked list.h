#pragma once
//Double linked list��˫����

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct Double_linked_list
{
	struct Double_linked_list* prev;
	int data;
	struct Double_linked_list* next;
}DLL;

//����һ���µĽڵ㣺Create a new node
DLL* Cnew_node(int x);


//��ʼ���յ�˫��ѭ����������ָ��ͷ����ָ�룬initialize����ʼ��
DLL* init_list();


//��ӡ��������
void print(DLL* phead);


//��������Ƿ�Ϊ��:Check if the linked list is empty
bool empty(DLL* phead);


//β�壺Tail plugging
void tail_plug(DLL* phead, int x);


//ͷ�壺Header
void header(DLL* phead, int x);


//�ڸ�����λ�� pos ����һ������ x ���½ڵ�:Insert a new node containing x at the given location pos
void insert(DLL* pos, int x);