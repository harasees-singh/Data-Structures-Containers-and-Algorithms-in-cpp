// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

void function(int n){
        for(int i = 0; i < n; i++){

                // i times
                for(int j = i; j < i*i; j++){
                        // i*i times
                        if(j%i == 0){
                                // will hit i times
                                for(int k = 0; k < j; k++){
                                        // p*i times
                                        // p varies from 1 to i
                                        // this loop will run i, 2i, 3i, 4i .... i*i times
                                        
                                        printf("*");
                                }
                        }
                }
                // therefore all the loops in this scope will run O(n*n*n) times.
        }
        // therefore the time complexity is O(n)*(number of times all the internal loops run) = O(n)*O(n*n*n)
        // O(n*n*n*n)
}

int32_t main(){
        FIO 

        return 0;
}
