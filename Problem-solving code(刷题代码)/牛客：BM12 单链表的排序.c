#define _CRT_SECURE_NO_WARNINGS 1

//https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08?tpId=295&tqId=1008897&ru=/exam/intelligent&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fintelligent
//˼·��ʹ���� "����ָ��" �������ҵ�������м�ڵ㣬Ȼ��ݹ�ض����ߵ���������������ϲ���������õ�����

// �ϲ����������������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummyNode = { 0, NULL };
    struct ListNode* tail = &dummyNode;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    }
    else {
        tail->next = l2;
    }

    return dummyNode.next;
}
struct ListNode* sortInList(struct ListNode* head) {
    // write code here
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Ѱ���м�ڵ�
    struct ListNode* slow = head, * fast = head, * prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // �Ͽ�����
    prev->next = NULL;

    // �����������ֱַ�ݹ�����
    struct ListNode* left = sortInList(head);
    struct ListNode* right = sortInList(slow);

    // �ϲ�������
    return mergeTwoLists(left, right);
}