#include<stdio.h>
#include<stdlib.h>
struct note{
    int x;
    int s;
};
int main(){
    struct note que[2501];
    int e[51][51]={0},book[51]={0};
    int head,tail;
    int i,j,n,m,a,b,cur,start,end,flag=0;
    n=5;m=7;start=1;end=5;

    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=99999;
            }
        }
    }

    printf("Enter flight-info(a b):");
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        e[a][b]=1;
        e[b][a]=1;
    }
    /*for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            printf("%6d",e[i][j]);
        }
        printf("\n");
    }*///测试用输出
    head=1;
    tail=1;

    que[tail].x=start;
    que[tail].s=0;
    tail++;
    book[start]=1;

    while(head<tail){
        
        cur=que[head].x;
        for(j=1;j<=n;j++){
            if(e[cur][j]!=99999 && book[j]==0){
                que[tail].x=j;
                que[tail].s=que[head].s+1;
                tail++;
                book[j]=1;
            }

            if(que[tail-1].x==end){
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
        head++;
    }

    printf("At least %d step",que[tail-1].s);
    getchar();getchar();
    return 0;
}
