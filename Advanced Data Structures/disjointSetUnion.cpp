#include<bits/stdc++.h>
using namespace std;

const int N = 500000;
int Rank[N + 1];
int parent[N + 1];

void MakeSet(){
        for(int i = 1; i <= N; i++)
                parent[i] = i;
}

int findParent(int v){

        if(parent[v] == v)
                return v;
        
        return parent[v] = findParent(parent[v]);
}

void Union(int u, int v){

        u = findParent(u), v = findParent(v);

        if(Rank[u] > Rank[v])
                parent[v] = u;
        else if(Rank[u] < Rank[v])
                parent[u] = v;
        else        
                parent[v] = u, Rank[u]++;
}

int main(){
        MakeSet();

        Union(1, 3), Union(5, 7), Union(5, 8), Union(3, 8), Union(9, 8);

        cout << findParent(7) << ' ' << findParent(3) << ' ' << parent[8];      // parent of 8 set to 1 instead of 5 due to path compression

}