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
class Deque {
public:
    int front, back;
    int size;
    int*arr;
    Deque(int n){
        arr = new int[n];
        front=-1,back=-1;
        size=0;
    }
    void insertRear(int n){
        if(size==10){
            cout << -1 << endl; 
            return;
        }
        if(back==-1){
            arr[0]=n; back=0; front=0; return;
        }
        arr[(++back)%10]=n;
        size++;
    }
    void insertFront(int n){
        if(size==10){
            cout << -1 << endl; 
            return;
        }
        if(front==-1){
            arr[9]=n; front=9; back=9; return;
        }
        front = (front - 1 + 10)%10;
        arr[(front)] = n; 
        size++;
    }
    void deleteFront(){
        if(size==0){
            cout << -1 << endl; 
            return;
        }
        size--;
        front++;
    }
    void deleteRear(){
        if(size == 0){
            cout << -1 << endl; 
            return; 
        }
        back = (back - 1 + 10)%10; size--;
    }
    int getFront(){
        if(size==0) return -1;
        
        return arr[front];
    }
    int getRear(){
        if(size == 0) return -1;
        
        return arr[back%10];
    }
    
    
};

int32_t main(){
    FIO 
    Deque q(10);

    q.deleteFront();

    q.insertFront(1), q.insertFront(2);

    q.deleteRear();

    q.deleteRear();

    cout << q.getFront() << endl;

    return 0;
}
