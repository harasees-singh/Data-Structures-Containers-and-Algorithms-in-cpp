#include<bits/stdc++.h>
#include<limits>
#include<queue>
using namespace std;
struct comp{
    
    bool operator()(std::vector<int>::iterator a, std::vector<int>::iterator b){
        return *a > *b;
        // cout << *a << *b << endl;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<int, vector<std::vector<int>::iterator>, comp> p;
        for(auto &a:arr){
            if(a.size()){
                a.push_back(INT32_MAX);
                auto it = a.begin();
                p.push(it);
                
            }
        }
        
        while(p.size()){
            // cout << *p.top() << endl;
            ans.push_back(*(p.top()));
            auto temp=p.top() + 1; p.pop();
            if(*temp!=INT32_MAX) p.push(temp);
        }
        return ans;
    }
};
int main(){
    Solution* a = new Solution();
    vector<vector<int>> arr;
    arr = {{1, 2, 3},  {4, 8, 45}, {4, 5, 8}, {3}, {8, 78}};
    // cout << arr[1][2];
    vector<int> ans = a->mergeKArrays(arr, 5);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}