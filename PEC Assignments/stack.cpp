#include<iostream>
using namespace std;
class Stack{
public: 
    int cap;
    int pt;
    int *arr;

    Stack(){
        pt = -1; 
        arr = new int[1000]; 
        cap = 1000;       
    }

    Stack(int n){
        pt = -1;
        cap = n;
        arr = new int[n];
    }

    void push(int n){
        if(pt < cap - 1)
            arr[++pt] = n;
        else cout << "Overflow" << '\n';
    }

    void pop(){
        if(pt >= 0)
            pt--;
        else cout << "Underflow" << endl;
    }

    int top(){
        if(pt >= 0)
            return arr[pt];
        else 
            cout << "Underflow" << endl;
    }

    void display(){
        int t = pt;
        while(t >= 0)
            cout << arr[t] << ' ', t--;
        cout << endl;
    }

    bool isEmpty(){
        return (pt < 0);
    }
};
int main(){
    Stack s(3);
    s.push(1), s.push(2), s.push(3), s.push(4);
    s.display();
    cout << s.top() << endl;
    s.pop();
    s.push(4);
    cout << s.top() << endl; s.pop(); s.pop(); s.pop(); s.pop();
    cout << s.isEmpty() << endl;
    return 0;
}