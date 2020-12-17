#include<stdio.h>
int main()
{
    int book[1001],i,j,t,n;
    for(i=0;i<=1000;i++)
    {
        book[i] = 0;
    }
    printf("How many numbers here:");
    scanf("%d", &n);
    printf("Enter numbers:");
    for(i=1;i<=n;i++)
    {
        scanf("%d", &t);
        book[t]++;
    }
    printf("sorted:\n");
    for(i=1000;i>=0;i--)
    {
        for(j=1;j<=book[i];j++)
        {
            printf("%d ",i);
        }
    }
    getchar();getchar();
    return 0;
}