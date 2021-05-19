#include<iostream>
int main(){
    int a=9;
    int &b = a;
    b++;
    std::cout << a;
}
