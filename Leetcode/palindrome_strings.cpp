#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
// we have a list w of strings. find number of pairs of i, j (j>i)
// such that atleast one of the jumbled forms of w[i] + w[j] is a palindrome.
int hash_(string s){
    int cur=0;
    for(auto ch:s){
        cur^=(1<<(ch-'a'));       // 0th position for a and 25th pos for z
    }
    return cur;
}
int32_t main(){
    FIO 
    vector<string> w={"abc", "ba", "the", "et", "t", "cba"};
    int power_2 = 0;
    mii answer;                 // need to check if the hash of 1 string ^ hash of another string == 0 or a power of 2
    int ans=0;        

    for(string s:w){
        int hash_val = hash_(s);
        ans+=answer[hash_val];
        answer[hash_val]++;
        loop(i, 0, 26){
            ans+=answer[hash_val^(1<<i)]; 
        }
    }
    cout << ans << endl;
}