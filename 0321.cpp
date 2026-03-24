//3643
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//提取子矩阵
vector<vector<int>> grid_new(vector<vector<int>>& grid,int x,int y,int k)
{
    vector<vector<int>> res(k,vector<int>(k,0));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            res[i][j] = grid[x+i][y+j];
        }
        
    }
    return res;
}

//垂直翻转矩阵
void grid_vertical(vector<vector<int>>& grid_new)
{
    int k = grid_new.size();
    int i = 0,j = k-1;
    while (i<j)
    {
        swap(grid_new[i],grid_new[j]);
        i++;
        j--;
    }
}

//返回原矩阵
vector<vector<int>> grid_ans(vector<vector<int>>& grid,vector<vector<int>>&grid_new, int x,int y,int k)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans = grid;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ans[x+i][y+j] = grid_new[i][j];
        }
        
    }
    return ans;
}

vector<vector<int>> two_func(vector<vector<int>>& grid,int x,int y,int k)
{
    vector<vector<int>> grid_new = grid;
    int i = x, j = x+k-1;
    while (i<j)
    {
        for (int z = y; z < y+k; z++)
        {
            swap(grid_new[i][z],grid_new[j][z]);
        }
        i++;
        j--;
    }
    return grid_new;
}

int main()
{
    vector<vector<int>> grid = {{1,0,1,0},{0,1,0,1},{1,0,1,0},{0,1,0,1}}; 
    int k = 3;
    vector<vector<int>> res = grid_new(grid,1,1,k);
    grid_vertical(res);
    res = grid_ans(grid,res,1,1,k);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}