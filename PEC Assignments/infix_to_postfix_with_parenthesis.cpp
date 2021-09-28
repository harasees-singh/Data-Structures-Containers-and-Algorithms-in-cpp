#include<iostream>
#include<string>
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
    int precedence[150] = {0};
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 3; 
    // if precedence of a char = 0 then we know that it must be a variable or '(' or ')'.
    string input; 
    cin >> input;
    Stack s(input.size());
    string ans; 
    for(char p : input){
        if(p == ')'){
            while(s.isEmpty() == false and s.top() != '(')
                ans.push_back(s.top()), s.pop();
            if(s.isEmpty() == false)
                s.pop();
        }
        else if(p == '(')
            s.push(p);

        else if(precedence[p] == 0)
            ans.push_back(p);

        else{
            while(s.isEmpty() == false and precedence[s.top()] > precedence[p])
                ans.push_back(s.top()), s.pop();
            s.push(p);
        }
    }
    while(s.isEmpty() == false and s.top() != '(')
        ans.push_back(s.top()), s.pop();
    cout << ans << endl;
}