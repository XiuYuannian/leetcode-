//3212
#include <iostream>
#include <vector>
using namespace std;

bool count_char(vector<vector<char>> &grid_new)
{
    if (grid_new.empty() || grid_new[0].empty()) return false;
    int count_X = 0, count_Y = 0;
    int m = grid_new.size(), n = grid_new[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid_new[i][j] == 'X')
                count_X++;
            else if (grid_new[i][j] == 'Y')
                count_Y++;
        }
    }

    return (count_X != 0 && count_X == count_Y);
}

vector<vector<char>> get_rect(vector<vector<char>> &grid, int row, int col)
{
    vector<vector<char>> grid_new(row + 1, vector<char>(col + 1));
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            grid_new[i][j] = grid[i][j];
        }
    }
    return grid_new;
}

int main()
{
    int ans = 0;
    vector<vector<char>> grid = {{'X','Y','.'},{'Y','.','.'}};

    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<vector<char>> grid_new = get_rect(grid, i, j);
            if (count_char(grid_new))
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}