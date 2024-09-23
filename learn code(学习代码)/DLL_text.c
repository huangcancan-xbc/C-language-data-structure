#define _CRT_SECURE_NO_WARNINGS 1
#include "Double linked list.h"

//Double linked list��˫����

int main() {
    // ��ʼ������
    DLL* list = init_list();

    // ���Կ�������
    printf("�б��ǿյ��� %s\n", empty(list) ? "Yes" : "No");

    // ����ͷ��
    header(list, 10);
    header(list, 20);
    header(list, 30);

    // ��ӡ��������
    printf("ͷ���������б�\n");
    print(list);

    // ����β��
    tail_plug(list, 40);
    tail_plug(list, 50);
    tail_plug(list, 60);

    // ��ӡ��������
    printf("β���������б�\n");
    print(list);

    // ���Բ��뵽ָ��λ��
    insert(list->next->next, 25); // �ڵڶ����ڵ�֮�����25
    printf("�ڵڶ���Ԫ�غ���� 25 ����б�\n");
    print(list);

    // �ٴμ�������Ƿ�Ϊ��
    printf("�б��ǿյ��� %s\n", empty(list) ? "Yes" : "No");

    // ��������ע�⣺ʵ�ʴ�����Ӧʵ�����ٺ�����
    // destroy_list(list); // ����ʵ�����������

    return 0;
}