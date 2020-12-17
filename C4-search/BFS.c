#include<stdio.h>
#include<stdlib.h>

struct note{
    int x;//横坐标
    int y;//纵坐标
    int f;//父亲在队列中的序号（广度优先搜索形成树结构）
    int s;//步数
};

int main(){
    struct note que[2501];//地图大小不超过50*50，则队列扩展不超过2500
    int a[51][51]={0}, book[51][51]={0};//地图 和 标记数组（防止一个点被重复扩展）
    //建立方向数组
    int next[4][2]={
        {0,1},//右
        {1,0},//左
        {0,-1},//上
        {-1,0}//下
    };

    int head,tail;
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;

    printf("Enter map info(n n):");
    scanf("%d %d",&n,&m);//输入地图长宽
    printf("Enter map:");
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);//依次输入地图数据
        }
    }
    printf("Enter startpoint and endpoint(n n n n):");
    scanf("%d %d %d %d",&startx,&starty,&p,&q);//初始点与目的地
    //初始化队列
    head=1;
    tail=1;
    //往队列插入迷宫入口坐标
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[startx][starty]=1;
    
    flag=0;//标记-是否到达目的地
    //队列不为空时循环
    while(head<tail){
        for(k=0;k<=3;k++){
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            if( tx<1 || tx>n ||ty<1||ty>m){//先判断是否走出地图，走出则跳过此循环节
                continue;
            }
            if(a[tx][ty]==0 && book[tx][ty]==0){//再判断是否遇见障碍或回到原路，否则往下走一步
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].f=head;
                que[tail].s=que[head].s+1;
                tail++;
            }
            if(tx==p && ty==q){//最后判断是否到达
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
        head++;//按步尝试的关键，每一步切换head求tail
    }
    //打印队列末（目标点）的步数
    printf("At least %d step",que[tail-1].s);//tail指向的是下一个空的位置

    system("pause");
    return 0;
}


