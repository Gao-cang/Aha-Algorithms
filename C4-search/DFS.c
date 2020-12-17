#include<stdio.h>
#include<stdlib.h>

int a[10],book[10],n;

void dfs(int step){
    int i;
    if(step==n+1){//输出条件：走完已有的格子了
        for(i=1;i<=n;i++){
            printf("%d",a[i]);
        }
        printf("\n");

        return;
    }

    for(i=1;i<=n;i++){
        if(book[i]==0){
            a[step]=i;
            book[i]=1;

            dfs(step+1);
            book[i]=0;
        }
    }
    //return;
}

int main(){
    scanf("%d", &n);
    dfs(1);
    system("pause");
    return 0;
}