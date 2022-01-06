#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE
int binarySearch(int input[], int size, int x){

    // int id = lower_bound(input, input + size, x) - input;
    // if(id != size and input[id] == x)
    //     return id;
    // else    
    //     return -1;
	if(size == 1)
        	return (*input == x ? 0 : -1);
    
    int mid = size/2;
    if(*(input + mid) == x)
        	return max(mid, binarySearch(input + mid + 1, (size + 1)/2 - 1, x));
        	
    if(*(input + mid - 1) >= x)
        	return binarySearch(input, (size)/2, x);
    else{
        	int ret = binarySearch(input + mid, (size + 1)/2, x);
        	return (ret == -1 ? -1 : mid + ret);
    }
}

int32_t main(){
    FIO 

    int input[] = {1, 2, 3, 5, 7};
    int size = 5;

    int id = lower_bound(input, input + size, 7) - input;
    if(id != size and input[id] == 7)
        cout << id;
    else    
        cout << -1;

    return 0;
}
