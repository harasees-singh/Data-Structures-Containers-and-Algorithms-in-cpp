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
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

class Polynomial {
public:
    int *degCoeff;      
    
    int capacity;
    
    Polynomial(){
        	degCoeff = new int[1000];
        
        	for(int i = 0; i < 1000; i++)
                	degCoeff[i] = 0;
        	
        	capacity = 1000;
    }
    Polynomial(Polynomial const &p){
        	degCoeff = new int[p.capacity];
        
        	capacity = p.capacity;
        	
        	for(int i = 0; i < p.capacity; i++)
                	degCoeff[i] = p.degCoeff[i];
    }
    
    void setCoefficient(int def, int cof){
        	degCoeff[def] = cof;
    }
    
    Polynomial operator+ (Polynomial p){
        	Polynomial t;
        
        	for(int i = 0; i < 1000; i++)
                	t.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
        
        	return t;
    }
    Polynomial operator- (Polynomial p){
        	Polynomial t;
        
        	for(int i = 0; i < 1000; i++)
                	t.degCoeff[i] = this->degCoeff[i] - p.degCoeff[i];
        
        	return t;
    }
    Polynomial operator* (Polynomial p){
        	Polynomial t;
        
        	for(int i = 0; i < 1000; i++){
                	if(this->degCoeff[i]){
                        	for(int j = 0; j < 1000; j++)
                                	if(p.degCoeff[j])
                                        	t.degCoeff[i + j] += this->degCoeff[i]*p.degCoeff[j];
                    }
            }
        
        	return t;
    }
    void operator= (Polynomial p){
        
        	for(int i = 0; i < 1000; i++)
                	this->degCoeff[i] = p.degCoeff[i];
        	return;
    }
    void print(){
        	for(int i = 0; i < 1000; i++)
                	if(degCoeff[i])
                        	cout << degCoeff[i] << 'x' << i << ' ';
    		cout << endl;
        	return ;
    }
};


int32_t main(){
    FIO 

    return 0;
}
