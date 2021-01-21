#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int one, two, three, four;
    int di, que;
    int max = 0;
    int num = 0, sum = 0;
    cin >> one >> two >> three >> four >> di >> que;
    if (max < one)  max = one;
    if (max < two)  max = two;
    if (max < three)  max = three;
    if (max < four)  max = four;
    if (one < di || max - one > que)
    {
        num = 1;
        sum++;
    }
    if (two < di || max - two > que)
    {
        num = 2;
        sum++;
    }
    if (three < di || max - three > que)
    {
        num = 3;
        sum++;
    }
    if (four < di || max - four > que)
    {
        num = 4;
        sum++;
    }
    if (!sum)
    {
        cout << "Normal";
        return 0;
    }
    if (sum > 1)
    {
        cout << "Warning: please check all the tires!";
        return 0;
    }
    printf("Warning: please check #%d!", num);
    
    return 0;
}
