#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define infinity                        999999999999999999      // 1e18 - 1
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

using namespace std;
MOD_DEFINE

void InsertionSort(vi &arr){

    for(int i = 0; i < arr.size(); i++){

        int j = i;

        int key = arr[i];

        while(j and arr[j - 1] > key)

            arr[j] = arr[j - 1], j--;

        arr[j] = key;
    }
}

int32_t main(){
    FIO 

    vi arr = {3, 5, 1, 7, 8, 4};

    vi arr = {8};

    InsertionSort(arr);

    for(auto p : arr) cout << p << space; cout << endl;

    return 0;
}
