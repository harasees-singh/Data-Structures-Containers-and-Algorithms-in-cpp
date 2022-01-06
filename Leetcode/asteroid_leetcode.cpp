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
#include <functional>

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
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
template<typename T>
void print(array<T,2> &arr);
template<typename T>
void print(vector<T> &v);
template<typename T>
void print(deque<T> &v); 
template<typename T>
T _gcd(T a, T b);
template<typename T>
vector<T> sieve(T n);
template<typename T>
T power(T x, T y, int p = LLONG_MAX);
int nxt();
// Returns n^(-1) mod p 
template<typename T>
T modInverse(T n, T p);
int gcd(vector<int> &diff);
bool isPowerof2(int x);
vector<int> divisors(int n){
	vector<int> ans;
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i ==0){
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	ans.pb(1);
	return ans;
}
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //

int32_t main(){
    FIO
    vi asteroids;
    asteroids.pb(8);
    asteroids.pb(-8);
    // asteroids.pb(1);
    // asteroids.pb(2);
    stack<int> ans;
    for (int i = 0; i < asteroids.size(); i++)
    {
        int cur = asteroids[i];
        bool entered_elseif = false;
        bool entered_while = false;
        while (ans.size() != 0 and cur < 0 and 0 < ans.top())
        {
            entered_while = true;
            // cout<<ans.top()<<endl;
            if (ans.top() < -cur)
            {
                ans.pop();
                continue;
            }
            else if (ans.top() == -cur)
            {    
                entered_elseif = true;
                ans.pop();
            }
            break;
        }
        if((ans.empty() || ans.top() < 0) && !entered_elseif) {ans.push(cur); continue;}
        if (!entered_while)
        {
            ans.push(cur);
        }
    } 

    int sz = ans.size();
    vector<int> ans_v(sz);
    for (int i = sz -1 ; i>= 0; i--){
        ans_v[i] = ans.top();
        // cout<<ans.top()<<" ";
        ans.pop();
    }   
    // cout<<endl;
    loop(i, 0, ans_v.size()){
        cout<<ans_v[i]<<" ";
    }
    // print(ans_v);
    cout<<endl;

    return 0;
}

// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
template<typename T>
T power(T x, T y, int p) { 
    T res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    // cout <<"x= "<< x << endl;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    // cout << "res" << res << endl;
    return res; 
} 
 
template<typename T>
vector<int32_t> sieve(int n){
	vector<int> prime(n+1, 1);
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
				prime[i*j] = 0;
			}
		}
	}
	vector<int32_t> ans;
	for(int i = 2; i<=n;i++){
		if(prime[i]) ans.pb(i);
	}
	return ans;
}
 
template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}
 
template<typename T>
void print(array<T,2> &arr){
	cout << arr[0] << " " << arr[1] << endl;
}
 
template<typename T>
void print(vector<T> &v){
	for(T x: v) cout << x << " ";
	cout << endl;
}
 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
 
template<typename T>
void print(deque<T> &v){
	for(auto x: v) cout << x << " ";
	cout << endl;
}
 
int nxt(){
    int x;
    cin >> x;
    return x;
}
 
bool isPowerof2(int x){
	return !(x && (x & (x-1)));
}