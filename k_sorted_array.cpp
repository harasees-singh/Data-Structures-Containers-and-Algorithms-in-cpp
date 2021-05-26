#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    // array is sorted but elements might be displaed by distance k
    // sort the damn thing in nlogk
    vector<int> arr = {1, 3, 2, 5, 6, 4};
    int k=2;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin()+3);          // store first 2 elements in min heap
    for(int i=1; i <= arr.size(); i++)
    {
        cout << pq.top() << endl;
        pq.pop();
        if(i+k<arr.size()) pq.push(arr[i+k]);
    }

}