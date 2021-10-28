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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto it : a) cin >> it;

	sort(a.begin(), a.end());
	vector<pair<int, int>> cnt;
	for (auto it : a) {
		if (cnt.empty() || cnt.back().first != it) {
			cnt.push_back({it, 1});
		} else {
			++cnt.back().second;
		}
	}
	vector<long long> prefsum, sufsum;
	vector<int> prefcnt, sufcnt;
	for (int i = 0; i < int(cnt.size()); ++i) {
		long long cursum = cnt[i].first * 1ll * cnt[i].second;
		int curcnt = cnt[i].second;
		if (prefsum.empty()) {
			prefsum.push_back(cursum);
			prefcnt.push_back(curcnt);
		} else {
			prefsum.push_back(prefsum.back() + cursum);
			prefcnt.push_back(prefcnt.back() + curcnt);
		}
	}
	for (int i = int(cnt.size()) - 1; i >= 0; --i) {
		long long cursum = cnt[i].first * 1ll * cnt[i].second;
		int curcnt = cnt[i].second;
		if (sufsum.empty()) {
			sufsum.push_back(cursum);
			sufcnt.push_back(curcnt);
		} else {
			sufsum.push_back(sufsum.back() + cursum);
			sufcnt.push_back(sufcnt.back() + curcnt);
		}
	}
	reverse(sufsum.begin(), sufsum.end());
	reverse(sufcnt.begin(), sufcnt.end());

	long long ans = INF64;
	for (int i = 0; i < int(cnt.size()); ++i) {
		int cur = max(0, k - cnt[i].second);

		int needl = 0;
		if (i > 0) needl = min(cur, prefcnt[i - 1]);
		int needr = max(0, cur - needl);
		long long res = 0;
		if (i > 0 && needl > 0) {
			res += prefcnt[i - 1] * 1ll * (cnt[i].first - 1) - prefsum[i - 1];
			res += needl;
		}
		if (i + 1 < int(cnt.size()) && needr > 0) {
			res += sufsum[i + 1] - sufcnt[i + 1] * 1ll * (cnt[i].first + 1);
			res += needr;
		}
		ans = min(ans, res);

		needr = 0;
		if (i + 1 < int(cnt.size())) needr = min(cur, sufcnt[i + 1]);
		needl = max(0, cur - needr);
		res = 0;
		if (i > 0 && needl > 0) {
			res += prefcnt[i - 1] * 1ll * (cnt[i].first - 1) - prefsum[i - 1];
			res += needl;
		}
		if (i + 1 < int(cnt.size()) && needr > 0) {
			res += sufsum[i + 1] - sufcnt[i + 1] * 1ll * (cnt[i].first + 1);
			res += needr;
		}
		ans = min(ans, res);
	}

	cout << ans << endl;
	return 0;
}

