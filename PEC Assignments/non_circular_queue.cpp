#include<bits/stdc++.h>
using namespace std;

struct Queue{

        int front, back;
        int* arr; 
        int cap;

        Queue(){
            front = 0, back = -1; arr = new int [1000]; cap = 1000;
        }

        Queue(int n){
            front = 0, back = -1; arr = new int [n]; cap = n;
        }

        bool isEmpty(){
            return (back == front - 1);
        }

        void pushBack(int a){

            if(back < cap - 1)
                    arr[++back] = a;
            
            else 
                    cout << "Queue is full, can't support push operation " << endl;
        }
        int top(){
            if(isEmpty())
                    cout << "Queue is empty returning " << endl;
            else
                    return arr[front];

            return -999999;
        }
        int dequeue(){
            	if(isEmpty())
			cout << "Queue is empty returning " << endl;
		else{    
			front++;
			return arr[front - 1];
           	}
            return -999999;
        }

        void printQueue(){
		int t = front;
		while(t != back + 1)
                    	cout << arr[t] << ' ', t++;
            	cout << endl;
        }
};

int32_t main(){

        cout << "Please enter the maximum number of elements that you will be entering in the queue " << endl;

        int n; cin >> n;  

        Queue Q(n);

        cout << "Queue of length " << n << " successfully initialized" << endl;
        cout << "Use 1 for enqueue operation, 2 to print the top element, 3 to dequeue, 4 to print the Queue, 5 to check if is empty and 0 to exit the program" << endl;

        while(true){
                
                int t; cin >> t;
                if(!t)
                        break;
                switch (t)
                {
                case 1:
                        int t; cin >> t;
                        Q.pushBack(t);
                        break;
                case 2:
                        cout << Q.top() << endl;
                        break;
                case 3:
                        Q.dequeue();
                        break;
                case 4:
                        Q.printQueue();
                        break;
                case 5:
                        cout << (Q.isEmpty() ? "EMPTY" : "NOT EMPTY") << endl;
                        break;
                default:
                        break;
                }
        }
        
        return 0;
}
