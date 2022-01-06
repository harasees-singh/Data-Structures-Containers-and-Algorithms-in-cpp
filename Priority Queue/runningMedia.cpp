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

void findMedian(int *arr, int n){
		if(n == 0)
            	return;
    	priority_queue<int, vector<int>> pb;
    	priority_queue<int, vector<int>, greater<int>> ps;
    	
    	int i = 0;
    
    	pb.push(arr[i++]);
    	cout << arr[0] << ' ';	
    
    	while(i < n){
            	int cur = arr[i++];
            
            	if(cur < pb.top())
                    	pb.push(cur);
        		else
                    	ps.push(cur);
        		
            	// cout << pb.top() << endl;
            
            	if((int)(pb.size()) - (int)(ps.size()) > 1){
                    	int transfer = pb.top();
                    	pb.pop();
                    	ps.push(transfer);
                }
            	if(((int)ps.size()) - ((int)pb.size()) > 1){
                    	int transfer = ps.top();
                    	ps.pop();
                    	pb.push(transfer);
                }
            	if(pb.size() > ps.size()){
                    	cout << pb.top() << ' ';
                }
            	else if(ps.size() > pb.size())
                    	cout << ps.top() <<  ' ';
        		else
                    	cout << (ps.top() + pb.top())/2 << ' ';
        }
}
int32_t main(){
        FIO 

        return 0;
}
