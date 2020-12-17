#include<stdlib.h>
#include<stdio.h>

int book[101],sum,n,e[101][101];

void dfs(int cur){
    int i;
    printf("%d ",cur);
    sum++;
    if(sum==n){
        return;
    }
    for(i=1;i<=n;i++){//从1号顶点到n号顶点依次尝试，看哪些顶点与当前顶点cur有边相连
        if(e[cur][i]==1&&book[i]==0){//如果本次尝试中未被访问过的点与本次尝试的起点有边相连
            book[i]=1;//就先标记它
            dfs(i);//然后以它为起点开始进一步尝试
        }
    }
    return;
}

int main(){
    int i,j,m,a,b;
    printf("Enter matrix-info(n m):");
    scanf("%d %d",&n,&m);
    //初始化矩阵。不用输入，图自带了点本身，未知的是点之间的关系
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=999999;
            }
        }
    }
    //读入顶点之间的边
    printf("Enter relations(x, y):");
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        e[a][b]=1;
        e[b][a]=1;//无向图，来回的路径都要激活
    }

    book[1]=1;
    dfs(1);

    getchar();getchar();
    return 0;
}