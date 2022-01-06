//Given an integer N, 
//find and return the count of minimum numbers required to 
//represent N as a sum of squares.
#include<bits/stdc++.h>
using namespace std;
vector<int> dp(100000 + 1, -1);
bool isSquare(int n){
    int l = 0, r = n;
    
    while(l <= r){
        int mid = (l + r)/2;
        if(mid*mid < n)
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return (l*l == n);
}
int minCount(int n)
{
	if(isSquare(n))
        return 1;
    if(dp[n] != -1) return dp[n];
    
    int mini = INT32_MAX;
    
    for(int i = 1; i*i < n; i++){
        mini = min(mini, minCount(n - i*i) + 1);
    }
    
    return dp[n] = mini;
}