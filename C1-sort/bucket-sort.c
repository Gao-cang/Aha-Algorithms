#include<stdio.h>

int main()
{
    int a[11],i,j,t;
    for(i = 0; i <= 10;i++)
    {
        a[i]=0;//create 10 buckect
    }
    printf("Enter the score:\n");
    for (i = 1; i <= 5;i++)
    {
        scanf("%d", &t);
        a[t]++;//throw marks into bucket on basis of No.
    }
    for ( i = 0; i <= 10; i++)//reverse:for(i=10;i>=0;i--)
    {
        for (j = 1; j <= a[i];j++)
        {
            printf("%d ", i);
        }
    }
    system("pause");
    return 0;
}