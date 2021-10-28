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

class Solution {
   public:
    int cal(vector<int>x, vector<int>y){
        return abs(x[0]-y[0]) + abs(x[1]-y[1]);
    }
    int minDistance(int height, int width, vector<int>&tree, vector<int>&squirrel, vector<vector<int>>&nuts){
        int sum =0;
        int mn = cal(squirrel, nuts[0]) - cal(tree, nuts[0]);
        int idx = 0;
        for(int i =0 ; i<nuts.size(); i++){
            sum += 2*(cal(tree, nuts[i]));
            //find min
            if(mn > cal(squirrel, nuts[i]) - cal(tree, nuts[i])){
                idx = i;
                mn = min(mn, cal(squirrel, nuts[i]) - cal(tree, nuts[i]));
            }
        }
        sum += mn;
        //show the path
        cout<<"squirrel -> Nut"<<idx<<" -> Tree";
        for(int i =0 ; i<nuts.size(); i++){
            if(i != idx){
                cout<<" -> Nut"<<i<<" -> Tree";
            }
        }
        cout<<endl;
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution ob;
    int h = 1e5;
    int w = 1e5;
    vector<int>t = {2,2};
    vector<int>s = {4,4};
    vector<vector<int>>n  ={{3,0}, {2,5}};
    cout<<(ob.minDistance(h,w,t,s,n))<<endl;
    return 0;
}