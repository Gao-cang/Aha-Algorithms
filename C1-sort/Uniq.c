#include<stdio.h>

void Uniq(int *a,int n)
{
    int i;
    printf("%d ",a[0]);
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        printf("%d ",a[i]);
    }
    printf("over\n");
    return;
}

int main()
{
    int a[10] = {15, 20, 20, 32, 40, 40, 67, 89, 300, 400};
    Uniq(a, 10);
    system("pause");
    return 0;
}