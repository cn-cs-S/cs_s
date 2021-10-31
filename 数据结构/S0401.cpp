#include <string>
#include <iostream>
using namespace std;

class SString {
public:
    string str;
};

void InitSString(SString &s) {
    getline(cin, s.str);
}

int Index_BF(SString &s1, SString &s2, int n) {
    return s1.str.find(s2.str) + 1;
}

int main()
{
    SString s1, s2;
    InitSString(s1); //初始化字符串，以回车结束
    InitSString(s2);

    // BF算法：s2若为s1的子串，返回匹配的开始位置，否则返回0
    cout << Index_BF(s1, s2, 1) << endl;
    return 0;
}