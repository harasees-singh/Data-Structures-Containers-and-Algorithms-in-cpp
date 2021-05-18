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
    // You are given an array a1,a2,…,an consisting of integers from 0 to 9. A subarray al,al+1,al+2,…,ar−1,ar is good if the sum of elements of this subarray is equal to the length of this subarray (∑i=lrai=r−l+1).

    // For example, if a=[1,2,0], then there are 3 good subarrays: a1…1=[1],a2…3=[2,0] and a1…3=[1,2,0].

    // Calculate the number of good subarrays of the array a.
    // vi a= {1, 2, 0, 1};
    
    test_cases_loop
    {
        int n; cin >> n;
        string s; cin >> s;
        vi a;

        loop(i, 0, s.size()){
            a.push_back(s[i] - 48);
        }
        mii ordered_map;
        ordered_map[1]++;
        // r-l+1 = prefix[r]-prefix[l-1] or prefix[r]-r = prefix[l-1]-(l-1)
        int prefix_sum=0;
        vi p(a.size(), 0);
        loop(i, 0, a.size()){
            prefix_sum+=a[i]; p[i] = prefix_sum;
        }
        int ans=0;
        loop(i, 0, a.size()){
            ans+=ordered_map[p[i]-i]; ordered_map[p[i]-i]++; 
        }
        cout << ans << endl;
    }
}