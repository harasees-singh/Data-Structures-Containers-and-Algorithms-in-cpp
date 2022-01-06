#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Pair{
        int first, second;

        Pair(int f, int s){
                first = f, second = s;
        }
};

Pair make_Pair(int f, int s){
        
        Pair q(f, s);
        return q;
}

const int N = 100000;

int P[N];
int d[N];
int vis[N];
vector<vector<Pair>> g; 
// vector<vector<pair<int, int>>> g; 

int FindMin(){
        // to greedily pick up the node which is closest to the source s and not included in the shortest paths tree.
        int mini = INT32_MAX;
        int idx = -1;
        for(int i = 1; i < N; i++){
                if(!vis[i] and d[i] < mini)
                        mini = d[i], idx = i;
        }
        // if we return idx = -1 that means all the nodes are now part of the shortest paths.  
        return idx;
}

void Relax(Pair p, int node){
        // Relaxing the edge {node, p.first}
        if(d[p.first] > d[node] + p.second){
                P[p.first] = node;
        }
        d[p.first] = min(d[p.first], d[node] + p.second);
}

void Dijkstra(int s){
        // initializing distance array and visited array.
        for(int i = 0; i < N; i++){
                d[i] = INT32_MAX;
                vis[i] = 0;
                P[i] = -1;
        }
        // initializing distance of source from source to 0
        d[s] = 0;

        for(int i = 1; i < g.size(); i++){
                int node = FindMin();
                // marking node as visited means it is a part of our shortest path tree from this point forward.
                vis[node] = 1;

                for(auto p : g[node])
                        // Relaxing all edges flowing out of node.
                        Relax(p, node);
        }
}

// single source shortest path in O(|E| + |V|*|V|) time.
int main(){

        cout << "Enter the number of vertices of the graph" << '\n';

        int n;
        cin >> n;

        g = vector<vector<Pair>>(n + 1);

        cout << "Enter the number of edges of the graph" << '\n';

        int m;
        cin >> m;

        for(int i = 0; i < m; i++){
                cout << "enter edge connecting u and v vertices and it's weight" << '\n';

                int u, v, w; cin >> u >> v >> w;

                g[u].push_back(make_Pair(v, w));
                g[v].push_back(make_Pair(u, w));
        }

        Dijkstra(1);

        for(int j = 1; j <= n; j++){
                int i = j;
                vector<int> path = {i};

                while(P[i] != -1)
                        path.push_back(P[i]), i = P[i];
                
                reverse(path.begin(), path.end());

                for(auto &p : path) cout << p << ' '; 
                
                cout << endl;
        }

        for(int i = 1; i <= n; i++) cout << d[i] << ' '; cout << endl;
}