// you r given n strings; u need to merge them with total minimum cost;
// cost for merging 2 strings is = len(string1) + len(string2);
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<functional>
using namespace std;
int main(){
    vector<string> vs = {"ye", "KJ", "j", "hel"};
    int cost=0;
    priority_queue<int, vector<int>, greater<int>> p;               
    for(auto a:vs){
        p.push(a.size());
    }
    while(p.size()>1){
        int min = p.top(); p.pop();
        int next_min = p.top(); p.pop();
        cost+=min+next_min;
        p.push(min+next_min);
    }
    cout << cost << endl;
}