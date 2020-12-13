#include<stdio.h>
int main()
{
    char str[1000];
    char *p=str;
    gets(str);
    int uppercase=0,lowercase=0,space=0,digit=0,others=0;
    while (( (*p>='A')&&(*p<='Z') ? uppercase++ : ((*p>='a')&&(*p<='z')) ? lowercase++ : (*p==' ') ? space++ : ((*p>='1')&&(*p<='9')) ? digit++ : others++) || *p)
    {
        p++;
        //printf("%x\t",p);
        printf("upper case:%d,lower case:%d,space:%d,digit:%d,others:%d\n",uppercase,lowercase,space,digit,others);
    }
    //while ((*p>='A')&&(*p<='Z')?uppercase++:((*p>='a')&&(*p<='z'))?lowercase++:(*p==' ')?space++:((*p>='1')&&(*p<='9'))?digit++:others++);
    printf("upper case:%d,lower case:%d,space:%d,digit:%d,others:%d",uppercase,lowercase,space,digit,others);
    
}