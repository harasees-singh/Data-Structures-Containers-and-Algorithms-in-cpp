#include<iostream>
#include<vector>
#define And &&
#define pb push_back
#define endl '\n'
#define space " "
#define vi std::vector<int>
using namespace std;
class MinHeap{
    public:
        vi list;
        void BuildMinHeap(){
            int i=(list.size()-1)/2;
            while(i>=1){
                sift_down(i);
                i-=1;
            }
                
        }
        void sift_down(int i){
            while(i<=(list.size()-1)/2)
            {   
                int left_child = list[2*i];
                int right_child;
                int min_index;
                2*i + 1 < (list.size()-1)? right_child = list[2*i+1] :right_child=INT32_MAX;
                left_child<right_child ? min_index = 2*i: min_index=2*i+1;
                
                if(list[min_index] > list[i]){
                    return;
                }
                swap(list[i],list[min_index]); 
                i=min_index;
            }
            return;
        }
        MinHeap(vi &v){
            list.pb(0);
            for(auto temp:v){
                list.pb(temp);
            }
            BuildMinHeap();
        }
        // sift up
        // use this for inserting an element in min heap
        // this will insert the element at the end of the list and then propagate it upwards till it fits at the right place 
        // and hence the name sift up
        void Insert(int a){
            list.pb(a);
            int i = (list.size()-1);
            while(i>1 And list[i/2]>list[i]){
                swap(list[i],list[i/2]); i=i/2;
            }
        }        
};
int main(){
    vi v = {8, 4, 6, 1, 5, -1};
    MinHeap H(v);
    H.Insert(3);
    H.Insert(-1);
    H.Insert(10);
    H.Insert(9);
    // cout << H.list[0] << " "<< H.list[1] << " " << H.list[2] << " " <<  H.list[3] << " " << H.list[4] << " " << H.list[5] <<  endl; 
    for(auto a: H.list){
        cout << a << space;
    }
    cout << endl;
    // cout << "list size is" << space << H.list.size() << endl;
    return 0;
}
