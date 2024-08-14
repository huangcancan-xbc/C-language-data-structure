#define _CRT_SECURE_NO_WARNINGS 1
//Single-linked lists��������
//Singly linked list nodes:������ڵ�(SLLN)
//list:�б�
//head:ͷ
//tail:β��β��
//temp:��ʱ��

#include "SList.h"

// �������ӡ
//����ʹ�ö���ָ�룬��û��Ҫ��Ҫ�ı�ʵ���ö��������ı���һ�������Լ� const�������飬�����һЩ����Ҫ���鷳��
void SList_print(SLLN* phead)
{
	//�˴��в��ɶ��ԣ�assert������������Դ�ӡ���˴�ʹ�ö��Ի���ֹ����
	//(������Ϊ�գ��˴�ָ�루phead��Ϊ�ա�˳���˴�����ԣ�assert����˳�����һ���ṹ�壬�ṹ������һ��ָ��ָ��һ������ռ䣬�ṹ��ָ��Ϊ�գ�������߲�����)

	SLLN* temp = phead;
	//ע�⣺�в���д�� while (temp->next != NULL),���һ�������޷���ӡ��
	 
	//��ȷд����
	//while (temp != NULL)
	while (temp)
	{
		printf("%d->", temp->data);
		temp = temp->next;
		//temp++/++temp,ע�⣺�в��ɼӼӣ��ڵ��ַ���ܱ�֤������
	}

	printf("NULL\n");
}

