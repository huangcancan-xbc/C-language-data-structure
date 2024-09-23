#define _CRT_SECURE_NO_WARNINGS 1
#include  "stack.h"

int main()
{
    ST* stack = malloc(sizeof(ST));
    if (!stack) {
        perror("malloc failed");
        return 1;
    }

    STInit(stack);
    int i = 1;
    int j = 2;
    int k = 3;

    STPush(stack, i);
    STPush(stack, j);
    STPush(stack, k);

    printf("��ջ����Ԫ����:%d\n", STTop(stack));
    STPop(stack);
    printf("��ջ����Ԫ����:%d\n", STTop(stack));

    STDestroy(stack);
    free(stack);
    return 0;
}