#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(2, vector<int> (1e6 + 1));
int knapsack(int* w, int* v, int n, int maxWeight) {
	dp[0][w[0]] = v[0];

    for(int i = 1; i < n; i++){
        int cur = w[i];
        
        for(int j = 0; j + cur <= maxWeight; j++){
            // calc value for weight = j
            if(dp[0][j] or !j)
            	dp[1][j + cur] = v[i] + dp[0][j];
        }
        for(int j = 0; j <= maxWeight; j++){
            dp[0][j] = max(dp[0][j], dp[1][j]);
            // dp[1][j] = 0;
        }
        
    }
    return (*max_element(dp[0].begin(), dp[0].end()));
}