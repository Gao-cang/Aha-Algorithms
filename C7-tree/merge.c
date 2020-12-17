#include<stdio.h>

int f[1000]={0},n,m,k,sum=0;
//初始化，数组里存的是自己数组下标
void init(){
    int i;
    for(i=1;i<=n;i++){
        f[i]=i;
    }
    return;
}
//通过递归不停找“父亲”
int getf(int v){
    if(f[v]==v){
        return v;
    }else{
        f[v]=getf(f[v]);//路径压缩，每次返回时回归到“祖宗”，提高后续运算的速度
        return f[v];
    }
}
//合并两个子集的函数
void merge(int v,int u){
    int t1,t2;//t1，t2分别是v和u的大boss，每次双方会谈必须是各自最大boss
    t1=getf(v);
    t2=getf(u);
    if(t1!=t2){//判断两个点是否在同一个集合中（是否为同一祖宗）
        f[t2]=t1;//靠左原则，右集合变成左集合的子集。压缩路径后，f[u]的根的值也赋为v的祖先f[t1]
    }
    return;
}

int main(){
    int i,x,y;
    printf("Enter (n m):");
    scanf("%d %d",&n,&m);

    init();
    printf("Enter (x y):");
    for(i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        merge(x,y);
    }
    for(i=1;i<=n;i++){
        if(f[i]==i){
            sum++;
        }
    }
    printf("Totally %d group.\n",sum);
    getchar();getchar();
    return 0;
}