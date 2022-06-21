// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

void InsertionSort(vector<int> &arr){

    for(int i = 0; i < arr.size(); i++){

        int j = i;

        int key = arr[i];

        while(j and arr[j - 1] > key)

            arr[j] = arr[j - 1], j--;

        arr[j] = key;
    }
}

void merge(int input[], int size){
    int* arr = new int[size];
    int* t = arr;
    
    int *pt1 = input;
    int *pt2 = input + size/2;

    while(pt1 < input + size/2 and pt2 < input + size){
        
        if(*pt1 < *pt2)
            	*t = *pt1, pt1++;
        
        else
            	*t = *pt2, pt2++;
        t++;
    }
    while(pt1 < input + size/2)
        	*t = *pt1, pt1++, t++;
	while(pt2 < input + size)
        	*t = *pt2, pt2++, t++;
    
    for(int i = 0; i < size; i++)
        	input[i] = arr[i];

    delete []arr;
}
void mergeSort(int input[], int size){
    if(size == 1)
        	return;
    
    mergeSort(input, size/2);
    
    mergeSort(input + size/2, (size + 1)/2);
    
    merge(input, size);
    
}

void getinsertionsort(vector<int> &arr){
    vector<int> cpy(arr);
    double start = clock();

    InsertionSort(cpy);

    double end= clock();

    cout << "insertionsort on array of size " << arr.size() << endl;
    cout << "time of execution " <<  fps((end - start) / CLOCKS_PER_SEC * 1000, 1) << " ms" << endl;
}
void getmergesort(vector<int> &arr){
    int cpy[arr.size()];

    for(int i = 0; i < arr.size(); i++) cpy[i] = arr[i];

    double start = clock();

    mergeSort(cpy, arr.size());

    double end = clock();
    cout << "mergesort on array of size " << arr.size() << endl;
    cout << "time of execution " <<  fps((end - start) / CLOCKS_PER_SEC * 1000, 1) << " ms" << endl;
}

int32_t main(){
        FIO 

        vector<int> lens = {40, 400, 4000, 40000};

        for(auto p : lens){
            random_device rd;

            mt19937 gen(100);

            uniform_int_distribution<> distr(1, 2 * p);

            vector<int> arr(p);

            for(int i = 0; i < p; i++){
                arr[i] = distr(gen);
            }
            getinsertionsort(arr);

            cout << endl;

            getmergesort(arr);
            cout << endl;
        }

        return 0;
}
