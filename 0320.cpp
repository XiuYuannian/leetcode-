#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

// 提取子矩阵
vector<vector<int>> grid_new(const vector<vector<int>>& grid, int x, int y, int k)
{
    vector<vector<int>> res(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            res[i][j] = grid[x + i][y + j];
        }
    }
    return res;
}

// 求子矩阵的最小绝对差
int grid_diff(const vector<vector<int>>& sub)
{
    unordered_set<int> st;
    for (int i = 0; i < sub.size(); i++)
    {
        for (int j = 0; j < sub[0].size(); j++)
        {
            st.insert(sub[i][j]);
        }
    }
    vector<int> res(st.begin(), st.end());
    if (res.size() < 2) return 0;

    sort(res.begin(), res.end());
    int diff = INT_MAX;
    for (int i = 1; i < res.size(); i++)
    {
        diff = min(diff, res[i] - res[i - 1]);
    }
    return diff;
}

int main()
{
    vector<vector<int>> grid = {{1, -2, 3}, {2, 3, 5}};
    int k = 2;

    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

    for (int i = 0; i <= m - k; i++)
    {
        for (int j = 0; j <= n - k; j++)
        {
            vector<vector<int>> sub = grid_new(grid, i, j, k);
            ans[i][j] = grid_diff(sub);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



class Solution {
public:
    int calc(vector<vector<int>>& grid, int r, int c, int k) {
        vector<int> a;
        a.reserve(k * k);

        for (int i = r; i < r + k; i++) {
            for (int j = c; j < c + k; j++) {
                a.push_back(grid[i][j]);
            }
        }

        sort(a.begin(), a.end());

        int ans = INT_MAX;
        for (int i = 1; i < (int)a.size(); i++) {
            if (a[i] != a[i - 1]) {
                ans = min(ans, a[i] - a[i - 1]);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                ans[i][j] = calc(grid, i, j, k);
            }
        }
        return ans;
    }
};