// 1594
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


pair<vector<vector<long long>>, vector<vector<long long>>> get_maxgt_mingt(
    const vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<long long>> maxgt(m, vector<long long>(n, 0));
    vector<vector<long long>> mingt(m, vector<long long>(n, 0));

    maxgt[0][0] = mingt[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        maxgt[i][0] = mingt[i][0] = maxgt[i - 1][0] * grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        maxgt[0][j] = mingt[0][j] = maxgt[0][j - 1] * grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            long long val = grid[i][j];
            long long from_up_max = maxgt[i - 1][j];
            long long from_left_max = maxgt[i][j - 1];
            long long from_up_min = mingt[i - 1][j];
            long long from_left_min = mingt[i][j - 1];

            if (val >= 0) {
                maxgt[i][j] = max(from_up_max, from_left_max) * val;
                mingt[i][j] = min(from_up_min, from_left_min) * val;
            } else {
                maxgt[i][j] = min(from_up_min, from_left_min) * val;
                mingt[i][j] = max(from_up_max, from_left_max) * val;
            }
        }
    }

    return {maxgt, mingt};
}

int maxProductPath(const vector<vector<int>> &grid) {
    constexpr int MOD = 1'000'000'007;
    auto result = get_maxgt_mingt(grid);
    const auto &maxgt = result.first;
    long long ans = maxgt.back().back();
    if (ans < 0) {
        return -1;
    }
    return static_cast<int>(ans % MOD);
}

int main() {
    vector<vector<int>> grid = {{1, 3}, {0, -4}};
    cout << maxProductPath(grid) << endl;
    return 0;
}
