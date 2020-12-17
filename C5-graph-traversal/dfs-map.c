#include<stdio.h>

int min=99999999,book[101],n;
int e[50][50];

void dfs(int cur,int dis){
    int j;
    if(dis>min){
        return;
    }
    if(cur==n){
        if(dis<min){
            min=dis;
            return;
        }
    }
    for(j=1;j<=n;j++){
        if(e[cur][j]!=999999 && book[j]==0){
            book[j]=1;
            dfs(j,dis+e[cur][j]);
            book[j]=0;
        }
    }
    return;
}

int main(){
    int i,j,m,a,b,c;
    printf("Enter map-info(nm):");
    scanf("%d %d",&n,&m);

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=99999;
            }
        }
    }
    printf("Enter road-info(a b c):");
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        e[a][b]=c;
    }

    book[1]=1;
    dfs(1,0);
    printf("%d",min);
    getchar();getchar();
    return 0;
}