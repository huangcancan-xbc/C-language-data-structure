#define _CRT_SECURE_NO_WARNINGS 1
#include  "stack.h"

//��ʼ��ջ�������ڴ沢��ʼ��Stack�ṹ�塣
void STInit(ST* p)
{
	assert(p);

	p->a = (int*)malloc(sizeof(int) * 4);

	if (p->a == NULL) { // �������ʧ��
		perror("malloc fail");
		return;
	}

	p->capacity = 4; // ����ջ�ĳ�ʼ����
	p->top = -1;//top��ջ��Ԫ��λ��
	//p->top=0; //top ���߶�Ԫ�ص���һ��λ��
}


// ����ջ���ͷ��ڴ档
//���һ�����������Ԫ�أ�ǰ�ĸ�����ֵ�����һ��Ԫ�صĿռ䱻�ͷŵ��ˣ���ô���������Ȼ�����Ԫ�ء�
// �ͷ��ڴ���ָ�ͷ��˸�Ԫ����ռ�õĵ�ַ�ռ䣬��������ı����鱾��Ĵ�С��
// ��ˣ���ʹ���һ��Ԫ�ص��ڴ汻�ͷţ�����Ĵ�С��Ȼ�����Ԫ�ء��������ͷź��Ԫ�ز����ٱ����ʣ�������ܵ���δ������Ϊ��
void STDestroy(ST* p)
{
	assert(p);
	free(p->a);
	p->a = NULL;
	p->top = -1;
	p->capacity = 0;
}


//��������Ԫ��ѹ��ջ�С�
void STPush(ST* p, int x)
{
	assert(p);

	if (p->top == p->capacity)
	{
		int* temp = (int*)realloc(p->a, sizeof(int) * p->capacity * 2);// ���·���˫���ռ�

		if (temp == NULL)
		{
			perror("realloc fail");
			return;
		}

		p->a = temp;//����ָ��
		p->capacity *= 2;//��������
	}

	p->a[++p->top] = x;// ѹ����Ԫ�ص�ջ��( a[p->top++] )
}


//����ջ��Ԫ�ء�
void STPop(ST* p)
{
	assert(p);//���ջΪ�գ����Ե���ջ��Ԫ�ػᵼ��δ�������Ϊ��
	assert(!STEmpty(p)); // ���ջ�Ƿ�����

	p->top--;
}


//����ջ��Ԫ�ص�������
int STSize(ST* p)
{
	assert(p);
	return p->top;
}


//�ж�ջ�Ƿ�Ϊ�ա�
bool STEmpty(ST* p)
{
	assert(p);
	return p->top == -1;//���ջΪ�գ��򷵻�true�����򷵻�false
}


//��ȡջ��Ԫ�ص�ֵ��
int STTop(ST* p)
{
	assert(p);
	assert(!STEmpty(p));//���ջΪ�գ����Ի�ȡջ��Ԫ�ػᵼ��δ�������Ϊ��
	return p->a[p->top];
	//return ps->a[ps->top - 1];
}