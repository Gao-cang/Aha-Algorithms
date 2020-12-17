#include<stdio.h>
#include<stdlib.h>

struct note{
    int x;
    int y;
};
char a[20][21]={
        {'#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','G','G','.','G','G','G','#','G','G','G','.','#'},
        {'#','#','#','.','#','G','#','G','#','G','#','G','#'},
        {'#','.','.','.','.','.','.','.','#','.','.','G','#'},
        {'#','G','#','.','#','#','#','.','#','G','#','G','#'},
        {'#','G','G','.','G','G','G','.','#','.','G','G','#'},
        {'#','G','#','.','#','G','#','.','#','.','#','.','#'},
        {'#','#','G','.','.','.','G','.','.','.','.','.','#'},
        {'#','G','#','.','#','G','#','#','#','.','#','G','#'},
        {'#','.','.','.','G','#','G','G','G','.','G','G','#'},
        {'#','G','#','.','#','G','#','G','#','.','#','G','#'},
        {'#','G','G','.','G','G','G','#','G','.','G','G','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };
int book[20][20],max,mx,my,n,m;

int getnum(int i,int j){//走步和计杀敌数是两个操作，所以分开算，此函数只计杀敌数
    int sum,x,y;
    sum=0;
    //站位向上统计
    x=i;y=j;
    while(a[x][y]!='#'){
        if(a[x][y]=='G'){
            sum++;
        }
        x--;
    }
    //站位向下统计
    x=i;y=j;
    while(a[x][y]!='#'){
        if(a[x][y]=='G'){
            sum++;
        }
        x++;
    }
    //站位向左统计
    x=i;y=j;
    while(a[x][y]!='#'){
        if(a[x][y]=='G'){
            sum++;
        }
        y--;
    }
    //站位向右统计
    x=i;y=j;
    while(a[x][y]!='#'){
        if(a[x][y]=='G'){
            sum++;
        }
        y++;
    }
    return sum;
}
void dfs(int x,int y){
    int next[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    int k,sum,tx,ty;
    //dfs第一步：结束方式（此程序中不结束，所以每次运算开始前记录结果值）
    sum=getnum(x,y);
    if(sum>max){
        max=sum;
        mx=x;
        my=y;
    }
    //dfs第二步：循环方式
    for(k=0;k<=3;k++){
        tx=x+next[k][0];//与循环节内的最后一步前后照应，每一步都是从上一步传过来的head开始循环
        ty=y+next[k][1];

        if(tx<0||tx>n-1||ty<0||ty>m-1){//这里最旁边一排是墙所以-1
                continue;
            }
            if(a[tx][ty]=='.' && book[tx][ty]==0){//是平地且没走过则继续
                book[tx][ty]=1;//先标记或后标记都可以
                dfs(tx,ty);
                //此程序又与纸牌游戏不同，此处不需要在下一个循环节开始前取消标记
                //因为取消标记代表下一次循环需要继续走这些点，换言之，每次循环是在求一条完整的路径
                //而这个程序只是想尝试所有的点
            }
    }
    return;

    
}

int main(){
    int i,startx,starty;

    printf("Enter map-info and start-point:(n m x y):");
    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    book[startx][starty]=1;
    max=getnum(startx,starty);
    mx=startx;my=starty;

    dfs(startx,starty);
    
    printf("When the bomb is setted on (%d,%d), it kills %d targets as best results.",mx,my,max);
    system("pause");
    return 0;
}