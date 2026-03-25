// 3546
#include <iostream>
#include <vector>

using namespace std;

bool can_partition_grid(const vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    long long total = 0;

    for (const auto &row : grid) {
        for (int val : row) {
            total += val;
        }
    }

    if (total % 2 != 0) {
        return false;
    }

    long long target = total / 2;
    long long prefix = 0;

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            prefix += grid[i][j];
        }
        if (prefix == target) {
            return true;
        }
    }

    prefix = 0;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < m; i++) {
            prefix += grid[i][j];
        }
        if (prefix == target) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {{1, 4}, {2, 3}};
    cout << (can_partition_grid(grid) ? "true" : "false") << endl;
    return 0;
}
