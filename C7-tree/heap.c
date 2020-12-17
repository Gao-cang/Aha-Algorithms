//运算结果有误，但没找到错误
#include<stdio.h>

int h[101],n;//h是存放堆的数组，n是堆的大小

void swap(int x,int y){
    int t;
    t=h[x];
    h[x]=h[y];
    h[y]=t;
    return;
}

void siftdown(int i){//传入一个需要向下调整的结点编号i，开始向下调整
    int t,flag=0;//flag用来标号是否需要继续向下调整
    //当i结点有儿子，并且需要继续调整的时候，循环就执行
    while(i*2<=n && flag==0){
        //首先判断它和左儿子的关系，并用t记录值较小的结点编号
        if(h[i]>h[i*2]){
            t=i*2;
        }else{
            t=i;
        }
        //如果右儿子，再对儿子进行讨论
        if(i*2+1<=n){
            
            if(h[t]>h[i*2+1]){
                t=i*2+1;
            }
        }
        if(t!=i){//如果发现最小的结点编号不是自己，说明子结点中有比父节点更小的
            swap(t,i);//交换他们
            i=t;//更新i为刚才与它交换的儿子节点的编号，便于接下来继续向下调整
        }else{
            flag=1;//否则说明当前的父节点已经比两个儿子节点都要小了，不用再调整了
        }
        return;
    }
}

void siftup(int i){//传入一个需要向上调整的结点编号
    int flag=0;//用来标记是否需要继续向上调整
    if(i==1){
        return;//如果是堆顶，就返回，不需要调整了
    }
    while(i!=1 && flag==0){
        if(h[i]<h[i/2]){//判断是否比父节点小
            swap(i,i/2);//交换与父节点的位置
        }else{
            flag=1;//表示已经不需要再调整了
        }
        i=i/2;//更新编号i为它父节点的编号，从而便于下一次继续向上调整
    }
    return;
}

void create(){
    int i;
    for(i=n/2;i>=1;i--){//从最后一个非叶结点到第1个结点依次进行向下调整
        siftdown(i);
    }
    return;
}

int deletemax(){
    int t;
    t=h[1];//用一个临时变量记录堆顶点的值
    h[1]=h[n];//将堆的最后一个点赋值到堆顶
    n--;//堆的元素减少1
    siftdown(1);//向下调整
    return t;//返回之前记录的堆的顶点的最小值
}

int main(){
    int i,num;
    //读入要排序的数字的个数
    printf("Enter num to be sorted (n):");
    scanf("%d", &num);
    
    printf("Enter heap nums (h[i]):");
    for(i=1;i<=num;i++){
        scanf("%d",&h[i]);
    }
    n=num;

    //变成堆格式
    create();

    //删除顶部元素，连续删除n次，从小到大把数输出出来
    for(i=1;i<=num;i++){
        printf("%d ",deletemax());
    }
    getchar();
    getchar();
    return 0;
}