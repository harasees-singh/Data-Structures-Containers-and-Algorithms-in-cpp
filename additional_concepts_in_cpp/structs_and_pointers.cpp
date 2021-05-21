#include<iostream>
#include<cstdlib>
using namespace std;
// sturcts are user defined datatypes
// amalgum of multiple primitive and non-primitive datatypes
// initialzina a struct
struct Product{
    int cost;
    string name;
    int prod_id;

    // member functions
    void display(){
        cout << "name of the product is " << name << " and the cost " << cost << endl;
    }
};
void update_cost(struct Product &p, int x){
    p.cost = x;
    return;
}
int main(){
    Product p1 = {10, "pencil", 78};
    p1.cost = 99;
    
    // advantage of references
    update_cost(p1, 100);
    p1.display();

    // pointers
    // types of pointers 

    // 1) dangling pointer - a ptr pointing to a memory location, that has 
    // been deleted.
    // 2) NULL pointer - a ptr which pts to nothing or null.
    // int* ptr=NULL; for initialization
    int* ptr;
    cout << *ptr << endl;        // gives a random value
    int* ptr_2 = NULL;           // NULL ptr initialized 
    cout << ptr_2 << endl;       // gives 0

    // why do we mention the datatype while defining the ptr
    // so that compiler is able to do the ptr arithmeitc 
    // 3) void ptr is a generic ptr that can pt to anything.
    // we can't dereference a void ptr and no arithmetic can be done

    void *ptr__;
    int x=100;
    ptr__=&x;
    cout << ptr__ << endl;
    cout << *((int*)ptr__) << endl;     // need to typecast before
                                        // dereferencing
    *((int*)ptr__) = 98;
    cout << x;                          // can use this to update values

    void *struc_ptr = &p1;
    cout << struc_ptr << endl;
    Product *p = &p1;
    cout << p->cost << endl;
    // cout << struc_ptr->cost << endl;     // this is not working
    

    // learning malloc;
    int *pm;
    void *v;
    v = malloc(5);      // (initializes in heap) makes a bucket of size 5 and returns it's ptr
    cout << v << endl;
    v = malloc(sizeof(int));        // make a bucket of the same size a sinteger
    pm = (int*)v;
    cout << *pm << endl;
    // pm = malloc(sizeof(int)); won't work

    // 4) wild pointer - an uninitialized ptr, can lead to memory leakage
    // 5) function poitner 

    // new and delete are keywords 
    // they are replacement to malloc, calloc, realloc and free functions

    // dynamic memory allocation

    int *q = new int(50);           // int is the type of the bucket
    cout << q << " " << *q << endl;
    float *f = new float(7.889);    // float is the type of the bucket
    cout << *f << endl;

    // a = {1, 2, 3, 4} here a stores the address of 1 i.e. the first element
    int *a = new int[40]();     // 40 len int array with all zeroes, array in heap
    cout << *a << " " << *(a+1) << endl;
    // int a[40];               // array in stack frame;
    int **arr = new int*(q);
    cout << **arr <<  endl;     // outputs the int stored at q;

    delete []a;                   // free the space that a pts to

    int **lol = new int*[10];       // primary array of len 10 which will store addressess of secondary arrays
    for(int i=0; i<10 ; i++){
        arr[i] = new int[5];
    }
    // made a 2d array lol of size 10x5
    cout << lol[1][1] << endl;

    for(int j=0; j<10; j++){
        delete []arr[j];
    }
    delete []arr;
    // if we use nothrow and the memory is full it will not return bad alloc error
    // insteard it will make it point to NULL;
    int *d = new(nothrow) int(50);
    if(!d){
        cout << "mem alloc failed " << endl;
    }
    cout << *d << endl;

    
    return 0;
}