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
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;
int32_t main(){
    // given 2 arrays x and p. x is sorted. find a pair of distinct integers 
    // i, j s.t. abs(x[j]-x[i]) + p[i] + p[j] is maximum but there is a 
    // condition that abs(x[j]-x[i]) <= k

    // we will choose i, j s.t. j>i

    // the q boils down to maximise x[j]+p[j] + p[i]-x[i]
    int k=2;
    pair<int, int> final_ans = {-1, -1};
    int x[] = {2, 6, 6, 6, 6, 6, 8, 8}; int p[] = {5, 100, 100, 0, -1, 500, 0, 0};
    deque<int> prospects;
    int max = INT32_MIN;
    for(int j=1; j<8; j++){
        
        int cur_sum = x[j]+p[j];
        while(prospects.size() && x[j]-x[prospects.front()]>k){
            prospects.pop_front();
        }
        if(prospects.size())
        {   
            if(cur_sum + p[prospects.front()]- x[prospects.front()] > max){
                max = cur_sum + p[prospects.front()]- x[prospects.front()]; final_ans = {prospects.front(), j};
            }
        }
        while(prospects.size() && -x[prospects.back()]+p[prospects.back()] <= p[j]-x[j]){
            prospects.pop_back();
        }
        prospects.push_back(j);
    }
    cout << final_ans.first << " " << final_ans.second << endl;
}