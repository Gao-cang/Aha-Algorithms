#include<stdio.h>
#include<stdlib.h>

int main(){
    int data[101], right[101];
    int i,n,t,len;
    
    //输入数据储存在数组-1中
    printf("Enter th length:");
    scanf("%d", &n);
    printf("Enter the numbers:");
    for(i=1;i<=n;i++){
        scanf("%d", &data[i]);
    }
    
    len=n;
    //初始化数组-2
    for(i=1;i<=n;i++){
        if(i!=n){
            right[i]=i+1;
        }else{
            right[i]=0;
        }
    }
    //在数组-1末尾添加新数
    len++;
    scanf("%d",&data[len]);

    //从链表头部开始遍历
    t=1;
    while(t!=0){
        if(data[right[t]]>data[len]){//如果当前结点的下一结点数大于新数，
            right[len]=right[t];//新数的下一节点标号等于当前结点的下节点
            right[t]=len;//当前节点的标号等于新数的编号
            break;
        }
        t=right[t];//用于遍历的标号计数法
    }
    //按标号的指向输出
    t=1;
    while(t!=0){
        printf("%d ",data[t]);
        t=right[t];
    }
    system("pause");
    return 0;
}