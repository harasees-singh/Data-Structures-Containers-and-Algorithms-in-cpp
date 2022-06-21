#include <bits/stdc++.h>
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x
using namespace std;
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
vector<int> parent, Size;
int find_set(int v)
{
    if (v == parent[v])
        return v;
 
    return parent[v] = find_set(parent[v]);
}

int union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {

		if (Size[a] < Size[b])
			swap(a, b);

		parent[b] = a;
		Size[a] += Size[b];
		return 1;
	}

	return 0;
}

void MST(int houses[][2], int n)
{
	vector<pair<int, pair<int, int> > > v;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			int p = abs(houses[i][0]
						- houses[j][0]);

			p += abs(houses[i][1]
					- houses[j][1]);

			v.push_back({ p, { i, j } });
		}
	}

	parent.resize(n);
	Size.resize(n);

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		parent[i] = i, Size[i] = 1;
	}

	int ans = 0;

	for (auto x : v) {

		if (union_sets(x.second.first,
					x.second.second)) {
			ans += x.first;
		}
	}

	cout << ans;
}

int32_t main()
{
    int n; cin >> n;

    int houses[n][2];
    vector<pair<int, int>> in(n); 
    
    for(auto &p : in) cin >> p;

    for(int i = 0; i < n; i++) houses[i][0] = in[i].first, houses[i][1] = in[i].second;

	MST(houses, n);

	return 0;
}
