#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000000 + 1, -1);
int balancedBTs(int n) {
    // Write your code here
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return 1;
    int MOD = 1e9 + 7;
    if(dp[n] != -1) return dp[n];
    long long x = balancedBTs(n - 1), y = balancedBTs(n - 2); 
    long long calc = 2*x*y;
    calc%=MOD;
    long long mul = x*x;
    mul%=MOD;
    return dp[n] = (calc + mul)%MOD;
}