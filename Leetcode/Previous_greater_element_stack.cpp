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
    FIO;
    stack<int> s;
    int arr[] = {4, 5, 1, 2};
    int pg=0;
    loop(i, 0, 4)
    {
        while(!s.empty() && arr[i]>arr[s.top()])
        {
            s.pop();
        }
        if(s.empty()) {s.push(i); cout << i+1 << endl; continue;}
        pg = s.top(); s.push(i); cout << i-pg << endl; 
    }
    cout << "printing stack " << endl;
    stack<int> a;
    a.push(3);
    a.push(5);
    while(!a.empty())
    {
        cout << a.top() << endl;
        a.pop();
    }
}