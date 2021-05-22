#include"iostream"
#include<list>
#include<unordered_map>
#define pb push_back
#define FIO std::ios::sync_with_stdio(false);
using namespace std;
int main(){
    FIO;
    // this cache will support O(1) key value pair insertion and O(1) retrieval 
    // in case the capacity is full remove the least recently used pair 
    list<int> order;

    int tasks=20;
    unordered_map<int, int> key_val;
    unordered_map<int, std::list<int>::iterator> key_address;
    int capacity = 2;
    int size=0;
    while(tasks--){
        string s;
        cin >> s; 
        if(s=="put"){
            
            int key, value;
            cin >> key >> value;
            key_val[key]=value;
            if(key_address.find(key)!=key_address.end()){           // if the key was already present then we can update it's value
                auto ptr = key_address[key];
                order.erase(ptr);
                order.pb(key);
                key_address[key]=--order.end();
            }
            else{
                if(size==capacity){
                    key_val.erase(*order.begin()); key_address.erase(*order.begin());
                    order.pop_front();
                    order.pb(key);
                    key_address[key] = --order.end();
                }
                else{
                    order.push_back(key);
                    key_address[key] = --order.end();
                    
                    size++;

                }

            }
            
        }
        else if(s=="get"){
            
            int key;
            cin>> key;
            if(key_val.count(key))
            {
                cout << key_val[key] << endl;
                order.erase(key_address[key]);
                order.pb(key);
                key_address[key] = --order.end();
            }
            else{
                cout << "key not found " << endl;
            }
        }
    }   
    return 0;
}