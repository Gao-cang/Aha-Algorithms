#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(){
    char a[101],s[101];
    int i,len,mid,next,top;

    printf("Is this string a palindrome?\n");
    gets(a);
    len=strlen(a);
    mid=len/2-1;

    top=0;
    for(i=0;i<=mid;i++){
        s[++top]=a[i];//提取前一半字符入栈
    }

    if(len%2==0){
        next=mid+1;//奇偶个数的半数起点不同
    }else{
        next=mid+2;
    }

    for(i=next;i<=len-1;i++){
        if(a[i]!=s[top]){//与后一半比较，其中前一半为栈，先进后出所以是倒序，后一半为顺序
            break;
        }
        top--;
    }
    if(top==0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    system("pause");
    return 0;
}
