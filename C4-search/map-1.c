//随机降落在一个点上，求所在岛屿的面积，使用广度优先搜索

#include<stdio.h>
#include<stdlib.h>

struct note{
    int x;
    int y;
};

int main(){
    struct note que[2501];
    int head,tail;
    int a[51][51]={
        {1,2,1,0,0,0,0,0,2,3},
        {3,0,2,0,1,2,1,0,1,2},
        {4,0,1,0,1,2,3,2,0,1},
        {3,2,0,0,0,1,2,4,0,0},
        {0,0,0,0,0,0,1,5,3,0},
        {0,1,2,1,0,1,5,4,3,0},
        {0,1,2,3,1,3,6,2,1,0},
        {0,0,3,4,8,9,7,5,0,0},
        {0,0,0,3,7,8,6,0,1,2},
        {0,0,0,0,0,0,0,0,1,0},
        };
    int book[51][51]={0};
    int i,j,k,sum,max=0,mx,my,n,m,sx,sy,tx,ty;

    int next[4][4]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };

    printf("Enter map-info and start-point:(n m x y)");
    scanf("%d %d %d %d",&n,&m,&sx,&sy);

    //步骤一：队列初始化
    head=1;
    tail=1;
    ////插入起始坐标
    que[tail].x=sx;
    que[tail].y=sy;
    tail++;
    book[sx][sy]=1;//每插入一个坐标都要检查标记，此程序中标记皆为0-1
    sum=1;//目标值开始计数

    //步骤二：开始bfs循环（条件为队列不为空）
    while(head<tail){
        for(k=0;k<=3;k++){
            //步骤二-1：计算下一点坐标
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //步骤二-2：判断是否越界、不循环的条件
            if(tx<0||tx>n-1||ty<0||ty>m-1){
                continue;
            }

            //步骤二-3：判断符合要求的点
            if(a[tx][ty]>0 && book[tx][ty]==0){
                sum++;
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                tail++;
            }
        }
        head++;
    }

    printf("The island have %d areas.", sum);
    system("pause");
    return 0;
}