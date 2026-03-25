//2906
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> get_grid_matrix(const vector<vector<int>> &grid)
{
    const int MOD = 12345;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> left(m, vector<int>(n, 1));
    vector<vector<int>> right(m, vector<int>(n, 1));
    long long left_val = 1, right_val = 1;
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            left[i][j] = left_val;
            left_val = (left_val * grid[i][j]) % MOD;
        }
    }
    for(int i =m-1;i>=0;i--)
    {
        for(int j =n-1;j>=0;j--)
        {
            right[i][j] = right_val;
            right_val = (right_val * grid[i][j]) % MOD;
        }
    }
    vector<vector<int>> res(m, vector<int>(n, 0));
    for(int i =0;i<m;i++)    
    {
        for(int j =0;j<n;j++)     
        {
            res[i][j] = (left[i][j] * right[i][j]) % MOD;
        }
    }
    return res;           
}



vector<vector<int>> get_grid(const vector<vector<int>> &grid) {
    constexpr int MOD = 12345;
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;

    vector<int> nums;
    nums.reserve(total);
    for (const auto &row : grid) {
        for (int val : row) {
            nums.push_back(val % MOD);
        }
    }

    vector<int> prefix(total, 1);
    vector<int> suffix(total, 1);

    for (int i = 1; i < total; i++) {
        prefix[i] = (prefix[i - 1] * nums[i - 1]) % MOD;
    }
    for (int i = total - 2; i >= 0; i--) {
        suffix[i] = (suffix[i + 1] * nums[i + 1]) % MOD;
    }

    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int idx = 0; idx < total; idx++) {
        int i = idx / n;
        int j = idx % n;
        res[i][j] = (prefix[idx] * suffix[idx]) % MOD;
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {{12345}, {2}, {1}};
    auto res = get_grid(grid);
    auto res1 = get_grid_matrix(grid);
    for (const auto &row : res1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
