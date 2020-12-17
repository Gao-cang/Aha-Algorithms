#include<stdio.h>
#include<stdlib.h>

int a[51][51];
int book[51][51],n,m,flag=0;
struct note{
    int x;
    int y;
}s[100];
int top;

void dfs(int x,int y,int front){
    int i;
    //判断是否达到终点，y=m+1只到达右下角那一格不够，还要要走出终点前那一格
    if(x==n && y==m+1){
        flag=1;
        for(i=1;i<=top;i++){
            printf("(%d,%d)",s[i].x,s[i].y);
        }
        return;
    }
    //判断是否越界
    if(x<1||x>n||y<1||y>m){
        return;
    }
    //判断这个格子是否已经走过了
    if(book[x][y]==1){
        return;
    }
    //没走过的话，先标记，然后开始本轮运算
    book[x][y]=1;

    //当前尝试的坐标入栈
    top++;
    s[top].x=x;
    s[top].y=y;

    //当前管道是直管的情况
    if(a[x][y]>=5 && a[x][y]<=6){
        if(front==1){
            dfs(x,y+1,1);
        }
        if(front==2){
            dfs(x+1,y,2);
        }
        if(front==3){
            dfs(x,y-1,3);
        }
        if(front==4){
            dfs(x-1,y,4);
        }
    }
    //当前进水口是弯管
    if(a[x][y]>=1 && a[x][y]<=4){
        if(front==1){
            dfs(x+1,y,2);
            dfs(x-1,y,4);
        }
        if(front==2){
            dfs(x,y+1,1);
            dfs(x,y-1,3);
        }
        if(front==3){
            dfs(x-1,y,4);
            dfs(x+1,y,2);
        }
        if(front==4){
            dfs(x,y+1,2);
            dfs(x,y-1,3);
        }
    }
    book[x][y]=0;
    top--;//当前尝试的坐标出栈
    return;
}

int main(){
    int i,j,num=0;
    printf("Enter map-info:");
    scanf("%d %d",&n,&m);

    printf("Enter the map by row:");
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1,1,1);
    if(flag==0){
        printf("Impossible\n");
    }else{
        printf("Find solution");
    }
    system("pause");
    return 0;
}