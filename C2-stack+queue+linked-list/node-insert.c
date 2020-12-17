#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head, *p,*q,*t;
    int i,n,a;
    printf("Enter the lenth:");
    scanf("%d",&n);
    head = NULL;
    printf("Enter th contents:");
    for(i=0;i<n;i++){
        scanf("%d", &a);
        //动态申请一个空间，用来存放当前结点，并用临时指针p指向此结点
        p=(struct node *)malloc(sizeof(struct node));
        p->data=a;//当前数据储存至当前结点的data域中
        p->next=NULL;//设置当前结点的下一结点为空
        if(head==NULL){
            head=p;//如果这是第一个创建的结点，则头指针指向此结点
        }else{
            q->next=p;//如果不是，则上一个结点的指针指向此结点
        }
        q=p;//为下一个数做准备，将代表“上一个结点”的q赋值为这个已经操作完毕的结点
    }

    printf("Now the node is: ");
    t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }

    printf("\nEnter the number to be inserted:");
    scanf("%d", &a);
    t=head;
    while(t!=NULL){
        if(t->next==NULL || t->next->data > a){//当前结点是末尾或下一结点值大于目标时插入
            p=(struct node *)malloc(sizeof(struct node));
            p->data=a;
            p->next=t->next;
            t->next=p;
            break;
        }
        t=t->next;
    }

    printf("\nNow the node is: ");
    t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }

    system("pause");
    return 0;
}