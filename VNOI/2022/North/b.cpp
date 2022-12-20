#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[11],b[11],str[1000005][11][11];
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef NEAL_DEBUG
        cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll m,n,s,check=0;
    cin>>m>>n>>s;
    for(ll i=1; i<=n; i++) {
        for(ll j=1; j<=n; j++) {
            str[0][i][j]=s;
        }
    }
    for(ll i=1; i<=n; i++) cin>>a[i]>>b[i];
    for(ll j=1; j<=m; j++) {
        check++;
        for(ll i=1; i<=n; i++) {
            for(ll k=1; k<=n; k++) {
                str[j][i][k]=(str[j-1][i][k]*a[k]+b[k])%m;
                if(str[j][i][k]==0) {
                    cout<<check;
                    return 0;
                }
            }
        }
    }
    if(!check) cout<<-1;
}