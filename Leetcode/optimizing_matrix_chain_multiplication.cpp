// dp 
// O(n**3)

// print the order in which matrices should be multiplied shuch that minimum scalar multiplications are used 

// parenthesize the expression

// for eg. A1 A2 A3 -> (A1(A2 A3))

// you are given an n + 1 length array of positive integers such that Ai matrix is of pi-1 x pi degrees

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int n = 10;

vector<vector<int>> m(n + 1, vector<int>(n + 1));

vector<vector<int>> s(n, vector<int>(n + 1));

void matrix_chain_order(vector<int> p){

    loop(i, 1, n + 1){

        m[i][i] = 0;   
    }

    loop(l, 2, n + 1){      // choose a length; calculate the answer for all subarrays of l length using subarrays of length 1, 2, 3... l-1;

        loop(i, 1, n - l + 2){

            int j = i + l - 1;

            m[i][j] = 1e9;

            loop(k, i, j){

                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < m[i][j]){

                    m[i][j] = q;

                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parsens(int i, int j){

    if(i == j){

        cout << "A" << i << " ";

    }

    else{

        cout << "( ";

        print_optimal_parsens(i, s[i][j]);

        print_optimal_parsens(s[i][j] + 1, j);

        cout << ") ";
    }
}

int main(){

    vector<int> p = {1, 4, 2, 8, 5, 6, 4, 1, 8, 7, 15, 2};

    matrix_chain_order(p);

    print_optimal_parsens(1, 10); 
}
