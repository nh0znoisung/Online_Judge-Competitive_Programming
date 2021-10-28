#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<pair<int, int>, cmp> segs;
		segs.insert({0, n - 1});
		vector<int> a(n);
		for (int i = 1; i <= n; ++i) {
			pair<int, int> cur = *segs.begin();
			segs.erase(segs.begin());
			int id = (cur.first + cur.second) / 2;
			a[id] = i;
			if (cur.first < id) segs.insert({cur.first, id - 1});
			if (id < cur.second) segs.insert({id + 1, cur.second});
		}
		for (auto it : a) cout << it << " ";
		cout << endl;
	}

	return 0;

}