//��ȡһ��������������һ���½ڵ�,lookup������
//�������ȫ����������void SList_tplug(SLLN** pphead, int x)������ 122-135 �� 
SLLN* lookup(int x)
{
	SLLN* newnode = (SLLN*)malloc(sizeof(SLLN)); // newnode: �½ڵ�
	if (newnode == NULL) // ���
	{
		perror("malloc fail");
		return NULL; // ���� NULL ��ʾʧ��
	}

	// �½ڵ��ʼ��Ϊ��
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

////��Ȼ�Ǵ���Ҫ������ȡ��ѵ�������ܽ���ۣ����������ؿ������ע�Ͳ��֣�������
//// ������β��	Tail plugging:β��
//void SList_tplug(SLLN* phead, int x)
//{
//	//�˴��в��ɶ��ԣ�assert��������Ϊ�գ�ָ�루phead��Ϊ�գ��˴�ʹ�ö��Ի���ֹ����
//
//	SLLN* newnode = (SLLN*)malloc(sizeof(SLLN));//newnode:�½ڵ�
//	if (newnode == NULL)//���
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	//�½ڵ��ʼ��Ϊ��
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//��β��β��ı��ʣ�ԭβ�ڵ���Ҫ�洢�µ�β�ڵ��ַ
//		//"��ȷ"д��(����ڴ����������������������֣��д�)��
//		SLLN* tail = phead;//tail:β
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;//�������ڣ�
//
//		//����д����
//		//SLLN* tail = phead;//tail:β
//		//while (tail != NULL)
//		//{
//		//	tail = tail->next;
//		//}
//		//tail = newnode;
//		//ԭ�򣺺���ջ֪֡ʶ��tail�Ǿֲ�������֮������٣�
//	}
//}//������������ԭ��
////��Աȣ�
////
////void temp(int *p)						void temp(int *ptr)
////{										{
////	*p = 1;									ptr = (int*)malloc(sizeof(int));
////}										}
////int main()				    ��			int main()
////{							��			{
////	int x = 0;				��				int* px=NULL;
////	temp(&x);								temp(px);
////
////	return 0;								return 0;
////}										}
////
////�ı����int��ʹ�õ���int��ָ�룻�ı�int*Ҫʹ��int*�ĵ�ַ��int**ָ�룡����
////����Ҫ�ı�*ptr��ʹ�õ���*ptr��ָ��
////����
////int main()
////{
////	int* px = NULL;
////	Func(&px);
////
////	free(px);
////
////	return 0;
////}
////��ȷ�ĺ���д����
void SList_tplug(SLLN** pphead, int x)
{
	//Ϊ��ʹ�� 35 �е� lookup �������� 122 �� 135 ��ע�͵����ĳ� 137 �е� SLLN* newnode = lookup(x);
	
	////�˴��в��ɶ��ԣ�assert��������Ϊ�գ�ָ�루phead��Ϊ�գ��˴�ʹ�ö��Ի���ֹ����

	//SLLN* newnode = (SLLN*)malloc(sizeof(SLLN));//newnode:�½ڵ�
	//if (newnode == NULL)//���
	//{
	//	perror("malloc fail");
	//	return;
	//}

	////�½ڵ��ʼ��Ϊ��
	//newnode->data = x;
	//newnode->next = NULL;

	SLLN* newnode = lookup(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β��β��ı��ʣ�ԭβ�ڵ���Ҫ�洢�µ�β�ڵ��ַ

		SLLN* tail = *pphead;//tail:β
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;//�������ڣ��������ı�ָ�룬�ı�ṹ���Ա����һ��ָ�룬����ջ֡��֪ʶҪ���ڣ�������
	}
}



// �������ͷ��		Header:ͷ��
void SList_header(SLLN** pphead, int x)
{
	assert(pphead);

	SLLN* newnode = lookup(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

// �������βɾ		Tail deletion:βɾ
void SList_tdel(SLLN** pphead)
{
	////����д����
	//SLLN* tail = *pphead;
	//while (tail->next != NULL)
	//{
	//	tail = tail->next;
	//}

	//free(tail);
	//tail = NULL;//����ԭ�򣺴���tail�Ǿֲ�������û�а�ǰһ��next�ڵ��ÿգ�ǰһ���ڵ���һ���ṹ�壬Ҫ��ǰһ���ṹ��ڵ��ÿգ���Ҫһ���ṹ���ָ�룡
	
	//����ѡһ
	//�����ļ��
	assert(pphead);
	assert(*pphead);//����assert(*pphead!=NULL);
	//����ļ��
	//if (*pphead == NULL)
	//{
	//	return;
	//}

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��ȷд��1��
		SLLN* temp = NULL;
		SLLN* tail = *pphead;
		while (tail->next != NULL)
		{
			temp = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		temp->next = NULL;

		//��ȷд��2��
		//SLLN* tail = *pphead;
		//while (tail->next->next != NULL)
		//{
			//tail = tail->next;
		//}

		//free(tail->next);
		//tail->next = NULL;
	}
}

// ������ͷɾ		Header deleted:ͷɾ
void SList_hdel(SLLN** pphead)
{
	//����ѡһ
	//�����ļ��
	assert(pphead);
	assert(*pphead);//����assert(*pphead!=NULL);
	//����ļ��
	//if (*pphead == NULL)
	//{
	//	return;
	//}

	SLLN* first = *pphead;//first:��һ
	*pphead = first->next;
	free(first);
	first = NULL;
}

// ���������		Find:����
SLLN* SList_find(SLLN* phead, int x)
{
	SLLN* temp = phead;

	while (temp)
	{
		if (temp->data == x)
		{
			return temp;
		}

		temp = temp->next;//����temp
	}
	return NULL;
}
//����ʹ�ò��Ҵ�ӡ������
//void SList_print_matching(SLLN* phead, int x)
//{
//	SLLN* temp = phead;
//	int found = 0; // ����Ƿ��ҵ���ƥ��Ľڵ�
//
//	while (temp)
//	{
//		if (temp->data == x)
//		{
//			printf("%d ", temp->data); // ��ӡƥ��Ľڵ�����
//			found = 1; // ����ҵ���ƥ��Ľڵ�
//		}
//		temp = temp->next;
//	}
//
//	if (!found)
//	{
//		printf("No matching elements found.\n"); // ���û���ҵ�ƥ��Ľڵ�
//	}
//	else
//	{
//		printf("\n"); // ��ӡ���з���ʹ�����������
//	}
//}


//��ָ���ڵ� pos ֮ǰ����һ���½ڵ�:Inserts a new node before specifying it
void SList_before(SLLN** pphead, SLLN* pos, int x)
{
	assert(pos);
	assert(pphead);

	if (pos == *pphead)
	{
		SList_header(pphead, x);
	}
	else
	{
		//��pos��ǰһ��λ��
		SLLN* temp = *pphead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}

		SLLN* newnode = lookup(x);
		temp->next = newnode;
		newnode->next = pos;
	}
}

//ɾ��ָ���ڵ� pos :Deletes the specified node		
void SList_del(SLLN** pphead, SLLN* pos)
{
	assert(pphead);
	assert(pos);
	//assert(*pphead);��Ҫ�ɲ�Ҫ

	if (*pphead == pos)
	{
		SList_hdel(pphead);
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLLN* temp = *pphead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}

		temp->next = pos->next;
		free(pos);

		//pos=NULL;û�ã���Ϊ�ββ��ı�ʵ�Σ���Ӧtext6��
	}
}

//��after
//��ָ���ڵ� pos ֮�����һ���½ڵ�:Inserts a new node after the specified node
void SList_after(SLLN* pos, int x)
{
	//������󣡣���
	//assert(pos);
	//SLLN* newnode = lookup(x);
	//pos->next = newnode;
	//newnode->next = pos->next;
	//�ڽ� pos �� next ָ��ָ���½ڵ� newnode ֮ǰ�������ȱ��� pos �ڵ����һ���ڵ�ĵ�ַ�������ⲿ��������ʧ��


	//��ȷд����
	assert(pos);
	SLLN* newnode = lookup(x);
	newnode->next = pos->next;//���� pos �ڵ����һ���ڵ�ĵ�ַ
	pos->next = newnode;//�� pos �� next ָ��ָ���½ڵ� newnode
}

//ɾ��ָ���ڵ� pos ֮��Ľڵ�:Deletes a node after the specified node
void SList_del2(SLLN* pos)
{
	assert(pos);
	assert(pos->next);

	//����д�������ɵ������֣���
	//pos->next = pos->next->next;

	//��ȷд��1��
	SLLN* temp = pos->next;
	pos->next = pos->next->next;
	free(temp);
	temp = NULL;

	//��ȷд��2��
	//SLLN* temp = pos->next;
	//pos->next = temp->next;
	//free(temp);
	//temp = NULL;
}

//�������٣�Destroyed������
void Destroyed(SLLN* phead)
{
	//�������
	//����д��1��
	//SLLN* temp = phead;
	//while (temp)
	//{
	//	free(temp);
	//	temp = temp->next;
	//}
	//����д��2��
	//SLLN* temp = phead;
	//while (temp)
	//{
	//	SLLN* tmp = temp;
	//	free(temp);
	//	temp = tmp->next;
	//}


	//��ȷд����
	SLLN* temp = phead;
	while (temp)
	{
		SLLN* tmp = temp->next;
		free(temp);
		temp = tmp;
	}

	//phead=NULL;
}
//���ߣ�
//void Destroyed(SLLN** pphead)
//{
//	assert(pphead);
//	SLLN* temp = *pphead;
//	while (temp)
//	{
//		SLLN* tmp = temp->next;
//		free(temp);
//		temp = tmp;
//	}
//
//	*pphead = NULL;
//}