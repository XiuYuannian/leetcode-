//3212
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ans = 0;
    vector<vector<char>> grid = {{'X','Y','.'},{'Y','.','.'}};
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> preX(m+1,vector<int>(n+1,0));
    vector<vector<int>> preY(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            preX[i][j] = preX[i-1][j] + preX[i][j-1] - preX[i-1][j-1];
            if (grid[i-1][j-1]=='X')
                preX[i][j]++;
            preY[i][j] = preY[i-1][j] + preY[i][j-1] - preY[i-1][j-1];
            if (grid[i-1][j-1]=='Y')
                preY[i][j]++;
            if (preX[i][j] != 0 && preX [i][j] == preY[i][j])
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}