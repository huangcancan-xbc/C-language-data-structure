#define _CRT_SECURE_NO_WARNINGS 1

//ţ�ͣ�BM24 ���������������
//https://www.nowcoder.com/practice/0bf071c135e64ee2a027783b80bf781d?tpId=295&tqId=1512964&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

//˼·����1����������������Ľڵ������
//��2�����ݽڵ����������a���ٶ�̬�ռ䣬
//��3��ָ��i ָ�� i �ĵ�ַ��i ��ֵ��Ϊ����a���±ꡣ

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
    // ����ڵ�Ϊ�գ��򷵻�0
}

void inorder(struct TreeNode* root, int* a, int* i)
{
    // ����ڵ�Ϊ�գ���ֱ�ӷ���
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, a, i);// �ݹ����������
    a[(*i)++] = root->val;// ����ǰ�ڵ��ֵ��������ĵ�ǰ����λ�ã���ʹ��������

    inorder(root->right, a, i);// �ݹ����������
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // write code here
    (*returnSize) = size(root);// ��ȡ���Ĵ�С
    int* a = (int*)malloc(sizeof(int) * (*returnSize));// ��̬���������Ա���������

    int i = 0;// ��ʼ����������
    inorder(root, a, &i);// ��ʼ���������������洢��������

    return a;// ���ؽ������
}