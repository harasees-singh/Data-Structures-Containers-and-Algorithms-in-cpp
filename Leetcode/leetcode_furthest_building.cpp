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
int furthestBuilding(vector<int>& heights, int bricks, int ladders){
    priority_queue<int, vector<int>, greater<int>> differences;
    int ans=0;
    
    for(int i=1; i< heights.size(); i++){
        int important = differences.size();
        // int top = differences.top();
        int curr_diff = heights[i]-heights[i-1];
        if(curr_diff>0){
            if(important<ladders){
                differences.push(curr_diff); ans++;
            }
            else if(differences.size()){
                int top =  differences.top();
                if(curr_diff > top){
                    if(bricks>=top){
                        bricks-=top;
                        differences.pop(); differences.push(curr_diff);
                        ans++;
                    }
                    else{
                        return ans;
                    }
                }
                else if(bricks-curr_diff>=0){
                    bricks-=curr_diff; ans++; 
                }
                else{
                    return ans;
                }
            }
            else{
                bricks-=curr_diff;
                if(bricks>=0)
                ans++;
                else{
                    return ans;
                }
            }
        }
        else ans++;
    }
    
    return ans;
}
int32_t main(){
    vi something={1, 5, 4, 2};
    cout << furthestBuilding(something, 3, 5);
    return 0;
}