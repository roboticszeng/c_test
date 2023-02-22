#include "stdio.h"

void changeArray(const int *p, int len, int *p_out);

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int a_out[100];
    printf("%d\n", sizeof(a));
    changeArray(a, sizeof(a) / sizeof(int), a_out);
    for(unsigned int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("a[i] = %d\n", a_out[i]);
    }
}

void changeArray(const int *p, int len, int *p_out)
{
    for(unsigned int i = 0; i < len; i++)
    {
        p_out[i] = p[i];
    }
}


