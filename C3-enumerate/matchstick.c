#include<stdio.h>
#include<stdlib.h>

int fun(int x){//火柴计数函数
    int num=0;
    int f[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    while(x/10!=0){
        num += f[x%10];//由低位往高位，算每一位上数字的火柴数
        x = x/10;//低位算完后直接省略
    }
    num+=f[x];
    return num;
}

int main(){
    int a,b,c,m,sum=0;
    scanf("%d", &m);//火柴棍个数

    for(a=0;a<=1111;a++){
        for(b=0;b<=1111;b++){
            c=a+b;//如果当作判断条件则需要多一个循环，此处化为运算条件减少大量运算
            if(fun(a)+fun(b)+fun(c) == m-4){
                printf("%d + %d = %d\n", a,b,c);
                sum++;
            }
        }
    }
    printf("Totally %d equations\n", sum);
    system("pause");
    return 0;
}