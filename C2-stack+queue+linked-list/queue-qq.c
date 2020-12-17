#include<stdio.h>

struct queue
{
    int data[100];
    int head;
    int tail;
};

int main()
{
    struct queue q;
    int i;
    q.head=1;
    q.tail=1;
    printf("Enter coded 9 numbers:");
    for(i=1;i<=9;i++)//向队列尾添加数据-先进
    {
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    printf("Decoded:");
    while(q.head<q.tail)
    {
        printf("%d",q.data[q.head]);//从队列头开始操纵-先出
        q.head++;

        q.data[q.tail] = q.data[q.head];
        q.tail++;
        q.head++;
    }
    
    system("pause");
    return 0;
}