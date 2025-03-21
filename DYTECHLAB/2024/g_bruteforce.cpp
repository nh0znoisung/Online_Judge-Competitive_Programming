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

int gcd_of_vector(const vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        result = gcd(result, nums[i]);
        if (result == 1) { // Early termination if gcd becomes 1
            return 1;
        }
    }
    return result;
}

// Recursive function to generate all partitions and calculate effectiveness
void partition(int index, vector<int>& current_sums, vector<vector<int> >& groups, const vector<int>& capabilities, int& total_effectiveness) {
    if (index == capabilities.size()) {
        total_effectiveness += gcd_of_vector(current_sums);
        return;
    }

    for (int i = 0; i < current_sums.size(); i++) {
        current_sums[i] += capabilities[index];
        partition(index + 1, current_sums, groups, capabilities, total_effectiveness);
        current_sums[i] -= capabilities[index];
    }

    // Try adding a new group
    current_sums.push_back(capabilities[index]);
    partition(index + 1, current_sums, groups, capabilities, total_effectiveness);
    current_sums.pop_back();
}

int calculate_total_effectiveness(const vector<int>& capabilities) {
    int total_effectiveness = 0;
    vector<int> current_sums; // stores the sum of each group in the current partition
    vector<vector<int> > groups; // to keep track of groupings (not used here directly)
    partition(0, current_sums, groups, capabilities, total_effectiveness);
    return total_effectiveness;
}

//TODO: make sure all variables get reset
// g++ 4.\ Counting\ Divisors.cpp -o a && ./a
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
    // cin>>t;
    while(t--){
    	run_case();
    }
    return 0;
}