#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;



int main()
{
    vector<int> a;
    vector<vector<int>*> b;
    b.push_back(&a);
    // b.push_back(a);
    // for(auto &c:b){
    //     c.push_back(4);
    //     cout << c[2] << endl;
    // }
    for(auto copy:b){
        copy->push_back(7);
    }
    cout << a[0] << endl;           // it's copy of the pointer and that's why it works
    vector<int> d = {1, 2, 4};
    vector<vector<int>> lol;
    lol.push_back(d);           // copy of d is pushed back
    for(auto a:lol){
        a.push_back(56);

    }
    cout << lol[0][3] << endl;       // won't work

    for(auto &a:lol){
        a.push_back(56);

    }
    cout << lol[0][3] << endl;      // works
    // a.push_back(1);
    // a.push_back(INT32_MAX);
    // std::vector<int>::iterator c;
    // c = a.end();
    // cout << *a.begin() << endl;
    // cout << *a.end() << endl;
}