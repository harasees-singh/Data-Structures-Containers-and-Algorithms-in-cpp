// O(n*n) approach with linear space complexity, brute force basically

#include<bits/stdc++.h>
using namespace std;
int main() {
	
	string s1, s2;
	
	cin >> s1 >> s2;
	
	if(s1.size() != s2.size()) {cout << "NO" << endl; exit(0);}
	
	bool ok = false;
	
	for(int i = 0; i < s1.size(); i++){
	    
	    if(s1 == s2.substr(i, s1.size())) {cout << "YES" << endl; ok = true; break;}
	    
	    s2.push_back(s2[i]);
	}
	
	if(!ok) cout << "NO" << endl;
	
	return 0;
}