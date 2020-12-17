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

int main(){
    struct note que[170];
    int head,tail;
    int book[20][20]={0};
    int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;

    int next[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };

    printf("Enter map-info and start-point:(n m x y):");
    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    head=1;
    tail=1;
    que[tail].x=startx;
    que[tail].y=starty;
    tail++;
    book[startx][starty]=1;
    max=getnum(startx,starty);
    mx=startx;my=starty;

    while(head<tail){
        for(k=0;k<=3;k++){
            tx=que[head].x+next[k][0];//与循环节内的最后一步前后照应，每一步都是从上一步传过来的head开始循环
            ty=que[head].y+next[k][1];
            if(tx<0||tx>n-1||ty<0||ty>m-1){//这里最旁边一排是墙所以-1
                continue;
            }
            if(a[tx][ty]=='.' && book[tx][ty]==0){//是平地且没走过则继续
                book[tx][ty]=1;//先标记或后标记都可以
                que[tail].x=tx;//插入新的点
                que[tail].y=ty;
                tail++;

                sum=getnum(tx,ty);
                if(sum>max){
                    max=sum;
                    mx=tx;
                    my=ty;
                }
            }
        }
        head++;//循环关键
    }
    

    
    printf("When the bomb is setted on (%d,%d), it kills %d targets as best results.",mx,my,max);
    system("pause");
    return 0;
}