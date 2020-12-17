//此程序有不懂的问题，书上代码和网友修改的代码都在赢牌的小循环处bug

#include<stdio.h>
#include<stdlib.h>

struct queue//玩家的动作：从前方出牌+赢牌至后方，先进先出的队列结构
{
    int data[1000];
    int head;
    int tail;
};

struct stack//牌堆的动作：堆牌至上方+从上方取牌，先进后出的栈结构
{
    int data[10];
    int top;
};

int main(){
    struct queue q1,q2;
    struct stack s;
    int i, t;
    int book[10];
    //提前初始化队列和栈
    q1.head=1;q1.tail=1;
    q2.head=1;q2.tail=1;
    s.top=0;
    //初始化赢牌判断系统
    for(i=0;i<=9;i++){
        book[i]=0;
    }
    
    printf("Enter 6 cards of Player-1:");
    for (i = 1; i <= 6; i++){
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    printf("Enter 6 cards of Player-2:");
    for (i = 1; i <= 6; i++){
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    //（游戏的获胜条件是两人中一人空队列）所以游戏进行条件：两队列皆不空
    while(q1.head<q1.tail && q2.head<q2.tail){
        t=q1.data[q1.head];
        q1.head++;//P1打出一张牌

        if(book[t]==0){
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }else{
            q1.data[q1.tail]=t;
            q1.tail++;
            while(s.data[s.top]!=t){
                book[s.data[s.top]]==0;
                q1.data[q1.tail]=s.data[s.top];
                q1.tail++;
                s.top--;
            }
            book[s.data[s.top]] =0;
            q1.data[q1.tail]=s.data[s.top];
            q1.tail++;
            s.top--;
        }
        
        if(q1.head==q1.tail){
            break;
        }

        t=q2.data[q2.head];
        q2.head++;//P2打出一张牌，一下所有操作和P1相同

        if(book[t]==0){
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }else{
            q2.data[q2.tail]=t;
            q2.tail++;
            while(s.data[s.top]!=t){
                book[s.data[s.top]]==0;
                q2.data[q2.tail]=s.data[s.top];
                q2.tail++;
                s.top--;
            }
            book[s.data[s.top]] =0;
            q2.data[q2.tail]=s.data[s.top];
            q2.tail++;
            s.top--;
        }
        //不需要再单独判断了，因为此时q1恒成立，q2成立=大循环条件成立
    }

    //胜负输出：空队列者负
    if(q2.head==q2.tail){
        printf("Player-1 win\n");
        printf("His cards is: ");
        for(i=q1.head; i<q1.tail; i++){
            printf("%d ", q1.data[i]);
        }
        if(s.top>0){
            printf("\n  Cards on table are:");
            for(i=0;i<=s.top;i++){
                printf("%d ",s.data[i]);
            }
        }else{
            printf("\n  No cards on table.");
        }
    }else{
        printf("Player-2 win\n");
        printf("His cards is: ");
        for(i=q2.head; i<q2.tail; i++){
            printf("%d ", q2.data[i]);
        }
        if(s.top>0){
            printf("\n  Cards on table are:");
            for(i=0;i<=s.top;i++){
                printf("%d ",s.data[i]);
            }
        }else{
            printf("\n  No cards on table.");
        }
    }

    system("pause");
    return 0;
}
