#include<stdio.h>

int main()
{
    int a[100],i,j,t,n;
    printf("How many numbers here:");
    scanf("%d", &n);
    printf("Enter the numbers:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j+1];a[j+1]=a[j];a[j]=t;
            }
        }
    }
    printf("sorted:");
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}