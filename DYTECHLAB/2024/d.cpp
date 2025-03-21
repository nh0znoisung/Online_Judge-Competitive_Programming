#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
#include <vector>
#include <numeric>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
const int M=998244353;
const int N=1000005,E=524288;


void init_code(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	#endif
}

pair<bool, bool> check_palin(string& s) {
    unordered_map<char, int> um;
    int n = s.size();
    for (char c : s) {
        um[c]++;
    }
    int count_odd = 0;
    bool is_palin = true; // is_palin
    bool is_all = false; // is_all value the same
    for (auto i : um) {
        if (i.second == n) is_all = true;
        if (i.second % 2 == 1) {
            count_odd++;
            if (count_odd > 1) {
                is_palin = false;
                break;
            }
        } else continue;
    }

    return make_pair(is_palin, is_all);
}

//TODO: make sure all variables get reset
// g++ 4.\ Counting\ Divisors.cpp -o a && ./a
void run_case(){
    string s; cin >> s;
    pair<bool, bool> p = check_palin(s);
    bool is_palin = p.first;
    bool is_all = p.second;
    if (!is_palin) {
        cout << "Skywalker" << endl;
    } else {
        if (s.size() % 2 == 0) {
            if (is_all) { // all with the same value
                cout << "Amidala" << endl;
            } else {
                cout << "Skywalker" << endl;
            }
            
        } else {
            cout << "Amidala" << endl;
        }
    }
    
}

int main() {
    init_code();
    int t;
    cin>>t;
    while(t--){
    	run_case();
    }
    return 0;
}