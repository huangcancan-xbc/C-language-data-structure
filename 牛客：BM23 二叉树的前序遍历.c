#define _CRT_SECURE_NO_WARNINGS 1

//ţ�ͣ�BM23 ��������ǰ�����
//https://www.nowcoder.com/practice/5e2135f4d2b14eb8a5b06fab4c938635?tpId=295&tqId=2291302&ru=/exam/intelligent&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fintelligent

//˼·����1����������������Ľڵ������
//��2�����ݽڵ����������a���ٶ�̬�ռ䣬
//��3��ָ��i ָ�� i �ĵ�ַ��i ��ֵ��Ϊ����a���±ꡣ

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
    // ����ڵ�Ϊ�գ��򷵻�0
}

void preorder(struct TreeNode* root, int* a, int* i)
{
    // ����ڵ�Ϊ�գ���ֱ�ӷ���
    if (root == NULL)
    {
        return;
    }

    a[(*i)++] = root->val;// ����ǰ�ڵ��ֵ��������ĵ�ǰ����λ�ã���ʹ��������
    preorder(root->left, a, i);// �ݹ����������
    preorder(root->right, a, i);// �ݹ����������
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    (*returnSize) = size(root);// ��ȡ���Ĵ�С
    int* a = (int*)malloc(sizeof(int) * (*returnSize));// ��̬���������Ա���������

    int i = 0;// ��ʼ����������
    preorder(root, a, &i);// ��ʼ���������������洢��������
    return a;// ���ؽ������
}