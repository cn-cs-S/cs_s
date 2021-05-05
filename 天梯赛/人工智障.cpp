
#include <iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int array[100];
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        array[i] = 0;
    }
    int s = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        
        bool is = true;
        for (int i = 0; i < s; i++)
        {
            if (num == array[i]) {
                is = false;
                
                break;
            }
            
        }
        if (is) {
            if (s < m) {
                s++;
            }
                if (x < m)
                {
                    array[x++] = num;
                }
                else
                {
                    x = 0;
                    array[x++] = num;
                }
            
            ++sum;
        }
        
    }
    cout << sum;
    
    return 0;
}