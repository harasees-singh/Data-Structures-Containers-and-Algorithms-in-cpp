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
int32_t main()
{
    int arr[] = {4, 1, 5, 8, 7, 1, 2, 6, 8};
    deque<int> q; int k=3;
    int curr=0;
    
    loop(i, 0, k){
        while(!q.empty() && arr[q.back()]<arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout <<arr[q.front()] << endl;
    loop(i, k, 9)
    {
        
        curr = q.front();
        if(i-curr==k) {q.pop_front();} 
        while(q.size() && arr[q.back()]<arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        auto it = &q.front();
        
        // loop(j, 0, q.size())
        // {
        //     cout << arr[*it] << ' ';
        //     it++;
        // }
        // cout << endl;
        cout << arr[q.front()] << endl;

    }
}