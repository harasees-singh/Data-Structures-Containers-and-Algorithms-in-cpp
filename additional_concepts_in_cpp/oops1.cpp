#include<iostream>
using namespace std;
class Product{
    public:
        Product(string name, int c){
            this->name =name; cost=c;
        }
        
        void display(){
            cout << name << " " << cost << endl;
        }
        Product* pointer(){
            return this;
        }
        
    private:
        string name;
        int cost;
};

int main(){
    // every class will give u a default constructor
    Product p("lol", 798);
    cout << p.pointer() << endl;
    p.display();
    // what happens when u create an object 
    // these are made in call stack
    // this is a pointer and it points to obj itself
    // only diff b/w struct and classes is that struct is public by default
    // classes are private by default.
    // structs are present for backward compatibility
    
}