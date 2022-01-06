#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    // ouput kth smallest number out of an unsorted array
    // in O(n + klogn) time
    int arr[] = {1, 5, 7, 2, 8, 9, 3};
    int k=3;
    priority_queue<int, vector<int>, greater<int>> p(arr, arr+7);
    // build a min heap out of the array;
    for(int i=0; i<k-1; i++){
        // cout << p.top() << endl;
        p.pop();
    }
    cout << p.top() << endl;
}