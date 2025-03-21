#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <algorithm>
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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int calculate_total_effectiveness(const vector<int>& capabilities) {
    int n = capabilities.size();
    int total_effectiveness = 0;
    
    for (int mask = 1; mask < (1 << n); ++mask) {
        int group_sum = 0;
        for0(i, n) {
            if (mask & (1 << i)) group_sum += capabilities[i];
        }
        
        int division_effectiveness = group_sum;
        for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask) {
            int subset_sum = 0;
            for0(i, n) {
                if (submask & (1 << i)) subset_sum += capabilities[i];
            }
            division_effectiveness = gcd(division_effectiveness, subset_sum);
        }
        total_effectiveness += division_effectiveness;
    }
    return total_effectiveness;
}

void run_case(){
    int n;
    cin >> n;
    vector<int> capabilities(n);
    for (int i = 0; i < n; i++) {
        cin >> capabilities[i];
    }
    cout << calculate_total_effectiveness(capabilities) << endl;
}

int main() {
    init_code();
    int t = 1;
    while(t--){
    	run_case();
    }
    return 0;
}
