#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int cai[3][3];
    int h, l;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            cin >> cai[i][k];
            sum += cai[i][k];
            if (cai[i][k] == 0)
            {
                h = i;
                l = k;
            }
        }
    }
    cai[h][l] = 45 - sum;
    int x, y;
    sum = 0;
    int shu[3];
    int fuc;
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        shu[i] = cai[x-1][y-1];
    }
    cin >> fuc;
    if (fuc == 1)
    {
        sum += cai[0][0] + cai[0][1] + cai[0][2];
    }
    if (fuc == 2)
    {
        sum += cai[1][0] + cai[1][1] + cai[1][2];
    }
    if (fuc == 3)
    {
        sum += cai[2][0] + cai[2][1] + cai[2][2];
    }
    if (fuc == 4)
    {
        sum += cai[0][0] + cai[1][0] + cai[2][0];
    }
    if (fuc == 5)
    {
        sum += cai[0][1] + cai[1][1] + cai[1][1];
    }
    if (fuc == 6)
    {
        sum += cai[0][2] + cai[1][2] + cai[2][2];
    }
    if (fuc == 7)
    {
        sum += cai[0][0] + cai[1][1] + cai[2][2];
    }
    if (fuc == 8)
    {
        sum += cai[0][2] + cai[1][1] + cai[2][0];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << shu[i] << endl;
    }
    
    if (sum == 6)
        cout <<  10000;
    if (sum == 7)
        cout << 36 ;
    if (sum == 8)
        cout << 720 ;
    if (sum == 9)
        cout << 360 ;
    if (sum == 10)
        cout <<  80;
    if (sum == 11)
        cout <<  252;
    if (sum == 12)
        cout <<  108;
    if (sum == 13)
        cout <<  72;
    if (sum == 14)
        cout <<  54;
    if (sum == 15)
        cout <<  180;
    if (sum == 16)
        cout <<  72;
    if (sum == 17)
        cout <<  180;
    if (sum == 18)
        cout <<  119;
    if (sum == 19)
        cout <<  36;
    if (sum == 20)
        cout <<  306;
    if (sum == 21)
        cout <<  1080;
    if (sum == 22)
        cout <<  144;
    if (sum == 23)
        cout <<  1800;
    if (sum == 24)
        cout <<  3600;
    return 0;
}
