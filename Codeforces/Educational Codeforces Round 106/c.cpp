#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1000005,E=524288;
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
int x[N],y[N],i,mp,c,t,f[N],a[N];
long long n,m,k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>c(n);
        for(long long i = 0; i<n; i++){
            cin>>c[i];
        }
        long long ans = INT64_MAX;
        long long idx1 = 0; // min of even
        long long idx2 = 1; //min of odd
        //IN case k = 2
        long long sum = 0;
        sum = n*c[0] + n * c[1];
        ans = sum;
        // cout<<sum<<endl;
        for(long long k = 2; k<n; k++){
            //even
            if(k % 2 == 1){
                //odd
                if(c[k] >= c[idx2]) sum = (long long) sum - c[idx2] + c[k];
                else{
                    sum = sum +(long long) (n-k/2)*(c[k] - c[idx2]); // check 1
                    idx2 = k;
                }
            }else{
                if(c[k] >= c[idx1]) sum = (long long) sum - c[idx1] + c[k];
                else{
                    // cout<<"awdfas"<<endl;
                    sum = sum + (long long) (n-k/2)*(c[k] - c[idx1]);
                    idx1 = k;
                }
            }
            if(sum < ans) ans = sum;
        }
        cout<<ans<<endl;

    }
    return 0;
}