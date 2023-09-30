#include <iostream>
using namespace std;

const int MAX = 100;

int minCostPath(int grid[MAX][MAX], int m, int n) {
    int dp[MAX][MAX];

    // Initialize the top-left cell
    dp[0][0] = grid[0][0];

    // Initialize the first column // col works
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Initialize the first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int grid[MAX][MAX];
    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int minCost = minCostPath(grid, m, n);
    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
