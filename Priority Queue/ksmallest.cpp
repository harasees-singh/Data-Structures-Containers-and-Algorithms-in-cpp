#include<vector>
class PriorityQueue {
    // Declare the data members here
	
    
    vector<int> pq;

    	
    public:
    PriorityQueue(){
    	
    }
    
   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMax() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        
        int id = pq.size() - 1;
        
        while(id > 0){
            	if(pq[id] > pq[(id - 1)/2])
                    	swap(pq[id], pq[(id - 1)/2]), id = (id - 1)/2;
            	else
                    	return;
        }
    }   	

    int removeMax() {
        // Implement the removeMax() function here
        int ret = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        
        pq.pop_back();
        
        int id = 0;
        while(true){
                int l = 2*id + 1;
                int r = 2*id + 2;
                if(l < pq.size() and r < pq.size()){
                        if(pq[id] >= pq[l] and pq[id] >= pq[r]) return ret;
                        if(pq[l] > pq[r])
                                swap(pq[l], pq[id]), id = l;
                        else 
                                swap(pq[r], pq[id]), id = r;
                }
                else if(l < pq.size()){
                        if(pq[id] >= pq[l]) return ret;


                        swap(pq[l], pq[id]); id = l;
                }
                else return ret;
        }
    }
};
vector<int> kSmallest(int arr[], int n, int k) {
    	PriorityQueue P;	
    	for(int i = 0; i < k; i++)
            	P.insert(arr[i]);
		
    	for(int i = k; i < n; i++){
            	if(arr[i] < P.getMax()){
                    	P.removeMax();
                    	P.insert(arr[i]);
                }
        }
    	vector<int> ret;
    
    	for(int i = 0; i < k; i++){
            	ret.push_back(P.removeMax());
        }
    	return ret;
}