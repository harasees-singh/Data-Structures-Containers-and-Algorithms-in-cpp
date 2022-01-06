#include<bits/stdc++.h>
using namespace std;
// nlgk
struct comp{
  		bool operator() (vector<int> *a, vector<int> *b){
            	return a->back() < b->back();
        }  
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
		vector<int> ret;
    	
    	priority_queue<vector<int>*, vector<vector<int>*>, comp> pq;
    	
    	
        for(auto p : input){
            	if(p->size()){
                    	pq.push(p);
                }
        }
    	while(pq.size()){
            	auto ele = pq.top();
            	pq.pop();
            	ret.push_back(ele->back());
            	ele->pop_back();
            	if(ele->size())	
                    	pq.push(ele);
        }
            	

    	reverse(ret.begin(), ret.end());
    
    	return ret;
}
