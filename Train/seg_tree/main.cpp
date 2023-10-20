#include <bits/stdc++.h>
using namespace std;
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define pb push_back
#define fi first
#define se second



typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;



const int MOD=998244353;
const int N=1000005,E=524288;
const int maxN = 2*1e5;
int st[4*maxN], a[maxN]; //st = segment tree (contain max values of nodes)
int n,q,k,x,y;
// length of st_max <= 4*N
// N = 2^k, #node in tree = 2^k + 2^(k-1)+ .. + 2 + 1 = 2^(k+1) < 4*N (Maybe just 3 is enough)

// 1-index: parent i, child 2*i, 2*i+1
// [i,j] -> [i,(i+j)/2] ++ [(i+j)/2+1,j]
// Stop case: when i == j
void update(int i, int v, int id = 1, int l = 1, int r = n){
    // id is mapping with range [l,r]
    // change A[i] = v

    if(i < l || r < i){
        return; //out side the range
    }

    if(l == r){ // node with only one element -> stop case
        st[id] = v; // max of this node is updated value
    }

    int mid = (l+r)/2; 

    //update all leaf nodes 
    update(i,v,2*id,l,mid); //left child
    update(i,v,2*id +1,mid+1,r); //right child

    //recursive to root node with 2 children
    st[id] = max(st[2*id],st[2*id +1]);
}

// Find max in [u,v]
int get(int u, int v, int id = 1, int l = 1, int r = n){
    //[u,v] not intersect with [l,r]
    if(l > v || r < u){
        return INT_MIN;
    }
    //[u,v] is  bounding [l,r]
    if(u <= l && r <= v){
        return st[id]; //this max value
    }
    int mid = (l+r)/2;
    return max(get(u,v,2*id,l,mid),get(u,v,2*id+1,mid+1,r));
}

// Build tree using recursive
void build(int id = 1, int l = 1, int r = n){
    if(l == r){ // stop case
        st[id] = a[l]; // node(a[l])
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = max(st[id*2],st[id*2+1]);
}


// n q (n < 2*10^5)
// 1 k u (a[k] = u)
// 2 a b (1<=a<=b<=n) (Get max in range [a,b])
//TODO: make sure all variables get reset
void run_case(){
    cin>>n>>q;
    for1(i,n) cin>>a[i];
    // Build Segment tree
    build();
    while(q--){
        cin>>k>>x>>y;
        if(k == 1){ //update value
            update(x,y);
        }else if(k == 2){ // Get max
            cout<<get(x,y)<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    run_case();
    return 0;
}