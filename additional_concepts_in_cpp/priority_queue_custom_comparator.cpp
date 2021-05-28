#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
unordered_map<int, int> map;
struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return map[lhs] < map[rhs];
    }
};
int main(){
    map[1]=1;
    map[5]=5;
    unordered_map<int, int> map;
    priority_queue<int, vector<int>, CustomCompare> p;
    p.push(5);
    p.push(1);
    p.push(6);
    while(p.size()){
        cout << p.top() << endl;
        p.pop();
    }
}