#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v((n, 0));
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int t = 0; t < k; t++)
        {
            int x;
            cin >> x;
            v[i][x] = 1;
        }
    }
    vector<vector<int>> visit((n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < n; t++)
        {
            
        }
        
    }
    
}