#define _CRT_SECURE_NO_WARNINGS 1
//list:�б�
//text:����

#include "SList.h"

//��һ�β��ԣ�
void text1()
{
	//�˴������Ӧ SList.c �ļ� 51 �� 119 �У�����������ͬʱȡ��ע�ͣ�������ȷ����ע�͵����ɲ鿴����Ч����
	/*SLLN* plist = NULL;
	SList_tplug(plist, 1);
	SList_tplug(plist, 2);
	SList_tplug(plist, 3);
	SList_tplug(plist, 4);
	SList_tplug(plist, 5);*/

	//���ı�ʵ��ֱ�Ӵ���Ҫ�ı䴫��ַ��
	
	//��ȷд����Ҫ����ַ������
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);//���ı�ʵ��ֱ�Ӵ���Ҫ�ı䴫��ַ��

}

//�ڶ��β��ԣ�
void text2()
{
	SLLN* plist = NULL;
	SList_header(&plist, 1);
	SList_header(&plist, 2);
	SList_header(&plist, 3);
	SList_header(&plist, 4);
	SList_header(&plist, 5);

	SList_print(plist);

	SList_tdel(&plist);
	SList_print(plist);

	SList_tdel(&plist);
	SList_print(plist);

	SList_tdel(&plist);
	SList_print(plist);
}

//�����β��ԣ�
void text3()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);
}

//���Ĵβ��ԣ�
void text4()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);

	//ֵΪ2���Ǹ��ڵ� *2
	SLLN* temp = SList_find(plist, 2);
	temp->data *= 2;
	SList_print(plist);

}

//����β��ԣ�
void text5()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);

	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);
	// ֵΪ2�Ǹ��ڵ�  *2
	SLLN* temp = SList_find(plist, 2);
	SList_before(&plist, temp, 20);
	SList_print(plist);

}

//�����β��ԣ�
void text6()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);

	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);
	// ֵΪ2�Ǹ��ڵ�  *2
	SLLN* temp = SList_find(plist, 2);
	SList_del(&plist, temp);
	temp = NULL;//�˴��ÿգ����߱��ü���

	SList_print(plist);

	Destroyed(plist);
	plist = NULL;
	//���ߣ� ����void Destroyed(SLLN** pphead); ��Чʱ ��������
	//Destroyed(&plist);
	//plist = NULL;
}

int main()
{
	//ÿ�ο�һ�����ԣ�Ҳ������д�������ݣ�
	//text1();
	//text2();
	text3();
	//text4();
	//text5();
	//text6();
	return 0;
}