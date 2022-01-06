#include<bits/stdc++.h>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>

using namespace std;
MOD_DEFINE

vector<vi> dp(1000, vi(1000));

int memoized_LCS_Length(string &a, string &b, int i, int j){

    if(i == 0 or j == 0) return 0;

    int ans = 0;

    if(a[i-1] == b[j-1]){ 
        
        //return 1 + memoized_LCS_Length(a, b, i-1, j-1);

        if(dp[i-1][j-1] != -1) return 1 + dp[i-1][j-1];

        else{

            dp[i][j] = 1 + memoized_LCS_Length(a, b, i-1, j-1);

            return dp[i][j];
        }
    }

    int first, second;

    if(dp[i-1][j]!=-1) first = dp[i-1][j];

    else 
        first = memoized_LCS_Length(a, b, i-1, j);

    if(dp[i][j-1]!=-1) second = dp[i][j-1];

    else
        second = memoized_LCS_Length(a, b, i, j-1);

    dp[i][j] = max(first, second);

    return max(first, second);
}

void printLongestCommonSubsequence(int i, int j, string &a, string &b){

    if(i==0 or j==0) return;

    if(a[i-1] == b[j-1]){

        printLongestCommonSubsequence(i-1, j-1, a, b);

        cout << a[i-1] << space;
    }

    else{

        if(dp[i-1][j] >= dp[i][j-1]) printLongestCommonSubsequence(i-1, j, a, b); else printLongestCommonSubsequence(i, j-1, a, b);
    }
}

int32_t main(){
    FIO
    
    loop(i, 1, 1000){loop(j, 1, 1000) dp[i][j] = -1;}
    // memoized version

    string a, b; cin >> a >> b;

    cout << memoized_LCS_Length(a, b, sz(a), sz(b)) << endl;

    printLongestCommonSubsequence(sz(a), sz(b), a, b);
    
    return 0;
}
