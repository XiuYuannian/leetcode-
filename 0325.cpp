//3546
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, vector<int>> get_grid_matrix(const vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> row_sum, col_sum;

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += grid[i][j];
        }
        row_sum.push_back(sum);
    }

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += grid[i][j];
        }
        col_sum.push_back(sum);
    }

    return {row_sum, col_sum};
}

bool has_equal_split(const vector<int> &a) {
    int leftsum = 0;
    int rightsum = 0;

    for (int val : a) {
        rightsum += val;
    }

    for (size_t i = 0; i + 1 < a.size(); i++) {
        leftsum += a[i];
        rightsum -= a[i];
        if (leftsum == rightsum) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {{1, 4}, {2,3}};

    auto result = get_grid_matrix(grid);
    const auto &row_sum = result.first;
    const auto &col_sum = result.second;

    if (has_equal_split(row_sum) || has_equal_split(col_sum)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
