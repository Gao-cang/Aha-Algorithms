//运算失败没找到问题
#include<stdio.h>

int main(){
    int dis[10],book[10]={0},i,j,u,v,min;
    int inf=9999999,n=6,m=9;
    //初始化原始地图信息
    int e[6][6]={{0,1,12,inf,inf,inf},
        {inf,0,9,3,inf,inf},
        {inf,inf,0,inf,5,inf},
        {inf,inf,4,0,13,15},
        {inf,inf,inf,inf,0,4},
        {inf,inf,inf,inf,inf,0}
    };
    //初始化dis数组
    for(i=0;i<n;i++){
        dis[i]=e[1][i];
    }
    //book数组初始化
    for(i=0;i<n;i++){
        book[i]=0;
    }book[0]=1;

    //Dijkstra算法
    for(i=0;i<n-1;i++){
        min=inf;
        for(j=0;j<n;j++){
            if(book[j]==0 && dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(v=0;v<n;v++){
            if(e[u][v]<inf){
                if(dis[v]>dis[u]+e[u][v]){
                    dis[v]=dis[u]+e[u][v];
                }
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d ",dis[i]);
    }

    getchar();getchar();
    return 0;
}