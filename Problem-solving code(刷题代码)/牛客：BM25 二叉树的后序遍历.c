#define _CRT_SECURE_NO_WARNINGS 1

//ţ�ͣ�BM25 �������ĺ������
//https://www.nowcoder.com/practice/1291064f4d5d4bdeaefbf0dd47d78541?tpId=295&tqId=2291301&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

//˼·����1����������������Ľڵ������
//��2�����ݽڵ����������a���ٶ�̬�ռ䣬
//��3��ָ��i ָ�� i �ĵ�ַ��i ��ֵ��Ϊ����a���±ꡣ

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
    // ����ڵ�Ϊ�գ��򷵻�0
}

void postorder(struct TreeNode* root, int* a, int* i)
{
    // ����ڵ�Ϊ�գ���ֱ�ӷ���
    if (root == NULL)
    {
        return;
    }
    postorder(root->left, a, i);// �ݹ����������
    postorder(root->right, a, i);// �ݹ����������
    a[(*i)++] = root->val;// ����ǰ�ڵ��ֵ��������ĵ�ǰ����λ�ã���ʹ��������

}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // write code here
    (*returnSize) = size(root);// ��ȡ���Ĵ�С
    int* a = (int*)malloc(sizeof(int) * (*returnSize));// ��̬���������Ա���������

    int i = 0;// ��ʼ����������
    postorder(root, a, &i);// ��ʼ���������������洢��������

    return a;// ���ؽ������
}