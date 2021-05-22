#include<iostream>
#include<memory>
using namespace std;
struct Player{
    int x, y;
    ~Player(){
        cout << "Player destructed " << endl;
    }
};
int main(){
    // languages like python, java and ruby have auto 
    // memory management through garbage collecter
    // can we directly initialize a var in heap in cpp?
    // no we have to use pointers.
    // free or delete only work with pointers
    // smart pointers manage these memory spaces automatically
    // unique ptr
    // shared ptr
    // weak ptr
    {
        unique_ptr<Player> ptr1 = make_unique<Player>();
        ptr1->x = 20;
        ptr1->y = 30;
        cout << ptr1->x << endl;
    }
    cout << "should have been destroyed by now" << endl;
    shared_ptr<int> lol = make_shared<int>();
    *lol = 30;
    shared_ptr<int> t = lol;
    cout << lol << " " << t << endl;
}