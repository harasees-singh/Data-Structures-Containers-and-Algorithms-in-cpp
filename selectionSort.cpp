#include<bits/stdc++.h>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>

using namespace std;

int find_min_element(int i, vi &arr){

    int minima = i;

    for(int j = i + 1; j < sz(arr); j++){

        if(arr[j] < arr[minima]) minima = j; 
    }

    return minima;
}

void SelectionSort(vi &arr){

    for(int i = 0; i < sz(arr); i++){

        int index = find_min_element(i, arr);

        swap(arr[i], arr[index]);
    }

    

    return;
}

MOD_DEFINE
int32_t main(){
    FIO

    vi input = {2, 4, 7, 9, 10, 4, 6, 11};

    SelectionSort(input);

    loop(i, 0, sz(input)) cout << input[i] << space; cout << endl;

    int arr[2] = {1, 2};

    return 0;
}
