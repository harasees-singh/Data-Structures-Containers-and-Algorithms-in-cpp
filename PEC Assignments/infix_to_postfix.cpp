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

bool is_variable(char t){
        return ((t <= 122 and t >= 97) or (t < 90 and t >= 65));
}

int32_t main(){
    FIO 

    stack<char> expression;

    string s; cin >> s; 

    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

    string postfix; 

    for(char c : s){

        if(is_variable(c))
                postfix += c;
        else{        
                
                while(!expression.empty() and priority[expression.top()] > priority[c])
                        postfix += expression.top(), expression.pop();
                
                expression.push(c);
        }       
        
    }
    while(!expression.empty())
            postfix += expression.top(), expression.pop(); 
    cout << postfix << endl;

    return 0;
}
