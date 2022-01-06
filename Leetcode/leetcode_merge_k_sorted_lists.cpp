/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class comp{
public:
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }    
};
class Solution {
public:
    ListNode* answer=new ListNode;
    // answer->next=NULL;
    priority_queue<ListNode*, vector<ListNode*>, comp> p;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto a:lists){
            if(a){
                p.push(a);
            }
        }
        // answer=p.top();
        ListNode* curr=answer;
        while(p.size()){
            ListNode* temp=p.top();
            
            // if(curr) curr->next = temp;
            curr->next = temp;
            curr=temp;
            ListNode* to_be_replaced = p.top();
            p.pop();
            if(to_be_replaced->next)
                p.push(to_be_replaced->next);
        }
        return answer->next;
    }
};
