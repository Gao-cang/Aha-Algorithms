#include<stdio.h>
int main(){
    int n,m,i,j,k,min,t1,t2,t3;
    int e[7][7],dis[7],book[7]={0};//对book数组进行了初始化
    int inf=999999;//用inf存储一个我们认为的正无穷值
    int count=0,sum=0;//count用来记录生成树中顶点的个数，sum用来存储路径之和

    //读入n和m，n表示顶点个数，m表示边的条数
    printf("Enter (n m):");
    scanf("%d %d",&n,&m);

    //初始化
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]!=inf;
            }
        }
    }

    //开始读入边
    printf("Enter (t1 t2 t3):");
    for(i=1;i<=m;i++){
        scanf("%d %d %d", &t1,&t2,&t3);
        e[t1][t2]=t3;//无向图，来回都要存储
        e[t2][t1]=t3;
    }

    //初始化dis数组，这里是1号顶点到各个顶点的初始距离，当前最小生成树只有1号顶点
    for(i=1;i<=n;i++){
        dis[i]=e[1][i];
    }

    //Prim核心部分
    //将1号顶点加入生成树
    book[1]=1;//这里用book来标记一个顶点是否已经加入生成树
    count++;
    while(count<n){
        min=inf;
        for(i=1;i<=n;i++){
            if(book[i]==0 && dis[i]<min){
                min=dis[i];
                j=i;
            }
        }
        book[j]=1;
        count++;
        sum=sum+dis[j];
        //扫描当前顶点j所有边，再以j为中心点，更新生成树到每一个非树顶点的距离
        for(k=1;k<=n;k++){
            if(book[k]==0 && dis[k]>e[j][k]){
                dis[k]=e[j][k];
            }
        }
        printf("%d",sum);
        getchar();getchar();
        return 0;
    }
}