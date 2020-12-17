//随机降落在一个点上，对所在岛屿着色，使用深度优先搜索

#include<stdio.h>
#include<stdlib.h>

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
int book[51][51]={0},n,m,sum;

void dfs(int x,int y,int color){
    int next[4][4]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    int k,tx,ty;

    a[x][y]=color;

    for(k=0;k<=3;k++){
        //步骤二-1：计算下一点坐标
        tx=x+next[k][0];
        ty=y+next[k][1];

        //步骤二-2：判断是否越界、不循环的条件
        if(tx<0||tx>n-1||ty<0||ty>m-1){
            continue;
        }

        //步骤二-3：判断符合要求的点
        if(a[tx][ty]>0 && book[tx][ty]==0){
            sum++;
            book[tx][ty]=1;
            dfs(tx,ty,color);
        }
    }
}

int main(){
    
    int i,j,sx,sy;

    printf("Enter map-info and start-point:(n m x y)");
    scanf("%d %d %d %d",&n,&m,&sx,&sy);

    book[sx][sy]=1;
    sum=1;
    dfs(sx,sy,-1);
    
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    
    system("pause");
    return 0;
}