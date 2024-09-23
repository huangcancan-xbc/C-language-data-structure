#pragma once
//stack:ջ

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct stack
{
	int capacity;//capacity:����
	int top;//top ���߶�Ԫ�ص���һ��λ��
	int* a;// �洢ջԪ�ص�ָ��
}ST;


//��ʼ��ջ�������ڴ沢��ʼ��Stack�ṹ�塣
void STInit(ST* p);


// ����ջ���ͷ��ڴ档
void STDestroy(ST* p);

//��������Ԫ��ѹ��ջ�С�
void STPush(ST* p, int x);


//����ջ��Ԫ�ء�
void STPop(ST* p);


//����ջ��Ԫ�ص�������
int STSize(ST* p);


//�ж�ջ�Ƿ�Ϊ�ա�
bool STEmpty(ST* p);


//��ȡջ��Ԫ�ص�ֵ��
int STTop(ST* p);