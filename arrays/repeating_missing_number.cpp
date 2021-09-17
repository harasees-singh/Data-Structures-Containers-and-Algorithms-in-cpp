#include<bits/stdc++.h>
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

using namespace std;
MOD_DEFINE

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int Xor = 0;
        
        for(int i = 0; i < n; i++) Xor = Xor xor arr[i] xor (i + 1);
        
        // Xor contains the xor of the missing and the repeating element.
        
        // any set bit in Xor means it was different for both the elements
        
        int setbit;
        
        for(int i = 0; i < 18; i++) 
            
            if(Xor & (1 << i)) 
            
                setbit = i;
                
        int ffXor = 0, ssXor = 0;
        
        for(int i = 0; i < n; i++){
            
            int p = arr[i];
            
            if(p & (1 << setbit))
                
                ffXor = ffXor xor p;
                
            else 
                ssXor = ssXor xor p;
        }
        
        for(int p = 1; p < n+1; p++){
            
            if(p & (1 << setbit))
                
                ffXor = ffXor xor p;
                
            else 
                ssXor = ssXor xor p;
        }
        
        int *ret = new int[2];
        
        for(int i = 0; i < n; i++){ 
            
            int p = arr[i];
        
            if(p == ffXor){
                
                ret[0] = p, ret[1] = ssXor; return ret;   
            }
            
            if(p == ssXor){
                
                ret[0] = p, ret[1] = ffXor; return ret;   
            }
        }
    }
};

