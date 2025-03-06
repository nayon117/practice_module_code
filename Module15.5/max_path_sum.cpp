#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9; 
int dp[11][11]; 
int A[11][11]; 
int n, m;

int solve(int i, int j) {
    if (i >= n || j >= m) return INF; 
    if (i == n-1 && j == m-1) return A[i][j]; 

    if (dp[i][j] != -1) return dp[i][j]; 

    int moveRight = solve(i, j + 1); 
    int moveDown = solve(i + 1, j); 

    return dp[i][j] = A[i][j] + max(moveRight, moveDown);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> A[i][j];


    memset(dp, -1, sizeof(dp)); 

    cout << solve(0, 0) << endl; 

    return 0;
}
