#include<stdio.h>

struct student
{
    char name[21];
    int score;
};

int main()
{
    struct student a[100],t;    
    int i,j,n;
    printf("How many students here:");
    scanf("%d", &n);
    printf("Enter the numbers:");
    for(i=1;i<=n;i++)
    {
        scanf("%s %d",a[i].name, &a[i].score);
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j].score < a[j+1].score)
            {
                t=a[j+1];a[j+1]=a[j];a[j]=t;
            }
        }
    }
    printf("sorted:");
    for(i=1;i<=n;i++)
    {
        printf("%s\n",a[i].name);
    }
    system("pause");
    return 0;
}