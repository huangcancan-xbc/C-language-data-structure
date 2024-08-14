#pragma once
//Single-linked lists��������(SList)
//list:�б�

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//node:�ڵ�
//next:��һ��
//data������
//Singly linked list nodes:������ڵ�(SLLN)

typedef struct SListnode
{
	int data;
	struct SListnode* next;
}SLLN;
//�ȼ��ڣ�
//struct SListnode
//{
//	int data;
//	struct SListnode* next;
//};
//typedef struct SListnode SLLN;

//�ҽڵ�
SLLN* lookup(int x);

// ��̬����һ���ڵ�:Dynamically apply for a node
//SLLN* Da_node(int x);

// �������ӡ
void SList_print(SLLN* phead);


// ������β��	Tail plugging:β��
//void SList_tplug(SLLN* phead, int x);//��
void SList_tplug(SLLN** pphead, int x);//�ԣ�


// �������ͷ��		Header:ͷ��
void SList_header(SLLN** pphead, int x);

// �������βɾ		Tail deletion:βɾ
void SList_tdel(SLLN** pphead);

// ������ͷɾ		Header deleted:ͷɾ
void SList_hdel(SLLN** pphead);

// ���������		Find:����
SLLN* SList_find(SLLN* phead, int x);
//void SList_print_matching(SLLN* phead, int x);

//��ָ���ڵ� pos ֮ǰ����һ���½ڵ�:Inserts a new node before specifying it
void SList_before(SLLN** pphead, SLLN* pos, int x);

//ɾ��ָ���ڵ� pos :Deletes the specified node		
void SList_del(SLLN** pphead, SLLN* pos);

//��after
//��ָ���ڵ� pos ֮�����һ���½ڵ�:Inserts a new node after the specified node
void SList_after(SLLN* pos, int x);

//ɾ��ָ���ڵ� pos ֮��Ľڵ�:Deletes a node after the specified node
void SList_del2(SLLN* pos);

//�������٣�Destroyed������
void Destroyed(SLLN* phead);
//void Destroyed(SLLN** pphead);����
