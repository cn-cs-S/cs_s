#include<stdio.h>
int main()
{
    int a,b,c;
    char str[1000]={"abcasdaksjlakfjlajfljfla"};
    int num=0;
/*
    num=scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",num);

    num=scanf("%s",&str);
    printf("%d\n",num);
*/
//scanf的返回值为参数个数，字符串算作一个参数；

/*
    num=printf("%s\n",str);
    printf("%d\n",num);
*/
//printf的返回值为输出的字符数，空的printf返回值为0；

/*
    (*p>='A')&&(*p<='Z') ? uppercase++ : ((*p>='a')&&(*p<='z')) ? lowercase++ : (*p==' ') ? space++ : ((*p>='1')&&(*p<='9')) ? digit++ : others++
*/
//形如这种的逻辑嵌套的返回值为响应的语句执行后的变量值
//注意++前置和后置的区别
    
}