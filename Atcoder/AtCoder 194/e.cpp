#include <bits/stdc++.h>
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

int missing(vector<int>nums){
     int firstMissingPositive(int[] nums) {
        int idx = 0, len = nums.length;
        while (idx < len) {

            if (nums[idx] == idx + 1 || nums[idx] <= 0 || nums[idx] > len) {
                idx++;
                continue;
            }

            if (nums[nums[idx] - 1] != nums[idx])
                swap(nums, idx, nums[idx] - 1);
            else
                idx++;
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1)
                return (i + 1);
        }

        return len + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>check(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i = 0; i<m; i++){
        check[a[i]]++;
    }
    return 0;
}