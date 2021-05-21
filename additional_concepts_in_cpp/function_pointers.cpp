#include<iostream>
#include<vector>
using namespace std;
void hello(){
        cout << "hello world" << endl;
    }
int fun(int n){
    cout << "fun with " << n << endl;
    return n;
}
void func(int val){
    cout << val << " ";
}
void for_each(vector<int> &v, void(*func)(int)){
    for(int val:v){
        func(val);
    }
    cout << endl;
}
int main(){
    int x=10;       // stored in stack frame for main
                    // a bucket labeled x containing x is stored
    //int *ptr = &x;  // here we declared the integer at compile time.
    // if we want to manage this at run time we need to use heap pool
    // to get access to the bucket without first declaring x
    // if the stack frame dies it will lead to the death of our var.
    // we use heap to solve this problem
    // we initialize the bucket in the heap and even if the stack frame dies our var is not affected.
    // introducing new and delete operators.
    
    // the new operator is the replacement to malloc in c
    // when u use new it creates a bucket in the heap and returns the address of the bucket
    // the type of the ptr var depends on the type of the bucket.
    int* ptr = new int(8);      // during a bucket
    cout << *ptr;
    // initializing an array
    int *arr = new int[10];
    // initialize it with all zeroes
    int *zeroes = new int[10]();
    for(int i=0; i<10; i++){
        cout << *zeroes << endl;
        zeroes++;
    }
    // 2d array in heap is not in column major or row major form
    int rows=3, cols=4;
    int **grid = new int*[rows];        // initialization of primary array
    for(int i=0; i<rows; i++){
        grid[i] = new int[cols];
    }
    // function pointers
    // void(*pointr)() = hello; // this is the traditional way
    auto pointr=&hello;
    pointr();
    cout << ptr;
    cout << endl;
    // this is diff from a normal ptr, try dereferencing it 
    int(*fptr)(int) = fun;
    // auto fptr = &fun;
    fptr(7);
    vector<int> v = {1, 2, 3, 4, 5};
    // callback 
    for_each(v, func);
    int a=10;
    // lambda in cpp
    for_each(v, [](int v) {cout << "value from lambda " << v << endl;});
    return 0;
}