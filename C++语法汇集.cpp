#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    char str;

//vector为容器，格式为vector<size_t>,size_t可为其他类
//c++中应多使用vector，string，少用数组和c风格字符串
    vector<char> v;             

//vector的用法
//添加元素
/*
    for (int i = 0; i < 10; i++)
    {
        v.push_back(str=getchar());
    }
*/

//范围for循环，关键字auto，r为引用类型，表示对于（）的每一个元素
/*
    for(auto &r : v)
    {
        putchar(r);
    }
*/

//迭代器的用法，成员函数begin，end
//应注意c++中条件语句应写成!=形式
/*
    for( auto beg=v.begin(),end=v.end() ; beg != end ; ++beg )
    {
        putchar(*beg);
    }
*/    

//string的性质探究
/*
    string s1("alsjd"),s2("4565464");

    printf("%d\n",s1);          //6421904
    printf("%d\n",&s1);         //6421840
    printf("%d\n",s1.begin());  //6421856
    printf("%d\n",s1.end());    //6421861
    putchar('\n');              

    s1=s1+"asdasd";             
    printf("%d\n",s1);          //6421968
    printf("%d\n",&s1);         //6421840
    printf("%d\n",s1.begin());  //6421856
    printf("%d\n",s1.end());    //6421867
    putchar('\n');

    s1=" ";
    printf("%d\n",s1);          //6422000
    printf("%d\n",&s1);         //6421840
    printf("%d\n",s1.begin());  //6421856
    printf("%d\n",s1.end());    //6421857
    putchar('\n');

    //根据观察，不论给string赋值什么，以整数形式输出时值会增大
    //根据迭代器的显示来看，&s1 和 s1.begin ，相差了16个字节
*/

    return 0;
}
