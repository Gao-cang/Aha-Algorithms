#include<stdio.h>
#include<stdlib.h>
int n,m,p,q,min=99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step){
    int next[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0},
    };
    int tx,ty,k;//tx,ty为下一步的坐标，k为循环标识
    //判断是否到达目的地
    if(x==p&&y==q){
        if(step<min){
            min=step;
        }
        return;
    }
    //枚举四个方向的走法
    for(k=0;k<=3;k++){
        tx = x+next[k][0];
        ty = y+next[k][1];
        //判断是否越界
        if(tx<1||tx>n||ty<1||ty>m){
            continue;
        }
        //判断下一个点是否是障碍物，或者已经在路径中（掉头、绕回）
        if(a[tx][ty]==0 && book[tx][ty]==0){
            book[tx][ty]=1;//先将此点标记
            dfs(tx,ty,step+1);
            book[tx][ty]=0;//关于此点的尝试结束后将此点取消标记
        }
    }
    return;
}

int main(){
    int i,j,startx,starty;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d %d %d", &startx,&starty,&p,&q);

    book[startx][starty]=1;
    dfs(startx,starty,0);

    printf("At least %d step", min);
    system("pause");
    return 0;
}