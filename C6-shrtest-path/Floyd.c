#include<stdio.h>
int main(){
    int k,i,j,inf=9999999;
    int e[5][5]={
        {0,2,6,4},
        {inf,0,3,inf},
        {7,inf,0,1},
        {5,inf,12,0}
    };
    
    for(k=3;k>=0;k--){//修改遍历顺序后没有出现错误
        for(i=3;i>=0;i--){
            for(j=3;j>=0;j--){
                if(e[i][j]>e[i][k]+e[k][j]){
                    e[i][j]=e[i][k]+e[k][j];
                }
            }
        }
    }
    
   //这里发现一个重大问题，由于写书者习惯从1开始循环，所以直接赋值的数组第一行第一列都会出问题
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%5d",e[i][j]);
        }
        printf("\n");
    }
    getchar();getchar();
    return 0;
}